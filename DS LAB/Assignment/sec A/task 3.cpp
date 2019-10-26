#include<iostream>
using namespace std;
void bubble_sort(int arr[] , int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<n-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					swap(arr[j],arr[j+1]);
				}
			}
		}
		else
		{
			for(int j=n-1;j>0;j--)
			{
				if(arr[j]<arr[j-1])
				{
					swap(arr[j],arr[j-1]);
				}
			}	
		}
		for(int k=0;k<n;k++)
		cout<<arr[k]<<" ";
		cout<<endl;
	}
	
}
int main()
{
	int arr[]={9,8,7,6,5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,n);
}
