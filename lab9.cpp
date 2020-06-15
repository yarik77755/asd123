#include "pch.h"
#include <iostream>
using namespace std;
struct time {
	int ms, s, m, h;
}T;
int main()
{
	int msec, sec, min, hour,helphour;
	cout << "read msec:";
	cin >> msec;
	cout << "read sec:";
	cin >> sec;
	cout << "read min:";
	cin >> min;
	cout << "read hour:";
	cin >> hour;
	if (hour < 0 || hour >24)
	{
		cout << "read hour:"<<endl;
		cin >> hour;
	}
	
	
	T.ms = msec % 60;
	T.s = sec % 60 + msec / 60;
	T.m = min % 60 + sec / 60;
	helphour = min / 60;
	T.h = hour+helphour;
	cout << "Time >>" << T.h << ":" << T.m << ":" << T.s << ":" << T.ms << endl<<endl;

	cout << "Enter your date and i say its leap year or not" << endl;

	int year,month,day;

	cout << "Read year:";
	
	cin >> year;
	if (year < 0)
	{
		cout << "Read year:";

		cin >> year;
	}

	cout << "Read month:";

	cin >> month;
	if (month < 0 || month >12)
	{
		cout << "Read month:";

		cin >> month;
	}
	cout << "Read day:";

	cin >> day;

	if (day < 1 || month >31)
	{
		cout << "Read day:";

		cin >> day;
	}

	if (year % 4 == 0)
		cout << "This Leap year!\n";
	else
		cout << "For next leap year:" << year % 4;

}