class SvgPolygon : public SvgShape
{
public:
	SvgPolygon(std::vector<double *> const &v) : SvgShape(), _v(v)
	{
		setSvgShapeStyle(this, 0, "black", "black");
	}
	std::string toSVG() const
	{
		std::string temp = "<polygon points=\"";
		for (auto i = _v.begin(); i < _v.end() - 1; i++)
		{
			temp += std::to_string((*i)[0]) + " " + std::to_string((*i)[1]) + " ";
		}
		temp += std::to_string((_v[_v.size() - 1])[0]) + " " + std::to_string((_v[_v.size() - 1])[1]) + "\" stroke-width=\"" + std::to_string(strokeWidth()) + "\" stroke=\"" + strokeColor() + "\" fill=\"" + fillColor() + "\"/>";
		return temp;
	}

private:
	std::vector<double *> _v;
};
