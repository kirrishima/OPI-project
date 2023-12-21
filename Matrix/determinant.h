#pragma once
#include <iostream>
#include <vector>

double determinant(const std::vector<std::vector<double>>& matrix);
std::vector<std::vector<double>> getMinor(const std::vector<std::vector<double>>& matrix, int row, int col);