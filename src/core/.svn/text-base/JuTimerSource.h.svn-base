#ifndef _JU_TIMER_SOURCE_H_
#define _JU_TIMER_SOURCE_H_

#include "JuEventSource.h"
#include <sys/time.h>

class JuTimerSource : public JuEventSource {
public:
	JuTimerSource(int interval);
	virtual ~JuTimerSource();
	virtual int check();
	virtual void dispatch();
	virtual int getFd() const;

private:
	int m_interval;
	struct timeval m_timeval;
};

#endif
