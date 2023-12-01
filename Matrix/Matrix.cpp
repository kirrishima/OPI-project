#include <iostream>
#include <vector>
#include "input_matrix.h"
#include "display_matrix.h"

using namespace std;

int main() {
	ConfigSettings settings = configureSettings();
	std::vector<std::vector<int>> myMatrix = inputMatrix(settings);
	setlocale(LC_ALL, "ru");
	if (!myMatrix.empty()) {
		cout << "Введенная матрица:" << endl;
		displayMatrix(myMatrix);
	}

	return 0;
}
