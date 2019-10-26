#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int arr[]={1,2,3,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,10,11,4,4,4};
	int count=0,j;
	for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
	{
		for(j=0;j<i;j++)
			if(arr[i]==arr[j])
				break;
		if(i==j)
			count++;
	}
	cout<<"Count : "<<count;
}
