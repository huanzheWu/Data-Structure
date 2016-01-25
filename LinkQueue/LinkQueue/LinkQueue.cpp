/*
*测试代码
*/
#include "stdafx.h"
#include "LinkQueue.h"
#include<string>
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	LinkQueue<string> lqueue;
	lqueue.push("one");
	lqueue.push("two");
	lqueue.push("three");
	lqueue.push("four");
	lqueue.push("five");
	cout << "队列的大小" << lqueue.size() << endl;
	while (!lqueue.isEmpty())
	{
		cout << lqueue.front() << endl;
		lqueue.pop();
	}
	getchar();
	return 0;
}

