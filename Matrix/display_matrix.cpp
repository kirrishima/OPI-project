#include <iostream>
#include <vector>
#include "display_matrix.h"
using namespace std;

void displayMatrix(const std::vector<std::vector<int>>& matrix){
	for (const auto& row : matrix) {
		for (int num : row) {
			cout << num << " ";
		}
		cout << endl;
	}
}