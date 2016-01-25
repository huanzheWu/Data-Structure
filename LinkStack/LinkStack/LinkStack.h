/*
*Author:huanzheWu
*date:2016/1/25
*基于链表的栈实现
*/
# ifndef LINK_STACK_HPP
# define LINK_STACK_HPP
template <typename T>
struct Node
{
	Node(T t) :value(t), next(nullptr){};
	Node() :next(nullptr){};

public:
	T value;
	Node<T>* next;
};
 template <typename T>
 class LinkStack
 {
 public:
	 LinkStack();
	 ~LinkStack();
 public:
	 
	 bool isEmpty();
	 int size();
	 void push(T t);
	 T pop();
	 T top();

 private:
	 
	 Node<T>* pbase;
	 Node<T>* ptop;
	 int count;

 private:
	 Node<T>* getPreTop();

 };

 template <typename T>
 LinkStack<T>::LinkStack()
 {
	 pbase = new Node<T>();
	 ptop = pbase;
	 count = 0;
 };

 template <typename T>
 LinkStack<T>::~LinkStack()
 {
	 while (pbase != ptop)
	 {
		 Node<T>* pnode = pbase->next;
		 delete pbase;
		 pbase = pnode;
	 }
	 delete ptop;
	 pbase = nullptr;
	 ptop = nullptr;
 };

 template <typename T>
 int LinkStack<T>::size()
 {
	 return count;
 };

 template <typename T>
 bool LinkStack<T>::isEmpty()
 {
	 return count == 0;
 };

 template<typename T>
 void LinkStack<T>::push(T t)
 {
	 Node <T> *pnode = new  Node<T>(t);
	 ptop->next = pnode;
	 ptop = pnode;
	 count++;
 };

template <typename T>
T LinkStack<T>::top()
{
	return ptop->value;
};

template<typename T>
Node<T>*  LinkStack<T>::getPreTop()
{
	Node<T>* ptemp = pbase;
	while (ptemp->next != ptop)
	{
		ptemp = ptemp->next;
	}
	return ptemp;
};



template <typename T>
T LinkStack<T>::pop()
{
	if (ptop != pbase) //判空
	{
		Node<T>*ptemp = ptop;
		ptop = getPreTop();
		delete ptemp;
		count--;
		return ptop->value;
	}
};


# endif