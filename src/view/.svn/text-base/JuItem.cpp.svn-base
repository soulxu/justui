#include "JuItem.h"

#include "JuView.h"

JuItem::JuItem(int x, int y, int width, int height, JuView *view) :
	m_view(view),
	m_rect(JuRect(x, y, width, height)),
	m_isFocus(false)
{

}

JuItem::~JuItem() {

}

JuRect JuItem::boundingRect() const {
	return m_rect;
}

void JuItem::update() {
	m_view->update();
}

void JuItem::keyPressEvent(JuKeyEvent *event) {

}

void JuItem::paintEvent(JuPaintEvent *event, JuPainter *painter) {

}

void JuItem::timerEvent(JuTimerEvent *event) {

}

void JuItem::setFocus(bool focus) {
	m_isFocus = focus;
}

bool JuItem::isFocus() const {
	return m_isFocus;
}

