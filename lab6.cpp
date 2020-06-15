#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Monitor
{
	string name;
	double ggz;
	int cost;
};

void Init(Monitor *arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Input name of manufacturer: ";
		cin >> arr[i].name;
		cout << "Input diagonal: ";
		cin >> arr[i].ggz; cin.ignore();
		cout << "Input price: ";
		cin >> arr[i].cost; cin.ignore();
		system("cls");

		
	}
}

void Print(Monitor *arr, const int n)
{
	cout << "\nList: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Manufacturer:	" << arr[i].name << "\nDiagonal:	" << arr[i].ggz << "\nPrice:	" << arr[i].cost;
	}
	cout << endl << endl;
}

void Search(Monitor *arr, const int n)
{
	system("cls");
	cout << "Monitors from Samsung and diagonal bigger than 32:"<<endl;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].name == "Samsung" && arr[i].ggz > 32 /* arr[i].name == "samsung"*/)
		{
			cout << "Manufacturer:	" + arr[i].name <<endl<< "Diagonal:	" << arr[i].ggz <<endl<< "Price:	" << arr[i].cost<<endl;
		}
			
	}
	cout << endl << endl;
}

void Write(Monitor *arr, const int n)
{
	ofstream file("file.txt", ios::binary | ios::in);
	for (int i = 0; i < n; i++)
	{
		file.write((char*)&arr[i].name, sizeof arr[i].name);
		file.write((char*)&arr[i].ggz, sizeof arr[i].ggz);
		file.write((char*)&arr[i].cost, sizeof arr[i].cost);
	}
	file.close();
}

int main()
{
	int n;
	cout << "Input number of computers:";
	cin >> n;
	if (n <= 0)
	{
		cout << "Error";
		return 0;
	}
	Monitor *arr = new Monitor[n];
	Init(arr, n);
	Print(arr, n);
	Write(arr, n);
	Search(arr, n);
	delete[] arr;
	return 0;
}