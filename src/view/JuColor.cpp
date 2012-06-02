#include <JuColor.h>

JuColor::JuColor() :
	m_a(0),
	m_r(0),
	m_g(0),
	m_b(0)
{

}
JuColor::JuColor(int a, int r, int g, int b) :
	m_a(a),
	m_r(r),
	m_g(g),
	m_b(b)
{

}
int JuColor::alpha() const {
	return m_a;
}

int JuColor::red() const {
	return m_r;
}

int JuColor::green() const {
	return m_g;
}

int JuColor::blue() const {
	return m_b;
}
