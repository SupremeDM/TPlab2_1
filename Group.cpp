#include "Group.h"

Group::Group() : number(0) , avverageMark(0)
{
	cout << "Вызван конструктор Group" << endl;
}

Group::Group(int number, Marray<Student> students, Marray<string> objects) : number(number), students(students), objects(objects)
{
	calculeteAverageMark();
	cout << "Вызван констукотр Group" << endl;
}

Group::Group(const Group& group) : number(group.number), students(group.students), objects(group.objects), avverageMark(group.avverageMark)
{
	cout << "Вызван констукотр копирования Group" << endl;
}

Group::~Group()
{
	cout << "Вызван деструктор Group" << endl;
}

void Group::inputFromConsole() {
	cout << "Введите номер: ";
	number = safeInput(1, INT32_MAX);
	cout << "Введите количество предметов: ";
	int tmpCount = safeInput(1, INT32_MAX);
	for (int i = 0; i < tmpCount; i++) {
		cout << "Введите " << i + 1 << " предмет: ";
		string tmp;
		getline(cin, tmp);
		objects += tmp;
	}
	cout << "Введите количество студентов: ";
	tmpCount = safeInput(1, INT32_MAX);
	for (int i = 0; i < tmpCount; i++) {
		cout << "Введите " << i + 1 << " студента:\n";
		Student tmp;
		tmp.inputFromConsole(objects.getSize());
		students += tmp;
	}
}

void Group::inputFromFile(ifstream& file) {
	string err = "Файл не может быть корректно прочитан";
	string tmpS;
	if (!getline(file, tmpS))
		throw err;
	number = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	int tmpCount = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	for (int i = 0; i < tmpCount; i++) {
		if (!getline(file, tmpS))
			throw err;
		objects += tmpS;
	}
	if (!getline(file, tmpS))
		throw err;
	tmpCount = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	for (int i = 0; i < tmpCount; i++) {
		Student tmp;
		tmp.inputFromFile(file);
		students += tmp;
	}
}

void Group::printToConsole()
{
	cout << "Номер: " << number << endl;
	cout << "Список предметов: " << endl;
	for (int i = 0; i < objects.getSize(); i++)
		cout << i + 1 << ". " << objects[i] << endl;
	cout << "Список студентов: " << endl;
	for (int i = 0; i < students.getSize(); i++)
	{
		cout << i + 1 << ". ";
		students[i].printToConsole();
	}
}

void Group::printToFile(ofstream& file) {
	file << number << endl;
	file << objects.getSize() << endl;
	for (int i = 0; i < objects.getSize(); i++)
		file << objects[i] << endl;
	file << students.getSize() << endl;
	for (int i = 0; i < students.getSize(); i++)
		students[i].printToFile(file);
}

void Group::change() {
	objects.clear();
	students.clear();
	cout << "Введите новый номер: ";
	number = safeInput(1, INT32_MAX);
	cout << "Введите новое количество предметов: ";
	int tmpCount = safeInput(1, INT32_MAX);
	for (int i = 0; i < tmpCount; i++) {
		cout << "Введите " << i + 1 << " предмет: ";
		string tmp;
		getline(cin, tmp);
		objects += tmp;
	}
	cout << "Введите новое количество студентов: ";
	tmpCount = safeInput(1, INT32_MAX);
	for (int i = 0; i < tmpCount; i++) {
		cout << "Введите " << i + 1 << " студента:\n";
		Student tmp;
		tmp.inputFromConsole(objects.getSize());
		students += tmp;
	}
}

Group& Group::operator=(const Group& group){
	if (this == &group)
		return *this;
	number = group.number;
	avverageMark = group.avverageMark;
	students = group.students;
	objects = group.objects;
	return *this;
}

bool Group::operator>(Group& group) {
	return number > group.number;
}

void Group::calculeteAverageMark() {
	double sum = 0;
	for (int i = 0; i < students.getSize(); i++)
		sum += students[i].getAverageMark();
	avverageMark = double(sum) / double(students.getSize());
}