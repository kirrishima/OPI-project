#include "input_matrix.h"
#include "display_matrix.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <fstream>
#include <algorithm>
#include <Windows.h>
using namespace std;

// Функция для ввода матрицы
std::vector<std::vector<double>> inputMatrix(char mode) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<std::vector<double>> matrix;
	string input;

	cout << "Введите размерность матрицы (формат: nxm или n x m): ";
	getline(cin, input);

	std::regex pattern("\\s*(\\d+)\\s*[xXхХ]\\s*(\\d+)\\s*");
	smatch matches;

	if (regex_match(input, matches, pattern)) {
		int rows = stoi(matches[1]);
		int cols = stoi(matches[2]);

		if (rows <= 0 || cols <= 0) {
			cerr << "Ошибка: Некорректные размеры матрицы." << endl;
			return matrix;
		}

		if (mode != '1' && rows != cols) {
			cerr << "Матрица должна быть квадратной";
			return matrix;
		}

		cout << "Введите элементы матрицы (" << rows << "x" << cols << ") построчно: " << endl;

		for (int i = 0; i < rows; ++i) {
			string inputLine;
			getline(cin, inputLine);

			istringstream iss(inputLine);
			vector<double> row;

			string token;
			bool errorPrinted = false;

			while (iss >> token) {
				try {
					size_t pos;
					double num = stod(token, &pos);

					if (pos != token.size()) {
						throw invalid_argument("");
					}

					row.push_back(num);
				}
				catch (const invalid_argument&) {
					cerr << "Ошибка: Некорректное значение в строке или тип данных." << endl;
					errorPrinted = true;
					--i;
					break;
				}
				catch (const out_of_range&) {
					cerr << "Ошибка: Число вне допустимого диапазона." << endl;
					--i;
					errorPrinted = true;
					break;
				}
			}

			if (!errorPrinted && row.size() != cols) {
				cerr << "Ошибка: Некорректное количество элементов в строке." << endl;
				--i;
			}
			else if (!errorPrinted) {
				matrix.push_back(row);
			}
		}
	}
	else {
		cerr << "Ошибка: Некорректный формат размерности матрицы." << endl;
	}

	return matrix;
}
