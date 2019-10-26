#include<iostream>
#include<cmath>
using namespace std;
int get_pivot(int A[],int n)
{
	int Arr[3]={A[0],A[n/2],A[n]};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		if(Arr[j]>Arr[j+1])
		swap(Arr[j],Arr[j+1]);	
	}
	for(int i=0;i<n;i++)
		if(Arr[1]==A[i])
			return i;
}
int partition(int A[],int start ,int end)
{
	int a=get_pivot(A,end);
	int pivot=A[a];
	int index=start;
	for(int i=start;i<=end;i++)
	{
		int b;
		cin>>b;
		if(A[i]<=pivot && i!=a)
		{
			swap(A[i],A[index]);
			index++;	
		}
	}
	swap(A[index],A[a]);
	cout<<index<<"\n";
	for(int i=start;i<=end;i++)
		cout<<A[i]<<" ";
		cout<<endl;
	return index;
}
void quick_sort(int A[],int start , int end)
{
	if(start<end)
	{
		int index=partition(A,start,end);
		quick_sort(A,start,index-1);
		quick_sort(A,index+1,end);
	}
}

int main()
{
	int arr[]={7,6,5,4,3,2,1,0};
	quick_sort(arr,0,7);
	cout<<endl;
	for(int i=0;i<8;i++)
	cout<<arr[i]<<" ";
}
