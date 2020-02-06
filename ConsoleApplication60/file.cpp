
#include <locale>
#include "windows.h"
#include "ctime"
#include "file.h"
#include "fstream"
#include <iostream>

using namespace std;
void Floop(char bukva[], char* slovo, bool* begin_game, int won, int errors) { //������� ����� ���
	while (1) {
		Litera(bukva);
		_strupr_s(bukva, 2);
		if (E_Bukva(slovo, bukva, begin_game)) {
			cout << "\n � ���� �����!\n";
			Bukva_out(slovo, begin_game);
			won++;
			if (won == strlen(slovo)) {
				cout << "\n�� ������, �� �������� �����!\n";
				break;
			}
		}
		else {
			cout << " \n���� ����� ���� � ���������� ����\n";
			errors--;
			cout << "\n���������� " << errors << " ����� \n";
			Errors(errors);
			if (errors == 0) {
				cout << "\n�� ����, �� ��������. �� ��������� ������� ��������� ��!\n";
				break;
			}
		}
	}
}

void Rules() {
	cout << "\n������� ��� \" ��������\" :\n" << endl;
	cout << "�������� ������ ����� .\n���� �  ���������, � ��������� ������ ������, ��� �������(�� ��������� � ����� ����� ������).\n";
	cout << "���������� ������� �����,��� ���� ������� � �� �����.\n���� ���� ����� � � ����, �� �������� \n���� �� ��� ���������� ������� � ������ ����, ������ ���� ����������� � ����.\n";
	cout << "���� ���� ����� ����, �� �� �������� ������������ ���� � ����, �� ������� ������.\n���������� �������� ���������� ����� ����, ���� �� ������ ��� �����.\n";
	cout << "�� ����� ����������� ������� �������� ���� ���� ������� ������ �� ��������" << endl;
	cout << "���� ����� � �������� ������������ �������,�� �������, �� ���������, ��������� ��������.\n���� ������� ������� ������� �����, �� ����� \n";
	cout << "\n��������� �������? ������ \"��ղ�\" ��� ���������� � ������� ����\n";
	char back[10];
	gets_s(back, 10);
	_strupr_s(back);
	if (strcmp(back, "��ղ�") == 0) {
		menu();
	}
	else {
		cout << "\n������� ������� ������. ������ �������� �������\n";
	}
};// �������, �� ����� ������� ���;

void file() { //�������, �� ������ � ������, � ����� ������� ������ ���� ��������
	fstream fout;//->  ��������� ��'��� ����� fstream
	fout.open("base.TXT", ios::beg | ios::in);//-> ��������� ���� � ����� ����������� �� ����� ��� ���
	char str[128] = {};//-> ��������� ����� �������
	int wordNum = rand() % 99;//-> �������� ����� � ������� �� 0 �� 99
	for (int i = 1; i <= 99; i++)//-> ����������� ������ � ����� �������
	{
		char buff[128] = {};//->��������� �������� ����� �������
		fout.getline(buff, 128);//-> �������� ����� � ���� ���� ���
		if (i == wordNum) {//->
			if (i <= 1 && i >= 9) {//->
				strcpy_s(str, 128, buff + 2);//-> ���� �������� ����� ����� 10, �� ������� � ����� ������ ���� �����
			}
			else {
				strcpy_s(str, 128, buff + 3);//->���� �������� ����� ����� 10 ��� ����� 99, �� ������� � ����� ������ ���� �����
			}
			break;//->
		}
	}
	_strupr_s(str);//-> �������, ��� ������ �� ����� � ����� � ������ �����
	cout << str << endl;//->������ ������� ��� ����, ���� ������� ���

	fout.close();//-> ��������� �������� ����

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
	cout << "\n\t\t\t  ��� ²��� ��� \n\t\t\t   \"��������\"\n" << endl;
	cout << "\n��� ������������ � ��������� ����ز�� \"�������\" " << endl;
	cout << "\n��� ������� ��� ����ز�� \"�����\" \n";
	cout << "\n��� ������ ����ز�� \"��ղ�\"\n" << endl;
	gets_s(buff, 32);
	_strupr_s(buff);
	if (strcmp(buff, "�������") == 0) {
		Rules();
	}
	else if (strcmp(buff, "�����") == 0) {
		file();
	}
	else if (strcmp(buff, "��ղ�") == 0) {
		return 0;
	}
	else
		cout << "\n������� �� ��������. ������ �������� �������.\n";
	return 0;
};//������� ���� ���

void Bukva_out(char* slovo, bool* begin_game) {   // �������, �� �������� �����, �� �������
	for (int i = 0; i < strlen(slovo); i++) {
		if (begin_game[i] == 1) {
			cout << slovo[i] << " ";
		}
		else
			cout << " _ ";
	}
};

bool E_Bukva(char* slovo, char* bukva, bool* begin_game) { // �������, �� ������� �������� ����� � ����� �������
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
		cout << "   |    �" << endl;
		cout << "   |   /|\\ " << endl;
		cout << "   |   / \\" << endl;
		cout << "   |   " << endl;
		cout << "  =============" << endl << endl;
		break;

	case 1:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    �" << endl;
		cout << "   |   /|\\ " << endl;
		cout << "   |   / \\" << endl;
		cout << "   |  |``|  " << endl;
		cout << "  =============" << endl << endl;
		break;
	case 2:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    �" << endl;
		cout << "   |   /|\\ " << endl;
		cout << "   |     \\" << endl;
		cout << "   |  |``|      " << endl;
		cout << "  =============" << endl << endl;
		break;
	case 3:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    �" << endl;
		cout << "   |   /|\\ " << endl;
		cout << "   |       " << endl;
		cout << "   |  |``|          " << endl;
		cout << "  =============" << endl << endl;
		break;

	case 4:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    �" << endl;
		cout << "   |   /|" << endl;
		cout << "   |       " << endl;
		cout << "   |  |``|          " << endl;
		cout << "  =============" << endl << endl;
		break;

	case 5:
		cout << endl << endl;
		cout << "   +----+      " << endl;
		cout << "   |    | " << endl;
		cout << "   |    �" << endl;
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
};         //�������, �� ������ "��������" ���������� ��������

void Zagadka(char* str) {
	cout << "� ������� ����� �� " << strlen(str) << " ����(-�). ³������� ���� �� ���� ���� \n";
};

char* Litera(char* bukva) {
	cout << "\n������ �����: \n" << endl;
	cin >> bukva;
	if (strlen(bukva) <= 1) {
		return bukva;
	}
};




