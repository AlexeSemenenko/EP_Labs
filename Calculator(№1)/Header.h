#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
#include <Windows.h>
#include <sstream>

#define MAX 80

double expr(const char* str);				//���������� ���������
double term(const char* str, int& index);	//������ ��
double power(const char* str, int& index);	//���������� �������
double number(const char* str, int& index); //������������� �����
char* extract(const char* str, int& index); //���������� ���������
void BracketsBalance(const char* str);		// ������ ������