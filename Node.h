#pragma once
#include<iostream>
#include<sstream>
template<class T>
class Node
{
	T* data;
	Node<T>* next;
public:
	Node(T*, Node<T>);
	~Node();
	Node<T>* getNext();
	T* getData();
	void setNext(Node<T>*);
};

template<class T>
T* Node<T>::getData()
{
	return data;
}
template<class T>
void Node<T>::setNext(Node<T>* n)
{
	next = n;
}
template<class T>
Node<T>::Node<T>(T* d, Node<T> n):data(d),next(n)
{
}
template<class T>
Node<T>::~Node<T>()
{
	if (data) {
		delete data;
	}
}
template<class T>
Node<T> *Node<T>::getNext()
{
	return next;
}

