#include<iostream>
#include<vector>
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <fstream>
#include <algorithm>
#include <Windows.h>
using namespace std;

void displayMatrix(const std::vector<std::vector<double>>& matrix) {
	for (const auto& row : matrix) {
		for (double num : row) {
			cout << num << " ";
		}
		cout << endl;
	}
}
// ������� ��� ���������� ������ �������
std::vector<std::vector<double>> getMinor(const std::vector<std::vector<double>>& matrix, int row, int col) {
	std::vector<std::vector<double>> minor;
	for (int i = 0; i < matrix.size(); ++i) {
		if (i != row) {
			std::vector<double> tempRow;
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (j != col) {
					tempRow.push_back(matrix[i][j]);
				}
			}
			minor.push_back(tempRow);
		}
	}
	return minor;
}

// ����������� ������� ��� ���������� ������������ �������
double determinant(const std::vector<std::vector<double>>& matrix) {

	if (matrix.size() == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	double det = 0;
	int sign = 1;
	for (int i = 0; i < matrix.size(); ++i) {
		det += sign * matrix[0][i] * determinant(getMinor(matrix, 0, i));
		sign = -sign;
	}

	return det;
}
// ������� ��� ����� �������
std::vector<std::vector<double>> inputMatrix() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<std::vector<double>> matrix;
	string input;

	cout << "������� ����������� ������� (������: nxm ��� n x m): ";
	getline(cin, input);

	std::regex pattern("\\s*(\\d+)\\s*[xX��]\\s*(\\d+)\\s*");
	smatch matches;

	if (regex_match(input, matches, pattern)) {
		int rows = stoi(matches[1]);
		int cols = stoi(matches[2]);

		if (rows <= 0 || cols <= 0) {
			cerr << "������: ������������ ������� �������." << endl;
			return matrix;
		}

		cout << "������� �������� ������� (" << rows << "x" << cols << ") ���������: " << endl;

		for (int i = 0; i < rows; ++i) {
			string inputLine;
			getline(cin, inputLine);

			istringstream iss(inputLine);
			vector<double> row;

			string token;
			bool errorPrinted = false;

			while (iss >> token) {
				try {
					size_t pos;
					double num = stod(token, &pos);

					if (pos != token.size()) {
						throw invalid_argument("");
					}

					row.push_back(num);
				}
				catch (const invalid_argument&) {
					cerr << "������: ������������ �������� � ������ ��� ��� ������." << endl;
					errorPrinted = true;
					--i;
					break;
				}
				catch (const out_of_range&) {
					cerr << "������: ����� ��� ����������� ���������." << endl;
					--i;
					errorPrinted = true;
					break;
				}
			}

			if (!errorPrinted && row.size() != cols) {
				cerr << "������: ������������ ���������� ��������� � ������." << endl;
				--i;
			}
			else if (!errorPrinted) {
				matrix.push_back(row);
			}
		}
	}
	else {
		cerr << "������: ������������ ������ ����������� �������." << endl;
	}

	return matrix;
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
		std::vector<std::vector<double>> matrix = inputMatrix();
		double det = determinant(matrix);
		std::vector<std::vector<double>> inversematrix(matrix.size(),std::vector<double>(matrix.size()));
		if (det == 0) cout << "����� �������� ������� ����������, �.�. ������� �����������\n";
		else {
			
			for (int i =0; i < matrix.size(); ++i) {
				for (int j = 0; j < matrix.size(); ++j) {
					int sign=pow(-1, i + j + 2);
					std::vector<std::vector<double>> minor=getMinor(matrix, i, j);
					inversematrix[j][i] =sign*( 1 / det)* determinant(minor);
					
					
				} 
			}
		}
		cout << "�������� ������� : \n";
		displayMatrix(inversematrix);
 }