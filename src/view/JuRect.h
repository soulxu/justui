#ifndef _JU_RECT_H_
#define _JU_RECT_H_

class JuRect {
public:
	JuRect(int x, int y, int w, int h);

	void setX(int x);
	void setY(int y);
	void setWidth(int w);
	void setHeight(int h);

	int x() const;
	int y() const;
	int width() const;
	int height() const;

private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
};

#endif
