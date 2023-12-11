﻿#include <iostream>
#include <vector>
#include "input_matrix.h"
#include "display_matrix.h"
#include "multiplication_matrix_by_number.h"
using namespace std;

int main() {

	std::vector<std::vector<double>> myMatrix = inputMatrix();
	setlocale(LC_ALL, "ru");
	if (!myMatrix.empty()) {
			cout << "Введенная матрица:" << endl;
			displayMatrix(myMatrix);

			myMatrix =multiplyMatrixByNumber(myMatrix);
			cout << "Умноженная матрица:" << endl;
			 displayMatrix(myMatrix);

	}

	return 0;
}
