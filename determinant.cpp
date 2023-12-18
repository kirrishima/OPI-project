#include <iostream>
#include <vector>

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