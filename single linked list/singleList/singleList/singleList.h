/*
* 基于C++template实现的单链表类
* 作者：huanzheWu
* 时间：2016/1/24
*/

# ifndef SINGLE_LIST_HXX
# define SINGLE_LIST_HXX
#include<iostream>

//节点结构
template <typename T>
class Node
{
public :
	T _value;
	Node* _next;
public:
	Node() = default;
	Node(T value, Node * next)
		: _value(value), _next(next){}
};

//单链表
template <typename T>
class SingleLink
{
public:
	typedef Node<T>*  pointer;

	SingleLink();
	~SingleLink();
	//获取长度
	int size();
	//判空
	bool isEmpty();
	//插入操作
	Node<T>* insert_after(int index, T t);
	Node<T>* insert_head(T t);
	Node<T>* insert_last(T t);
	//删除操作
	Node<T>*  del(int index);
	Node<T>*  delete_head();
	Node<T>*  delete_last();
	//获取元素
	T get(int index);
	T get_head();
	T get_last();
private :
	int count;
	Node<T> * phead;
	Node<T> * getNode(int index);
};

//默认构造函数
template <typename T>
SingleLink<T>::SingleLink()
:count(0), phead(nullptr)
{
	//创建头节点
	phead = new Node<T>();
	phead->_next = nullptr;
};

/*
返回指定索引的前一个位置节点，若链表为空，则返回头节点
*/

template <typename T>
Node<T>* SingleLink<T>::getNode(int index)
{
	if (index > count||index < 0 )
		return nullptr;
	int temp = 0;
	Node<T>* ptr = phead;
	while (temp < index)
	{
		temp++;
		ptr = ptr->_next;
	}
	return ptr;
}
/*
析构函数
*/
template <typename T>
SingleLink<T>::~SingleLink()
{
	while (!isEmpty())
	{
		del(0);
	}
	//进行销毁
};

//返回链表的大小
template <typename T>
int SingleLink<T>::size()
{
	return count;
};
//链表判空
template <typename T>
bool SingleLink<T>::isEmpty()
{
	return count==0;
};
//在指定位置插入新节点
template <typename T>
Node<T>* SingleLink<T>::insert_after(int index, T t)
{
	Node<T> * ptrNode = getNode(index);
	if (ptrNode)
	{
		Node<T> *newNode = new Node<T>(t,ptrNode->_next);
		ptrNode->_next = newNode;
		count++;
		return newNode;
	}
	return nullptr;
};
/*
从头部插入
*/
template <typename T>
Node<T>* SingleLink<T>::insert_head(T t)
{
	return insert_after(0, t);
};
/*
从尾部进行插入
*/
template <typename T>
Node<T>* SingleLink<T>::insert_last(T t)
{
	return insert_after(count, t);
};
/*
删除链表指定位置元素
*/
template <typename T>
Node<T>* SingleLink<T>::del(int index)
{
	if (isEmpty())
		return nullptr;
	Node<T>* ptrNode = getNode(index);
	Node<T>* delNode = ptrNode->_next;
	ptrNode->_next = delNode->_next;
	count--;
	delete delNode;
	return ptrNode->_next;
};
/*
删除头节点
*/
template<typename T>
Node<T>* SingleLink<T>::delete_head()
{
	return del(0);
};
/*
删除尾节点
*/
template<typename T>
Node<T>*SingleLink<T>::delete_last()
{
	return del(count);
};



# endif