#include <algorithm>
#include "input_matrix.h"
#include "config.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <fstream>
using namespace std;

// Функция для ввода матрицы
std::vector<std::vector<int>> inputMatrix(const ConfigSettings& settings){
	std::vector<std::vector<int>> matrix;
	string input;

	if (settings.backspace_enabled) {
		cout << "Включена возможность удаления строки." << endl;
	}
	else {
		cout << "Отключена возможность удаления строки." << endl;
	}

	cout << "Введите размерность матрицы (формат: nxm или n x m): ";
	getline(cin, input);

	if (input == "--config") {
		ConfigSettings newSettings = configureSettings();
		return inputMatrix(newSettings); // Рекурсивный вызов с новыми настройками
	}

	regex pattern("\\s*(\\d+)\\s*[xX]\\s*(\\d+)\\s*");
	smatch matches;

	if (regex_match(input, matches, pattern)) {
		int rows = stoi(matches[1]);
		int cols = stoi(matches[2]);

		if (rows <= 0 || cols <= 0) {
			cerr << "Ошибка: Некорректные размеры матрицы." << endl;
			return matrix;
		}

		cout << "Введите элементы матрицы (" << rows << "x" << cols << "):" << endl;

		for (int i = 0; i <= rows; ++i) {
			string inputLine;
			getline(cin, inputLine);

			transform(inputLine.begin(), inputLine.end(), inputLine.begin(), ::tolower);

			if (settings.backspace_enabled && inputLine == "backspace") {
				if (!matrix.empty()) {
					matrix.pop_back();
					i -= 2;
				}
				else {
					cerr << "Ошибка: Нет строк для удаления." << endl;
					i--;
				}
			}
			else if (settings.backspace_enabled && inputLine != "backspace" && i == rows)  {
				return matrix;
			}
			else if (!settings.backspace_enabled && i == rows - 1) {
				i++;
				goto add_row_to_matrix;
			}
			else {

			add_row_to_matrix:

				istringstream iss(inputLine);
				vector<int> row;

				int num;
				while (iss >> num) {
					row.push_back(num);
				}

				if (row.size() != cols) {
					cerr << "Ошибка: Некорректное количество элементов в строке." << endl;
					--i;
				}
				else {
					matrix.push_back(row);
				}
			}
		}
	}
	else {
		cerr << "Ошибка: Некорректный формат размерности матрицы." << endl;
	}

	return matrix;
}
