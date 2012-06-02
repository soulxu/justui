#ifndef _JU_PRIMARY_SOURCE_H_
#define _JU_PRIMARY_SOURCE_H_

#include <JuEventSource.h>

class JuPrimarySourcePriv;
class JuEvent;

class JuPrimarySource : public JuEventSource {
public:
	JuPrimarySource();
	virtual ~JuPrimarySource();

	bool init();

	void postEvent(JuEvent *event);

	virtual int check();
	virtual void dispatch();
	virtual int getFd() const;

private:
	JuPrimarySourcePriv *m_priv;
};

#endif
