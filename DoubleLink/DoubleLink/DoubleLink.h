/*
* content: 循环双向链表
* Author:huanzheWu
* date : 2016/1/25
* 
*/

# ifndef DOUBLE_LINK_HPP
# define DOUBLE_LINK_HPP
/*
双向链表的节点结构
*/
template <typename T>
struct Node
{
public:
	Node()= default;
	Node(T value, Node<T>* preptr, Node<T>* nextptr)
		:_value(value), pre_ptr(preptr), next_ptr(nextptr){}

public:
	T _value;
	Node<T>* pre_ptr;
	Node<T>* next_ptr;
};

/*
* 双向链表类
*/
template<typename T>
class DoubleLink
{
public:
	typedef Node<T>* pointer;
public:
	DoubleLink();
	~DoubleLink(){};
public:
	Node<T>* insert(int index, T value);
	Node<T>* insert_front(T value);
	Node<T>* insert_last(T value);

	Node<T>* del(int index);
	Node<T>* delete_front();
	Node<T>* delete_last();

	bool isEmpty();
	int size();

	T get(int index);
	T get_front();
	T get_last();
	Node<T>* getHead();

private:
	Node<T>* phead;
	int count;
private :
	Node<T>* getNode(int index);
};
/*
* 构造函数
*
*/
template <typename T>
DoubleLink<T>::DoubleLink()
{
	phead = new Node<T>(0, nullptr, nullptr);
	phead->next_ptr = phead;
	phead->pre_ptr = phead;
	count = 0;
};
template<typename T>
Node<T>* DoubleLink<T>::getHead()
{
	return phead;
}

/*
*返回链表长度
*/
template <typename T>
int DoubleLink<T>::size()
{
	return count;
}
/*
获取指定下标的元素
*/
template <typename T>
Node<T>* DoubleLink<T>::getNode(int index)
{
	if (index >= count || index < 0)
		return nullptr;

	if (index<=count / 2) //如果在前半部分
	{
		Node<T>* pnode = phead->next_ptr;
		while (index)
		{
			pnode = pnode->next_ptr;
			index--;
		}
		return pnode;
	}						//在后半部分

	index = count - index-1;
	Node<T>* pnode = phead->pre_ptr;
	while (index)
	{
		pnode = pnode->pre_ptr;
		index--;
	}
	return pnode;
};
/*
*将新节点插到第一个位置
*/
template <typename T>
Node<T>* DoubleLink<T>::insert_front(T value)
{
	Node<T>* newNode = new Node<int>(value, phead, phead->next_ptr);
	phead->next_ptr ->pre_ptr= newNode;
	phead->next_ptr = newNode;
	count++;
	return newNode;
};
/*
*将新节点插到链表尾部
*/
template <typename T>
Node<T>* DoubleLink<T>::insert_last(T value)
{
	Node<T> * newNode = new Node<int>(value, phead->pre_ptr, phead);
	phead->pre_ptr->next_ptr = newNode;
	phead->pre_ptr = newNode;
	count++;
	return newNode;
};
/*
*将节点位置插到index位置之前
*/

template <typename T>
Node<T>* DoubleLink<T>::insert(int index, T value)
{
	if (index == 0)
		return insert_front(value);

	Node<T>* pNode = getNode(index);
	if (pNode == nullptr)
		return nullptr;
	Node<T>* newNode = new Node<T>(value, pNode->pre_ptr, pNode);
	pNode->pre_ptr->next_ptr = newNode;
	pNode->pre_ptr = newNode;
	count++;

	return newNode;
};
/*
*删除链表第一个节点
*返回删除后链表第一个节点
*/
template<typename T>
Node<T>* DoubleLink<T>::delete_front()
{
	if (count == 0)		//空树，返回nullptr
	{
		return nullptr; 
	}
	Node<T>* pnode = phead->next_ptr;
	phead->next_ptr = pnode->next_ptr;
	pnode->next_ptr->pre_ptr = phead;
	delete pnode;
	count--;
	return phead->next_ptr;
};
/*
*删除链表的末尾节点
*返回删除后链表尾部元素
*/
template<typename T>
Node<T>* DoubleLink<T>::delete_last()
{
	if (count == 0)
	{
		return nullptr;
	}
	Node<T>*pnode = phead->pre_ptr;
	pnode->pre_ptr->next_ptr = phead;
	phead->pre_ptr = pnode->pre_ptr;
	delete pnode;
	count--;
	return phead->pre_ptr;
}
/*
*删除指定位置的元素
*
*/
template <typename T>
Node<T>* DoubleLink<T>::del(int index)
{
	if (index == 0)
		return delete_front();
	if (index == count - 1)
		return delete_last();
	if (index >= count)
		return nullptr;
	Node<T>* pnode = getNode(index);
	pnode->pre_ptr->next_ptr = pnode->next_ptr;
	pnode->next_ptr->pre_ptr = pnode->pre_ptr;
	
	Node<T>* ptemp = pnode->pre_ptr;
	delete pnode;
	count--;
	return ptemp;
};

template <typename T>
bool DoubleLink<T>::isEmpty()
{
	return count == 0;
};
/*
*获取第一个节点的值
*/
template<typename T>
T DoubleLink<T>::get_front()
{
	return phead->next_ptr->_value;
};
/*
*获取最后一个节点的值
*/
template <typename T>
T DoubleLink<T>::get_last()
{
	return phead->pre_ptr->_value;
};
/*
*获取指定位置节点的值
*/
template <typename T>
T DoubleLink<T>::get(int index)
{
	Node<T>  pnode = getNode(index);
	return pnode->_value;
};
# endif