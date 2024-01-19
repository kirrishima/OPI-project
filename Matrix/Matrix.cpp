#include <iostream>
#include <vector>
#include <Windows.h>
#include <sstream>
#include "determinant.h"
#include "display_matrix.h"
#include "input_matrix.h"
#include "matrix_by_matrix_product.h"
#include "multiplication_matrix_by_number.h"
#include "Summary.h"
#include "inversematrix.h"
#include <string>
using namespace std;

#define INPUT_MATRIX(str, matrix, mode) \
    std::cout<<str; \
    std::vector<std::vector<double>> matrix = inputMatrix(mode); \
    if (matrix.empty()) { \
        return 1; \
    } \
    cout << "Введенная матрица:\n"; \
    displayMatrix(matrix); \

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	string choice;
	cout << "Возможности:\n 1)Умножение матрицы на число\n 2)Сложение двух матриц\n 3)Умножение двух матриц\n 4)Нахождение определителя\n 5)Нахождение обратной матрицы\nВыберите действие:";
	getline(cin, choice);
	/*while (std::cin.get() != '\n');*/
	if (choice.length() != 1) {
		cerr << "Допускается ввод только одного символа";
		return 1;
	}
	switch (choice[0]) {
	case '1': {
		cout << "\n\nУмножение матрицы на число\n\n";
		INPUT_MATRIX("Ввод матрицы:\n", matrix);
		auto resultMatrix = multiplyMatrixByNumber(matrix);
		if (resultMatrix != matrix) {
			cout << "\nРезультат умножения:\n";
			displayMatrix(resultMatrix);
		}
		break;
	}
	case '2': {
		cout << "\n\nСложение двух матриц\n\n";
		INPUT_MATRIX("Введите матрицу A:\n", firstMatrix);
		INPUT_MATRIX("Введите матрицу B:\n", secondMatrix);

		auto result = matrixSummary(firstMatrix, secondMatrix);
		if (result.empty()) {
			cerr << "Размерности матриц не совпадают";
			return 1;
		}
		cout << "\nA + B:\n";
		displayMatrix(result);
		break;
	}
	case '3': {
		cout << "\n\nУмножение двух матриц\n\n";
		INPUT_MATRIX("Введите матрицу A:\n", firstMatrix);
		INPUT_MATRIX("Введите матрицу B:\n", secondMatrix);

		if (firstMatrix[0].size() != secondMatrix.size()) {
			cerr << "Невозможно выполнить умножение матриц: матрицы не согласованны";
			return 1;
		}
		auto resultMatrix = multiplyMatrixByMatrix(firstMatrix, secondMatrix);
		cout << "A x B:\n";
		displayMatrix(resultMatrix);
		break;
	}
	case '4': {
		cout<<"\n\nНахождение определителя\n\n";
		INPUT_MATRIX("Ввод матрицы:\n", matrix, '2');

		if (matrix.size() != matrix[0].size()) {
			cerr << "Матрица должна быть квадратной";
			return 1;
		}
		double det = determinant(matrix);
		cout << "Определитель матрицы = " << det;
		break;
	}
	case '5':

	{
		cout << "\n\nНахождение обратной матрицы\n\n";
		INPUT_MATRIX("Ввод матрицы:\n", matrix, '2');

		auto result = inverseMatrix(matrix);
		cout << "Обратная матрица: \n";
		displayMatrix(result);
		break;
	}
	default: {
		cout << "Такого варианта нету";
	}
	}

	return 0;
}
