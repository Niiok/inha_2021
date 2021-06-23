
#include "List.h"


template<typename T>
List<T>::List()
{
}
template<typename T>
List<T>::List(int size)
{
	if (size < 0)
		assert(0);

	for (int i = 0; i < size; ++i)
		push_back(T());
}
template<typename T>
List<T>::~List()
{
	Node* temp = head_;

	do {
		Node* next = temp->back;
		delete temp;
		temp = next;
	} while (temp != head_);
}


// modifier
template<typename T>
void List<T>::push_back(T data)
{
	insert(size_, data);
}
template<typename T>
void List<T>::pop_back()
{
	erase(size_ - 1);
}

template<typename T>
void List<T>::push_front(T data)
{
	insert(0, data);
}
template<typename T>
void List<T>::pop_front()
{
	erase(0);
}

template<typename T>
void List<T>::insert(int index, T data)
{
	Node* prev = FindNode(index);		// check range in FindNode()

	if (size_ == 0)
	{
		head_ = new Node;

		head_->data = data;
		head_->front = head_;
		head_->back = head_;

		prev = head_;
	}
	else
	{
		Node* prev_front = prev->front;	// O->o
		prev_front->back = new Node;	// O->N  o
		prev->front = prev_front->back;	// o  N<-o

		prev->front->data = data;
		prev->front->front = prev_front;	// o<-N  o
		prev->front->back = prev;			// o  N->o
	}

	++size_;
	if (index == 0)
		head_ = prev->front;
}
template<typename T>
void List<T>::erase(int index)
{
	if (size_ == 0 || size_ <= index)
		assert(0);

	Node* prev = FindNode(index);		//    D   
	Node* prev_front = prev->front;		// O  d   
	Node* prev_back = prev->back;		// o  d  O

	prev_front->back = prev_back;		// O--d->o
	prev_back->front = prev_front;		// o<-d--O

	delete prev;						// o<--->o

	if (index == 0)
		head_ = prev_back;

	--size_;
}



// element access
template<typename T>
T& List<T>::front()
{
	return head_->data;
}
template<typename T>
T& List<T>::back()
{
	return head_->front->data;
}
template<typename T>
T& List<T>::operator[] (int index)
{
	if (index >= size_ || index < 0)
		assert(0);

	Node* ret = FindNode(index);

	return ret->data;
}



// etc
template<typename T>
int List<T>::size()
{
	if (size_ < 0)
		assert(0);
	return size_;
}

template<typename T>
int List<T>::foreach(int(*func)(T& a, T& b), T& b)
{
	Node* temp = head_;
	int i = 0;

	for (; i < size_; ++i)
	{
		if (func(temp->data, b))
			break;

		temp = temp->back;
	}

	if (i == size_)
		i = -1;

	return i;
}