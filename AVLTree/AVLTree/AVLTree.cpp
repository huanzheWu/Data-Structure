// AVLTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "AVLTree.h"
#include <iostream>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	AVLTree<int> a;

    vector<int> val{ 13, 8, 21, 3, 10, 17, 25, 2, 6, 9, 12, 15, 19, 23, 27, 1, 5, 7, 11, 14, 16, 18, 20, 22, 24, 26, 28, 4 };

	for (size_t i = 0; i < val.size(); i++)
		a.insert(val[i]);
	cout << "���ߣ�" << a.height() << endl;
	cout << "ǰ�����:"  << endl;
	a.preOrder();

	cout << "�������:" << endl;
	a.InOrder();

	cout << "�������:" << endl;
	a.postOrder();
	
    cout << endl;

    a.show();

	//cout << "ɾ��Ԫ��9"<<endl;
	//a.remove(9);
    cout << "ɾ��Ԫ��12" << endl;
    a.remove(12);
    cout << endl;

    a.show();

	AVLTreeNode<int>* b = a.search_iterator(10);

	if (b != nullptr)
		cout << b->key << endl;
	else
		cout << "�޴�Ԫ��" << endl;

	//system("pause");

	return 0;
}

