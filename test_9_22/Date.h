#pragma once
#include <iostream>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out,const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 2000, int month = 1, int day = 1);
	Date(const Date& d);
	int GetDayOfMonth(int year,int month)
	{
		static int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if(month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return day[month];
	}
	bool operator==(const  Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator>(const Date& d)const;
	bool operator!=(const Date& d)const;
	Date& operator+=(int day);
	Date& operator=(const Date& d);
	Date operator+(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(Date& d);
	Date& operator++();
	Date operator++(int);

private:
	int _year;
	int _month;
	int _day;
};