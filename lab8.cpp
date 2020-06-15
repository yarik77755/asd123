#include "pch.h"
#include <iostream>
#include<cmath>

using namespace std;

struct m_Node { //элемента списка
	int data;
	m_Node *next;
	m_Node *prev;
};

class MList {
	int size;
	m_Node *head;
	m_Node *tail;

	m_Node *get(int index) { //получаем i элемент списка
		m_Node *temp = head;
		for (int i = 0; i < size && i < index; ++i) {
			temp = temp->next;
			i++;
		}
		return temp;
	}
public:
	MList() { //конструктор
		head = tail = 0;
		size = 0;
	}
	void Add(const int &data) { //добавление в конец списка
		m_Node *temp = new m_Node;
		temp->data = data;
		temp->next = 0;
		temp->prev = tail;
		if (tail) {
			tail->next = temp;
		}
		tail = temp;
		if (head == 0) {
			head = temp;
		}
		++size;
	}

	int & operator[](int index) { //получение i элемента
		m_Node *temp = head;
		for (int i = 0; i < size && i < index; ++i) {
			temp = temp->next;
		}
		return temp->data;
	}

	int Delete(int index) { //удаление i элемента
		m_Node *temp = get(index);
		if (temp->prev) {
			temp->prev->next = temp->next;
		}
		if (temp->next) {
			temp->next->prev = temp->prev;
		}
		int data = temp->data;

		if (!temp->prev) {
			head = temp->next;
		}
		if (!temp->next) {
			tail = temp->prev;
		}
		delete temp;
		--size;
		return data;
	}

	int size_() { return size; }
	~MList() { //деструктор
		for (int i = 0; i < size; ++i) {
			m_Node* temp = head;
			head = head->next;
			delete temp;
		}
		size = 0;
	}
};

int main() {

	MList mq;
	mq.Add(5);
	mq.Add(1);
	mq.Add(6);
	mq.Add(3);
	mq.Add(4);
	cout << "list = ";
	for (int i = 0; i < mq.size_(); ++i) {
		cout << mq[i] << ' ';
	}
	cout << "\nDelete a list = ";
	for (int i = 0; i < mq.size_(); ++i) {
		if (abs(mq[i]) < 5) {
			mq.Delete(i);
		}
	}
	for (int i = 0; i < mq.size_(); ++i) {
		cout << mq[i] << ' ';
	}
	cout << '\n';
	return 0;
}