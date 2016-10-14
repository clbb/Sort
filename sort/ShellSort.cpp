#include<iostream>
using namespace std;
void PrintUnit(int a[],int n,int j)
{
	cout<<j<<":";
	for(int i = 0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
void Print(int a[],int n)
{
	for(int i = 0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;	
} 
void Shell(int a[],int n,int dk)
{
	if(a==NULL || n == 1 || n == 0 || dk < 0)
		return;

	int monitor = 0;
	int j = 0;
	for(int i = dk; i<n; i+=dk)
	{
		if(a[i] < a[i-dk])
		{
			monitor = a[i];
			j = i-dk;
			while(monitor < a[j])//防制越界j=-1!!
			{
				a[j+dk] = a[j];
				j-=dk;
			}
			a[j+dk] = monitor;
		}
		PrintUnit(a,8,i);
	}
}
void ShellSort(int a[],int n)
{
	int dk = n >> 1;
	while(dk >= 1)//相当于插入排序
	{
		Shell(a,n,dk);
		dk >>= 1;
	}

}
int main()
{
	int a[8] = {4,2,3,5,7,9,0,1};
	ShellSort(a,8);
	Print(a,8);
	return 0;
}
