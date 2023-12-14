#include <iostream>
#include <vector>
#include "input_matrix.h"
#include "display_matrix.h"
#include "multiplication_matrix_by_number.h"
#include "matrix_by_matrix_product.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int mode;
	cout << "Выберите режим работы программы:" << endl << "1-умножение матрицы на число" << endl << "2-умножение матриц" << endl;
	cin >> mode;


	switch(mode) {
	case 1:{
			std::vector<std::vector<double>> myMatrix = inputMatrix();
			if (!myMatrix.empty()) {
				cout << "Введенная матрица:" << endl;
				displayMatrix(myMatrix);

				myMatrix = multiplyMatrixByNumber(myMatrix);
				cout << "Умноженная матрица:" << endl;
				displayMatrix(myMatrix);

			}
		}
	case 2: {
		cin.ignore();

		std::vector<std::vector<double>> Matrix_A = inputMatrix();
		cout << "Введенная матрица:" << endl;
		displayMatrix(Matrix_A);

		std::vector<std::vector<double>> Matrix_B = inputMatrix();
		cout << "Введенная матрица:" << endl;
		displayMatrix(Matrix_B);
		
		if (!Matrix_A.empty() and !Matrix_B.empty()) {

			std::vector<std::vector<double>> Matrix_res = multiplyMatrixByMatrix(Matrix_A, Matrix_B);
			cout << "Умноженная матрица:" << endl;
			displayMatrix(Matrix_res);

		}
	}
	}

	return 0;
}
//