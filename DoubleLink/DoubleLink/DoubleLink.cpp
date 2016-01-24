/*
双链表测试代码
作者：huanzheWu
时间：2016/1/24
*/

#include "stdafx.h"
#include"DoubleLink.h"
#include<iostream>
using namespace std;


int main()
{
	DoubleLink<int> dlink;
	//插入测试
	for (int i = 0; i < 10; i++)
	{
		dlink.insert(0, i+10);
	}
	dlink.insert(0,  100);
	dlink.insert_last(1000);
	cout <<"链表长度:"<< dlink.size() << endl;

	//删除测试
	dlink.delete_front();
	dlink.delete_last();
	dlink.del(3);


	DoubleLink<int>::pointer ptr = dlink.getHead();
	ptr = ptr->next_ptr;
	while (ptr != dlink.getHead())
	{
		cout << ptr->_value<<endl;
		ptr = ptr->next_ptr;
	}

	getchar();
	return 0;
}
