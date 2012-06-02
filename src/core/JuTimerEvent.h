#ifndef _JU_TIMER_EVENT_H_
#define _JU_TIMER_EVENT_H_

#include "JuEvent.h"

class JuTimerEvent : public JuEvent {
public:
	JuTimerEvent(int timerId);
	virtual ~JuTimerEvent() { };
	int timerId() const;

private:
	int m_timerId;
};

#endif
