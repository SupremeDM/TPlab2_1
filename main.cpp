#include "Group.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Group>& groups);
void changeObject(Marray<Group>& groups);
void deleteObject(Marray<Group>& groups);
void print(Marray<Group>& groups);
void searchObject(Marray<Group>& groups);
void printToFile(Marray<Group>& groups);
void inputFromFile(Marray<Group>& groups);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Group> groups;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 7);
		switch (method)
		{
		case 1:
			addObject(groups);
			break;
		case 2:
			changeObject(groups);
			break;
		case 3:
			deleteObject(groups);
			break;
		case 4:
			print(groups);
			break;
		case 5:
			searchObject(groups);
			break;
		case 6:
			printToFile(groups);
			break;
		case 7:
			try
			{
				inputFromFile(groups);
			}
			catch (string err)
			{
				cout << err << endl;
			}
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. Добавить объект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные" << endl;
	cout << "5. Вывести фамилии стдентов и номера групп, если средний балл студента больше 4.0" << endl;
	cout << "6. Вывести в файл" << endl;
	cout << "7. Ввести из файла" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Marray<Group>& groups) {
	Group group;
	group.inputFromConsole();
	groups += group;
	groups.sort();
}

void changeObject(Marray<Group>& groups) {
	if (groups.getSize() > 0) {
		print(groups);
		cout << "Введите номер группы для изменения: ";
		groups[safeInput(1, groups.getSize()) - 1].change();
	}
	else
		cout << "Список групп пуст. Нечего изменять\n";
	groups.sort();
}

void deleteObject(Marray<Group>& groups) {
	if (groups.getSize() > 0) {
		print(groups);
		cout << "Введите номер группы для удаления: ";
		groups -= safeInput(1, groups.getSize()) - 1;
	}
	else
		cout << "Список групп пуст. Нечего удалять\n";
	groups.sort();
}

void print(Marray<Group>& groups) {
	if (groups.getSize() == 0)
		cout << "Список групп пуст.\n";
	else {
		cout << "Список групп\n";
		for (int i = 0; i < groups.getSize(); i++) {
			cout << i + 1 << ". Группа\n";
			groups[i].printToConsole();
		}
	}
}

void searchObject(Marray<Group>& groups) {
	if (groups.getSize() == 0)
		cout << "Список групп пуст\n";
	else {
		bool isPrint = false;
		for (int i = 0; i < groups.getSize(); i++) {
			Marray<Student> students = groups[i].getStudents();
			for (int j = 0; j < students.getSize(); j++)
				if (students[j].getAverageMark() > 4.0) {
					isPrint = true;
					cout << groups[i].getNumber() << " " << students[i].getSecondName() << endl;
				}
		}
			
		if (!isPrint)
			cout << "Студентов со средним баллом больше 4.0 нет\n";
	}
}

void printToFile(Marray<Group>& groups) {
	string filename;
	if (processInputNameOfOutputFile(filename)) {
		ofstream output(filename);
		output << groups.getSize() << endl;
		for (int i = 0; i < groups.getSize(); i++)
			groups[i].printToFile(output);
		output.close();
	}
}

void inputFromFile(Marray<Group>& groups) {
	groups.clear();
	string filename;
	if (processInputNameOfInputFile(filename)) {
		ifstream input(filename);
		string tmpS;
		int countRecord;
		if (!getline(input, tmpS))
		{
			input.close();
			string err = "Файл не может быть прочитан";
			throw err;
		}
		countRecord = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
		try
		{
			for (int i = 0; i < countRecord; i++)
			{
				Group obj;
				obj.inputFromFile(input);
				groups += obj;
			}
		}
		catch (string err)
		{
			input.close();
			throw err;
		}
		input.close();
	}
}