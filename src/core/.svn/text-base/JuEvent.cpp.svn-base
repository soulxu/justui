#include "JuEvent.h"

#include <assert.h>
#include <JuDebug.h>

JuEvent::JuEvent(int type) :
	m_type(type),
	m_isAccepted(false)
{
	m_size = sizeof(*this);
	assert(m_size < JU_EVENT_MAX_SIZE);
}
int JuEvent::type() const {
	return m_type;
}

bool JuEvent::isAccepted() const {
	return m_isAccepted;
}

void JuEvent::accept() {
	m_isAccepted = true;
}

void JuEvent::ignore() {
	m_isAccepted = false;
}

int JuEvent::size() const {
	return m_size;
}
