﻿#pragma once
#include <string>
// Структура для хранения настроек
struct ConfigSettings {
    //переменная, хранящая настройку того активирована ли возможность удаления строчек матрицы
    bool backspace_enabled;
};

// Функция для ввода и обработки настроек
ConfigSettings configureSettings();

// Функция для изменения и обработки настроек
ConfigSettings configureSettings(std::string setup);