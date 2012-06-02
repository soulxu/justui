#include <JuGuiApp.h>
#include <JuView.h>
#include <JuRectItem.h>
#include <JuTimer.h>
#include <JuImageItem.h>

int main(int argc, char **argv) {
	JuGuiApp app(argc, argv);
	//JuTimer timer;
	JuView v;
	v.setBgColor(0, 255, 255, 255);
	JuImageItem i1(10, 10, 279, 204, "tv.png", &v);
	JuImageItem i2(10, 150, 128, 128, "local.png", &v);
	JuImageItem i3(10, 250, 128, 128, "musics.png", &v);
	//app.addView(&v);
	//JuRectItem r(100, 100, 800, 600, &v);
	//v.addItem(&r);
	v.addItem(&i1);
	v.addItem(&i2);
	v.addItem(&i3);
	//timer.start(5000);
	v.update();
	return app.exec();
}
