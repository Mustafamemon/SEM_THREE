#include<iostream>
#include<cmath>
using namespace std;
int partition(int A[],int start ,int end)
{
	int pivot=A[end];
	int index=start;
	for(int i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			swap(A[i],A[index]);
			index++;	
		}
	}
	swap(A[index],A[end]);
	
	/*
		cout<<index<<"\n";
		for(int i=start;i<=end;i++)
			cout<<A[i]<<" ";
			cout<<endl;
	*/
	return index;
}

int get_pivot(int A[],int start,int end)
{
	int Arr[3]={A[start],A[end/2],A[end]};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
			if(Arr[j]>Arr[j+1])
				swap(Arr[j],Arr[j+1]);	
	}
	for(int i=0;i<=end;i++)
	if(Arr[1]==A[i])
	{
		swap(A[end],A[i]);
		return partition(A,start,end);
	}
}

void quick_sort(int A[],int start , int end)
{
	if(start<end)
	{
		int index=get_pivot(A,start,end);
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
