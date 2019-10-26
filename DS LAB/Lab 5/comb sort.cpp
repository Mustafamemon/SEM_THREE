#include<iostream>
using namespace std;

void swap1(int &a , int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int* bubblesort(int *ptr , int size)
{
	for(int gap=size-1;gap>=1;gap/=1.3)
	{
		for(int j=size-1;j>=gap;j--)
		{
			if(ptr[j]<ptr[j-gap])
			{
				cout<<gap<<" ";
			
				swap1(ptr[j],ptr[j-gap]);
			}
		}
	}
	return ptr;
}
int main()
{
	int arr[] = {1,0,5,3,2,6};
	int size=sizeof(arr)/sizeof(arr[0]);
	int *ptr1=bubblesort(arr,size);
	for(int i=0;i<size;i++)
	{
		cout<<ptr1[i]<<" ";
	}
}
