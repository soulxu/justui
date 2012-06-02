#ifndef _JU_KEYBOARD_SOURCE_H_
#define _JU_KEYBOARD_SOURCE_H_

#include "JuEventSource.h"

class JuTtySourcePriv;

class JuTtySource : public JuEventSource {
public:
	JuTtySource(const char *dev);
	virtual ~JuTtySource();
	bool initDevice();
	void closeDevice();
	virtual int check();
	virtual void dispatch();
	virtual int getFd() const;

private:
	JuTtySourcePriv *m_priv;
};

#endif

