#pragma once


void Rules();// функція, що описує правила гри

bool menu();//ГОЛОВНЕ МЕНЮ ГРИ

void Bukva_out(char* slovo, bool* begin_game);  // Функція, що виводить букву, що співпала

bool E_Bukva(char* slovo, char* bukva, bool* begin_game); // Функція, що визначає наявність букви у масиві символів

void Errors(int errors); //функція, що містить "графічне" зображення шибениці

void Zagadka(char* str);// проста функція, що виводить на екран кількість букв у слові, що загадала програма

char* Litera(char* bukva);// просить ввести літеру

void Floop(char bukva[], char* slovo, bool* begin_game, int won, int errors); //Основна логіка гри

void file(); //Функція, що працює з файлом, а також створює основін змінні програми


