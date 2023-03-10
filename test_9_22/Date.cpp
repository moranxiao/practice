#pragma warning(disable:4996)
#include "Date.h"

Date::Date(int year, int month, int day)
	:_year(year),
	_month(month),
	_day(day)
{
	_year = year;
	_day = day;
	_month = month;
}
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

bool Date::operator>=(const Date& d)const
{
	return *this > d || *this == d;
}
bool Date::operator<(const Date& d)const
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}


bool Date::operator==(const Date& d)const
{
	return (_year == d._year)
		&& (_month == d._month)
		&& (_day == d._day);
}
bool Date::operator>(const Date& d)const
{
	if (_year >= d._year)
	{
		if(_year > d._year)
			return true;
		else if(_year == d._year
			&& _month >= d._month)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month
				&& _day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	if (&d == this)
		return *this;
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= (-day);
		return *this;
	}
	_day += day;
	day = GetDayOfMonth(_year, _month);
	while (_day > day)
	{
		_day -= day;
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
		day = GetDayOfMonth(_year, _month);
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date ret = *this;
	return ret += day;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += (-day);
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		day = GetDayOfMonth(_year, _month);
		_day += day;
	}
	return *this;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp = *this;
	++*this;
	return tmp;
}

int Date::operator-(Date& d)
{
	int n = 0;
	if (*this > d)
	{
		while (*this != d)
		{
			d++;
			n++;
		}
	}
	else
	{
		while (*this != d)
		{
			d -= 1;
			n--;
		}
	}
	return n;
}

ostream& operator<<(ostream& out,const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}