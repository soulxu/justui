#include <JuApp.h>
#include <JuEvent.h>
#include <JuKeyEvent.h>
#include <JuDebug.h>

class App : public JuApp {
public:
	App(int argc, char **argv) : JuApp(argc, argv) {

	}
	virtual void onEvent(JuEvent *event) {

		if (event->type() == JuEvent::KeyPressEvent) {
			JuKeyEvent *e = (JuKeyEvent *)event;
			JUDEBUG("onEvent::KeyPressEvent : %d", e->keyCode());
		}
	}
};

int main(int argc, char **argv) {
	App a(argc, argv);

	return a.exec();
}
