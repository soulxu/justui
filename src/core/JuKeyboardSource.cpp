#include "JuKeyboardSource.h"

#include <string>

using namespace std;
struct JuKeyboardSourcePriv {
	string dev;
	int fd;

};

JuKeyboardSource(const char *dev);
virtual ~JuKeyboardSource();
virtual int check() = 0;
virtual void dispatch() = 0;
virtual int getFd() const = 0;
