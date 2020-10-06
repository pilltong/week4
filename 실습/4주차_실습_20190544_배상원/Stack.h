#include <iostream>
#include "LinkedList.h"

template <class T>
class Stack : public LinkedList<T> {
	public :
		virtual bool Delete(T &element);
};

template <class T>
bool Stack<T>::Delete(T &element) {
	if (this -> first == 0) {
		cout<<"List Empty"<<endl;
		return false;
	}
	Node<T> *current;
	current = this -> first;
	element = this -> first -> data;

	this -> first = this -> first -> link;
	delete current;

	this -> current_size--;
	
	return true;
}
	
