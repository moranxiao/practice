#pragma warning(disable:4996)
#include <iostream>

class date
{
public:
	date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator==(const date& d)
	{
		return _year == d._day
			&& _month == d._month
			&& _day == d._day;
	}
	int GetMonth(int year, int month)
	{
		static int arr[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return arr[month];
		}
	}
	date operator+=(int d)
	{
		_day += d;
		int day = GetMonth(_year, _month);
		while (_day > day)
		{
			_day -= day;
			_month++;
			if (_month > 12)
			{
				_year++;
				_month -= 12;
			}
			day = GetMonth(_year, _month);
		}
		return *this;
	}
	date operator+(int d)
	{
		date ret(*this);
		ret._day += d;
		int day = GetMonth(_year, _month);
		while (ret._day > day)
		{
			ret._day -= day;
			ret._month++;
			if (ret._month > 12)
			{
				ret._year++;
				ret._month -= 12;
			}
			day = GetMonth(ret._year, ret._month);
		}
		return ret;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	date d1(2022,9,19);
	d1 += 100;
	return 0;
}