#ifndef _JU_GUI_APP_H_
#define _JU_GUI_APP_H_

#include "JuApp.h"

class JuGuiAppPriv;
class JuView;

class JuGuiApp : public JuApp {
public:
	JuGuiApp(int argc, char **argv);
	virtual ~JuGuiApp();

	void addView(JuView *m_view);

protected:
	virtual void onEvent(JuEvent *event);

private:
	JuGuiAppPriv *m_priv;
};

#endif
