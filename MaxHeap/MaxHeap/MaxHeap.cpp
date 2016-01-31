// MaxHeap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"MaxHeap.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	MaxHeap<int> heap(11);
	for (int i = 0; i < 10; i++)
	{
		heap.insert(i);
	}
	heap.print();
	cout << endl;
	heap.remove(8);
	heap.print();
 	getchar();
	return 0;
}

