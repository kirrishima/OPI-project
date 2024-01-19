#include <iostream>
#include <vector>
#include "multiplication_matrix_by_number.h"
#include <iostream>
#include <sstream>

using namespace std;
std::vector<std::vector<double>> multiplyMatrixByNumber(const std::vector<std::vector<double>>& matrixToBeMultiplied) {
    std::vector<std::vector<double>> multipliedMatrix(matrixToBeMultiplied);

    std::string number;
    std::cout << "������� �����, �� ������� ����� �������� �������: ";
    std::cin >> number;
    double numFromString;
    try {
        size_t pos;
        numFromString = stod(number, &pos);

        if (pos != number.size()) {
            throw invalid_argument("");
        }


    }
    catch (const invalid_argument&) {
        cerr << "������: ������������ �������� ��� ��� ������." << endl;
        return multipliedMatrix;

    }
    catch (const out_of_range&) {
        cerr << "������: ����� ��� ����������� ���������." << endl;
        return multipliedMatrix;

    }
    for (auto& row : multipliedMatrix) {
        for (auto& num : row) {
            num *= numFromString;
        }
    }

    return multipliedMatrix;
}