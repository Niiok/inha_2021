#ifndef __Stack_h__
#define __Stack_h__

#include <iostream>
#include <assert.h>


template <typename T>
class Stack {

	/*struct Node {
		T value;
		T* below;
	};*/

public:
	Stack(int max);
	~Stack();

private:
	int max_ = 0;
	int size_ = 0;	//ptr
	T* stk_ = NULL;
	//Node* top_ = NULL;

private:
	int Initialize(int max) { }
public:
	int Push(T x);
	int Pop(T *x);
	T Pop();
	int Peek(T *x) const;
	T Peek() const;
	void Clear(void);
	int Capasity(void) const;
	int Size(void) const;
	int IsEmpty(void) const;
	int IsFull(void) const;
	int Search(int x) const;
	void Print(void) const;
	void Terminate(void);
	T operator[](int i) const;
};

// -----------------------------------------------

int Initialize(Stack<int>* s, int max);

int Push(Stack<int>* s, int x);

int Pop(Stack<int>* s, int *x);

int Peek(const Stack<int>* s, int *x);

void Clear(Stack<int>* s);

int Capasity(const Stack<int>* s);

int Size(const Stack<int>* s);

int IsEmpty(const Stack<int>* s);

int IsFull(const Stack<int>* s);

int Search(const Stack<int>* s, int x);

void Print(const Stack<int>* s);

void Terminate(Stack<int>* s);


#include "Stack.cpp"

#endif