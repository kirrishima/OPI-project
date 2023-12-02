#include <iostream>
#include <vector>
#include "input_matrix.h"
#include "display_matrix.h"
using namespace std;

int main() {
	ConfigSettings settings = configureSettings();
	cout << "Что делаем? (input matrix  -  вввод матрицы, --config - настройка по умолчанию): ";
	std::string choice;
	getline(cin, choice);
	if (choice == "input matrix") {
	std::vector<std::vector<double>> myMatrix = inputMatrix(settings);
	setlocale(LC_ALL, "ru");
	if (!myMatrix.empty()) {
		cout << "Введенная матрица:" << endl;
		displayMatrix(myMatrix);
	}
	}
	else if (choice == "--config") {
		configureSettings("--config");
	}

	return 0;
}
