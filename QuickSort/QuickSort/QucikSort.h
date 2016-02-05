#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

template <typename T>
void Swap(T & a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
/*快速排序*/
template <typename T>
int Partition(T arr[], int start, int end)
{
		T x = arr[start]; //保存基准的值,这里并没有使用随机基准
		int i = start;
		int j = start + 1;
		while (j <end)
		{
			if (arr[j] >=x)
			{
				i = i+1;
				Swap(arr[i], arr[j]);
			}
			j++;
		}
		Swap(arr[i], arr[start]);
		return i;
}

template <typename T>
void QuickSort(T arr[], int start, int end)
{
	if (start < end)
	{
		int i = Partition(arr, start, end);
		QuickSort(arr, start, i );
		QuickSort(arr, i + 1, end);
	}
}

template <typename T>
void QuickSort(T arr[], int length)
{
	QuickSort(arr, 0, length);
}
 
#endif