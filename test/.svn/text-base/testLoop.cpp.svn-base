#include "JuLoop.h"
#include "JuTimerSource.h"

int main(int argc, char **argv) {
	JuLoop l;
	JuTimerSource src(1000000);
	l.addSource(&src);
	return l.exec();
}
