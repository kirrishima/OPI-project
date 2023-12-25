#include <iostream>
#include <vector>
#include <Windows.h>
#include "determinant.h"
#include "display_matrix.h"
#include "input_matrix.h"
#include "matrix_by_matrix_product.h"
#include "multiplication_matrix_by_number.h"
#include "Summary.h"
#include "inversematrix.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char choice;
    cout << "Возможности:\n 1)Умножение матрицы на число\n 2)Сложение двух матриц\n 3)Умножение двух матриц\n 4)Нахождение определителя\n 5)Нахождение обратной матрицы\nВыберите действие:";
    cin >> choice;
    while (std::cin.get() != '\n');

    switch (choice) {
    case '1': {
        cout << "\n\nУмножение матрицы на число\n\n";
        std::vector<std::vector<double>> matrix = inputMatrix();
        cout << "Введенная матрица:\n";
        displayMatrix(matrix);
        auto resultMatrix = multiplyMatrixByNumber(matrix);
        cout << "\nРезультат умножения:\n";
        displayMatrix(resultMatrix);
        break;
    }
    case '2': {
        cout << "\n\nСложение двух матриц\n\n";
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

        auto result = matrixSummary(firstMatrix, secondMatrix);
        if (result.empty()) {
            cerr << "Размерности матриц не совпадают";
            return 1;
        }
        cout << "\nA + B:\n";
        displayMatrix(result);
        break;
    }
    case '3': {
        cout << "\n\nУмножение двух матриц\n\n";
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
        std::vector<std::vector<double>> matrix = inputMatrix('2');
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
    case '5':
    {
        cout << "\n\nНахождение обратной матрицы\n\n";
        std::vector<std::vector<double>> matrix = inputMatrix('2');
        if (matrix.empty()) {
            return 1;
        }

        auto result = inverseMatrix(matrix);
        cout << "Обратная матрица: \n";
        displayMatrix(result);
        break;
    }
    default: {
        cout << "Такого варианта нету";
    }
    }

    return 0;
}
