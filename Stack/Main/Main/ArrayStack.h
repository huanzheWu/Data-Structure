# ifndef ARRAY_STACK_HPP
# define ARRAY_STACK_HPP

template<typename T>
class ArrayStack
{
public:
	ArrayStack(int s = 10);
	~ArrayStack();

public:
	T top();
	void push(T t);
	T pop();
	bool isEmpty();
	int size();

private:
	int count;
	int capacity;
	T * array;
};
 template <typename T>
 ArrayStack<T>::ArrayStack(int s = 10)
	 :count(0), capacity(s), array(nullptr)
 {
	 array = new T[capacity];
 };
 
 template<typename T>
 ArrayStack<T>::~ArrayStack()
 {
	 if (array)
	 {
		 delete[]array;
		 array = nullptr;
	 }
 };

 template <typename T>
 bool ArrayStack<T>::isEmpty()
 {
	 return count == 0;
 };

 template <typename  T>
 int ArrayStack<T>::size()
 {
	 return count;
 };

 template <typename T>
void ArrayStack<T>::push(T t)
 {
	 if (count != capacity)
	 {
		 array[count++] = t;
	 }
 };

 template <typename T>
 T ArrayStack<T>::pop()
 {
	 if (count != 0)
	 {
		 return array[--count];
	 }
 };

 template <typename T>
 T ArrayStack<T>::top()
 {
	 if (count != 0)
	 {
		 return array[count - 1];
	 }
 };



# endif 