// MaxHeap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"MaxHeap.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	MaxHeap<int> heap(11);
	//逐个元素构建大顶堆
	for (int i = 0; i < 10; i++)
	{
		heap.insert(i);
	}
	heap.print();
	cout << endl;
	heap.remove(8);
	heap.print();
	cout << endl;

	//根据指定的数组创建大顶堆
	MaxHeap<int> heap2(11);
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	heap2.createMapHeap(a, 10);
	heap2.print();
	getchar();
	return 0;
}

