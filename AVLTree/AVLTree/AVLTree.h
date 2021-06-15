/*
*content:AVL��
*Author : huanzheWu
*date: 2016/1/27
*
*/
#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_
template <typename T>
struct AVLTreeNode
{
	AVLTreeNode(T value, AVLTreeNode<T>*l, AVLTreeNode<T>*r)
	:key(value), lchild(l), rchild(r){}

	T key;
	int height; 
	AVLTreeNode<T>* lchild;
	AVLTreeNode<T>* rchild;
};

template<typename T>
class AVLTree
{
public:
	AVLTree();			//���캯��
	~AVLTree();			//��������

    void show(); // tree print

	void preOrder();	//ǰ�����AVL��
	void InOrder();		//�������AVL��	
	void postOrder();	//�������AVL��

	void print();		//��ӡAVL��
	void destory();		//����AVL��

	void insert(T key);	//����ָ��ֵ�Ľڵ�
	void remove(T key);	//�Ƴ�ָ��ֵ�Ľڵ�

	AVLTreeNode<T>* search_recurse(T key);	//���õݹ��㷨����ָ��ֵ�Ĳ���
	AVLTreeNode<T>* search_iterator(T key);	//���õ����㷨����ָ��ֵ�Ĳ���
	T minimum();		//����AVL�е���Сֵ
	T maximum();		//����AVL�е����ֵ

	int height();		//�������ĸ߶�

private:
	AVLTreeNode<T>* root;	//AVL���ĸ��ڵ�

private:
    void show(AVLTreeNode<T>* pnode, size_t indent) const; // tree print

	void preOrder(AVLTreeNode<T>* pnode) const;
	void inOrder(AVLTreeNode<T>* pnode) const;
	void postOrder(AVLTreeNode<T>* pnode) const;

	void print(AVLTreeNode<T>* pnode,T key, int direction) const;
	void destory(AVLTreeNode<T>* & pnode);

	int height(AVLTreeNode<T>* pnode) ;
	int max(int a, int b);

	AVLTreeNode<T>* insert(AVLTreeNode<T>* &pnode, T key);		
	AVLTreeNode<T>* remove(AVLTreeNode<T>* & pnode, T key); //ɾ��AVL���нڵ�pdel�������ر�ɾ���Ľڵ�

	AVLTreeNode<T>* minimum(AVLTreeNode<T>*pnode)const;
	AVLTreeNode<T>* maximum(AVLTreeNode<T>*pnode)const;

	AVLTreeNode<T>* search_recurse(AVLTreeNode<T>* pnode, T key) const;
	AVLTreeNode<T>* search_iterator(AVLTreeNode<T>* pnode, T key) const;

	AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* pnode);		//����:��������
	AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* pnode);		//����:��������
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* pnode);	//˫��:����������������
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* pnode);	//˫��:����������������

};

/*���캯��*/
template <typename T>
AVLTree<T>::AVLTree()
:root(nullptr){};

/*��������*/
template <typename T>
AVLTree<T>::~AVLTree()
{
	destory(root);
}

/*���������еĽϴ���*/
template<typename T>
int AVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
};

/*�����������ڵ�ֵ*/
template <typename T>
AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T>* pnode)const
{
	if (pnode != nullptr)
	{
		while (pnode->rchild != nullptr)
			pnode = pnode->rchild;
		return pnode;
	}
	return nullptr;
};

template<typename T>
T AVLTree<T>::maximum()
{
	AVLTreeNode<T>* presult = maximum(root);
	if (presult != nullptr)
		return presult->key;
};

/*����������С�ڵ�ֵ*/
template <typename T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* pnode)const
{
	if (pnode != nullptr)
	{
		while (pnode->lchild != nullptr)
			pnode = pnode->lchild;
		return pnode;
	}
	return nullptr;
};

template<typename T>
T AVLTree<T>::minimum()
{
	AVLTreeNode<T>* presult = minimum(root);
	if (presult != nullptr)
		return presult->key;
};

/*����һ�����ĸ߶�*/
template <typename T>
int AVLTree<T>::height(AVLTreeNode<T>* pnode) 
{
	if (pnode != nullptr)
	{
		return pnode->height;
	}
	return 0;																//����ǿ������߶�Ϊ0
};

template <typename T>
int AVLTree<T>::height()
{
	return height(root);
};

/*����ת����*/
/*pnodeΪ��Сʧ�������ĸ��ڵ�*/
/*������ת��ĸ��ڵ�*/
template<typename T>
AVLTreeNode<T>* AVLTree<T>::leftRotation(AVLTreeNode<T>* proot)
{
	AVLTreeNode<T>* prchild = proot->rchild;
	proot->rchild = prchild->lchild;
	prchild->lchild = proot;

	proot->height = max(height(proot->lchild),height(proot->rchild))+1;     //���½ڵ�ĸ߶�ֵ
	prchild->height = max(height(prchild->lchild), height(prchild->rchild)) + 1; //���½ڵ�ĸ߶�ֵ

	return prchild;					 
};

/*����ת����*/
/*pnodeΪ��Сʧ�������ĸ��ڵ�*/
/*������ת��ĸ��ڵ�*/
template <typename  T>
AVLTreeNode<T>* AVLTree<T>::rightRotation(AVLTreeNode<T>*proot)
{
	AVLTreeNode<T>* plchild = proot->lchild;
	proot->lchild = plchild->rchild;
	plchild->rchild = proot;

	proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;     //���½ڵ�ĸ߶�ֵ
	plchild->height = max(height(plchild->lchild), height(plchild->rchild)) + 1; //���½ڵ�ĸ߶�ֵ

	return plchild;
};

/*�����������ת*/
/*����prootΪ��Сʧ�������ĸ��ڵ�*/
/*������ת��ĸ��ڵ�*/
template <typename T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* proot)
{
	proot->lchild= leftRotation(proot->lchild);
	return rightRotation(proot);
};
/*������������*/
/*����prootΪ��Сʧ�������ĸ��ڵ�*/
/*������ת��ĸ��ڵ�*/
template<typename T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* proot)
{
	proot->rchild = rightRotation(proot->rchild);
	return leftRotation(proot);
};

/*�������*/
/*�ݹ�ؽ��в���*/
/*���ز����ĸ��ڵ�*/
template <typename T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &pnode, T key)
{
	if (pnode == nullptr)	//Ѱ�ҵ������λ��
	{
		pnode = new AVLTreeNode<T>(key, nullptr, nullptr);
	}
	else if (key > pnode->key)	//����ֵ�ȵ�ǰ���ֵ�󣬲��뵽��ǰ������������
	{
		pnode->rchild = insert(pnode->rchild, key);
		if (height(pnode->rchild) - height(pnode->lchild) == 2) //��������ʧ��
		{
			if (key > pnode->rchild->key) //���һ���������������ҽڵ㣬��������
				pnode=leftRotation(pnode);
			else if (key < pnode->rchild->key)  //���������������������ڵ�,��������������ת
				pnode=rightLeftRotation(pnode);
		}
	}
	else if (key < pnode->key) //����ֵ�ȵ�ǰ�ڵ�ֵС�����뵽��ǰ������������
	{
		pnode->lchild = insert(pnode->lchild, key);
		if (height(pnode->lchild) - height(pnode->rchild) == 2) //������뵼��ʧ��
		{
			if (key < pnode->lchild->key)		//����������뵽�����������ӽڵ��ϣ���������
				pnode = rightRotation(pnode);
			else if (key>pnode->lchild->key)
				pnode = leftRightRotation(pnode);//����ģ����뵽���������Һ��ӽڵ��ϣ��������������ת
		}
	}
	pnode->height = max(height(pnode->lchild), height(pnode->rchild)) + 1;
	return pnode;
};

template <typename T>
void AVLTree<T>::insert(T key)
{
	insert(root, key);
};


/*�ݹ����ָ��Ԫ��*/
template <typename T>
AVLTreeNode<T>* AVLTree<T>::search_recurse(T key)
{
	return search_recurse(root,key);
};
template <typename T>
AVLTreeNode<T>* AVLTree<T>::search_recurse(AVLTreeNode<T>* pnode, T key) const
{
	if (pnode != nullptr)
	{
		if (key == pnode->key)
			return pnode;
		if (key > pnode->key)
			return search_recurse(pnode->rchild,key);
		else
			return search_recurse(pnode->lchild,key);
	}
	return nullptr;
};

/*�ǵݹ����ָ��Ԫ��*/
template <typename T>
AVLTreeNode<T>* AVLTree<T>::search_iterator(T key)
{
	return search_iterator(root, key);
};
template <typename T>
AVLTreeNode<T>* AVLTree<T>::search_iterator(AVLTreeNode<T>* pnode, T key) const
{
	while (pnode != nullptr)
	{
		if (pnode->key == key)
			return pnode;
		else if (key > pnode->key)
			pnode = pnode->rchild;
		else
			pnode = pnode->lchild;
	}
	return nullptr;
};


/*ɾ��ָ��Ԫ��*/
template<typename T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* & pnode, T key)
{
	if (pnode != nullptr)
	{
		if (key == pnode->key)			//�ҵ�ɾ���Ľڵ�
		{
			//��AVLҲ�Ƕ�����������ɾ���ڵ�Ҫά�������������������
			if (pnode->lchild != nullptr&&pnode->rchild != nullptr)		//�����Ҷ���Ϊ��
			{
				if (height(pnode->lchild) > height(pnode->rchild))		//����������������
				{
					//ʹ�����������ڵ������汻ɾ�ڵ㣬��ɾ�������ڵ�
					AVLTreeNode<T>* ppre = maximum(pnode->lchild);		//���������ڵ�
					pnode->key = ppre->key;								//�����ڵ��ֵ���ǵ�ǰ���
					pnode->lchild = remove(pnode->lchild, ppre->key);	//�ݹ��ɾ�����ڵ�
				}
				else
				{
					//ʹ����С�ڵ������汻ɾ�ڵ㣬��ɾ������С�ڵ�
					AVLTreeNode<T>* psuc = minimum(pnode->rchild);		//����������С�ڵ�
					pnode->key = psuc->key;								//����С�ڵ�ֵ���ǵ�ǰ���
					pnode->rchild = remove(pnode->rchild, psuc->key);	//�ݹ��ɾ����С�ڵ�
				}

                pnode->height = max(height(pnode->lchild), height(pnode->rchild)) + 1;

			}
			else
			{
				AVLTreeNode<T> * ptemp = pnode;
                if (pnode->lchild != nullptr)
                    pnode = pnode->lchild;
                else if (pnode->rchild != nullptr)
                    pnode = pnode->rchild;
                else
                    pnode = nullptr;
				delete ptemp;

                if (pnode != nullptr)
                    pnode->height = 1;
				return pnode;
			}
		
		}
		else if (key > pnode->key)		//Ҫɾ���Ľڵ�ȵ�ǰ�ڵ����������������ɾ��
		{
			pnode->rchild = remove(pnode->rchild, key);

			if (height(pnode->lchild) - height(pnode->rchild) == 2) //ɾ���������ڵ㵼�²�ƽ��:�൱��������������
			{
				if (height(pnode->lchild->rchild)>height(pnode->lchild->lchild))
					pnode = leftRightRotation(pnode);				//�൱�������
				else
					pnode = rightRotation(pnode);					//�൱�������
			}

            pnode->height = max(height(pnode->lchild), height(pnode->rchild)) + 1;
		}
		else if (key < pnode->key)		//Ҫɾ���Ľڵ�ȵ�ǰ�ڵ�С����������������ɾ��
		{
			pnode->lchild = remove(pnode->lchild, key);

			if (height(pnode->rchild) - height(pnode->lchild) == 2)  //ɾ���������ڵ㵼�²�ƽ�⣺�൱������������һ
			{
				if (height(pnode->rchild->lchild)>height(pnode->rchild->rchild))
					pnode = rightLeftRotation(pnode);				
				else
					pnode = leftRotation(pnode);
			}

            pnode->height = max(height(pnode->lchild), height(pnode->rchild)) + 1;
		}
		return pnode;
	}
	return nullptr;
};
template<typename T>
void AVLTree<T>::remove(T key)
{
	root =remove(root, key);
};


template<typename T>
void AVLTree<T>::show()
{
    show(root, 0);
}


template<typename T>
void AVLTree<T>::show(AVLTreeNode<T>* pnode, size_t indent) const
{
    if (pnode->rchild != nullptr)
        show(pnode->rchild, indent + 1);
    for (size_t i = 0; i < indent; ++i)
        cout << '\t';

    cout << pnode->key << endl;

    if (pnode->lchild != nullptr)
        show(pnode->lchild, indent + 1);
}

/*�������*/
template<typename T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
		inOrder(pnode->lchild);
		cout << pnode->key << endl;
		inOrder(pnode->rchild);
	}
};

template<typename T>
void AVLTree<T>::InOrder()
{
	inOrder(root);
};

/*ǰ�����*/
template<typename T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
		cout << pnode->key << endl;
        preOrder(pnode->lchild);
        preOrder(pnode->rchild);
	}
};
template<typename T>
void AVLTree<T>::preOrder()
{
	preOrder(root);
};

/*���б���*/
template<typename T>
void AVLTree<T>::postOrder(AVLTreeNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
        postOrder(pnode->lchild);
        postOrder(pnode->rchild);
		cout << pnode->key << endl;
	}
}
template<typename T>
void AVLTree<T>::postOrder()
{
	postOrder(root);
};


/*����AVL��*/
template<typename T>
void AVLTree<T>::destory(AVLTreeNode<T>* & pnode)
{
	if (pnode != nullptr)
	{
		destory(pnode->lchild);
		destory(pnode->rchild);
		delete pnode;
		pnode = nullptr;
	}
};
template<typename T>
void AVLTree<T>::destory()
{
	destory(root);
}
#endif