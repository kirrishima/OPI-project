#include<iostream>
#include<vector>
#include "determinant.h"

std::vector<std::vector<double>> inverseMatrix(const std::vector<std::vector<double>>& matrix) {
	double det = determinant(matrix);
	std::vector<std::vector<double>> inversematrix(matrix.size(), std::vector<double>(matrix.size()));
	if (det == 0)
		std::cout << "Найти обратную матрицу невозможно, т.к. матрица вырожденная\n";
	else {

		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix.size(); ++j) {
				int sign = pow(-1, i + j + 2);
				std::vector<std::vector<double>> minor = getMinor(matrix, i, j);
				inversematrix[j][i] = sign * (1 / det) * determinant(minor);

			}
		}
	}
	return inversematrix;
}