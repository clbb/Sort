#include<iostream>
using namespace std;
void Print(int a[],int n,int j)
{
	cout<<j<<":";
	for(int i = 0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
void SelectSort(int a[],int n)
{
	if(a == NULL || n == 0 || n == 1)
		return;
	int min = 0;
	for(int i = 0; i<n; ++i){
		min = i;
		for(int j = i+1; j<n; ++j)
			if(a[j] < a[min])
				min = j;
				if(min != i)
					std::swap(a[i],a[min]);
	Print(a,8,i);
}
} 

int main()
{
	int a[8] = {4,2,3,5,7,9,0,1};
	SelectSort(a,8);
	for(int i = 0; i<8; ++i)
		cout<<a[i]<<" ";
	cout<<endl;	
	return 0;
}
