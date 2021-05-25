#include "queue.h"


template<typename T>
Queue<T>::Queue(int max)
{
	max_ = max;
	size_ = 0;	//num
	front_ = 0;
	rear_ = 0;
	que_ = (T*)malloc(sizeof(T) * max);
	assert(que_ != NULL);

	//top_ = NULL;
}

template<typename T>
Queue<T>::~Queue()
{
	free(que_);
}

template<typename T>
int Queue<T>::Enque(T x)
{
	if (IsFull())
		return -1;
	else
	{
		que_[rear_] = x;
		rear_ = ((rear_ + 1) % max_);
		++size_;
		return 0;
	}
}

template<typename T>
int Queue<T>::Deque(T *x)
{
	if (IsEmpty())
		return -1;
	else
	{
		*x = que_[front_];
		front_ = ((front_ + 1) % max_);
		--size_;
		return 0;
	}
}

template<typename T>
int Queue<T>::Peek(T *x) const
{
	if (IsEmpty())
		return -1;
	else
	{
		*x = que_[front_];
		return 0;
	}
}

template<typename T>
void Queue<T>::Clear(void)
{
	size_ = 0;
	rear_ = front_;
}

template<typename T>
int Queue<T>::Capasity(void) const
{
	return max_;
}

template<typename T>
int Queue<T>::Size(void) const
{
	return size_;
}

template<typename T>
int Queue<T>::IsEmpty(void) const
{
	if (size_ == 0)
		return 1;
	else
		return 0;
}

template<typename T>
int Queue<T>::IsFull(void) const
{
	if (size_ == max_)
		return 1;
	else
		return 0;
}

template<typename T>
int Queue<T>::Search(int x) const
{
	int i = front_;
	int count = 0;

	while (count < size_)
	{
		if (que_[i] == x)
			return i;

		i = (i + 1) % max_;
		++count;
	}

	return -1;
}

template<typename T>
void Queue<T>::Print(void) const
{
	int i = front_;
	int count = 0;

	while (count < size_)
	{
		printf(" %d", que_[i]);

		i = (i + 1) % max_;
		++count;
	}

	printf("\n");
}

template<typename T>
void Queue<T>::Terminate(void)
{
	delete this;
}


// -----------------------------------------------


int Initialize(Queue<int>* s, int max)
{
	s = new Queue<int>(max);
	return 0;
}

int Enque(Queue<int>* s, int x)
{
	return s->Enque(x);
}

int Deque(Queue<int>* s, int *x)
{
	int origin = *x;
	int ret = s->Deque(x);

	if (ret == -1)
		*x = origin;

	return ret;
}

int Peek(const Queue<int>* s, int *x)
{
	int origin = *x;
	int ret = s->Peek(x);

	if (ret == -1)
		*x = origin;

	return ret;
}

void Clear(Queue<int>* s)
{
	s->Clear();
}

int Capasity(const Queue<int>* s)
{
	return s->Capasity();
}

int Size(const Queue<int>* s)
{
	return s->Size();
}

int IsEmpty(const Queue<int>* s)
{
	return s->IsEmpty();
}

int IsFull(const Queue<int>* s)
{
	return s->IsFull();
}

int Search(const Queue<int>* s, int x)
{
	return s->Search(x);
}

void Print(const Queue<int>* s)
{
	s->Print();
}

void Terminate(Queue<int>* s)
{
	s->Terminate();
}
