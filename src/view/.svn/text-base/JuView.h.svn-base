#ifndef _JU_VIEW_H_
#define _JU_VIEW_H_

class JuViewPriv;
class JuEvent;
class JuItem;
class JuColor;
class JuPainter;

class JuView {
public:
	enum PixelType {
			Unknown = -1,
			RGB16 = 0,
			ARGB32
	};

	JuView();
	JuView(JuViewPriv *);
	virtual ~JuView();

	virtual bool init() = 0;

	virtual int width() const = 0;
	virtual int height() const = 0;
	virtual void sync() = 0;
	virtual int bitsPerPixel() const = 0;
	virtual char *base() const = 0;
	virtual JuPainter *painter() const = 0;

	virtual PixelType colorType() const;
	JuColor bgColor() const;
	void setBgColor(const JuColor &color);
	void addItem(JuItem *item);
	void processEvent(JuEvent *event);
	void update();

protected:
	JuViewPriv *m_priv;
};

#endif
