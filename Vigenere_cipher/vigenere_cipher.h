
// vigenere_cipher.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CvigenerecipherApp:
// Сведения о реализации этого класса: vigenere_cipher.cpp
//

class CvigenerecipherApp : public CWinApp
{
public:
	CvigenerecipherApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CvigenerecipherApp theApp;
