#include<iostream>
using namespace std;
void Print(int a[],int n,int j)
{
	cout<<j<<":";
	for(int i = 0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

int GetPartion(int a[],int left,int right)
{
	int L = left;
	int R = right-1;
	int key = a[left];
	while(L < R)
	{
		while(L < R && a[key] <  a[R])
			R--;
		if(L < R)
		{
			a[L] = a[R];
			L++;
		}
		while(L < R && a[key] > a[L])
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
	if(a == NULL || left > right)
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
	for(int i = 0; i<8; ++i)
		Print(a,8,i);
	for(int i = 0; i<8; ++i)
		cout<<a[i]<<" ";
	cout<<endl;	
	return 0;
}
