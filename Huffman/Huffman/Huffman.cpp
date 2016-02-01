// Huffman.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Huffman.h"
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	Huffman<int> huff;
	int a[] = { 10,20,30,40 };
	huff.creat(a, 4);	//构建一棵哈夫曼树
	huff.print();		//打印节点间关系
	getchar();
	return 0;
}

