#include<iostream>
using namespace std;
int max_num(int arr[],int n)
{
	int temp=0;
	for(int i=0;i<n;i++)
	{
		if(temp<arr[i])
		temp=arr[i];
	}
	return temp;
}

int min_num(int arr[],int n)
{
	int temp=max_num(arr,n);
	for(int i=0;i<n;i++)
	{
		if(temp>arr[i])
		temp=arr[i];
	}
	if(temp>0)
	temp=0;
	return temp;
}
void count_sort(int arr[],int n)
{
	int max=max_num(arr,n);
	int min=min_num(arr,n);
	int output[n];
	int arr1[max+min*-1+1]={0};
	for(int i=min;i<=max;i++)
	{
		for(int j=0;j<n;j++)
		if(arr[j]==i)
		{
			arr1[i-min]++;
		}
	}
	//CF:Cum.fre
	for(int i=1;i<=max+min*-1;i++)
	{
		arr1[i]=arr1[i-1]+arr1[i];
	}
	for(int i=0;i<n;i++)
	{
		arr1[arr[i]-min]--;	
		output[arr1[arr[i]-min]]=arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<output[i]<<" ";
	}
	cout<<endl;
	
}
int main()
{
	int arr[]={-7,-3,1,-4,2,5,6,0,8,9,-9,8,7,4,-2,-6,3,-5,-1};
	count_sort(arr,19);
}
