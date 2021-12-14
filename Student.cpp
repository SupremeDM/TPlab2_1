#include "Student.h"

Student::Student() : secondName("�� ������"), iniciales("�� ������")
{
	cout << "������ ����������� Student" << endl;
}

Student::Student(string secondName, string iniciales, Marray<int> marks) : 
	secondName(secondName), iniciales(iniciales), marks(marks)
{
	cout << "������ ����������� Student" << endl;
}

Student::Student(const Student& student) : secondName(student.secondName), iniciales(student.iniciales), marks(student.marks)
{
	cout << "������ ����������� ����������� Student" << endl;
}

Student::~Student()
{
	cout << "������ ���������� Student" << endl;
}

void Student::inputFromConsole(int countMarks)
{
	cout << "������� �������: ";
	getline(cin, secondName);
	cout << "������� ��������(A.A.): ";
	iniciales = inputIniciales();
	for (int i = 0; i < countMarks; i++) {
		cout << "������� " << i + 1 << " ������: ";
		marks += safeInput(1, 5);
	}
}

void Student::inputFromFile(ifstream& file) {
	string err = "���� �� ����� ���� ��������� ��������";
	string tmpS;
	if (!getline(file, tmpS))
		throw err;
	secondName = tmpS;
	if (!getline(file, tmpS))
		throw err;
	iniciales = tmpS;
	if (!getline(file, tmpS))
		throw err;
	int countMarks = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	for (int i = 0; i < countMarks; i++) {
		if (!getline(file, tmpS))
			throw err;
		marks += (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	}	
}

void Student::printToConsole()
{
	cout << "���: " << secondName << " " << iniciales << endl;
	if (marks.getSize() > 0) {
		cout << "������: ";
		for (int i = 0; i < marks.getSize(); i++)
			cout << marks[i] << " ";
		cout << endl;
	}
	else
		cout << "������ ���" << endl;
}

void Student::printToFile(ofstream& file) {
	file << secondName << endl;
	file << iniciales << endl;
	file << marks.getSize() << endl;
	for (int i = 0; i < marks.getSize(); i++)
		file << marks[i] << endl;
}

void Student::change(int countMarks)
{
	cout << "������� ����� �������: ";
	getline(cin, secondName);
	cout << "������� ����� ��������: ";
	getline(cin, iniciales);
	for (int i = 0; i < countMarks; i++) {
		cout << "������� " << i + 1 << " ������: ";
		marks += safeInput(1, 5);
	}
}

double Student::getAverageMark() {
	int sum = 0;
	for (int i = 0; i < marks.getSize(); i++)
		sum += marks[i];
	return double(sum) / double(marks.getSize());
}

Student& Student::operator=(const Student& student) {
	if (this == &student)
		return *this;
	secondName = student.secondName;
	iniciales = student.iniciales;
	marks = student.marks;
	return *this;
}