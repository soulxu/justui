#ifndef _JU_BUTTON_ITEM_H_
#define _JU_BUTTON_ITEM_H_

#include <JuItem.h>

class JuButtonItem : public JuItem {
public:
	JuButtonItem(int x, int y, int w, int h);
	void setText(const char *text);
	void setTextColor(const JuColor &color);
	void setBgColor(const JuColor &color);
	void setActiveColor(const JuColor &color);
	void setBgImg(const char *img);
	void setActiveImg(const char *img);

	virtual void paintEvent(JuPaintEvent *event, JuPainter *painter);

private:
	char *m_text;
	char *m_bgImg;
	char *m_actImg;
	JuColor m_textColor;
	JuColor m_bgColor;
	JuColor m_actColor;
	int m_pressed;
};
#endif
