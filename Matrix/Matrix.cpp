#include <iostream>
#include <vector>
#include <Windows.h>
#include "determinant.h"
#include "display_matrix.h"
#include "input_matrix.h"
#include "matrix_by_matrix_product.h"
#include "multiplication_matrix_by_number.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char choice;
    cout << "Выберите действие:\n 1)Умножение матрицы на число\n 2)Сложение двух матриц\n 3)Умножение двух матриц\n 4)Нахождение определителя\n ";
    cin >> choice;

    while (std::cin.get() != '\n');

    switch (choice) {
    case '1': {
        std::vector<std::vector<double>> matrix = inputMatrix();
        cout << "Введенная матрица:\n";
        displayMatrix(matrix);
        auto resultMatrix = multiplyMatrixByNumber(matrix);
        cout << "\nРезультат умножения:\n";
        displayMatrix(resultMatrix);
        break;
    }
    case '2': {
        cout << "In progress";
        break;
    }
    case '3': {
        cout << "Введите матрицу A:\n";
        std::vector<std::vector<double>> firstMatrix = inputMatrix();
        if (firstMatrix.empty()) {
            return 1;
        }
        cout << "Введенная матрица:\n";
        displayMatrix(firstMatrix);

        cout << "Введите матрицу B:\n";
        std::vector<std::vector<double>> secondMatrix = inputMatrix();
        if (secondMatrix.empty()) {
            return 1;
        }
        cout << "Введенная матрица:\n";
        displayMatrix(secondMatrix);

        if (firstMatrix[0].size() != secondMatrix.size()) {
            cerr << "Невозможно выполнить умножение матриц: матрицы не согласованны";
            return 1;
        }
        auto resultMatrix = multiplyMatrixByMatrix(firstMatrix, secondMatrix);
        cout << "A x B:\n";
        displayMatrix(resultMatrix);
        break;
    }
    case '4': {
        cout << "\n\nНахождение определителя\n\n";
        std::vector<std::vector<double>> matrix = inputMatrix();
        if (matrix.empty()) {
            return 1;
        }
        cout << "Введенная матрица:\n";
        displayMatrix(matrix);
        if (matrix.size() != matrix[0].size()) {
            cerr << "Матрица должна быть квадратной";
            return 1;
        }
        double det = determinant(matrix);
        cout << "Определитель матрицы = " << det;
        break;
    }
    default: {
        cout << "Такого варианта нету";
    }
    }

    return 0;
}
