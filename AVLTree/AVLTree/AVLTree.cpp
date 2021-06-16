// AVLTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "AVLTree.h"
#include <iostream>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	AVLTree<int> a;

    vector<int> val{ 10, 9, 11, 12 };
    //{ 13, 8, 21, 3, 10, 16, 29, 1, 6, 9, 11, 14, 19, 26, 31, 2, 4, 7, 12, 15, 17, 20, 24, 28, 30, 33, 5, 18, 23, 25, 27, 32, 22 };
    //{ 8, 3, 10, 1, 6, 9, 11, 2, 4, 7, 12, 5 };
    //{ 10, 9, 11, 12 };
    
    
    // other
    //{ 13, 8, 21, 3, 10, 17, 25, 2, 6, 9, 12, 15, 19, 23, 27, 1, 5, 7, 11, 14, 16, 18, 20, 22, 24, 26, 28, 4 };

	for (size_t i = 0; i < val.size(); i++)
		a.insert(val[i]);
	cout << "树高：" << a.height() << endl;
	cout << "前序遍历:"  << endl;
	a.preOrder();

	cout << "中序遍历:" << endl;
	a.InOrder();

	cout << "后序遍历:" << endl;
	a.postOrder();
	
    cout << endl;

    a.show_build();
    cout << endl;

    a.show();

	cout << "删除元素9"<<endl;
	a.remove(9);
    //cout << "删除元素12" << endl;
    //a.remove(12);
    cout << endl;

    a.show();

    

	//AVLTreeNode<int>* b = a.search_iterator(10);

	//if (b != nullptr)
	//	cout << b->key << endl;
	//else
	//	cout << "无此元素" << endl;

	//system("pause");

	return 0;
}

