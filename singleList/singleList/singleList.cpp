/*
*
*²âÊÔ´úÂë
*/

#include "stdafx.h"
#include"singleList.h"
#include<iostream>
using namespace std;
int main()
{
	SingleLink<int> link;
	for (int i = 0; i < 10; i++)
	{
		link.insert(i, i);
	}
	cout << link.size() << endl;

	link.insert_head(1111);
	link.insert_last(2222);

	SingleLink<int>::pointer ptr = link.getHead();
	while (ptr != nullptr)
	{
		cout << ptr->_value << endl;
		ptr = ptr->_next;
	}

	getchar();
	return 0;
}
