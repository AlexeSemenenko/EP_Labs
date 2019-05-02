#pragma once

#include <iostream>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <Windows.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

constexpr int MAX = 50;

struct concert
{
	std::string name;
	int left{};
	int capacity{};
	tm date{};
};

class concerts_list
{
public:
	using vector_t = std::vector<concert>;
	vector_t list_;

	using iterator = vector_t::iterator;
	concerts_list() = default;
	concerts_list(concerts_list const&) = delete;
	concerts_list(concerts_list&&) = delete;
	int get_concert_amount() const;
	concert& operator[](const int index);
	bool book_ticket(const int index);
	void sort_by_name();
	void sort_by_date();
	std::vector<concert>::iterator begin();
	std::vector<concert>::iterator end();
	std::vector<concert>::iterator find_first_name(std::string const&);
	std::vector<concert>::iterator find_first_date_between(tm const& date1, tm const& date2);

	friend std::istream& operator>>(std::istream& in, concerts_list& l1);
	friend std::ostream& operator<<(std::ostream& out, const concerts_list& l1);
};