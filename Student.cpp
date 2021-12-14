#include "Student.h"

Student::Student() : secondName("Не задано"), iniciales("Не задано")
{
	cout << "Вызван конструктор Student" << endl;
}

Student::Student(string secondName, string iniciales, Marray<int> marks) : 
	secondName(secondName), iniciales(iniciales), marks(marks)
{
	cout << "Вызван конструктор Student" << endl;
}

Student::Student(const Student& student) : secondName(student.secondName), iniciales(student.iniciales), marks(student.marks)
{
	cout << "Вызван конструктор копирования Student" << endl;
}

Student::~Student()
{
	cout << "Вызван деструктор Student" << endl;
}

void Student::inputFromConsole(int countMarks)
{
	cout << "Введите фамилию: ";
	getline(cin, secondName);
	cout << "Введите инициалы(A.A.): ";
	iniciales = inputIniciales();
	for (int i = 0; i < countMarks; i++) {
		cout << "Введите " << i + 1 << " оценку: ";
		marks += safeInput(1, 5);
	}
}

void Student::inputFromFile(ifstream& file) {
	string err = "Файл не может быть корректно прочитан";
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
	cout << "ФИО: " << secondName << " " << iniciales << endl;
	if (marks.getSize() > 0) {
		cout << "Оценки: ";
		for (int i = 0; i < marks.getSize(); i++)
			cout << marks[i] << " ";
		cout << endl;
	}
	else
		cout << "Оценок нет" << endl;
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
	cout << "Введите новую фамилию: ";
	getline(cin, secondName);
	cout << "Введите новые инициалы: ";
	getline(cin, iniciales);
	for (int i = 0; i < countMarks; i++) {
		cout << "Введите " << i + 1 << " оценку: ";
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