#include <fstream>
#include "svg_shape.h"
class SvgLine : public SvgShape
{
public:
	SvgLine(double x1, double y1, double x2, double y2) : SvgShape(), _x1(x1), _y1(y1), _x2(x2), _y2(y2)
	{
		setSvgShapeStyle(this, 0, "black", "black");
	}
	std::string toSVG() const
	{
		return "<line x1=\"" + std::to_string(_x1) + "\" y1=\"" + std::to_string(_y1) + "\" x2=\"" + std::to_string(_x2) + "\" y2=\"" + std::to_string(_y2) + "\" stroke-width=\"" + std::to_string(strokeWidth()) + "\" stroke=\"" + strokeColor() + "\" fill=\"" + fillColor() + "\"/>";
	}

private:
	double _x1, _y1, _x2, _y2;
};
