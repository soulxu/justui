#include <JuButtonItem.h>

#include <string.h>

JuButtonItem::JuButtonItem(int x, int y, int w, int h) :
	JuItem(x, y, w, h),
	m_text(NULL),
	m_bgImg(NULL),
	m_actImg(NULL)
{

}
void JuButtonItem::setText(const char *text) {
	if (text == NULL)
		return;
	strdup(m_text, text, strlen(text));
}

void JuButtonItem::setTextColor(const JuColor &color) {
	m_textColor = color;
}

void JuButtonItem::setBgColor(const JuColor &color) {
	m_bgColor = color;
}

void JuButtonItem::setActiveColor(const JuColor &color) {
	m_actColor = color;
}

void JuButtonItem::setBgImg(const char *img) {
	if (img == NULL)
		return;
	strdup(m_bgImg, img, strlen(img));
}

void JuButtonItem::setActiveImg(const char *img) {
	if (img == NULL)
		return;
	strdup(m_actImg, img, strlen(img));
}

void JuButtonItem::paintEvent(JuPaintEvent *event, JuPainter *painter) {
	if (isFocus()) {
		painter->setColor(m_actColor);
		if (m_bgImg != NULL)
			painter->drawImage(m_bgImg);
		else
			painter->drawRect(m_rect.x(), m_rect.y(), m_rect.width(), m_rect.height());
	}
	else {
		painter->setColor(m_color);
		if (m_bgImg != NULL)
			painter->drawImage(m_bgImg);
		else
			painter->drawRect(m_rect.x(), m_rect.y(), m_rect.width(), m_rect.height());
	}


}
