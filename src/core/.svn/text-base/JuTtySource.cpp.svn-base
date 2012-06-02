#include "JuTtySource.h"

#include "JuKeyEvent.h"
#include "JuDebug.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <linux/kd.h>
#include <sys/ioctl.h>

#include <string>
using namespace std;

struct JuTtySourcePriv {
	string dev;
	int fd;
	struct termios oldTermios;
	struct termios newTermios;
	int kbdMode;
};

JuTtySource::JuTtySource(const char *dev) : m_priv(new JuTtySourcePriv()){
	m_priv->dev = dev;
	m_priv->fd = -1;
}

JuTtySource::~JuTtySource() {
	tcsetattr(m_priv->fd, TCSANOW, &(m_priv->oldTermios));
	ioctl(m_priv->fd, KDSKBMODE, m_priv->kbdMode);
	closeDevice();
	delete m_priv;
}

bool JuTtySource::initDevice() {
	if (m_priv->fd >= 0) {
		JUDEBUG("Device has already initialized.");
		return false;
	}

	JUDEBUG("open device : %s", m_priv->dev.c_str());
	if (m_priv->dev == "") {
		m_priv->fd = 0;
	}
	else {
		m_priv->fd = open(m_priv->dev.c_str(), O_RDONLY);
	}

	if (m_priv->fd < 0) {
		JUDEBUG("Can not open tty device %s", m_priv->dev.c_str());
		return false;
	}

	if (tcgetattr(m_priv->fd, &(m_priv->oldTermios)) < 0) {
		JUDEBUG("Can not get tty attr");
		close(m_priv->fd);
		return false;
	}

	if (tcgetattr(m_priv->fd, &(m_priv->newTermios)) < 0) {
		close(m_priv->fd);
		return false;
	}

	m_priv->newTermios.c_lflag &= ~(ICANON | ECHO);
	//ICANON 常规模式，行输入。非常规模式，输入即返回
	//ECHO 是否回显
	//ISIG 是否启用控制字符, ctrl+c之类的
	//m_priv->newTermios.c_lflag &= ~(ICANON | ECHO | ISIG);
	//VTIME read返回时间 0=无限期阻塞
	//VMIN read读到多少字节后返回
	m_priv->newTermios.c_cc[VTIME] = 0;
	m_priv->newTermios.c_cc[VMIN] = 1;

	ioctl(m_priv->fd, KDGKBMODE, &m_priv->kbdMode);
	//ioctl(m_priv->fd, KDSKBMODE, K_RAW);
	tcsetattr(m_priv->fd, TCSANOW, &(m_priv->newTermios));
	return true;
}

void JuTtySource::closeDevice() {
	close(m_priv->fd);
}

int JuTtySource::getFd() const {
	return m_priv->fd;
}

int JuTtySource::check() {
	return -1;
}

void JuTtySource::dispatch() {
	char buffer[32];
	int n = 0;
	//JUDEBUG("");
	if (m_priv->fd < 0) {
		return;
	}

	while (1) {
		n = read(m_priv->fd, buffer + n, 32 - n);
		//JUDEBUG("read %d", n);
		if (n == 0) {
			JUDEBUG("Recevie An EOF");
			return;
		}
		else if (n < 0 && (errno != EINTR && errno != EAGAIN)) {
			return;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < n; ++i) {
		JuKeyEvent evt(buffer[i]);
		dispatchEvent((JuEvent *)&evt);
	}
}
