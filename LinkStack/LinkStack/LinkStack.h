/*
*Author:huanzheWu
*date:2016/1/25
*基于链表的栈实现
*/
# ifndef LINK_STACK_HPP
# define LINK_STACK_HPP

/*链表节点结构*/
template <typename T>
struct Node
{
	Node(T t) :value(t), next(nullptr){};
	Node() :next(nullptr){};

public:
	T value;
	Node<T>* next;
};

/*栈的抽象数据结构*/
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
	 
	 Node<T>* phead;
	 int count;
 };
 /*构造函数*/
 template <typename T>
 LinkStack<T>::LinkStack()
 {
	 phead = new Node<T>();
	 count = 0;
 };
 /*析构函数*/
 template <typename T>
 LinkStack<T>::~LinkStack()
 {
	 while (phead->next != nullptr)
	 {
		 Node<T>*pnode = phead->next;
		 phead->next = phead->next;
		 delete pnode;
	 }
	 phead = nullptr;
 };

 /*返回栈的大小*/
 template <typename T>
 int LinkStack<T>::size()
 {
	 return count;
 };
 /*栈的判空操作*/
 template <typename T>
 bool LinkStack<T>::isEmpty()
 {
	 return count == 0;
 };
 /*插入元素*/
 template<typename T>
 void LinkStack<T>::push(T t)
 {
	 Node <T> *pnode = new  Node<T>(t);
	 pnode->next = phead->next;
	 phead->next = pnode;
	 count++;
 };
 /*弹栈*/
 template <typename T>
 T LinkStack<T>::pop()
 {
	 if (phead->next != nullptr) //栈空判断
	 {
		 Node<T>* pdel = phead->next;
		 phead->next = phead->next->next;
		 T value = pdel->value;
		 delete pdel;
		 count--;
		 return value;
	 }
 };
 /*获取栈顶元素*/
template <typename T>
T LinkStack<T>::top()
{
	if (phead->next!=nullptr)
		return phead->next->value;
};

# endif