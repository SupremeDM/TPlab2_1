#include "helper.h"

bool checkChar(const char& ch) {
	return isalpha(ch) && !islower(ch);
}

bool checkStringToIniciales(std::string s) {
	return s.size() == 4 && checkChar(s[0]) && s[1] == '.' && checkChar(s[2]) && s[3] == '.';
}

std::string inputIniciales() {
	std::string years;
	while (true) {
		std::cin >> years;
		if (!checkStringToIniciales(years))
			std::cout << "Неверный ввод.\nПовторите снова: " << std::endl;
		else
			return years;
	}
}

bool checkStringToInt(const std::string& s) {
	for (auto ch : s) {
		if (!isdigit(ch))
			return false;
	}
	return true;
}

bool checkFilename(std::string file)
{
	if (file.size() < 4 && file[0] != '0') {
		std::cout << "Имя файла слишком короткое." << std::endl;
		return false;
	}
	if ((((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
		&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'a') || (file[0] == 'A')) && ((file[1] == 'u') || (file[1] == 'U'))
			&& ((file[2] == 'x') || (file[2] == 'X')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'p') || (file[0] == 'P')) && ((file[1] == 'r') || (file[1] == 'R'))
			&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
			&& ((file[2] == 'm') || (file[2] == 'M')) && ((file[3] == '1') || (file[3] == '2')
				|| (file[3] == '3') || (file[3] == '4') || (file[3] == '5') || (file[3] == '6')
				|| (file[3] == '7') || (file[3] == '8') || (file[3] == '9')) && ((file[4] == '.')
					|| (file[4] == '\0'))) || (((file[0] == 'l') || (file[0] == 'L')) && ((file[1] == 'p')
						|| (file[1] == 'P')) && ((file[2] == 't') || (file[2] == 'T')) && ((file[3] == '1')
							|| (file[3] == '2') || (file[3] == '3') || (file[3] == '4') || (file[3] == '5')
							|| (file[3] == '6') || (file[3] == '7') || (file[3] == '8') || (file[3] == '9'))
						&& ((file[4] == '.') || (file[4] == '\0'))))
	{
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Данное имя файла используется Windows." << std::endl;
		return false;
	}
	int i = file.size();
	if ((file[i] == '\0') && (file[i - 1] == 't') && (file[i - 2] == 'x') && (file[i - 3] == 't') && (file[i - 4] == '.') ||
		(file[i] == '\0') && (file[i - 1] == 't') && (file[i - 2] == 'a') && (file[i - 3] == 'd') && (file[i - 4] == '.'))
		return true;
	else
	{
		if (file[i - 1] != '0')
			std::cout << "Файл должен иметь формат .txt или .dat" << std::endl;
		return false;
	}
}

bool processInputNameOfInputFile(std::string& filename)
{
	std::ifstream file;
	bool isCorrect;
	std::cout << "Введите название файла (с расширением)(0 - отказ): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	if (isCorrect)
		file.open(filename);
	while (!file.is_open() && filename[0] != '0')
	{

		if (isCorrect)
			std::cout << "Такого файла не существует." << std::endl;
		std::cout << "Введите название повторно (с расширением): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
		if (isCorrect)
			file.open(filename);
	}
	file.close();
	if (filename[0] != '0') {
		std::cout << "Файл успешно открыт" << std::endl;
		return true;
	}
	else {
		std::cout << "Вы отказались от ввода данных из файла" << std::endl;
		return false;
	}

}

bool processInputNameOfOutputFile(std::string& filename)
{
	bool isCorrect;
	std::cout << "Введите название файла (с расширением)(0 - отказ): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	while (!isCorrect && filename[0] != '0') {
		std::cout << "Введите название повторно (с расширением): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
	}
	if (filename[0] != '0') {
		std::cout << "Файл успешно открыт" << std::endl;
		return true;
	}
	else {
		std::cout << "Вы отказались от ввода данных из файла" << std::endl;
		return false;
	}
}