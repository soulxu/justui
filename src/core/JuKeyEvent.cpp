#include "JuKeyEvent.h"

JuKeyEvent::JuKeyEvent(int keyCode) : JuEvent(JuEvent::KeyPressEvent), m_keyCode(keyCode) {

}

int JuKeyEvent::keyCode() const {
	return m_keyCode;
}
