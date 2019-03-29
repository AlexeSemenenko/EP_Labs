#include "stdafx.h"
#include "cipher.h"
#include <cctype>

void create_square(std::string square[27][27])
{
	square[0][0] = "0";
	char symbol = 'a', alf[26];

	for (auto i = 1; i < 27; i++, symbol++)
	{
		square[i][0] = symbol;
		square[0][i] = symbol;
	}

	symbol = 'a';
	for (auto i = 0; i < 26; symbol++, i++)
	{
		alf[i] = symbol;
	}

	for (auto i = 1; i < 27; i++)
	{
		auto k = i - 1;
		for (auto j = 1; j < 27; j++)
		{
			square[i][j] = alf[k];
			if (alf[k] == 'z')
				k = -1;
			k++;
		}
	}
}

std::string create_key(std::string to_encrypt, std::string keyword)
{
	std::string key;
	for (auto i = 0, j = 0; i < to_encrypt.size(); i++, j++)
	{
		if (to_encrypt[i] == ' ' || to_encrypt[i] == '.' || to_encrypt[i] == ',' || to_encrypt[i] == '!' || to_encrypt[i] == '?' || to_encrypt[i] == '(' || to_encrypt[i] == ')'
			|| to_encrypt[i] == '1' || to_encrypt[i] == '2' || to_encrypt[i] == '3' || to_encrypt[i] == '4' || to_encrypt[i] == '5' || to_encrypt[i] == '6' || to_encrypt[i] == '7'
			|| to_encrypt[i] == '8' || to_encrypt[i] == '9' || to_encrypt[i] == '0' || to_encrypt[i] == ':' || to_encrypt[i] == ';' || to_encrypt[i] == '<' || to_encrypt[i] == '>'
			|| to_encrypt[i] == '~' || to_encrypt[i] == '`' || to_encrypt[i] == '@' || to_encrypt[i] == '"' || to_encrypt[i] == '*' || to_encrypt[i] == '&' || to_encrypt[i] == '%'
			|| to_encrypt[i] == '[' || to_encrypt[i] == ']' || to_encrypt[i] == '{' || to_encrypt[i] == '}' || to_encrypt[i] == '+' || to_encrypt[i] == '-' || to_encrypt[i] == '%'
			|| to_encrypt[i] == '^' || to_encrypt[i] == '#' || to_encrypt[i] == '¹' || to_encrypt[i] == '/' || to_encrypt[i] == '\'' || to_encrypt[i] == '\\' || to_encrypt[i] == '|')
		{
			key += to_encrypt[i];
			j--;
		}
		else
			key += keyword[j];

		if (j == keyword.size() - 1)
			j = -1;
	}

	key += '\0';
	return key;
}

std::string encrypt(std::string to_encrypt, std::string key, std::string square[27][27])
{
	std::string res = {};
	auto x = 0, y = 0;
	bool flag = true;
	for (auto i = 0; i < key.size() - 1; i++)
	{
		if (to_encrypt[i] == ' ' || to_encrypt[i] == '.' || to_encrypt[i] == ',' || to_encrypt[i] == '!' || to_encrypt[i] == '?' || to_encrypt[i] == '(' || to_encrypt[i] == ')'
			|| to_encrypt[i] == '1' || to_encrypt[i] == '2' || to_encrypt[i] == '3' || to_encrypt[i] == '4' || to_encrypt[i] == '5' || to_encrypt[i] == '6' || to_encrypt[i] == '7'
			|| to_encrypt[i] == '8' || to_encrypt[i] == '9' || to_encrypt[i] == '0' || to_encrypt[i] == ':' || to_encrypt[i] == ';' || to_encrypt[i] == '<' || to_encrypt[i] == '>'
			|| to_encrypt[i] == '~' || to_encrypt[i] == '`' || to_encrypt[i] == '@' || to_encrypt[i] == '"' || to_encrypt[i] == '*' || to_encrypt[i] == '&' || to_encrypt[i] == '%'
			|| to_encrypt[i] == '[' || to_encrypt[i] == ']' || to_encrypt[i] == '{' || to_encrypt[i] == '}' || to_encrypt[i] == '+' || to_encrypt[i] == '-' || to_encrypt[i] == '%'
			|| to_encrypt[i] == '^' || to_encrypt[i] == '#' || to_encrypt[i] == '¹' || to_encrypt[i] == '/' || to_encrypt[i] == '\'' || to_encrypt[i] == '\\' || to_encrypt[i] == '|')
		{
			res += to_encrypt[i];
		}
		else
		{
			if (std::isupper(to_encrypt[i]))
			{
				to_encrypt[i] = std::tolower(to_encrypt[i]);
				flag = false;
			}

			for (auto j = 1; j < 27; j++)
			{
				if (key[i] == square[0][j][0])
					x = j;
				if (to_encrypt[i] == square[0][j][0])
					y = j;
			}

			if (!flag)
			{
				res += std::toupper(square[x][y][0]);
				flag = true;
			}
			else
				res += square[x][y][0];
		}
	}
	res += '\0';

	return res;
}