#include <vector>
#include <iostream>
#include "Summary.h"
using namespace std;

std::vector < std::vector<double>> matrixSummary(const std::vector<std::vector<double>>& matrix_a, const std::vector<std::vector<double>>& matrix_b) {
    std::vector < std::vector<double>> res; 
    if (matrix_a.size() != matrix_b.size() || matrix_a[0].size() != matrix_b[0].size()) {
        return res;
    }

    res = std::vector<std::vector<double>>(matrix_a.size(), std::vector<double>(matrix_a[0].size(), 0));

    for (int i = 0; i < matrix_a.size(); ++i) {
        for (int j = 0; j < matrix_a[0].size(); ++j) {
            res[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    return res;
}