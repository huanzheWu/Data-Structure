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
	bool remove(T data);	//移除元素
private:
	int capacity;	//容量，也即是数组的大小
	int size;		//堆大小，也即是数组中有效元素的个数
	T * heap;		//底层的数组
private:
	void filterUp(int index); //从index所在节点，往根节点调整堆
	void filterDown(int begin ,int end ); //从begin所在节点开始，向end方向调整堆
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
/*插入元素时候使用*/
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

/*删除元素*/
template<typename T>
bool MaxHeap<T>::remove(T data)
{
	if (size == 0) //如果堆是空的
		return false;
	int index;
	for (index = 0; index < size; index++)  //获取值在数组中的索引
	{
		if (phead[index] == date)
			break;
	}
	if (index == size)			//数组中没有该值
		return false;  
	
	heap[index] = heap[size - 1];
	filterDown(index,size--);   
	return true;
};
/*从上到下调整堆*/
/*删除元素时候使用*/
template<typename T>
void MaxHeap<T>::filterDown(int begin,int end)
{
	int current = begin;	//当前结点

	int child = begin * 2 + 1; //当前结点的左孩子

	T value = heap[current];	//保存当前结点的值

	while (child <= end)
	{
		if (child < end&&heap[child] < heap[child+1])//选出两个孩子中较大的孩子
			child++;
		if (value>heap[child])	//无须调整；调整结束
			break;
		else
		{
			heap[current] = heap[child];	//孩子节点覆盖当前结点
			current = child;				//向下移动
			child = child * 2 + 1;			
		}
	}
	heap[curren] = value;
};

# endif 