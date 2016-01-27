// AVLTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"AVLTree.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	AVLTree<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(8);
	a.insert(9);
	a.insert(10);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	
	a.InOrder();
	cout << endl;
	a.remove(10);

	a.insert(11);
	a.InOrder();
	a.destory();
	a.InOrder();


	AVLTreeNode<int>* b = a.search_recurse(11);
	if (b != nullptr)
		cout << b->key;
	getchar();
	return 0;
}

