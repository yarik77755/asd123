#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
struct Computer {
	short size;
	int day;
	int month;
	int year;
	float prize;
};
int main()
{
	Computer AMD№1;
	AMD№1.size = 8;
	AMD№1.day = 24;
	AMD№1.month = 10;
	AMD№1.year = 2010;
	AMD№1.prize = 8569.5;

	Computer AMD№2;
	AMD№2 = { 4,13,3,2009,4599 };

	Computer AMD№3;
	AMD№3 = { 6,25,8,2011,6999 };
	if (AMD№1.prize < AMD№2.prize && AMD№1.prize < AMD№3.prize) {
		cout << "Producer -" << " AMD \n" << "Size of RAM - " << AMD№1.size << " Gb" << "\n" << "Release date - " << AMD№1.day << "." << AMD№1.month << "." << AMD№1.year << "\n" << "Prize -" << AMD№1.prize << "$" << endl;
	}
	else if(AMD№2.prize < AMD№1.prize && AMD№2.prize < AMD№3.prize){
		cout << "Producer -" << " AMD \n" << "Size of RAM - " << AMD№2.size << " Gb" << "\n" << "Release date - " << AMD№2.day << "." << AMD№2.month << "." << AMD№2.year << "\n" << "Prize -" << AMD№2.prize << "$" << endl;
	}
	else if (AMD№3.prize < AMD№2.prize && AMD№3.prize < AMD№1.prize) {
		cout << "Producer -" << " AMD \n" << "Size of RAM - " << AMD№3.size << " Gb" << "\n" << "Release date - " << AMD№3.day << "." << AMD№3.month << "." << AMD№3.year << "\n" << "Prize -" << AMD№3.prize << "$" << endl;
	}
	return 0;
}