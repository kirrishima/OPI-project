#include <iostream>
#include <vector>
#include "display_matrix.h"
using namespace std;

void displayMatrix(const std::vector<std::vector<double>>& matrix){
	for (const auto& row : matrix) {
		for (double num : row) {
			cout << num << " ";
		}
		cout << endl;
	}
}