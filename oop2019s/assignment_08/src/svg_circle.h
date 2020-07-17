#include <fstream>
#include "svg_shape.h"
class SvgCircle : public SvgShape
{
  public:
	SvgCircle(double x, double y, double r) : SvgShape(), _x(x), _y(y), _r(r)
	{
		setSvgShapeStyle(this, 0, "black", "black");
	}
	std::string toSVG() const
	{
		return "<circle cx=\"" + std::to_string(_x) + "\" cy=\"" + std::to_string(_y) + "\" r=\"" + std::to_string(_r) + "\" stroke-width=\"" + std::to_string(strokeWidth()) + "\" stroke=\"" + strokeColor() + "\" fill=\"" + fillColor() + "\"/>";
	}

  private:
	double _x, _y, _r;
};
