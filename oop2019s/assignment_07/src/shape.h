#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

class Shape
{
  private:
  public:
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
};

template <class RandomAccessIterator, class Condition>
std::vector<Shape *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond)
{
	std::vector<Shape *> vec;
	for (RandomAccessIterator i = begin; i < end; i++)
		if (cond(*i))
			vec.push_back(*i);
	return vec;
}

#endif
