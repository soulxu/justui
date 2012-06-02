#ifndef _JU_APP_H_
#define _JU_APP_H_

#include "JuEventListener.h"

class JuAppPriv;

class JuApp : public JuEventListener {
public:
	JuApp(int argc, char **argv);
	virtual ~JuApp();

	int exec();
	void exit(int exitcode);

	static JuApp *getApp();

	void postEvent(JuEvent *event);
	void addEventListener(JuEventListener *listener);

protected:
	virtual void onEvent(JuEvent *event);

private:
	void parseArgs(int argc, char **argv);

private:
	JuAppPriv *m_priv;
	static JuApp *gApp;
};
#endif
