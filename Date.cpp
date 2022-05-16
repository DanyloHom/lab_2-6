#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Date::Date()
{
	triad.setFirst(0);
	triad.setSecond(0);
	triad.setThird(0);
}

Date::Date(int f, int s, int t)
{
	setDay(f);
	setMounth(s);
	setYear(t);
}

Date::Date(const Date& d)
{
	setDay(d.getDay());
	setMounth(d.getMounth());
	setYear(d.getYear());
}

bool Date::Init(int d, int m, int y)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if (d > 0 && d <= 31) {
			setDay(d);
			setMounth(m);
			setYear(y);
			return true;
		}
	}

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d > 0 && d <= 30) {
			setDay(d);
			setMounth(m);
			setYear(y);
			return true;
		}
	}
	if (m == 2) {
		if (y % 4 == 0 || y % 100 == 0 || y % 400 == 0) {
			if (d > 0 && d <= 29)
				setDay(d);
			setMounth(m);
			setYear(y);
			return true;
		}
		else {
			if (d > 0 && d <= 28)
				setDay(d);
			setMounth(m);
			setYear(y);
			return true;
		}

	}
	else
		return false;
}

void Date::Read()
{
	int d = 0, m = 0, y = 0;

	do {
		cout << "enter day " << endl;
		cin >> d;
		cout << "enter mounth " << endl;
		cin >> m;
		cout << "enter year " << endl;
		cin >> y;
	} while (!Init(d, m, y));
}

void Date::Display()
{
	cout << endl;

	if (getDay() < 10 && getMounth() >= 10)
		cout << "date is : " << "0" << getDay() << "." << getMounth() << "." << getYear() << endl;

	if (getDay() < 10 && getMounth() < 10)
		cout << "date is : " << "0" << getDay() << "." << "0" << getMounth() << "." << getYear() << endl;

	if (getDay() >= 10 && getMounth() >= 10)
		cout << "date is : " << getDay() << "." << getMounth() << "." << getYear() << endl;

	if (getDay() >= 10 && getMounth() < 10)
		cout << "date is : " << getDay() << "." << "0" << getMounth() << "." << getYear() << endl;

	cout << endl;
}

void Date::PlusDay()
{
	triad.PlusFirst();
	Check();
}

void Date::PlusMounth()
{
	triad.PlusSecond();
	Check();
}

void Date::PlusYear()
{
	triad.PlusThird();
	Check();
}

void Date::ChangeDays(int value)
{
	setDay(getDay() + value);
	Check();
}

void Date::Check()
{
	int d = getDay();
	int m = getMounth();
	int y = getYear();

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		int count = 31;
		if (d > count)
			MounthChanger(count);
	}

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		int count = 30;
		if (d > count)
			MounthChanger(count);
	}

	if (m == 2) {
		if (y % 4 == 0 || y % 100 == 0 || y % 400 == 0) {
			int count = 29;
			if (d > count)
				MounthChanger(count);
		}
		else {
			int count = 28;
			if (d > count)
				MounthChanger(count);
		}
	}

}

void Date::MounthChanger(int value)
{
	setDay(getDay() - value);
	setMounth(getMounth() + 1);
	YearCheck();
	return Check();
}

void Date::YearCheck()
{
	if (getMounth() > 12) {
		setYear(getYear() + 1);
		setMounth(getMounth() - 12);
	}
}

string Date::toString() const
{
	stringstream sout;

	if (getDay() < 10 && getMounth() >= 10)
		sout << "0" << getDay() << "." << getMounth() << "." << getYear() << endl;

	if (getDay() < 10 && getMounth() < 10)
		sout << "0" << getDay() << "." << "0" << getMounth() << "." << getYear() << endl;

	if (getDay() >= 10 && getMounth() >= 10)
		sout << getDay() << "." << getMounth() << "." << getYear() << endl;

	if (getDay() >= 10 && getMounth() < 10)
		sout << getDay() << "." << "0" << getMounth() << "." << getYear() << endl;

	return sout.str();
}

Date::operator string() const
{
	stringstream sout;

	if (getDay() < 10 && getMounth() >= 10)
		sout << "0" << getDay() << "." << getMounth() << "." << getYear() << endl;

	if (getDay() < 10 && getMounth() < 10)
		sout << "0" << getDay() << "." << "0" << getMounth() << "." << getYear() << endl;

	if (getDay() >= 10 && getMounth() >= 10)
		sout << getDay() << "." << getMounth() << "." << getYear() << endl;

	if (getDay() >= 10 && getMounth() < 10)
		sout << getDay() << "." << "0" << getMounth() << "." << getYear() << endl;

	return sout.str();
}

Date& Date::operator=(Date& d)
{
	triad = d.triad;
	return *this;
}

Date& Date::operator++()
{
	triad++;
	return *this;
}

Date& Date::operator--()
{
	triad--;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	triad++;
	return tmp;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	triad--;
	return tmp;
}



ostream& operator<<(ostream& out, Date& t)
{
	out << string(t);
	return out;
}

istream& operator>>(istream& in, Date& t)
{
	int d, m, y;
	cout << "enter day " << endl;
	in >> d;
	cout << "enter mounth " << endl;
	in >> m;
	cout << "enter year " << endl;
	in >> y;

	t.setDay(d);
	t.setMounth(m);
	t.setYear(y);

	return in;
}


Date::Triad::Triad()
{
	first = second = third = 0;
}

Date::Triad::Triad(int f, int s, int t)
{
	first = f;
	second = s;
	third = t;
}

Date::Triad::Triad(const Triad& t)
{
	first = t.first;
	second = t.second;
	third = t.third;
}

void Date::Triad::setFirst(int value)
{
	first = value;
}

void Date::Triad::setSecond(int value)
{
	second = value;

}

void Date::Triad::setThird(int value)
{
	third = value;
}

void Date::Triad::Init(int f, int s, int t)
{
	setFirst(f);
	setSecond(s);
	setThird(t);
}

void Date::Triad::Read()
{
	int f, s, t;
	cout << "enter first " << endl;
	cin >> f;
	cout << "enter second " << endl;
	cin >> s;
	cout << "enter third " << endl;
	cin >> t;
	Init(f, s, t);
}

void Date::Triad::Display() const
{
	cout << "first = " << first << endl;
	cout << "second = " << second << endl;
	cout << "third = " << third << endl;
}

void Date::Triad::PlusFirst()
{
	first++;
}

void Date::Triad::PlusSecond()
{
	second++;
}

void Date::Triad::PlusThird()
{
	third++;
}


Date::Triad::operator string() const
{
	stringstream ss;

	ss << "first = " << first << "second = " << second << "third = " << third;

	return ss.str();

}

Date::Triad& Date::Triad::operator=(Date::Triad& t)
{
	first = t.first;
	second = t.second;
	third = t.third;

	return *this;
}

Date::Triad& Date::Triad::operator++()
{
	++first;
	++second;
	++third;

	return *this;
}

Date::Triad& Date::Triad::operator--()
{
	--first;
	--second;
	--third;

	return *this;
}

Date::Triad Date::Triad::operator++(int)
{
	Triad tmp(*this);
	first++;
	second++;
	third++;

	return tmp;
}

Date::Triad Date::Triad::operator--(int)
{
	Triad tmp(*this);
	first--;
	second--;
	third--;

	return tmp;
}


