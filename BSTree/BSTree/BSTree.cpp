// BSTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BSTree.h"
#include<iostream>
using namespace std;
int main()
{
	BSTree<int> t;
	t.insert(62);
	t.insert(58);
	t.insert(47);
	t.insert(51);
	t.insert(35);
	t.insert(37);
	t.insert(88);
	t.insert(73);
	t.insert(99);
	t.insert(93);
	t.insert(95);
	cout << "前序遍历:" << endl;
	t.preOrder() ;
	cout << endl << "中序遍历：" << endl;
	t.inOrder();
	cout << endl << "后续遍历:" << endl;
	t.postOrder();

	cout << "最大数:" << t.search_maximum() << endl;
	cout << "最小数:" << t.search_minimun() << endl;

/*	int i;

	t.remove(62);	
	while (cin >> i)
	{
		BSNode<int> * pnode = t.search_recursion(i);
		if (pnode)
			cout << "find" << pnode->value << endl;
		else
			cout << "not find" << endl;
	}*/

	t.destory();
	cout << endl << "中序遍历：" << endl;
	t.inOrder();
	getchar();
	return 0;
}
