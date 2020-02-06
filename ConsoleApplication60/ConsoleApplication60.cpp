
#include "file.h"
#include <locale>
#include "windows.h"
#include "ctime"
#include "fstream"
#include <iostream>

using namespace std;


int main()
{
	srand(time(NULL));       // функція, для генерації випадкових значень
	SetConsoleCP(1251);     //->
	SetConsoleOutputCP(1251);//->           для введення і виведення українських символів
	setlocale(LC_CTYPE, "ukr");//-> 
	while (1) {
		if (!menu())
			break;
	}
	system("pause");
	return 0;
}