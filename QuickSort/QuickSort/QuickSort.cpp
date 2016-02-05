// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"QucikSort.h"
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int array[22] = { 123,432,543,
		66,345,234,
		7,78,9,
		0,678,456,
		34, 54, 724, 
		6, 1234, 12, 
		68, 89, 453,
		8 };
	QuickSort(array, 22);
	for (int i = 0; i < 22; i++)
		cout << array[i] << " ";
	getchar();
	return 0;
}

