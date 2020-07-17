#ifndef SVG_SHAPE_H
#define SVG_SHAPE_H

class SvgShape
{
public:
	SvgShape() {}
	void setFillColor(std::string fillColor)
	{
		_fillColor = fillColor;
	}
	void setStroke(double strokeWidth, std::string strokeColor)
	{
		_strokeColor = strokeColor;
		_strokeWidth = strokeWidth;
	}
	virtual std::string toSVG() const = 0;

protected:
	double strokeWidth() const
	{
		return _strokeWidth;
	}

	std::string strokeColor() const
	{
		return _strokeColor;
	}

	std::string fillColor() const
	{
		return _fillColor;
	}

private:
	double _strokeWidth;
	std::string _strokeColor, _fillColor;
};

void setSvgShapeStyle(SvgShape *shape, double strokeWidth, std::string strokeColor, std::string fillColor)
{
	shape->setStroke(strokeWidth, strokeColor);
	shape->setFillColor(fillColor);
}

std::string makeSvgOutput(int width, int height, std::vector<SvgShape *> const &shape)
{
	std::string temp = "";
	temp += "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height) + "\" viewBox=\"0 0 100 100\">";
	for (auto i = shape.begin(); i < shape.end(); i++)
	{
		temp += (*i)->toSVG();
	}
	temp += "</svg>";
	return temp;
}

#endif