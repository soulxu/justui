#ifndef _JU_ITEM_H_
#define _JU_ITEM_H_

#include "JuRect.h"

class JuKeyEvent;
class JuPaintEvent;
class JuTimerEvent;
class JuPainter;
class JuEvent;
class JuView;

class JuItem {
public:
	JuItem(int x, int y, int w, int h, JuView *view);
	virtual ~JuItem();

	JuRect boundingRect() const;
	void setFocus(bool focus);
	bool isFocus() const;

	void update();

	virtual void keyPressEvent(JuKeyEvent *event);
	virtual void paintEvent(JuPaintEvent *event, JuPainter *painter);
	virtual void timerEvent(JuTimerEvent *event);

protected:
	JuView *m_view;
	JuRect m_rect;
	bool m_isFocus;
};

#endif
