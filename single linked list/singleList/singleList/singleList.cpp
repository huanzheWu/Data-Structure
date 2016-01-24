// singleList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"singleList.h"
#include<iostream>
using namespace std;
int main()
{
	SingleLink<int> link;
	for (int i = 0; i < 3; i++)
	{
		SingleLink<int>::pointer ptr =link.insert_after(i, i);
		if (ptr!=nullptr)
			cout << ptr->_value<<endl;
	}
	cout << endl;
	link.insert_head(10010);
	link.insert_last(2334);

	while (!link.isEmpty())
	{
		SingleLink<int>::pointer ptr  = link.delete_head();
		if (ptr!=nullptr)
			cout << ptr->_value << endl;
	}
	getchar();
	return 0;
}
