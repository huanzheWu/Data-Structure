// Main.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"ArrayStack.h"
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ArrayStack <int> p(5);
	for (int i = 0; i < 5; i++)
	{
		p.push(i);
	}
	cout << "栈的大小:"<<p.size() << endl;
	cout << "栈是否为空:"<<p.isEmpty() << endl;
	cout << "栈顶元素："<<p.top() << endl;
	cout << "依次出栈:" << endl;
	while (!p.isEmpty())
	{
		cout << p.pop() << endl;
	}
	getchar();
	return 0;
}

