#include<iostream>

using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n+2];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int temp=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	int k ;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;int i=0,temp1=arr[n-1];
	while(temp1!=arr[i])
	{
		if(arr[i]%2!=0)
		{
			int temp=arr[i];
			for(int j=i;j<n-1;j++)	
				arr[j]=arr[j+1];
			arr[n-1]=temp;
		}
		else
		{
			i++;
		}
	}	
	if(arr[i]%2!=0)
	{
		int temp=arr[i];
		for(int j=i;j<n-1;j++)	
			arr[j]=arr[j+1];
		arr[n-1]=temp;
	}
	int sum=0;
	k=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]%2==0)
		{
			sum=sum+arr[i];
			++k;
		}
		else
		{
			for(int l=n;l>k;l--)
			{
				arr[l]=arr[l-1];
			}			
			arr[k]=sum;
			k++;
			sum=0;
			break;
		}
	}
	for(int i=k;i<n+1;i++)
	{
		if(arr[i]%2!=0)
		{
			sum=sum+arr[i];
		}	
	}
	arr[n+1]=sum;
	for(int i=0;i<n+2;i++)
	{
		cout<<arr[i]<<" ";
	}
}
