/*
* 基于C++template实现的单链表类
* 作者：huanzheWu
* 时间：2016/1/24
*/

# ifndef SINGLE_LIST_HXX
# define SINGLE_LIST_HXX

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

	int size();						 //获取长度
	bool isEmpty();					 //判空

	Node<T>* insert(int index, T t); //在指定位置进行插入
	Node<T>* insert_head(T t);		 //在链表头进行插入
	Node<T>* insert_last(T t);		 //在链表尾进行插入

	Node<T>*  del(int index);		 //在指定位置进行删除
	Node<T>*  delete_head();		 //删除链表头
	Node<T>*  delete_last();		 //删除链表尾

	T get(int index);			     //获取指定位置的元素
	T get_head();					 //获取链表头元素
	T get_last();					 //获取链表尾元素

	Node<T>* getHead();				 //获取链表头节点

private :
	int count;
	Node<T> * phead;				 

private :
	Node<T> * getNode(int index);	  //获取指定位置的节点
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
	Node<T>* preNode = phead;
	while (temp < index)
	{
		temp++;
		preNode = preNode->_next;
	}
	return preNode;
}
/*
析构函数
*/
template <typename T>
SingleLink<T>::~SingleLink()
{
	Node<T>* pNode = phead->_next;
	while (nullptr != pNode)
	{
		Node<T>* temp = pNode;
		pNode = pNode->_next;
		delete temp;
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


template<typename T>
Node<T>* SingleLink<T>::getHead()
{
	return phead->_next;
}

/*
在指定位置插入新节点
*/
template <typename T>
Node<T>* SingleLink<T>::insert(int index, T t)
{
	Node<T> * preNode = getNode(index);
	if (preNode)
	{
		Node<T> *newNode = new Node<T>(t,preNode->_next); //构建新节点，构建时指明节点的next节点
		preNode->_next = newNode;
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
	return insert(0, t);
};
/*
从尾部进行插入
*/
template <typename T>
Node<T>* SingleLink<T>::insert_last(T t)
{
	return insert(count, t);
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