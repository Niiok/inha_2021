#include "BinaryTree.h"

template<typename T>
BinaryTree<T>::BinaryTree()
{

}
template<typename T>
BinaryTree<T>::BinaryTree(int i)
{
	root_ = new Node();
	root_->index = i;

	++size_;
}
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	Queue<Node*> que(size_);
	Node* todel;

	if (size_ == 0)
		return;

	postorder(que, root_);

	for (; size_ > 0 && !que.IsEmpty(); --size_)
	{
		que.Deque(&todel);
		delete todel;
	}

	assert(size_ == 0 && que.IsEmpty());

	return;
}



// modifier
template<typename T>
void BinaryTree<T>::Add(int index, T data)
{
	Node* temp = root_;
	Node* prev = NULL;

	if (size_ == 0)
	{
		root_ = new Node(NULL, NULL, NULL, data, index);
		++size_;
		return;
	}

	while (temp != NULL)
	{
		if (index > temp->index)
		{
			prev = temp;
			temp = temp->right;
		}
		else if (index < temp->index)
		{
			prev = temp;
			temp = temp->left;
		}
		else if (index == temp->index)
		{
			printf("\n이미 사용 중인 번호입니다.\n");
			return;
		}
	}


	if (index > prev->index)
		prev->right = new Node(prev, NULL, NULL, data, index);
	else //if(index < prev->index)
		prev->left = new Node(prev, NULL, NULL, data, index);


	++size_;
}
template<typename T>
void BinaryTree<T>::Remove(int index)
{
	if (size_ < 1)
		return;

	Node* todel = FindNode(index);
	if (todel == NULL)
	{
		printf("\n존재하지 않는 번호입니다.\n");
		return;
	}

		if (todel->right != NULL && todel->left != NULL) // two child
		{
			Node* temp = todel->left;

			while (temp->right != NULL)
				temp = temp->right;

			todel->swap(temp);
			todel = temp;

			if (todel->left == NULL && todel->right == NULL)	// no child
			{
				todel->parent->right = NULL;
			}
			else // one child
			{
				Node* child = todel->left;
				
				todel->parent->right = child;
				child->parent = todel->parent;
			}
				delete todel;
		}
		else if (todel->left == NULL && todel->right == NULL)	// no child
		{
			if (todel == root_)
				root_ = NULL;
			else if (todel->index > todel->parent->index)
				todel->parent->right = NULL;
			else //if(todel->index < todel->parent->index)
				todel->parent->left = NULL;

			delete todel;
		}
		else // one child
		{
			Node* child = (todel->left != NULL) ? todel->left : todel->right;

			if (todel == root_)
			{
				root_ = child;
				child->parent = NULL;
			}
			else if (todel->index > todel->parent->index)
			{
				todel->parent->right = child;
				child->parent = todel->parent;
			}
			else //if(todel->index < todel->parent->index)
			{
				todel->parent->left = child;
				child->parent = todel->parent;
			}

			delete todel;
		}

	--size_;
}


// element access
template<typename T>
bool BinaryTree<T>::Search (int index)
{
	if (FindNode(index) != NULL)
		return true;
	else
		return false;
}
template<typename T>
T& BinaryTree<T>::operator[] (int index)
{
	Node* temp = FindNode(index);

	if (temp != NULL)
		return *(temp->data);
	else
		return *(Node().data);
}


// etc
template<typename T>
int BinaryTree<T>::size()
{
	assert(size_ >= 0);

	return size_;
}
template<typename T>
int BinaryTree<T>::foreach(int(*func)(T& a, T& b), T& b)
{
	Queue<Node*> que(size_);
	Node* getter;
	int i = 0;

	if (size_ == 0)
		return -1;

	inorder(que, root_);

	for (;i < size_ && !que.IsEmpty(); ++i)
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
int BinaryTree<T>::inorder(Queue<Node*>& que, Node* target)
{
	if (target->left != NULL)
		inorder(que, target->left);

	que.Enque(target);

	if (target->right != NULL)
		inorder(que, target->right);

	return 0;
}
template<typename T>
int BinaryTree<T>::postorder(Queue<Node*>& que, Node* target)
{
	if (target->left != NULL)
		postorder(que, target->left);

	if (target->right != NULL)
		postorder(que, target->right);

	que.Enque(target);

	return 0;
}

//template<typename T>
//int BinaryTree<T>::binary_each(int(*func)(T& a, T& b), T& b)
//{
//	//int left = 0;
//	//int right = size_ - 1;
//	//int node_index;
//	//Node* temp = FindNode((right + left) / 2);
//
//	//if (size_ == 0)
//	//	return -1;
//
//	//do
//	//{
//	//	node_index = (left + right) / 2;
//	//	printf("%d  ", node_index);
//
//	//	int func_result = func(temp->data, b);
//
//	//	if (func_result > 0)
//	//	{
//	//		right = node_index - 1;
//	//		for (int i = node_index; i != (left + right) / 2; --i)
//	//			temp = temp->front;
//	//	}
//	//	else if (func_result < 0)
//	//	{
//	//		left = node_index + 1;
//	//		for (int i = node_index; i != (left + right) / 2; ++i)
//	//			temp = temp->back;
//	//	}
//	//	else if (func_result == 0)
//	//	{
//	//		return node_index;
//	//	}
//
//	//} while (left <= right);
//
//
//	//return -left - 1;
//	return 0;
//}