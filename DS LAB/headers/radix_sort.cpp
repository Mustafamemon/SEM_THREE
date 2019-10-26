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

void count_sort(int arr[],int arr2[],int output[],int n)
{
	int max=max_num(arr2,n);
	int min=min_num(arr2,n);
	int arr1[max-min+1]={0};
	for(int i=min;i<=max;i++)
	{
		for(int j=0;j<n;j++)
			if(arr2[j]==i)
				arr1[i-min]++;
	}
	//CF:Cum.fre
	for(int i=1;i<=max-min;i++)
	{
		arr1[i]=arr1[i-1]+arr1[i];
	}
	for(int i=0;i<n;i++)
	{
		arr1[arr2[i]-min]--;	
		output[arr1[arr2[i]-min]]=arr[i];
	}
}
void radix_sort(int arr[],int n)
{
	int max=max_num(arr,n);
	int i=10;
	while(max>0)
	{
		max/=i;
		i*=10;
	}
	int arr1[n],arr2[n];
	for(int j=10;j<=i;j*=10)
	{
		for(int k=0;k<n;k++)
		{
			arr1[k]=arr[k]%j;
		}
		count_sort(arr,arr1,arr2,n);
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr2[i]<<" ";
	}
}
int main()
{
	int arr[]={63,-51,44,33,24,10,60,50,40,30,20,-100};
	radix_sort(arr,12);
	
}
