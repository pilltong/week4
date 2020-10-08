#include "newArray.h"
#include <iostream>

template <class T>
class GrowableArray : public Array<T> {
	public :
		GrowableArray(int size);
		virtual T& operator[] (int i);
};

template <class T>
GrowableArray<T>::GrowableArray(int size) {
	if (size <= 0) {
		cout<<"Array size Error!"<<endl;
		return;
	}
	this -> data = new T[size];
	this -> len = size;
}

template <class T>
T& GrowableArray<T>::operator [](int i) {
	if (i >= this -> len) {
		int Nlen = 2 * this -> len;
		T *Ndata = new T[Nlen];

		for(int k = 0; k < this -> len; k++) 
			/*this -> data[k] = Ndata[k];*/
			Ndata[k] = this -> data[k];

		for(int j = this -> len; j < Nlen; j++) 
			Ndata[j] = 0;
		
		this -> len = Nlen;
		this -> data = Ndata;

		return this -> data[i];
	}
	else 
		return this -> data[i];

}

