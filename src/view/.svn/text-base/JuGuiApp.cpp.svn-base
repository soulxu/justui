#include "JuGuiApp.h"

#include "JuView.h"

struct JuGuiAppPriv {
	JuView *view;
};

JuGuiApp::JuGuiApp(int argc, char **argv) : JuApp(argc, argv), m_priv(new JuGuiAppPriv()) {
	m_priv->view = 0;
}

void JuGuiApp::addView(JuView *view) {
	m_priv->view = view;
}

JuGuiApp::~JuGuiApp() {
	delete m_priv->view;
	delete m_priv;
}
void JuGuiApp::onEvent(JuEvent *event) {
	m_priv->view->processEvent(event);
}
