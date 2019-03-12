#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <iostream>
#include <cmath>
#include <Windows.h>
#include <sstream>

#define MAX_SIZE 44

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define ZERO 10
#define DIV 11
#define MUL 12
#define MINUS 13
#define PLUS 14
#define DELETE 15
#define EQUALLY 16
#define POINT 17
#define DEG 20
#define DELETE_ALL 21
#define DENIAL 22
#define AND 23
#define OR 24
#define XOR 25
#define LEFT 26
#define RIGHT 27
#define FACTORIAL 28
#define SQRT 29
#define BIN 30

bool isSeparator(char c);
double calc(const char* str);