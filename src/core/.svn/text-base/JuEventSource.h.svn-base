#ifndef _JU_EVENT_SOURCE_H_
#define _JU_EVENT_SOURCE_H_

class JuEvent;
class JuEventListener;
class JuEventSourcePriv;

class JuEventSource {
public:
	JuEventSource();
	virtual ~JuEventSource();
	virtual int check() = 0;
	virtual void dispatch() = 0;
	virtual int getFd() const = 0;
	void addListener(JuEventListener *listener);

protected:
	void dispatchEvent(JuEvent *event);

private:
	JuEventSourcePriv *m_priv;
};

#endif
