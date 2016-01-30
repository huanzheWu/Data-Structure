/*
conetent : 大顶堆
author :huanzheWu
date:2016/1/30
*/

# ifndef _MAX_HEAP_HCC_
# define _MAX_HEAP_HCC_
/*大顶堆类定义*/
template <typename T>
class MaxHeap
{
public:
	MaxHeap(int cap = 10);
	~MaxHeap(){};
public:
	bool insert(T val);	//往二叉堆中插入元素
	bool remove();	//移除元素
private:
	int capacity;	//容量，也即是数组的大小
	int size;		//堆大小，也即是数组中有效元素的个数
	T * heap;		//底层的数组
private:
	void filterUp(int index); //从index所在节点，往根节点调整堆
};
/*默认构造函数*/
template <typename T>
MaxHeap<T>::MaxHeap(int cap = 10) //默认的数组大小为10
:capacity(cap), size(0), heap(nullptr)
{
	heap = new T[capacity];
};

/*插入元素*/
template <typename T>
bool MaxHeap<T>::insert(T val)
{
	if (size == capacity) //如果数组已满，则返回false
		return false;
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
};
/*从下到上调整堆*/
template <typename T>
void MaxHeap<T>::filterUp(int index)
{
	while (index > 0) //如果还未到达根节点，继续调整
	{
		int indexParent = index / 2;  //求其双亲节点
		if (heap[index] > heap[indexParent])
		{
			T temp = heap[index];
			heap[index] = heap[indexParent];
			heap[indexParent] = temp;
		}
		index = indexParent;
	}
};

# endif 