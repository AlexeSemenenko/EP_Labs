#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <iostream>
#include <cmath>
#include <Windows.h>
#include <sstream>

#define MAX_SIZE 44

bool isSeparator(char c);
double calc(const char* str);