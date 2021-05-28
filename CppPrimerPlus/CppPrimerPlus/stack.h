#ifndef ___Stack
#define ___Stack

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
	T getByIndex(int i) const;
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





template<typename T>
Stack<T>::Stack(int max)
{
	max_ = max;
	size_ = 0;
	stk_ = (T*)malloc(sizeof(T) * max);
	assert(stk_ != NULL);

	//top_ = NULL;
}

template<typename T>
Stack<T>::~Stack()
{
	free(stk_);
}

template<typename T>
int Stack<T>::Push(T x)
{
	if (IsFull())
		return -1;
	else
	{
		stk_[size_] = x;
		++size_;
		return 0;
	}
}

template<typename T>
int Stack<T>::Pop(T *x)
{
	if (IsEmpty())
		return -1;
	else
	{
		--size_;
		*x = stk_[size_];
		return 0;
	}
}

template<typename T>
T Stack<T>::Pop()
{
	if (IsEmpty())
		return -1;
	else
	{
		--size_;
		return stk_[size_];
	}
}

template<typename T>
int Stack<T>::Peek(T *x) const
{
	if (IsEmpty())
		return -1;
	else
	{
		*x = stk_[size_ - 1];
		return 0;
	}
}

template<typename T>
T Stack<T>::Peek() const
{
	if (IsEmpty())
		return -1;
	else
	{
		return stk_[size_ - 1];
	}
}

template<typename T>
void Stack<T>::Clear(void)
{
	size_ = 0;
}

template<typename T>
int Stack<T>::Capasity(void) const
{
	return max_;
}

template<typename T>
int Stack<T>::Size(void) const
{
	return size_;
}

template<typename T>
int Stack<T>::IsEmpty(void) const
{
	if (size_ == 0)
		return 1;
	else
		return 0;
}

template<typename T>
int Stack<T>::IsFull(void) const
{
	if (size_ == max_)
		return 1;
	else
		return 0;
}

template<typename T>
int Stack<T>::Search(int x) const
{
	for (int i = size_ - 1; i <= 0; --i)
	{
		if (stk_[i] == x)
			return i;
	}

	return -1;
}

template<typename T>
void Stack<T>::Print(void) const
{
	for (int i = 0; i < size_; ++i)
		printf(" %d", stk_[i]);
	printf("\n");
}

template<typename T>
void Stack<T>::Terminate(void)
{
	delete this;
}


template<typename T>
T Stack<T>::getByIndex(int i) const
{
	if (i >= size_)
		return 0;
	else if (i < 0)
		assert(0);
	else
		return stk_[i];
}




#endif