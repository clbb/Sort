#include<iostream>
using namespace std;
/*
1.找枢轴
2.递归解决左 左边比枢轴小
3.递归解决右 右边比枢轴大
4 2 3 5 7 9 0 1
2 3 3 5 7 9 1 4

*/
int GetPartion(int a[],int left,int right)
{
	int L = left;
	int R = right-1;
	int key = a[left];
	while(L < R)
	{
		while(L < R && a[R] > key)
			R--;
		if(L < R)
		{
			a[L] = a[R];
			L++;
		}
		while(L < R && a[L] < key)	
			L++;
		if(L < R)
		{
			a[R] = a[L];
			R--;
		}
	}
	a[L] = key;
	return L;
	
}
 void QuickSort(int a[],int left,int right)
 {
 	if(a == NULL || left >= right)
 		return;
 	if(left < right)
	{
		int Partion = GetPartion(a,left,right);
		QuickSort(a,left,Partion);
		QuickSort(a,Partion+1,right);
	}
}
int main()
{
	int a[8] = {4,2,3,5,7,9,0,1};
	QuickSort(a,0,8);
	for(int i = 0;i<8;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
