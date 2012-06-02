#include <JuApp.h>
#include <JuTimer.h>
#include <JuEventListener.h>
#include <JuEvent.h>
#include <JuCustomEvent.h>
#include <JuDebug.h>

class Sender : public JuEventListener {
public:
	void onEvent(JuEvent *event) {
		if (event->type() != JuEvent::CustomEvent) {
			JUDEBUG("post a custom event.");
			JuCustomEvent e;
			JuApp::getApp()->postEvent(&e);
		}
		else {
			JUDEBUG("Recive a custom event.");
		}
	}
};
int main(int argc, char **argv) {
	JuApp app(argc, argv);
	Sender s;
	app.addEventListener(&s);
	//JuTimer t;
	//t.start(1000000);
	//JuTimer t2;
	//t2.start(500000);
	return app.exec();
}
