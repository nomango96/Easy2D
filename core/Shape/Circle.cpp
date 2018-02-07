#include "..\eshape.h"
#include "..\enodes.h"

e2d::Circle::Circle()
	: m_pD2dCircle(nullptr)
{
}

e2d::Circle::Circle(Point center, float radius)
	: m_pD2dCircle(nullptr)
{
	this->_setCircle(center, radius);
}

e2d::Circle::Circle(Node * node)
	: m_pD2dCircle(nullptr)
{
	float minSide = min(node->getRealWidth(), node->getRealHeight());
	this->_setCircle(
		Point(
			node->getRealWidth() / 2,
			node->getRealHeight() / 2
		),
		minSide / 2
	);
}

e2d::Circle::~Circle()
{
	SafeReleaseInterface(&m_pD2dCircle);
}

void e2d::Circle::_setCircle(Point center, float radius)
{
	SafeReleaseInterface(&m_pD2dCircle);

	Renderer::getID2D1Factory()->CreateEllipseGeometry(
		D2D1::Ellipse(
			D2D1::Point2F(
				center.x, 
				center.y),
			radius,
			radius),
			&m_pD2dCircle
		);
}

ID2D1EllipseGeometry * e2d::Circle::_getD2dGeometry() const
{
	return m_pD2dCircle;
}
