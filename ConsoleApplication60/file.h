#pragma once


void Rules();// �������, �� ����� ������� ���

bool menu();//������� ���� ���

void Bukva_out(char* slovo, bool* begin_game);  // �������, �� �������� �����, �� �������

bool E_Bukva(char* slovo, char* bukva, bool* begin_game); // �������, �� ������� �������� ����� � ����� �������

void Errors(int errors); //�������, �� ������ "��������" ���������� ��������

void Zagadka(char* str);// ������ �������, �� �������� �� ����� ������� ���� � ����, �� �������� ��������

char* Litera(char* bukva);// ������� ������ �����

void Floop(char bukva[], char* slovo, bool* begin_game, int won, int errors); //������� ����� ���

void file(); //�������, �� ������ � ������, � ����� ������� ������ ���� ��������


