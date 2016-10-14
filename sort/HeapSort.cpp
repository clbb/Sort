#include<iostream>
using namespace std;
void Print(int a[],int n,int j)
{
	cout<<j<<":";
	for(int i = 0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
/*
建最大堆
交换0位置，end位置的元素，保证把最大元素放在最后面，－－end
调堆
重复前面的动作

建堆：
从第一个非叶子节点的父节点开始
调堆：
判断有无右孩子 && 找出左右孩子中最大的一个
和父节点比较，若孩子中较大的一个大于父节点，则和根交换
并调整根和孩子的位置
否则（两个孩子逗比根小）break；

AdjustDown  把大的取下来，删除的时候用
AdjustUp    把小的调下来，插入时候用
*/
void AdjustDown(int a[],int size,int parent)
{
	int child = parent*2+1;
	while(child < size)
	{
		while(child+1 < size && a[child] <  a[child+1])
			child++;
		if(a[parent]  < a[child])
		{
			swap(a[parent],a[child]);
			parent = child;
			child = parent*2+1;
		}
		else
			break;
	}
}
void HeapSort(int a[],int size) 
{
	if(a == NULL || size <= 0)
		return;
	for(int i = (size-2)/2; i<=0; i++)
	{
		AdjustDown(a,size,i);
	}

	//排序思路：将堆中最大的与数组最后一个元素交换,每次都少排一个
	for(int j = 0; j<size; ++j)
	{
		swap(a[0],a[size-1-j]);
		AdjustDown(a,size-1-j,0);
	}	
}
int main()
{
	int a[8] = {4,2,3,5,7,9,0,1};
	HeapSort(a,8);
	for(int i = 0; i<8; ++i)
		cout<<a[i]<<" ";
	cout<<endl;	
	return 0;
}
