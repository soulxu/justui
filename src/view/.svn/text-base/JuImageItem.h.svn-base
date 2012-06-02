#ifndef _JU_IMAGE_ITEM_H_
#define _JU_IMAGE_ITEM_H_

#include <JuItem.h>

class JuPaintEvent;
class JuPainter;
class JuView;
class JuImageItemPriv;

class JuImageItem : public JuItem {
public:
	JuImageItem(int x, int y, int w, int h, const char *file, JuView *view);
	virtual ~JuImageItem();

protected:
	virtual void paintEvent(JuPaintEvent *event, JuPainter *painter);

private:
	JuImageItemPriv *m_priv;
};

#endif
