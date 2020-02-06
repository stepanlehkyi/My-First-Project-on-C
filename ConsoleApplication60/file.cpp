
#include <locale>
#include "windows.h"
#include "ctime"
#include "file.h"
#include "fstream"
#include <iostream>

using namespace std;
void Floop(char bukva[], char* slovo, bool* begin_game, int won, int errors) { //Основна логіка гри
	while (1) {
		Litera(bukva);
		_strupr_s(bukva, 2);
		if (E_Bukva(slovo, bukva, begin_game)) {
			cout << "\n Є така буква!\n";
			Bukva_out(slovo, begin_game);
			won++;
			if (won == strlen(slovo)) {
				cout << "\nМої вітання, Ви відгадали слово!\n";
				break;
			}
		}
		else {
			cout << " \nТакої букви немає у загаданому слові\n";
			errors--;
			cout << "\nЗалишилося " << errors << " спроб \n";
			Errors(errors);
			if (errors == 0) {
				cout << "\nНа жаль, Ви програли. Не втрачайте наснаги спробуйте ще!\n";
				break;
			}
		}
	}
}

void Rules() {
	cout << "\nПРАВИЛА ГРИ \" ШИБЕНИЦЯ\" :\n" << endl;
	cout << "Програма загадує слово .\nВоно є  іменником, у називному відмінку однини, або множини(за відсутності у слова форми однини).\n";
	cout << "Користувач пропонує літеру,яка може входити в це слово.\nЯкщо така літера є в слові, то програма \nпише її над відповідними рисками — стільки разів, скільки вона зустрічається в слові.\n";
	cout << "Якщо такої літери немає, то до шибениці домальовують коло в петлі, що зображає голову.\nКористувач продовжує відгадувати літери доти, доки не відгадає все слово.\n";
	cout << "За кожну неправильну відповідь програма додає одну частину тулуба до шибениці" << endl;
	cout << "Якщо тулуб у шибениці намальований повністю,то гравець, що відгадував, вважається повішеним.\nЯкщо гравцеві вдається вгадати слово, він виграє \n";
	cout << "\nПрочитали правила? введіть \"ВИХІД\" для повернення у головне меню\n";
	char back[10];
	gets_s(back, 10);
	_strupr_s(back);
	if (strcmp(back, "ВИХІД") == 0) {
		menu();
	}
	else {
		cout << "\nКоманда введена невірно. Введіть коректну команду\n";
	}
};// функція, що описує правила гри;

void file() { //Функція, що працює з файлом, а також створює основін змінні програми
	fstream fout;//->  Створюємо об'єкт класу fstream
	fout.open("base.TXT", ios::beg | ios::in);//-> відкриваємо файл у якому зберігаються всі слова для гри
	char str[128] = {};//-> створюємо масив символів
	int wordNum = rand() % 99;//-> генеруємо число в діапазоні від 0 до 99
	for (int i = 1; i <= 99; i++)//-> проходимося циклом у цьому діапазоні
	{
		char buff[128] = {};//->створюємо буферний масив символів
		fout.getline(buff, 128);//-> отримуємо рядок з нашої бази слів
		if (i == wordNum) {//->
			if (i <= 1 && i >= 9) {//->
				strcpy_s(str, 128, buff + 2);//-> якщо рандомне число менше 10, то копіюємо у масив власне саме слово
			}
			else {
				strcpy_s(str, 128, buff + 3);//->якщо рандомне число більше 10 але менше 99, то копіюємо у масив власне саме слово
			}
			break;//->
		}
	}
	_strupr_s(str);//-> функція, яка робить всі букви в масиві з великої літери
	cout << str << endl;//->робимо підказку для себе, коли тестуємо гру

	fout.close();//-> закриваємо відкритий файл

	char bukva[2] = {};
	char* slovo = new char[strlen(str)];
	slovo = str;
	bool* begin_game = new bool[strlen(slovo)];
	short errors = 8;
	short won = 0;
	Zagadka(str);
	Floop(bukva, slovo, begin_game, won, errors);
};

bool menu() {
	char buff[32];
	cout << "\n\t\t\t  ВАС ВІТАЄ ГРА \n\t\t\t   \"ШИБЕНИЦЯ\"\n" << endl;
	cout << "\nДЛЯ ОЗНАЙОМЛЕННЯ З ПРАВИЛАМИ НАПИШІТЬ \"ПРАВИЛА\" " << endl;
	cout << "\nДЛЯ ПОЧАТКУ ГРИ НАПИШІТЬ \"СТАРТ\" \n";
	cout << "\nДЛЯ ВИХОДУ НАПИШІТЬ \"ВИХІД\"\n" << endl;
	gets_s(buff, 32);
	_strupr_s(buff);
	if (strcmp(buff, "ПРАВИЛА") == 0) {
		Rules();
	}
	else if (strcmp(buff, "СТАРТ") == 0) {
		file();
	}
	else if (strcmp(buff, "ВИХІД") == 0) {
		return 0;
	}
	else
		cout << "\nКоманда не коректна. Введіть коректну команду.\n";
	return 0;
};//ГОЛОВНЕ МЕНЮ ГРИ

void Bukva_out(char* slovo, bool* begin_game) {   // Функція, що виводить букву, що співпала
	for (int i = 0; i < strlen(slovo); i++) {
		if (begin_game[i] == 1) {
			cout << slovo[i] << " ";
		}
		else
			cout << " _ ";
	}
};

bool E_Bukva(char* slovo, char* bukva, bool* begin_game) { // Функція, що визначає наявність букви у масиві символів
	bool Is_It = 0;
	for (int i = 0; i < strlen(slovo); i++) {
		for (int j = 0; j < strlen(bukva); j++) {
			if (bukva[j] == slovo[i]) {
				begin_game[i] = 1;
				Is_It++;
			}
		}
	}
	return Is_It;
};

void Errors(int errors) {
	switch (errors) {
	case 0:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    О" << endl;
		cout << "   |   /|\\ " << endl;
		cout << "   |   / \\" << endl;
		cout << "   |   " << endl;
		cout << "  =============" << endl << endl;
		break;

	case 1:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    О" << endl;
		cout << "   |   /|\\ " << endl;
		cout << "   |   / \\" << endl;
		cout << "   |  |``|  " << endl;
		cout << "  =============" << endl << endl;
		break;
	case 2:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    О" << endl;
		cout << "   |   /|\\ " << endl;
		cout << "   |     \\" << endl;
		cout << "   |  |``|      " << endl;
		cout << "  =============" << endl << endl;
		break;
	case 3:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    О" << endl;
		cout << "   |   /|\\ " << endl;
		cout << "   |       " << endl;
		cout << "   |  |``|          " << endl;
		cout << "  =============" << endl << endl;
		break;

	case 4:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    О" << endl;
		cout << "   |   /|" << endl;
		cout << "   |       " << endl;
		cout << "   |  |``|          " << endl;
		cout << "  =============" << endl << endl;
		break;

	case 5:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    О" << endl;
		cout << "   |    |" << endl;
		cout << "   |       " << endl;
		cout << "   |  |``|         " << endl;
		cout << "  =============" << endl << endl;
		break;

	case 6:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |       " << endl;
		cout << "   |       " << endl;
		cout << "   |       " << endl;
		cout << "   |  |``|         " << endl;
		cout << "  =============" << endl << endl;
		break;

	case 7:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |       " << endl;
		cout << "   |       " << endl;
		cout << "   |       " << endl;
		cout << "   |       " << endl;
		cout << "   |  |``|         " << endl;
		cout << "  =============" << endl << endl;
		break;

	}
};         //функція, що містить "графічне" зображення шибениці

void Zagadka(char* str) {
	cout << "Я загадав слово на " << strlen(str) << " літер(-и). Відгадате його по одній літері \n";
};

char* Litera(char* bukva) {
	cout << "\nВведіть літеру: \n" << endl;
	cin >> bukva;
	if (strlen(bukva) <= 1) {
		return bukva;
	}
};




