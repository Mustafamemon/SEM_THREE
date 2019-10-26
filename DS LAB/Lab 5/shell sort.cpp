#include<iostream>
using namespace std;

int* insertionsort(int *ptr , int size)
{
	int value,j;
	for(int gap=size/2;gap>0;gap/=2)
	{
		for(int i=gap;i<size;i++)
		{
			value=ptr[i];
			for(j=i;j>=gap && ptr[j-gap]>value;j-=gap)
			{
				ptr[j]=ptr[j-gap];
			}
			if(i!=j)
			ptr[j]=value;
		}
	}
	return ptr;
}
int main()
{
	int arr[] = {9,5,3,1,2,0,8,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int *ptr1=insertionsort(arr,size);
	for(int i=0;i<size;i++)
	{
		cout<<ptr1[i]<<" ";
	}
}
