#pragma once
#include "helper.h"
#include "Marray.h"
using namespace std;

class Student
{
private:
	string secondName, iniciales;
	Marray<int> marks;
public:
	Student();
	Student(string secondName, string iniciales, Marray<int> marks);
	Student(const Student& student);
	~Student();

	void inputFromConsole(int countMarks);
	void inputFromFile(ifstream& file);
	void printToConsole();
	void printToFile(ofstream& file);
	void change(int countMarks);

	string getSecondName() { return secondName; }
	void setSecondName(string secondName) { this->secondName = secondName; }

	string getIniciales() { return iniciales; }
	void setIniciales(string iniciales) { this->iniciales = iniciales; }

	Marray<int> getMarks() { return marks; }
	int geCountMarks() { return marks.getSize(); }
	void setMarks(Marray<int>& marks) { this->marks = marks; }

	double getAverageMark();

	Student& operator=(const Student& student);
};

