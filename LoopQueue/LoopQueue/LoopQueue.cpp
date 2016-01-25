/*
*测试代码
*/

#include "stdafx.h"
#include"LoopQueue.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	LoopQueue<string> queue(6);
	queue.push("one");
	queue.push("two");
	queue.push("three");
	queue.push("four");
	queue.push("five");
	cout << "队列长度" << queue.size() << endl;
	while (!queue.isEmpty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}
	getchar();
	return 0;

}

