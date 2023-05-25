#pragma once
#include"Node.h"
template<class T>
class List
{
	Node<T>* first;
	int size;
public:
	List();
	bool isEmpty();
	void insert(T* data);
	std::string toString();
	bool deleteFirst();
	Node<T>* getFirst();
	void setFirst(Node<T>* node);
	~List();
};
template<class T>
List<T>::List()
{
	first = nullptr;
	size = 0;
}
template<class T>
bool List<T>::isEmpty() 
{
	return (first == nullptr);
}
template<class T>
void List<T>::insert(T* data)
{
	first = new Node(data, first);
}
template<class T>
std::string List<T>::toString()
{
	std::stringstream s;
	Node<T> aux = first;
	while (aux)
	{
		s << aux->getData()->toString() << std::endl;
		aux = aux->getNext();
	}
	return s;
}
template<class T>
bool List<T>::deleteFirst()
{
	if (first) {
		Node<T>* aux = first;
		first = first->next;
		delete aux;
		return true;
	}
	return false;
}
template<class T>
Node<T>* List<T>::getFirst()
{
	return primero;
}
template<class T>
void List<T>::setFirst(Node<T>* node)
{
	first = node;
}
template<class T>
List<T>::~List()
{
	Node<T>* current = first;
	while (current) {
		Node<T>* next = current->next;
		delete current;
		current = next;
	}
	first = nullptr;
}