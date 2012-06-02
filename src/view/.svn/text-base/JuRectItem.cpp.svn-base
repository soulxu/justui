#include "JuRectItem.h"

#include "JuPainter.h"
#include <JuDebug.h>
JuRectItem::JuRectItem(int x, int y, int w, int h, const JuColor &color, JuView *view) :
	JuItem(x, y, w, h, view),
	m_color(color)
{
	m_offset = 0;
}

void JuRectItem::paintEvent(JuPaintEvent *event, JuPainter *painter) {
	JUDEBUG("");
	painter->setColor(m_color);
	painter->drawRect(m_rect.x(), m_rect.y(), m_rect.width(), m_rect.height());
}
