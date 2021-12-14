#pragma once
#include "Student.h"

class Group
{
private:
	int number;
	double avverageMark;
	Marray<Student> students;
	Marray<string> objects;
	void calculeteAverageMark();
public:
	Group();
	Group(int number, Marray<Student> students, Marray<string> objects);
	Group(const Group& group);
	~Group();

	void inputFromConsole();
	void inputFromFile(ifstream& file);
	void printToConsole();
	void printToFile(ofstream& file);
	void change();

	int getNumber() { return number; }
	void setNumber(int number) { this->number = number; }

	Marray<Student> getStudents() { return students; }
	void setStudents(Marray<Student>& students) { this->students = students; }

	Marray<string> getObjects() { return objects; }
	void setObjects(Marray<string>& objects) { this->objects = objects; }

	double getAverageMark() { return avverageMark; }

	Group& operator=(const Group& group);
	bool operator>(Group& group);
};

