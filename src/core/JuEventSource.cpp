#include "JuEventSource.h"

#include "JuEventListener.h"

#include <vector>

using namespace std;

struct JuEventSourcePriv {
	vector<JuEventListener *> m_listeners;
};

JuEventSource::JuEventSource() : m_priv(new JuEventSourcePriv()) {

}

JuEventSource::~JuEventSource() {
	delete m_priv;
}

void JuEventSource::addListener(JuEventListener *listener) {
	m_priv->m_listeners.push_back(listener);
}

void JuEventSource::dispatchEvent(JuEvent *event) {
	for (int i = 0; i < m_priv->m_listeners.size(); i++) {
		m_priv->m_listeners.at(i)->onEvent(event);
	}
}
