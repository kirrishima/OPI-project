#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, m, k, l;
    setlocale(0, "");

    cout << "������� ������� ������ ������� (1 - ������, 2 - �������): ";
    cin >> n >> m;

    cout << "������� ������� ������ ������� (1 - ������, 2 - �������): ";
    cin >> k >> l;

    if (n == k && m == l) {
        cout << "������� ������ �������\n";

        std::vector<std::vector<int>> Matrix1(n, std::vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> Matrix1[i][j];
            }
        }

        cout << "\n";

        for (const auto& row : Matrix1) {
            for (const auto& element : row) {
                cout << element << " ";
            }
            cout << "\n";
        }

        cout << "\n������� ������ �������\n";

        std::vector<std::vector<int>> Matrix2(k, std::vector<int>(l, 0));

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < l; ++j) {
                cin >> Matrix2[i][j];
            }
        }

        cout << "\n";

        for (const auto& row : Matrix2) {
            for (const auto& element : row) {
                cout << element << " ";
            }
            cout << "\n";
        }

        cout << "\n��������� �������� ������: \n";

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                Matrix1[i][j] += Matrix2[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << Matrix1[i][j] << " ";
            }
            cout << "\n";
        }
    }

    else {
        cout << "\n\t������������ ������ ������\n";
    }

    return 0;
}
