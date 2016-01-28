// AVLTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"AVLTree.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	AVLTree<int> a;
	for (int i = 0; i < 10; i++)
		a.insert(i);
	cout << "树高：" << a.height() << endl;
	cout << "前序遍历:"  << endl;
	a.preOrder();

	cout << "中序遍历:" << endl;
	a.InOrder();

	cout << "后序遍历:" << endl;
	a.postOrder();
	
	cout << "删除元素10"<<endl;
	a.remove(10);

	AVLTreeNode<int>* b = a.search_iterator(10);

	if (b != nullptr)
		cout << b->key;
	else
		cout << "无此元素" << endl;

	getchar();

	return 0;
}

