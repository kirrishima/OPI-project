#include <iostream>
#include <vector>
#include "input_matrix.h"
#include "display_matrix.h"
using namespace std;

int main() {

	std::vector<std::vector<double>> myMatrix = inputMatrix();
	setlocale(LC_ALL, "ru");
	if (!myMatrix.empty()) {
		cout << "Введенная матрица:" << endl;
		displayMatrix(myMatrix);
	}
	return 0;
}
