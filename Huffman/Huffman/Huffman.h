#ifndef _HUFFMAN_TREE_HPP_
#define _HUFFMAN_TREE_HPP_
template <typename T>
struct HuffmanNode
{
	HuffmanNode() = default;
	HuffmanNode(T key)
		:lchild(nullptr), rchild(nullptr), parent(nullptr){}
	~HuffmanNode();

	T key;
	HuffmanNode<T>* lchild;
	HuffmanNode<T>* rchild;
	HuffmanNode<T>* parent;

};

template <typename T>
class Huffman
{
public:
	Huffman();
	~Huffman();

	void preOrder();			  //前序遍历哈夫曼树
	void inOrder();				  //中序遍历哈夫曼树
	void postOrder();			  //后序遍历哈夫曼树

	void creat(T a[], int size);  //创建哈夫曼树
	void destory();				  //销毁哈夫曼树
	void print();				  //打印哈夫曼树

private:
	void preOrder(HuffmanNode<T>* pnode);
	void inOrder(HuffmanNode<T>* pnode);
	void postOrder(HuffmanNode<T>*pnode);
	void print(HuffmanNode<T>*pnode);
	void destroy(HuffmanNode<T>*pnode);

private:
	HuffmanNode<T>* root;
};

/*默认构造函数*/
template<typename T>
Huffman<T>::Huffman()
	:root(nullptr){};

/*创建哈夫曼树*/
template<typename T>
void Huffman<T>::creat(T a[], int size)
{
	//我们每次都要从剩下的节点里挑选两个最小的，适合用小顶堆
};

#endif