#include<iostream>
#include "Date.h"
#include "Date.h"
#include <string>


using namespace std;

int main()
{
	int d;
	Date a(1, 1, 1);
	cout << a << endl;

	cout << "b = a" << endl;
	Date b = a;
	cout << b << endl;

	cout << "enter amount of days + b " << endl;
	cin >> d;

	b.ChangeDays(d);
	cout << b << endl;

	cout << "b++" << endl;
	b++;
	cout << b << endl;

	cout << "b--" << endl;
	b--;
	cout << b << endl;

	cout << "++b" << endl;
	++b;
	cout << b << endl;

	cout << "--b" << endl;
	--b;
	cout << b << endl;


}