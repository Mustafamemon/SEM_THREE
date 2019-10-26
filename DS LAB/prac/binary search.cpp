#include<iostream>
using namespace std;
int binary_search(int arr[] , int n,int i,int data)
{
	if(i<=n)
	{
		int mid = i+(n-i)/2;
		if(arr[mid]==data)
		return mid ;
		if(arr[mid]>data)
		{
			binary_search(arr,mid-1,i,data);
		}
		else	
		{
			binary_search(arr,n,mid+1,data);
		}	
	}
	else		
		return -1;
}
int main()
{
	int arr[]={1,2,3,4,5};
	cout<<binary_search(arr,4,0,6);
}
