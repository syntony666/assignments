#include "../src/student.h"

TEST(NameTest, constructor)
{
	Student *g001 = new Grad("G2018CSIE001", "Mike");
	Student *s001 = new Undergrad("U2018EECS001", "John");
	ASSERT_EQ("Mike", g001->name());
	ASSERT_EQ("G2018CSIE001", g001->id());
	ASSERT_EQ("John", s001->name());
	ASSERT_EQ("U2018EECS001", s001->id());
}

class CourseTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		c01 = new Course("2019s01", "OOP");
		c02 = new Course("2019s02", "LA");

		s01 = new Undergrad("U2018EECS001", "EEE"); //4
		s02 = new Undergrad("U2018EECS002", "BBB"); //1
		s03 = new Undergrad("U2018EECS003", "III"); //8
		s04 = new Grad("U2018EECS004", "DDD");		//3
		s05 = new Undergrad("U2018EECS005", "AAA"); //0
		s06 = new Grad("U2018EECS006", "FFF");		//5
		s07 = new Undergrad("U2018EECS007", "CCC"); //2
		s08 = new Undergrad("U2018EECS008", "GGG"); //6
		s09 = new Grad("U2018EECS009", "JJJ");		//9
		s10 = new Undergrad("U2018EECS010", "HHH"); //7
	}
	void TearDown()
	{
		delete s01;
		delete s02;
		delete s03;
		delete s04;
		delete s05;
		delete s06;
		delete s07;
		delete s08;
		delete s09;
		delete s10;
		delete c01;
		delete c02;
	}

	Course *c01;
	Course *c02;

	Student *s01;
	Student *s02;
	Student *s03;
	Student *s04;
	Student *s05;
	Student *s06;
	Student *s07;
	Student *s08;
	Student *s09;
	Student *s10;
};

TEST_F(CourseTest, constructor)
{
	ASSERT_EQ("OOP", c01->name());
	ASSERT_EQ("2019s01", c01->id());
}

TEST_F(CourseTest, addOneStudent)
{
	(*c01).add(s01);
	auto students = c01->getStudentsByNameInc();
	ASSERT_EQ("U2018EECS001", students[0]->id());
	ASSERT_EQ("EEE", students[0]->name());
	ASSERT_EQ(1, c01->size());
}

TEST_F(CourseTest, addManyStudent)
{
	Student *s[] = {s01, s02, s03, s04};
	c01->add(s, s + 4);
	auto students = c01->getStudentsByNameInc();
	ASSERT_EQ("OOP", c01->name());
	ASSERT_EQ("2019s01", c01->id());
	ASSERT_EQ(4, c01->size());
	ASSERT_EQ("BBB", students[0]->name());
	ASSERT_EQ("DDD", students[1]->name());
	ASSERT_EQ("EEE", students[2]->name());
	ASSERT_EQ("III", students[3]->name());
}

TEST_F(CourseTest, setScore)
{
	Student *s[] = {s01, s02, s03, s04, s05, s06};
	c02->add(s, s + 6);
	vector<string> id = {"U2018EECS001", "U2018EECS005", "U2018EECS006", "U2018EECS004"};
	vector<int> score = {95, 60, 30, 50};
	c02->setScores(id, score);
	auto students = c02->getStudentsByNameInc();
	ASSERT_EQ(95, students[3]->getScore("LA"));
	ASSERT_EQ(60, students[0]->getScore("LA"));
	ASSERT_EQ(30, students[4]->getScore("LA"));
	ASSERT_EQ(50, students[2]->getScore("LA"));
}
TEST_F(CourseTest, setScoreException)
{
	Student *s[] = {s01, s02, s03, s04, s05, s06};
	c02->add(s, s + 6);
	vector<string> id = {"U2018EECS001", "U2018EECS005", "U2018EECS006", "U2018EECS004"};
	vector<int> score = {95, 60, 30, 50, 90};
	ASSERT_ANY_THROW(c02->setScores(id, score));
}

TEST_F(CourseTest, FailedStudent)
{
	Student *s[] = {s01, s02, s03, s04};
	c02->add(s, s + 4);
	vector<string> id = {"U2018EECS001", "U2018EECS002", "U2018EECS003", "U2018EECS004"};
	vector<int> score = {95, 60, 30, 65};
	c02->setScores(id, score);
	auto students = c02->failedStudents();
	ASSERT_EQ(2, students.size());
}