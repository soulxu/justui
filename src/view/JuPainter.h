#ifndef _JU_PAINTER_H_
#define _JU_PAINTER_H_

class JuView;
class JuPainterPriv;
class JuColor;

class JuPainter {
public:
	enum Align {
		JuCenter,
		JuLeft,
		JuRight
	};

	JuPainter(JuView *view);
	JuPainter(JuPainterPriv *priv);
	virtual ~JuPainter();

	virtual void sync() = 0;
	virtual void setTextSize(int s) = 0;
	virtual void setColor(const JuColor &color) = 0;
	virtual void setColor(int a, int r, int g, int b) = 0;
	virtual void drawRect(int x, int y, int w, int h) = 0;
	virtual void drawImage(const char *file, int x, int y) = 0;
	virtual void drawImage(const char *file, int x, int y, int w, int h) = 0;
	virtual void drawText(int x, int y, const char *text) = 0;
	virtual void drawText(int x, int y, int w, int h, const char *text, Align align) = 0;
	virtual void drawPoint(int x, int y) = 0;
	virtual void drawLine(int x0, int y0, int x1, int y1) = 0;

	void save();
	void restore();
	void translate(int x, int y);

protected:
	virtual void syncContext() = 0;

protected:
	JuPainterPriv *m_priv;
};

#endif
