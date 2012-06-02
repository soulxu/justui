#include "JuLoop.h"

#include "JuEventSource.h"

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <vector>

#include "JuDebug.h"

using namespace std;

struct JuLoopPriv {
	vector<JuEventSource *> m_sourceList;
	int m_exitCode;
	bool m_isRunning;
};

JuLoop::JuLoop() : m_priv(new JuLoopPriv()) {
	if (getCurrentMainLoop() == NULL) {
		setCurrentMainLoop(this);
	}
	m_priv->m_exitCode = 0;
	m_priv->m_isRunning = true;
}

JuLoop::~JuLoop() {
	delete m_priv;
}

void JuLoop::addSource(JuEventSource *source) {
	m_priv->m_sourceList.push_back(source);
}

void JuLoop::removeSource(JuEventSource *source) {
	vector<JuEventSource *>::iterator iter = m_priv->m_sourceList.begin();

	while (iter != m_priv->m_sourceList.end()) {
		if (*iter == source) {
			m_priv->m_sourceList.erase(iter);
		}

		iter++;
	}
}

int JuLoop::computeTimeout() {
	if (m_priv->m_sourceList.size() <= 0) {
		return -1;
	}

	int ret = m_priv->m_sourceList.at(0)->check();

	for (int i = 1; i < m_priv->m_sourceList.size(); i++) {
		JuEventSource *src = m_priv->m_sourceList.at(i);
		int c = src->check();
		ret = ((ret > 0 && ret < c) ? ret : c);
	}

	return ret;
}

int JuLoop::exec() {
	int timeout = 0;
	struct timeval timeoutVal;
	struct timeval *tv;

	while (m_priv->m_isRunning) {
		timeout = computeTimeout();
		JUDEBUG("timeout %d", timeout);

		while (timeout == 0) {
			for (int i = 0; i < m_priv->m_sourceList.size(); i++) {
				JuEventSource *src = m_priv->m_sourceList.at(i);

				if (src->check() == 0)
					src->dispatch();
			}

			timeout = computeTimeout();
		}

		if (timeout < 0) {
			tv = NULL;
		}
		else {
			timeoutVal.tv_sec = 0;
			timeoutVal.tv_usec = timeout;
			tv = &timeoutVal;
		}

		int fdCount = 0;
		int maxfd = 0;
		fd_set fds;
		FD_ZERO(&fds);

		for (int i = 0; i < m_priv->m_sourceList.size(); i++) {
			JuEventSource *src = m_priv->m_sourceList.at(i);
			int fd = src->getFd();

			if (fd != -1) {
				if (fd > maxfd)
					maxfd =fd;
				FD_SET(src->getFd(), &fds);
				fdCount++;
			}
		}

		//JUDEBUG("fdCount :: %d", fdCount);

		int ret = select(maxfd + 1, &fds, NULL, NULL, tv);

		//JUDEBUG("select return");

		if (ret < 0) {
			JUDEBUG("select error");
			exit(-1);
			continue;
		}

		if (ret == 0) {
			for (int i = 0; i < m_priv->m_sourceList.size(); i++) {
				JuEventSource *src = m_priv->m_sourceList.at(i);

				if (src->check() == 0)
					src->dispatch();
			}
		}
		else if (ret > 0) {
			JUDEBUG("fd returned");
			for (int i = 0; i < m_priv->m_sourceList.size(); i++) {
				JuEventSource *src = m_priv->m_sourceList.at(i);
				if (FD_ISSET(src->getFd(), &fds))
					src->dispatch();
			}
		}
		else {
			JUDEBUG("select error");
		}
	}

	return m_priv->m_exitCode;
}

void JuLoop::exit(int exitCode) {
	m_priv->m_exitCode = exitCode;
	m_priv->m_isRunning = false;
}

JuLoop *gMainLoop = NULL;
