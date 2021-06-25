#include "stack.h"



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
T Stack<T>::operator[](int i) const
{
	if (i >= size_)
		return 0;
	else if (i < 0)
		assert(0);
	else
		return stk_[i];
}


// -----------------------------------------------


int Initialize(Stack<int>* s, int max)
{
	s = new Stack<int>(max);
	return 0;
}

int Push(Stack<int>* s, int x)
{
	return s->Push(x);
}

int Pop(Stack<int>* s, int *x)
{
	int origin = *x;
	int ret = s->Pop(x);
	
	if (ret == -1)
		*x = origin;

	return ret;
}

int Peek(const Stack<int>* s, int *x)
{
	int origin = *x;
	int ret = s->Peek(x);

	if (ret == -1)
		*x = origin;

	return ret;
}

void Clear(Stack<int>* s)
{
	s->Clear();
}

int Capasity(const Stack<int>* s)
{
	return s->Capasity();
}

int Size(const Stack<int>* s)
{
	return s->Size();
}

int IsEmpty(const Stack<int>* s)
{
	return s->IsEmpty();
}

int IsFull(const Stack<int>* s)
{
	return s->IsFull();
}

int Search(const Stack<int>* s, int x)
{
	return s->Search(x);
}

void Print(const Stack<int>* s)
{
	s->Print();
}

void Terminate(Stack<int>* s)
{
	s->Terminate();
}
