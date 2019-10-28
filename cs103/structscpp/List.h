//
// Created by nik on 10/28/19.
//

#ifndef STRUCTSCPP_LIST_H
#define STRUCTSCPP_LIST_H

typedef unsigned int uint;

template<typename T>
class List {
protected:
	List() = default;

	inline virtual ~List() {
		delete[] this->data;
		this->length = 0;
	};

public:

	uint length = 0;
	uint capacity = 16;
	T* data = nullptr;

	inline virtual void clear() {
		delete[] this->data;
		this->length = 0;
	};

	inline virtual uint size() { return this->length; };

	inline virtual bool isEmpty() { return this->length == 0; };

	inline virtual void resize() {
		this->capacity = this->capacity * 2 + 1;
		this->data = (T*) reallocarray(this->data, this->capacity, sizeof(T));
	};

	virtual T get(uint) = 0;

	virtual int indexOf(T) = 0;

	virtual int lastIndexOf(T) = 0;

	virtual bool contains(T) = 0;

	virtual void add(T) = 0;

	virtual void add(T, uint) = 0;

	virtual void remove(T) = 0;

	virtual void set(T, uint) = 0;
};


#endif //STRUCTSCPP_LIST_H
