#include <gtest/gtest.h>
#include <string>
using namespace std;
TEST(String, Length)
{
	string a = "Hello, world!!";
	ASSERT_EQ(14, a.length());
}

TEST(String, Empty)
{
	string a = "Hello, world!!";
	string b = "";
	ASSERT_EQ(0, a.empty());
	ASSERT_EQ(1, b.empty());
}

TEST(String, Clear)
{
	string a = "Hello, world!!";
	a.clear();
	ASSERT_EQ("", a);
}

TEST(String, Insert)
{
	string a = "to be question";
	string b = "the ";
	string c = "or not to be";
	string::iterator it;
	a = a.insert(6, b);
	ASSERT_EQ("to be the question", a);
	a = a.insert(6, c, 3, 4);
	ASSERT_EQ("to be not the question", a);
	a = a.insert(10, "that is cool", 8);
	ASSERT_EQ("to be not that is the question", a);
	a = a.insert(10, "to be ");
	a = a.insert(15, 1, ':');
	it = a.insert(a.begin() + 5, ',');
	ASSERT_EQ("to be, not to be: that is the question", a);
	a.insert(a.end(), 3, '.');
	a.insert(it + 2, c.begin(), c.begin() + 3);
	ASSERT_EQ("to be, or not to be: that is the question...", a);
	ASSERT_ANY_THROW(a.insert(10000, c));
}

TEST(String, Copy)
{
	char buffer[20];
	string str("Test string...");
	size_t length = str.copy(buffer, 6, 5);
	buffer[length] = '\0';
	string b(buffer);
	ASSERT_EQ("string", b);
}

TEST(String, Compare)
{
	string a = "Hello, world!!";
	string b = "Hello";
	ASSERT_LT(0, a.compare(b));
	ASSERT_GT(0, b.compare(a));
	ASSERT_EQ(0, a.compare(a));
}

TEST(String, Swap)
{
	string a = "Hello";
	string b = "World";
	swap(a, b);
	ASSERT_EQ("Hello", b);
	ASSERT_EQ("World", a);
}

TEST(String, Find_1)
{
	string a = "First, you are learning features of a new language, in this case, C++. Being a superset of the C language, C++ adds many new features for representing objects, exceptions, name spaces and templates, etc.";
	ASSERT_EQ(55, a.find("this"));
}

TEST(String, Find_2)
{
	string a = "First, you are learning features of a new language, in this case, C++. Being a superset of the C language, C++ adds many new features for representing objects, exceptions, name spaces and templates, etc.";
	ASSERT_EQ(-1, a.find("go"));
}