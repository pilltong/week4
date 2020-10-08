#ifndef __ARRAY__
#define __ARRAY__
#include <iostream>

using namespace std;

template <class T>
class Array {
	protected:
		T *data;
		int len;
	public:
		Array() {};
		Array(int size);
		~Array();

		int length() const;
		virtual T& operator[](int i);
		virtual T operator[] (int i) const;

		void print();
};

template <class T>
Array<T>::Array(int size) {
	if(size <= 0) 
		cout<<"Array size Error!"<<endl;
	else
		data = new T[size];
		len = size;
}

template <class T>
Array<T>::~Array() {
	delete [] data;
}

template <class T>
int Array<T>::length() const {
	return len;
}

template <class T>
T & Array<T>::operator[](int i) {
	static T tmp;
	if (i >= 0 && i < len)
		return data[i];
	else
		cout<<"Array index Error!"<<endl;
		return tmp;
}

template <class T>
T Array<T>::operator[] (int i) const {
	if (i >= 0 && i < len)
		return data[i];
	else
		cout<<"Array index Error!"<<endl;
		return 0;
}

template <class T>
void Array<T>::print() {
	int i = 0;
	cout<<"[";
	for(i=0; i<len; i++) {
		cout<<" "<<data[i];
	}
	cout<<" ]"<<endl;
}

#endif
