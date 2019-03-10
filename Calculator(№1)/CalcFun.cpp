#include "Header.h" 

void BracketsBalance(const char* str)
{
	int r_bracket = 0, l_bracket = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
			l_bracket++;
		if (str[i] == ')')
			r_bracket++;
	}

	if (l_bracket != r_bracket)
		throw std::exception("Error! Incorrect number of brackets.");
}

double expr(const char* str)
{
	BracketsBalance(str);
	int index = 0;
	double value = term(str, index);
	for (; ; )
	{
		switch (*(str + index++))
		{
		case '\0':
			return value;
		case '+':
			value += term(str, index);
			break;
		case '-':
			value -= term(str, index);
			break;
		default:
			break;
		}
	}
}

double term(const char* str, int& index)
{
	double value = power(str, index);

	while ((*(str + index) == '*') || (*(str + index) == '/'))
	{
		if (*(str + index) == '*')
			value *= power(str, ++index);
		if (*(str + index) == '/')
		{
			double divider = power(str, ++index);

			if (divider == 0)
				throw std::exception("Error! Division by zero.");

			value /= divider;
		}
	}
	return value;
}

double power(const char* str, int& index)
{
	double value = number(str, index);
	while (*(str + index) == '^')
	{
		value = pow(value, number(str, ++index));
	}
	return value;
}

double number(const char* str, int& index)
{
	double value = 0.0;
	if (*(str + index) == '(')
	{
		char* p_substr;
		p_substr = extract(str, ++index);
		value = expr(p_substr);
		delete[] p_substr;
		return value;
	}

	while (isdigit(*(str + index)))
		value = 10 * value + (*(str + index++) - '0');
	if (*(str + index) != '.')
		return value;
	double factor = 1.0;

	while (isdigit(*(str + (++index))))
	{
		factor *= 0.1;
		value = value + (*(str + index) - '0')* factor;
	}
	return value;
}

char* extract(const char* str, int& index)
{
	char buffer[MAX];
	char* p_str;
	int numL = 0;
	int buf_index = index;
	do
	{
		buffer[index - buf_index] = *(str + index);
		switch (buffer[index - buf_index])
		{
		case ')':
			if (numL == 0)
			{
				buffer[index - buf_index] = '\0';
				++index;
				p_str = new char[index - buf_index];
				if (!p_str)
				{
					return nullptr;
				}
				strcpy_s(p_str, index - buf_index, buffer);

				return p_str;
			}
			else
				numL--;
			break;
		case '(':
			numL++;
			break;
		}
	} while (*(str + index++) != '\0');

	return nullptr;
}