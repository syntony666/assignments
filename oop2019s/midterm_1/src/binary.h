#include <cmath>
#include <sstream>
using namespace std;
class Binary
{
  public:
	Binary()
	{
		_bit = -1;
		_bin = new int[1];
		*_bin = {-1};
	}
	Binary(int input[], int s)
	{
		_bit = s;
		_bin = new int[s];
		for (int i = 0; i < s; i++)
		{
			if (input[i] != 1 && input[i] != 0)
				throw string("Not a binary bit!!");
			_bin[i] = input[i];
		}
	}
	Binary(const Binary &b)
	{
		_bit = b._bit;
		_bin = new int[b._bit];
		for (int i = 0; i < b._bit; i++)
		{
			_bin[i] = b._bin[i];
		}
	}
	~Binary()
	{
		delete[] _bin;
	}
	Binary &operator=(Binary const &b)
	{
		_bit = b._bit;
		_bin = new int[b._bit];
		for (int i = 0; i < b._bit; i++)
		{
			_bin[i] = b._bin[i];
		}
		return *this;
	}
	Binary operator+(Binary const &b)
	{
		Binary a(*this);
		a.add(b);
		return a;
	}
	Binary operator-(Binary const &b)
	{
		Binary a(*this);
		a.substract(b);
		return a;
	}
	Binary operator>>(int a)
	{
		checkEmpty();
		for (int i = _bit - 1; i >= 0; i--)
		{
			if (i - a < 0)
			{
				setBit(i, 0);
			}
			else
			{
				setBit(i, _bin[i - a]);
			}
		}
		return *this;
	}
	Binary operator<<(int a)
	{
		checkEmpty();
		for (int i = 0; i < _bit; i++)
		{
			if (i + a >= _bit)
			{
				setBit(i, 0);
			}
			else
			{
				setBit(i, _bin[i + a]);
			}
		}
		return *this;
	}
	void resize(int new_size)
	{
		checkEmpty();
		if (new_size < _bit)
			throw string("Too small to resize!!");
		int newbin[new_size];
		for (int i = 0; i < new_size - bit(); i++)
			newbin[i] = 0;
		for (int i = new_size - bit(); i < new_size; i++)
		{
			newbin[i] = _bin[i - new_size + bit()];
		}
		_bit = new_size;
		_bin = new int[new_size];
		for (int i = 0; i < new_size; i++)
		{
			setBit(i, newbin[i]);
		}
	}
	void setBit(int pos, int data)
	{
		checkEmpty();
		if (pos >= _bit || pos < 0)
			throw string("Position out of range!!");
		if (data != 1 && data != 0)
			throw string("Not a binary bit!!");
		_bin[pos] = data;
	}
	int toInt() const
	{
		if (_bit == -1)
			throw string("Empty Binary!!!");
		int temp = 0;
		for (int i = 0; i < _bit; i++)
			if (_bin[i] == 1)
				temp += pow(2, _bit - i - 1);
		return temp;
	}
	std::string toString() const
	{
		if (_bit == -1)
			throw string("Empty Binary!!!");
		stringstream ss;
		for (int i = 0; i < _bit; i++)
		{
			ss << _bin[i];
		}
		return ss.str();
	}
	int bit()
	{
		checkEmpty();
		return _bit;
	}
	int &element(int i)
	{
		checkEmpty();
		return _bin[i];
	}

	void add(Binary b)
	{
		checkEmpty();
		b.checkEmpty();
		int size = 0;
		if (bit() >= b.bit())
			size = bit();
		else
			size = b.bit();
		this->resize(size);
		b.resize(size);
		for (int i = 0; i < size; i++)
			_bin[i] += b.element(i);
		for (int i = size - 1; i > 0; i--)
		{
			if (_bin[i] == 2)
			{
				setBit(i, 0);
				_bin[i - 1] += 1;
			}
			if (_bin[i] == 3)
			{
				setBit(i, 1);
				_bin[i + 1] += 1;
			}
		}
		if (_bin[0] >= 2)
		{
			int temp = _bin[0];
			setBit(0, 0);
			resize(size + 1);
			if (temp == 2)
			{
				setBit(1, 0);
				setBit(0, 1);
			}
			if (temp == 3)
			{
				setBit(1, 1);
				setBit(0, 1);
			}
		}
	}

	void substract(Binary b)
	{
		if (bit() == -1 || b.bit() == -1)
			throw string("Empty Binary!!!");
		if (toInt() < b.toInt())
			throw string("The result is negative!!");
		int size = 0;
		if (bit() >= b.bit())
			size = bit();
		else
			size = b.bit();
		this->resize(size);
		b.resize(size);
		for (int i = 0; i < size; i++)
		{
			_bin[i] -= b.element(i);
		}
		for (int i = size - 1; i >= 0; i--)
		{
			if (_bin[i] == -1)
			{
				_bin[i] += 2;
				_bin[i - 1] -= 1;
			}
			if (_bin[i] == -2)
			{
				_bin[i] += 2;
				_bin[i - 1] -= 1;
			}
		}
	}

	void checkEmpty()
	{
		if (_bit == -1 && _bin[0] == -1)
		{
			throw string("Empty Binary!!!");
		}
	}

  private:
	int _bit;
	int *_bin;
};
