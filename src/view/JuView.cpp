#include "JuView.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <linux/fb.h>
#include <sys/mman.h>

#include <vector>
#include <map>
#include <string>
using namespace std;

#include <JuPainter.h>
#include <JuItem.h>
#include <JuEvent.h>
#include <JuKeyEvent.h>
#include <JuPaintEvent.h>
#include <JuRect.h>
#include <JuColor.h>

#include <JuDebug.h>

JuView::JuView() : m_priv(new JuViewPriv()) {
}

JuView::JuView(JuViewPriv *priv) : m_priv(priv) {

}

JuView::~JuView() {
	delete m_priv;
}

void JuView::processEvent(JuEvent *event) {
	JUDEBUG("");

	switch (event->type()) {
	case JuEvent::PaintEvent:
		for (int i = 0; i < m_priv->items.size(); i++) {
			JUDEBUG("PaintEvent");
			JuItem *item = m_priv->items.at(i);
			JuRect r = item->boundingRect();
			painter()->translate(r.x(), r.y());
			item->paintEvent((JuPaintEvent *)event, painter());
		}

		break;
	case JuEvent::KeyPressEvent:
		for (int i = 0; i < m_priv->items.size(); i++) {
			m_priv->items.at(i)->keyPressEvent((JuKeyEvent *)event);
		}
		break;
	case JuEvent::TimerEvent:
		for (int i = 0; i < m_priv->items.size(); i++) {
					m_priv->items.at(i)->timerEvent((JuTimerEvent *)event);
		}
		break;
	}
}

JuColor JuView::bgColor() const {
	return m_priv->bgColor;
}

void JuView::setBgColor(const JuColor &color) {
	m_priv->bgColor = color;
}

void JuView::addItem(JuItem *item) {
	m_priv->items.push_back(item);
}

void JuView::update() {
	JuPaintEvent evt;
	processEvent(&evt);
	sync();
}

JuView::PixelType JuView::colorType() const {
	return m_priv->colorType;
}
