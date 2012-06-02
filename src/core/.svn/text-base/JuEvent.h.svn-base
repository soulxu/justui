#ifndef _JU_EVENT_H_
#define _JU_EVENT_H_

#include <linux/limits.h>

#define JU_EVENT_MAX_SIZE PIPE_BUF

class JuEvent {
private:
	int m_size;
	int m_type;
	bool m_isAccepted;

public:
	enum EventType {
			Unknown = -1,
			TimerEvent = 0,
			KeyPressEvent,
			PaintEvent,
			CustomEvent
	};

	JuEvent(int type);
	virtual ~JuEvent() { }

	int type() const;
	bool isAccepted() const;
	void accept();
	void ignore();

	int size() const;
};

#endif
