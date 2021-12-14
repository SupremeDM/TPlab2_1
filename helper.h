#pragma once
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
T safeInput(T minInput, T maxInput) {
	while (true)
	{
		T method;
		std::cin >> method;
		if (std::cin.fail() || method < minInput || method > maxInput)
		{
			std::cin.clear();
			std::cout << "Неверный ввод.\nПовторите снова: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}

std::string inputIniciales();
bool checkStringToInt(const std::string& s);
bool processInputNameOfInputFile(std::string& filename);
bool processInputNameOfOutputFile(std::string& filename);