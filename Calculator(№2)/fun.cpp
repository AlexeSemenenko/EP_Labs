#include "header.h" 

double calc(const char* str)
{
	int i = 0;
	double result = 0;
	int j = 0;
	int k = 0;
	double f = 0;
	double s = 0;
	int fd = 0;
	int sd = 0;
	char first[MAX_SIZE] = "", second[MAX_SIZE] = "", op[2] = "";

	while (!isSeparator(str[i]))
	{
		first[j] = str[i];
		i++;
		j++;
	}

	op[0] = str[i];
	i++;

	while (str[i] != '\0')
	{
		second[k] = str[i];
		i++;
		k++;
	}

	for (int i = 0; i < std::size(first); i++)
	{
		if (first[i] == '.')
			fd = 1;
		if (fd == 1)
			break;
	}

	for (int i = 0; i < std::size(second); i++)
	{
		if (second[i] == '.')
			sd = 1;
		if (sd == 1)
			break;
	}

	f = atof(first);
	s = atof(second);

	switch (op[0])
	{
	case '+':
		result = f + s;
		break;
	case '-':
		result = f - s;
		break;
	case '*':
		result = f * s;
		break;
	case '/':
		if (s != 0)
			result = f / s;
		else
			throw std::exception("Error! Division by zero.");
		break;
	case '^':
		if (f != 0 && s != 0)
			result = pow(f, s);
		if (f == 0 && s == 0)
			result = 1;
		break;
	case 'X':
		if (fd == 1 || sd == 1)
			throw std::exception("Error! This operation does not apply to fractional numbers.");
		else
		{
			int fi = 0, si = 0;
			fi = static_cast<int>(f);
			si = static_cast<int>(s);
			result = fi ^ si;
		}
		break;
	case '|':
		if (fd == 1 || sd == 1)
			throw std::exception("Error! This operation does not apply to fractional numbers.");
		else
		{
			int fi = 0, si = 0;
			fi = static_cast<int>(f);
			si = static_cast<int>(s);
			result = fi | si;
		}
		break;
	case '&':
		if (fd == 1 || sd == 1)
			throw std::exception("Error! This operation does not apply to fractional numbers.");
		else
		{
			int fi = 0, si = 0;
			fi = static_cast<int>(f);
			si = static_cast<int>(s);
			result = fi & si;
		}
		break;
	case '>':
		if (fd == 1 || sd == 1)
			throw std::exception("Error! This operation does not apply to fractional numbers.");
		else
		{
			int fi = 0, si = 0;
			fi = static_cast<int>(f);
			si = static_cast<int>(s);
			result = fi >> si;
		}
		break;
	case '<':
		if (fd == 1 || sd == 1)
			throw std::exception("Error! This operation does not apply to fractional numbers.");
		else
		{
			int fi = 0, si = 0;
			fi = static_cast<int>(f);
			si = static_cast<int>(s);
			result = fi << si;
		}
		break;
	case '~':
		if (sd == 1)
			throw std::exception("Error! This operation does not apply to fractional numbers.");
		else
		{
			int si = 0;
			si = static_cast<int>(s);
			result = (~si) & 0x0007;
//			result = ~fi;
		}
		break;
	case '!':
		if (fd == 1)
			throw std::exception("Error! This operation does not apply to fractional numbers.");
		else
		{
			int fac = 1;
			int fi = 0;
			fi = static_cast<int>(f);
			for (int i = 1; i <= fi; i++)
				fac *= i;
			result = static_cast<double>(fac);
		}
		break;
	case '?':
		result = sqrt(s);
		break;
	default:
		break;;
	}

	return result;
}

bool isSeparator(char c)
{
	char separator[] = { "+,-,*,/,X,|,<,>,&,^,~,!,?" };
	int i = 0;

	while (separator[i] != '\0')
	{
		if (c == separator[i])
			return true;
		i++;
	}
	return false;
}