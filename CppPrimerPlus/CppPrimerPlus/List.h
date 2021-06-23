#pragma once
#include <assert.h>

template <typename T>
class List
{
	struct Node {
		Node* front = NULL;
		T data;
		Node* back = NULL;
	};

public:
	List();
	List(int);
	virtual ~List();

private:
	Node* head_ = NULL;
	int size_ = 0;


public:

	// modifier
	void push_back(T data);
	void pop_back();
	void push_front(T data);
	void pop_front();
	void insert(int index, T data);
	void erase(int index);

	// element access
	T& front();
	T& back();
	T& operator[] (int index);

	// etc
	int size();
	int foreach(int(*func)(T& a, T& b), T& b);



private:
	Node* FindNode(int index)
	{
		if (index > size_ || index < 0)
			assert(0);

		Node* prev = head_;

		if (index < size_ / 2)
			for (int i = 0; i != index; ++i)
				prev = prev->back;
		else
			for (int i = size_; i != index; --i)
				prev = prev->front;
		return prev;
	}
};


#include "List.cpp"