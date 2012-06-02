#include "JuPrimarySource.h"

#include <JuEvent.h>

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <memory.h>
#include <JuDebug.h>

struct JuPrimarySourcePriv {
	JuPrimarySourcePriv() : m_writefd(-1), m_readfd(-1), m_buf(NULL) {

	}

	int m_writefd;
	int m_readfd;
	char *m_buf;
};

JuPrimarySource::JuPrimarySource() : m_priv(new JuPrimarySourcePriv()) {

}

bool JuPrimarySource::init() {
	assert(m_priv != NULL);

	if (m_priv->m_readfd != -1) {
		JUDEBUG("It has already initialized.");
		return false;
	}

	int fd[2];

	if (pipe(fd) < 0) {
		JUDEBUG("Can not create pipe.");
		return false;
	}

	m_priv->m_readfd = fd[0];
	m_priv->m_writefd = fd[1];
	m_priv->m_buf = new char[JU_EVENT_MAX_SIZE];
	return true;
}

int JuPrimarySource::getFd() const {
	return m_priv->m_readfd;
}

int JuPrimarySource::check() {
	return -1;
}

void JuPrimarySource::dispatch() {
	assert(m_priv != NULL);

	int ret = read(m_priv->m_readfd, m_priv->m_buf, JU_EVENT_MAX_SIZE);

	if (ret < 0 || ret < sizeof(JuEvent)) {
		JUDEBUG("Reading event fault %d : %d", ret, sizeof(JuEvent));
		return;
	}

	int *p = (int *)(m_priv->m_buf);

	if (*(++p) != ret) {
		JUDEBUG("Event size is not right");
		return;
	}

	dispatchEvent((JuEvent *)(m_priv->m_buf));
}

void JuPrimarySource::postEvent(JuEvent *event) {
	if (write(m_priv->m_writefd, (char *)event, event->size()) != event->size()) {
		JUDEBUG("Writing event fault.");
	}
}

JuPrimarySource::~JuPrimarySource() {
	if (m_priv != NULL) {
		if (m_priv->m_readfd != -1) {
			close(m_priv->m_readfd);
		}

		if (m_priv->m_writefd != -1) {
			close(m_priv->m_writefd);
		}

		delete m_priv->m_buf;

		delete m_priv;
	}
}
