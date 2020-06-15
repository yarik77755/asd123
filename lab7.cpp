#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
struct element {
	int h;
	element *Next;
};
class List
{
public:
	element * Head;
	List() { Head = NULL; }
	~List() {
		while (Head != NULL) {
			element *temp = Head->Next;
			delete Head;
			Head = temp;
		}
	};
	void push(int a);
	void Show();
	void sum();
	void pop();
};
void List::push(int a) {
	element *temp = new element;
	temp->h = a;
	temp->Next = Head;
	Head = temp;
	cout << "add:" << a << endl;
}
void List::Show() {
	element *temp = Head;
	while (temp != NULL) {
		cout << temp->h << endl;
		temp = temp->Next;
	}
}
void List::pop() {
	if (Head != NULL) {
		element *temp = Head;
		cout << "Element:" << Head->h << " delete" << endl;
		Head = Head->Next;
		delete temp;
	}
}
void List::sum() {
	int s = 0;
	element *temp = Head;
	while (temp != NULL) {
		s += temp->h;
		temp = temp->Next;
	}
	cout << "sum:" << s << endl;
}
int main() {
	List l;
	for (int i = 0; i < 5; i++)
		l.push(i + 1);
	l.Show();
	for (int i = 0; i < 3; i++)
		l.pop();
	l.Show();
	l.sum();
	return 0;
};