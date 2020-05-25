#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int count=0;
	int max = 0;
	char const N = 10;
	char arr[] = {1,2,'l',4,'y','u',9,9,0,'s'};
	for (int i = 0; i < N; i++) {
		if (arr[i] >=0&&arr[i]<=9 ) {
			count++;
			if (max < count) {
				max = count;
			}
		}
		else {
			count = 0;

		}
	}
	cout<<"max digital sequence length is "<<max<<endl;
	return max;
}
