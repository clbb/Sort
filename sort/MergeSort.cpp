#include<iostream>
/////////////////
using namespace std;
//1 3 5 7 9 2 4 6 8 10
#define _SIZE_ 10

void PrintUnit(int a[],int n)
{
	for(int i = 0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

void Merge(int a[],int left,int mid,int right)
{
	int tmp[1000]={0};
	for(int i = 0; i<1000; i++)
		tmp[i] = a[i];
 
	int sort1 = left;
	int sort2 = mid+1;
	int cur = left;
	while(sort1 <= mid && sort2 <= right )
	{ 
		if(tmp[sort1] <= tmp[sort2])
			a[cur++] = tmp[sort1++];
		else
			a[cur++] = tmp[sort2++];
	}
	while(sort1 <= mid)
		a[cur++] = tmp[sort1++];
	while(sort2 <= right)
		a[cur++] = tmp[sort2++];

}

void MergeSort(int a[],int left,int right)
{
	if( left >= right)
		return;
	cout<<"why here error"<<endl;
	int mid = (left+right)/2;
	MergeSort(a,left,mid);
	MergeSort(a,mid+1,right);
	Merge(a,left,mid,right);

} 

int main()
{
	int a[10] = {1,3,5,7,9,2,4,6,8,10};
	MergeSort(a,0,9);
	for(int i = 0; i<10; ++i)
		cout<<a[i]<<" ";
	cout<<endl;	
	return 0;
}
