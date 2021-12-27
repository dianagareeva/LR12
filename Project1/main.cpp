#include "Header.h"
#include <conio.h>
#include<iostream>

using namespace std;

template <typename T>
Stack<T>::Stack() {}

template <typename T>
Stack<T>::Stack(T a)
{
	tail = new Node<T>;
	tail->prev = nullptr;
	tail->next = nullptr;
	tail->a = a;
	count = 0;

}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete tail;
	delete next;
	tail = other.tail;
	other.tail = nullptr;
}

template <typename T>
int Stack<T>::GetSize() const
{
	return count;
}

template <typename T>
void Stack<T>::Push(const T a)
{
	Node<T>* newnode = new Node<T>;
	Node<T>* checking = next;
	if (HasElements())
	{
		while (checking->next != nullptr)
		{
			checking = checking->next;
		}
		next = newnode;
		tail->prev = nullptr;
	}
	else
	{
		tail = newnode;
		next = newnode;
	}
	newnode->a = a;
	newnode->prev = checking;
	newnode->next = nullptr;
	count = count + 1;
}

template <typename T>
void Stack<T>::Pop(T& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	a = next->a;
	if (next != tail)
	{
		next = next->prev;
		next->next = nullptr;
	}
	else
	{
		next = tail = nullptr;
	}
	count = count - 1;
}

template <typename T>
void Stack<T>::Peek(T& a)
{
	if (!HasElements()) { throw NoElementsException("Stack is Empty!"); };
	a = next->a;
}

template <typename T>
bool Stack<T>::HasElements() const
{
	if (this->tail != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Stack<double> a;
	double b;
	bool flag = true;
	while (flag)
	{
		cout << "1. �������� ������� � ����\n";
		cout << "2. �������� ������� �� �����\n";
		cout << "3. ���������� ������� �� �����\n";
		cout << "4. ����� �����\n";
		cout << "5. �����\n";
		switch (_getch()) 
		{
			case '1':
				cout << "�������� �������: ";
				cin >> b;
				a.Push(b);
				break;
			case '2':
				try
				{
					a.Pop(b);
					cout << "���������� ������� " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "���� ����\n";
				}
				break;
			case '3':
				try
				{
					a.Peek(b);
					cout << "��������� ������� " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "���� ����\n";
				}
				break;
			case '4':
				b = a.GetSize();
				cout << "����� �����: " << b << endl;
				break;
			case '5':
				flag = false;
				break;

		}
	}

}