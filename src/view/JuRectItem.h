#ifndef _JU_RECT_ITEM_H_
#define _JU_RECT_ITEM_H_

#include <JuItem.h>
#include <JuColor.h>

class JuView;

class JuRectItem : public JuItem {
public:
	JuRectItem(int x, int y, int w, int h, const JuColor &color, JuView *view);
	virtual void paintEvent(JuPaintEvent *event, JuPainter *painter);

private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int m_offset;
	JuColor m_color;
};

#endif
