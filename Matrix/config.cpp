#include "config.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;


ConfigSettings configureSettings() {
	setlocale(LC_ALL, "ru");
	ConfigSettings settings;

	ifstream configFile("config.txt");
	if (configFile.is_open()) {
		string line;
		while (getline(configFile, line)) {
			size_t pos = line.find("backspace_enabled:");
			if (pos != string::npos) {
				// ��������� �������� ���������
				string valueStr = line.substr(pos + 18);
				settings.backspace_enabled = (valueStr.find("1") != string::npos);
				configFile.close();
				return settings;
			}
		}
		configFile.close();
	}

	// ���� �� �������, ��������� ������������ ���������� ���������
	cout << "��������� �������� ������ �����������. ������� �������� (y/n)? ";
	char response;
	cin >> response;

	// ������� �������� ������
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	settings.backspace_enabled = (response == 'y' || response == 'Y');

	ofstream configFileOut("config.txt");
	configFileOut << "backspace_enabled: " << (settings.backspace_enabled ? 1 : 0) << endl;
	configFileOut.close();

	return settings;
}