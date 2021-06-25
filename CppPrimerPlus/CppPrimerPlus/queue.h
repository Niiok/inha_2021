#ifndef __Queue_h__
#define __Queue_h__

#include <iostream>
#include <assert.h>


template <typename T>
class Queue {

	/*struct Node {
		T value;
		T* below;
	};*/

public:
	Queue(int max);
	~Queue();

private:
	int max_ = 0;
	int size_ = 0;		//num
	int front_ = 0;	//place to deque
	int rear_ = 0;		//place to enque
	T* que_ = NULL;
	//int b_empty_ = 1;
	//int b_full_ = 0;
	//Node* front_ = NULL;
	//Node* rear_ = NULL;

private:
	int Initialize(int max) { }
public:
	int Enque(T x);
	int Deque(T *x);
	int Peek(T *x) const;
	void Clear(void);
	int Capasity(void) const;
	int Size(void) const;
	int IsEmpty(void) const;
	int IsFull(void) const;
	int Search(int x) const;
	void Print(void) const;
	void Terminate(void);

};

// -----------------------------------------------

int Initialize(Queue<int>* s, int max);

int Enque(Queue<int>* s, int x);

int Deque(Queue<int>* s, int *x);

int Peek(const Queue<int>* s, int *x);

void Clear(Queue<int>* s);

int Capasity(const Queue<int>* s);

int Size(const Queue<int>* s);

int IsEmpty(const Queue<int>* s);

int IsFull(const Queue<int>* s);

int Search(const Queue<int>* s, int x);

void Print(const Queue<int>* s);

void Terminate(Queue<int>* s);


#include "Queue.cpp"

#endif