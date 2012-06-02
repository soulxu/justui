#include "JuApp.h"

#include <JuTtySource.h>
#include <JuLoop.h>
#include <JuPrimarySource.h>
#include <JuDebug.h>

#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

struct JuAppPriv {
	JuAppPriv() {
		m_mainLoop = NULL;
		m_ttySrc = NULL;
		m_priSrc = NULL;
		memset(tty, 0, 4096);
	}
	JuLoop *m_mainLoop;
	JuTtySource *m_ttySrc;
	JuPrimarySource *m_priSrc;
	char tty[4096];
	vector<JuEventListener *> m_listeners;
};

JuApp *JuApp::gApp = NULL;

JuApp *JuApp::getApp() {
	return gApp;
}

JuApp::JuApp(int argc, char **argv) : m_priv(new JuAppPriv()){
	if (gApp != NULL) {
		JUDEBUG("Only one JuApp can exist!");
		exit(-1);
	}

	gApp = this;

	if (getCurrentMainLoop() == NULL) {
		setCurrentMainLoop(new JuLoop());
	}

	parseArgs(argc, argv);

	m_priv->m_mainLoop = getCurrentMainLoop();
	m_priv->m_priSrc = new JuPrimarySource();
	if (!m_priv->m_priSrc->init()) {
		JUDEBUG("can not init primary source");
        exit(-1);
		return;
	}
	m_priv->m_priSrc->addListener(this);

	m_priv->m_ttySrc = new JuTtySource(m_priv->tty);
	if (!m_priv->m_ttySrc->initDevice()) {
		JUDEBUG("Can not init input device");
		exit(-1);
		return;
	}
	m_priv->m_ttySrc->addListener(this);

	m_priv->m_mainLoop->addSource(m_priv->m_priSrc);
	m_priv->m_mainLoop->addSource(m_priv->m_ttySrc);
}

JuApp::~JuApp() {
	gApp = NULL;
	delete this->m_priv->m_mainLoop;
	delete this->m_priv->m_priSrc;
	delete this->m_priv->m_ttySrc;
	delete this->m_priv;
}

void JuApp::exit(int exitCode) {
	m_priv->m_mainLoop->exit(exitCode);
}

void JuApp::parseArgs(int argc, char **argv) {
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-tty") == 0) {
			i++;
			i < argc ? strcpy(m_priv->tty, argv[i]) : NULL;
		}
	}
}

int JuApp::exec() {
	return m_priv->m_mainLoop->exec();
}

void JuApp::onEvent(JuEvent *event) {
	for (int i = 0; i < m_priv->m_listeners.size(); i++) {
		m_priv->m_listeners.at(i)->onEvent(event);
	}
}

void JuApp::addEventListener(JuEventListener *listener) {
	m_priv->m_listeners.push_back(listener);
}

void JuApp::postEvent(JuEvent *event) {
	m_priv->m_priSrc->postEvent(event);
}
