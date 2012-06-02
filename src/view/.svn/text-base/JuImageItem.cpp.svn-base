#include "JuImageItem.h"

#include <JuPainter.h>
#include <JuDebug.h>
#include <string>
using namespace std;

struct JuImageItemPriv {
	string file;
};

JuImageItem::JuImageItem(int x, int y, int w, int h, const char *file, JuView *view) : JuItem(x, y, w, h, view) {
	m_priv = new JuImageItemPriv();
	m_priv->file = file;
}

JuImageItem::~JuImageItem() {
	delete m_priv;
}

void JuImageItem::paintEvent(JuPaintEvent *event, JuPainter *painter) {
	JUDEBUG("%s", m_priv->file.c_str());
	painter->drawImage(m_priv->file.c_str(), 0, 0, m_rect.width(), m_rect.height());
}
