#pragma once
#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T content;
	Node<T> *next;
};
template<class T>
class vector_
{
public:
	int number;
	Node<T> *first;
	vector_()
	{
		number = 0;
		first = new Node<T>;
	}
	void push_back(T a)
	{
		Node<T> *current = new Node<T>;
		current->content = a;
		current->next = NULL;
		Node<T> *p = first;
		for (int i = 0; i <= number - 1; i++)
		{
			p = p->next;
		}
		p->next = current;
		number++;
	}
	T& operator[](int i)
	{
		Node<T> *p = first->next;
		for (int j = 0; j <= i - 1; j++)
		{
			p = p->next;
		}
		return p->content;
	}
	void clear()
	{
		Node<T> *p = first->next;
		Node<T> *current;
		for (int i = 0; i <= number - 1; i++)
		{
			current = p;
			p = p->next;
			delete current;
		}
		number = 0;
	}
};