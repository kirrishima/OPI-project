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
				// Извлекаем значение настройки
				string valueStr = line.substr(pos + 18);
				settings.backspace_enabled = (valueStr.find("1") != string::npos);
				configFile.close();
				return settings;
			}
		}
		configFile.close();
	}
	
	char response;
	// Если не найдено, предложим пользователю установить настройки
	cout << "Настройка удаления строки отсутствует. Желаете включить (y/n)? ";
	while (true) {
		cin >> response;
		response = tolower(response);
		if (response == 'y') break;
		else if (response == 'n') break;
		else cout << "Неверный ввод\n";
	}

	// Очистка входного буфера
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	settings.backspace_enabled = (response == 'y' || response == 'Y');

	ofstream configFileOut("config.txt");
	configFileOut << "backspace_enabled: " << (settings.backspace_enabled ? 1 : 0) << endl;
	configFileOut.close();

	return settings;
}

ConfigSettings configureSettings(std::string setup) {
	setlocale(LC_ALL, "ru");
	if (setup == "--config") {
		ConfigSettings settings;
		char response;
		// Если не найдено, предложим пользователю установить настройки
		cout << "Настройка возможности удаления строки матрицы при вводе используя слово backspace. Желаете включить (y/n)? ";
		while (true) {
			cin >> response;
			response = tolower(response);
			if (response == 'y') break;
			else if (response == 'n') break;
			else cout << "Неверный ввод\n";
		}

		// Очистка входного буфера
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		settings.backspace_enabled = (response == 'y' || response == 'Y');

		ofstream configFile("config.txt");
		configFile << "backspace_enabled: " << (settings.backspace_enabled ? 1 : 0) << endl;
		configFile.close();

		return settings;
	}
}