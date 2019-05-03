#include "concerts.h"

void concert::get_info(std::string info)
{
	auto pos = 0;
	std::string subs[4];

	for (auto i = 0; i < 3; i++)
	{
		pos = info.find(';');
		subs[i] = info.substr(0, pos);
		info.erase(0, pos + 1);
	}
	subs[3] = info;

	name = subs[0];
	capacity = std::stol(subs[1]);
	left = std::stol(subs[2]);
	std::stringstream ss(subs[3]);
	ss >> std::get_time(&date, "%Y-%m-%d %H:%M");
}

void concerts_list::add_concert(std::string info)
{
	concert buf{};
	buf.get_info(info);
	list_.push_back(buf);
}

std::ostream& operator<<(std::ostream& out, const concerts_list& l1)
{
	for (auto const& l : l1.list_)
	{
		out << l.name << ";" << l.capacity << ";" << l.left << ";" 
			<< std::put_time(&l.date, "%Y-%m-%d %H:%M") << std::endl;
	}

	return out;
}

std::istream& operator>>(std::istream& in, concerts_list& l1)
{
	std::string str;
	std::getline(in, str);

	auto pos = 0;
	std::string subs[4];

	for (auto i = 0; i < 3; i++)
	{
		pos = str.find(';');
		subs[i] = str.substr(0, pos);
		str.erase(0, pos + 1);
	}
	subs[3] = str;

	concert c;
	c.name = subs[0];
	c.capacity = std::stol(subs[1]);
	c.left = std::stol(subs[2]);
	std::stringstream ss(subs[3]);
	ss >> std::get_time(&c.date, "%Y-%m-%d %H:%M");

	l1.list_.push_back(c);

	return in;
}

int concerts_list::get_concert_amount() const
{
	return	list_.size();
}

concert& concerts_list::operator[](const int index)
{
	if (index >= list_.size() || index < 0)
		throw std::out_of_range("The index is not included in the values area");

	return list_[index];
}

bool concerts_list::book_ticket(const int index)
{
	if (list_[index].left == 0)
	{
		return false;
	}
	list_[index].left--;
	return true;
}

std::vector<concert>::iterator concerts_list::begin()
{
	return list_.begin();
}

std::vector<concert>::iterator concerts_list::end()
{
	return list_.end();
}

void concerts_list::sort_by_name()
{
	std::sort(list_.begin(), list_.end(), [](concert const& c1, concert const& c2) -> bool
	{
		return c1.name < c2.name;
	});
}

void concerts_list::sort_by_date()
{
	std::sort(list_.begin(), list_.end(), [](concert c1, concert c2) -> bool
	{
		return mktime(&c1.date) < mktime(&c2.date);
	});
}

std::vector<concert>concerts_list::find_first_name(std::string const& c_name)
{
	std::vector<concert>::iterator temp = std::find_if(list_.begin(), list_.end(), [&c_name](concert const& c)
	{
		int len1 = c.name.length(), len2 = c_name.length();
		int min_len = len1 <= len2 ? len1 : len2;

		return c.name.substr(0, min_len) == c_name.substr(0, min_len);
	});

	std::vector<concert> found_concerts;

	while (temp != list_.end())
	{
		found_concerts.push_back(*temp);

		temp = std::find_if(++temp, list_.end(), [&c_name](concert const& c)
		{
			int len1 = c.name.length(), len2 = c_name.length();
			int min_len = len1 <= len2 ? len1 : len2;

			return c.name.substr(0, min_len) == c_name.substr(0, min_len);
		});
	}

	return found_concerts;
}

std::vector<concert> concerts_list::find_first_date_between(tm const& date1, tm const& date2)
{
	tm d1 = date1, d2 = date2;

	std::vector<concert>::iterator temp = std::find_if(list_.begin(), list_.end(), [&d1, &d2](concert & c)
	{
		return (mktime(&d1) <= mktime(&c.date)) && (mktime(&c.date) <= mktime(&d2));
	});

	std::vector<concert> found_concerts;

	while (temp != list_.end())
	{
		found_concerts.push_back(*temp);

		temp = std::find_if(++temp, list_.end(), [&d1, &d2](concert & c)
		{
			return (mktime(&d1) <= mktime(&c.date)) && (mktime(&c.date) <= mktime(&d2));
		});
	}

	return found_concerts;
}