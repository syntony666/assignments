#ifndef STUDENT_H
#define STUDENT_H

#include <map>

using namespace std;

class Student
{
public:
	Student(string id, string name) : _id(id), _name(name)
	{
		_student[id] = name;
	}
	string id() const { return _id; }

	string name() const { return _name; }

	void setScore(string courseName, int score)
	{
		_score[courseName] = score;
	}

	int getScore(string courseName) const
	{
		return _score.at(courseName);
	}

	virtual bool isFail(string course) = 0;

private:
	string _name;
	string _id;
	map<string, int> _score;
	map<string, string> _student;
};

class Undergrad : public Student
{
public:
	Undergrad(string id, string name) : Student(id, name) {}

	bool isFail(string course) { return getScore(course) < 60; }
};

class Grad : public Student
{
public:
	Grad(string id, string name) : Student(id, name) {}

	bool isFail(string course) { return getScore(course) < 70; }
};

class Course
{
public:
	Course(string id, string name) : _id(id), _name(name) {}

	string id() const { return _id; }

	string name() const { return _name; }

	int size() const
	{
		return _student.size();
	}

	void add(Student *s)
	{
		_student[(*s).name()] = s;
		_studentID[(*s).id()] = s;
		(*s).setScore(_name, -1);
	}

	void add(Student **begin, Student **end)
	{
		for (auto i = begin; i != end; i++)
		{
			_student[(**i).name()] = *i;
			_studentID[(**i).id()] = *i;
			(*i)->setScore(_name, -1);
		}
	}

	vector<Student *> getStudentsByNameInc()
	{
		vector<Student *> names;
		for (auto i = _student.begin(); i != _student.end(); i++)
			names.push_back(i->second);
		return names;
	}

	void setScores(vector<string> ids, vector<int> scores)
	{
		if (ids.size() != scores.size())
			throw string("Error");
		for (auto i = 0; i <= ids.size() - 1; i++)
		{
			_studentID.find(ids[i])->second->setScore(_name, scores[i]);
		}
	}

	vector<Student *> failedStudents()
	{
		vector<Student *> names;
		for (auto i = _student.begin(); i != _student.end(); i++)
			if (i->second->isFail(_name))
				names.push_back(i->second);
		return names;
	}

private:
	string _id;
	string _name;
	map<string, Student *> _student;
	map<string, Student *> _studentID;
};

#endif
