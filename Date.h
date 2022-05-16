#pragma once
#include <string>

using namespace std;

class Date
{
private:
	class Triad
	{
	private:
		int first;
		int second;
		int third;
	public:
		Triad();
		Triad(int f, int s, int t);
		Triad(const Triad& t);


		int getFirst()const { return first; }
		int getSecond()const { return second; }
		int getThird()const { return third; }
		void setFirst(int value);
		void setSecond(int value);
		void setThird(int value);
		void Init(int f, int s, int t);
		void Read();
		void Display()const;
		void PlusFirst();
		void PlusSecond();
		void PlusThird();

		operator string() const;
		Triad& operator =(Triad& v);

		Triad& operator ++();
		Triad& operator --();
		Triad operator ++(int);
		Triad operator --(int);
	};
	Triad triad;

public:
	Date();
	Date(int f, int s, int t);
	Date(const Date& d);
	Triad getTriad()const { return triad; }

	int getDay()const { return triad.getFirst(); }
	int getMounth()const { return triad.getSecond(); }
	int getYear()const { return triad.getThird(); }

	void setTriad(Triad triad) { this->triad = triad; }

	void setDay(int value) { triad.setFirst(value); }
	void setMounth(int value) { triad.setSecond(value); }
	void setYear(int value) { triad.setThird(value); }

	bool Init(int d, int m, int y);
	void Read();
	void Display();

	void PlusDay();
	void PlusMounth();
	void PlusYear();

	void ChangeDays(int value);
	void Check();
	void MounthChanger(int value);
	void YearCheck();
	std::string toString()const;

	operator string() const;
	Date& operator=(Date& d);
	friend ostream& operator << (ostream& out, Date& t);
	friend istream& operator >> (istream& in, Date& t);

	Date& operator ++();
	Date& operator --();
	Date operator ++(int);
	Date operator --(int);
};

