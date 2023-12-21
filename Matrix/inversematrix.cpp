#include<iostream>
#include<vector>
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <fstream>
#include <algorithm>
#include <Windows.h>
using namespace std;

void displayMatrix(const std::vector<std::vector<double>>& matrix) {
	for (const auto& row : matrix) {
		for (double num : row) {
			cout << num << " ";
		}
		cout << endl;
	}
}
// Функция для вычисления минора матрицы
std::vector<std::vector<double>> getMinor(const std::vector<std::vector<double>>& matrix, int row, int col) {
	std::vector<std::vector<double>> minor;
	for (int i = 0; i < matrix.size(); ++i) {
		if (i != row) {
			std::vector<double> tempRow;
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (j != col) {
					tempRow.push_back(matrix[i][j]);
				}
			}
			minor.push_back(tempRow);
		}
	}
	return minor;
}

// Рекурсивная функция для вычисления определителя матрицы
double determinant(const std::vector<std::vector<double>>& matrix) {

	if (matrix.size() == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	double det = 0;
	int sign = 1;
	for (int i = 0; i < matrix.size(); ++i) {
		det += sign * matrix[0][i] * determinant(getMinor(matrix, 0, i));
		sign = -sign;
	}

	return det;
}
// Функция для ввода матрицы
std::vector<std::vector<double>> inputMatrix() {
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

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
		std::vector<std::vector<double>> matrix = inputMatrix();
		double det = determinant(matrix);
		std::vector<std::vector<double>> inversematrix(matrix.size(),std::vector<double>(matrix.size()));
		if (det == 0) cout << "Найти обратную матрицу невозможно, т.к. матрица вырожденная\n";
		else {
			
			for (int i =0; i < matrix.size(); ++i) {
				for (int j = 0; j < matrix.size(); ++j) {
					int sign=pow(-1, i + j + 2);
					std::vector<std::vector<double>> minor=getMinor(matrix, i, j);
					inversematrix[j][i] =sign*( 1 / det)* determinant(minor);
					
					
				} 
			}
		}
		cout << "Обратная матрица : \n";
		displayMatrix(inversematrix);
 }