#include<iostream>
using namespace std;
/*插入排序
前面走过的位置都有序 
*/
void PrintUnit(int a[],int n,int j)
{
	cout<<j<<":";
	for(int i = 0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;	
}
void Print(int a[],int n)
{
	for(int i = 0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;	
}
void InsertSort(int a[],int n)
{
	if(a == NULL || n == 0 || n == 1)
		return;
	int monitor = 0;
	int j = 0;
	for(int i = 1; i<n; ++i)
	{
		if(a[j] < a[j+1])
		{
			monitor = i;
			j = i-1;
			while(monitor < a[j])
			{
				a[j+1] = a[j];
				j++;
			}
			a[j+1] = a[monitor];
		}
			PrintUnit(a,8,i);	
	}
} 
int main()
{
	int a[8] = {4,2,3,5,7,9,0,1};
	InsertSort(a,8);
	Print(a,8);	 
	return 0;
}
