#ifndef _JU_KEYBOARD_SOURCE_H_
#define _JU_KEYBOARD_SOURCE_H_

#include "JuEventSource.h"

class JuKeyboardSourcePriv;

class JuKeyboardSource : public JuEventSource {
public:
	JuKeyboardSource(const char *dev);
	virtual ~JuKeyboardSource();
	virtual int check() = 0;
	virtual void dispatch() = 0;
	virtual int getFd() const = 0;

private:
	JuKeyboardSourcePriv *m_priv;
};
#endif

