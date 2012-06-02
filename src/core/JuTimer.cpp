#include "JuTimer.h"

#include "JuTimerSource.h"
#include "JuLoop.h"
#include "JuApp.h"

#include <vector>

using namespace std;
struct JuTimerPriv {
	JuTimerSource *m_source;
	bool m_isRunning;
};

JuTimer::JuTimer() {
	m_priv = new JuTimerPriv;
	m_priv->m_isRunning = false;
}

void JuTimer::start(int usec) {
	if (m_priv->m_isRunning)
		return;

	m_priv->m_source = new JuTimerSource(usec);
	getCurrentMainLoop()->addSource(m_priv->m_source);
	m_priv->m_source->addListener(JuApp::getApp());
	m_priv->m_isRunning = true;
}

void JuTimer::stop() {
	if (m_priv->m_isRunning) {
		delete m_priv->m_source;
		m_priv->m_source = NULL;
		getCurrentMainLoop()->removeSource(m_priv->m_source);
		m_priv->m_isRunning = false;
	}
}

JuTimer::~JuTimer() {
	delete m_priv;
}

int JuTimer::timerId() {
	return (long)m_priv->m_source;
}
