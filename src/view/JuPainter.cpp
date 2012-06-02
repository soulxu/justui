#include "JuPainter.h"

#include <JuView.h>
#include <JuPainter_p.h>

#include <vector>
using namespace std;

JuPainterPriv::JuPainterPriv(JuView *view) : view(view) {
	curContext.origX = 0;
	curContext.origY = 0;
}

JuPainterPriv::~JuPainterPriv() {

}

JuPainter::JuPainter(JuView *view) : m_priv(new JuPainterPriv(view)) {

}

JuPainter::JuPainter(JuPainterPriv *priv) : m_priv(priv) {

}

JuPainter::~JuPainter() {
	delete m_priv;
}

void JuPainter::translate(int x, int y) {
	m_priv->curContext.origX = x;
	m_priv->curContext.origY = y;
}

void JuPainter::save() {
	m_priv->contexts.push_back(m_priv->curContext);
}

void JuPainter::restore() {
	m_priv->curContext = m_priv->contexts.back();
	m_priv->contexts.pop_back();
	syncContext();
}
