#ifndef _JU_TIMER_H_
#define _JU_TIMER_H_

#include "JuEventListener.h"

class JuTimerPriv;

class JuTimer {
public:
	JuTimer();
	virtual ~JuTimer();
	void start(int usec);
	void stop();
	int timerId();

private:
	JuTimerPriv *m_priv;
};

#endif
