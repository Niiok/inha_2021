#include "AVLtree.h"

template<typename T>
AVLtree<T>::AVLtree()
{

}
template<typename T>
AVLtree<T>::~AVLtree()
{
	Queue<Node*> que(this->size_);
	Node* todel;

	if (this->size_ == 0)
		return;

	this->postorder(que, this->root_);

	for (; this->size_ > 0 && !que.IsEmpty(); --this->size_)
	{
		que.Deque(&todel);
		delete todel;
	}

	assert(this->size_ == 0 && que.IsEmpty());

	return;
}


// modifier
template<typename T>
void AVLtree<T>::Add(int index, T data)
{
	Node* temp = this->root_;
	Node* prev = NULL;

	if(this->FindNode(index) != NULL)
	{
		printf("\n이미 사용 중인 번호입니다.\n");
		return;
	}

	if (this->size_ == 0)
	{
		this->root_ = new Node(NULL, NULL, NULL, data, index);
		++this->size_;
		return;
	}

	while (temp != NULL)
	{
		if (index > temp->index)
		{
			prev = temp;
			temp->right_count++;
			temp = temp->right;
		}
		else if (index < temp->index)
		{
			prev = temp;
			temp->left_count++;
			temp = temp->left;
		}
	}

	if (index > prev->index)
		prev->right = new Node(prev, NULL, NULL, data, index);
	else //if(index < prev->index)
		prev->left = new Node(prev, NULL, NULL, data, index);

	CheckBalance(prev);
	

	++this->size_;
}

template<typename T>
void AVLtree<T>::Remove(int index)
{
	if (this->size_ < 1)
		return;

	Node* todel = (Node*)this->FindNode(index);
	if (todel == NULL)
	{
		printf("\n존재하지 않는 번호입니다.\n");
		return;
	}

	while (todel->right != NULL || todel->left != NULL)
	{
		if (todel->left != NULL)
		{
			todel->left_count--;
			Node* temp = todel->left;

			while (temp->right != NULL)
			{
				temp->right_count--;
				temp = temp->right;
			}

			todel->swap(temp);
			todel = temp;
		}
		else
		{
			todel->right_count--;
			Node* temp = todel->right;

			while (temp->left != NULL)
			{
				temp->left_count--;
				temp = temp->left;
			}

			todel->swap(temp);
			todel = temp;
		}
	}

	if (todel != root_) 
	{
		if (todel->parent->index > todel->index)
			todel->parent->left = NULL;
		else
			todel->parent->right = NULL;
	}

	CheckBalance(todel->parent);

	delete todel;

	--this->size_;

	if (size_ == 0)
		root_ = NULL;
}




// element access
template<typename T>
bool AVLtree<T>::Search(int index)
{
	if (FindNode(index) != NULL)
		return true;
	else
		return false;
}
template<typename T>
T& AVLtree<T>::operator[] (int index)
{
	Node* temp = FindNode(index);

	if (temp != NULL)
		return *(temp->data);
	else
		return *(Node().data);
}


// etc
template<typename T>
int AVLtree<T>::size()
{
	assert(size_ >= 0);

	return size_;
}
template<typename T>
int AVLtree<T>::foreach(int(*func)(T& a, T& b), T& b)
{
	Queue<Node*> que(size_);
	Node* getter;
	int i = 0;

	if (size_ == 0)
		return -1;

	inorder(que, root_);

	for (; i < size_ && !que.IsEmpty(); ++i)
	{
		que.Deque(&getter);
		if (func(*(getter->data), b))
			break;
	}

	assert(i == size_ && que.IsEmpty());

	if (i == size_)
		i = -1;

	return i;
}

template<typename T>
int AVLtree<T>::inorder(Queue<Node*>& que, Node* target)
{
	if (target->left != NULL)
		inorder(que, target->left);

	que.Enque(target);

	if (target->right != NULL)
		inorder(que, target->right);

	return 0;
}
template<typename T>
int AVLtree<T>::postorder(Queue<Node*>& que, Node* target)
{
	if (target->left != NULL)
		postorder(que, target->left);

	if (target->right != NULL)
		postorder(que, target->right);

	que.Enque(target);

	return 0;
}
template<typename T>
int AVLtree<T>::BFS(Queue<Node*>& que, Node* target)
{
	static Queue<Node*>to_search(1024);
	Node* buf;

	if (target == NULL)
		return -1;

	que.Enque(target->left);
	que.Enque(target->right);

	if (target->left != NULL)
		to_search.Enque(target->left);
	if (target->right != NULL)
		to_search.Enque(target->right);

	if (!to_search.IsEmpty())
	{
		to_search.Deque(&buf);
		BFS(que, buf);
	}

	return 0;
}


template<typename T>
void AVLtree<T>::CheckBalance(Node* parent)
{

	if (parent == NULL)
		return;
	if (parent == root_)
		return;


	if (abs(parent->parent->left_count - parent->parent->right_count) > 1)
		RotateBalance(parent);

	CheckBalance(parent->parent);

}

template<typename T>
void AVLtree<T>::RotateBalance(Node* parent)
{
	int x_child = 0;

	Node *t1 = NULL,
		*t2 = NULL,
		*t3 = NULL,
		*t4 = NULL;

	Node *x = NULL,
		*y = NULL,
		*z = NULL;

	Node *first = NULL,
		*second = NULL,
		*third = NULL;

	x = parent->parent;	// grand parent

	if (x->left_count > x->right_count)		// might be parent
	{
		y = x->left;

		t4 = x->right;
		x_child = 4;
		third = x;
	}
	else
	{
		y = x->right;

		t1 = x->left;
		x_child = 1;
		first = x;
	}

	if (y->left_count > y->right_count)		// might be child
	{
		z = y->left;

		if (x_child == 4)
		{
			t3 = y->right;
			t2 = z->right;
			t1 = z->left;
			first = z;
			second = y;
		}
		else
		{
			t4 = y->right;
			t3 = z->right;
			t2 = z->left;
			second = z;
			third = y;
		}
	}
	else
	{
		z = y->right;

		if (x_child == 1)
		{
			t2 = y->left;
			t3 = z->left;
			t4 = z->right;
			second = y;
			third = z;
		}
		else
		{
			t1 = y->left;
			t2 = z->left;
			t3 = z->right;
			first = y;
			second = z;
		}
	}

	if (x == root_)
		root_ = second;
	else
	{
		if (x->index > x->parent->index)
			x->parent->right = second;
		else
			x->parent->left = second;

	}
	second->parent = x->parent;
	first->parent = second;
	third->parent = second;
	
	second->left = first;
	second->right = third;
	first->left = t1;
	first->right = t2;
	third->left = t3;
	third->right = t4;
	


	if (t1 != NULL)
	{
		t1->parent = first;
		first->left_count = (t1->left_count + t1->right_count + 1);
	}
	else
		first->left_count = 0;

	if (t2 != NULL)
	{
		t2->parent = first;
		first->right_count = (t2->left_count + t2->right_count + 1);
	}
	else
		first->right_count = 0;

	if (t3 != NULL)
	{
		t3->parent = third;
		third->left_count = (t3->left_count + t3->right_count + 1);
	}
	else
		third->left_count = 0;

	if (t4 != NULL)
	{
		t4->parent = third;
		third->right_count = (t4->left_count + t4->right_count + 1);
	}
	else
		third->left_count = 0;

	second->left_count = (first->left_count + first->right_count + 1);
	second->right_count = (third->left_count + third->right_count + 1);


	return;
}

template<typename T>
int AVLtree<T>::ShowTree(int width)
{
	Queue<Node*> que(2048);
	Node* pointer;

	if (size_ == 0)
		return 0;

	que.Enque(root_);
	BFS(que, root_);

	int i = 2;
	int j = 0;
	while (!que.IsEmpty())
	{
		Node* buf;
		que.Deque(&buf);


		printf("<");
		for (int w = 0; w < width / (2 << j) - 2; w++)
			printf(" ");
		if (buf != NULL)
			printf("%2d", buf->index);		//printf("%2d-%2d-%2d", buf->left_count, buf->index, buf->right_count);
		else
			printf("  ");
		for (int w = 0; w < width / (2 << j) - 2; w++)
			printf(" ");
		printf(">");

		if (i == (2 << j))
		{
			printf("\n");
			++j;
		}
		++i;
	}


	return 0;
}