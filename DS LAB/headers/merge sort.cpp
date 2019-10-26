#include<iostream>
using namespace std;
void merge(int lA[],int rA[],int array[] ,int llen,int rlen)
{
	int i,j,k;
	i=j=k=0;
	while(i<llen && j<rlen)
	{
		if(lA[i]<rA[j])
		{
			array[k]=lA[i];
			i++;
		}
		else
		{
			array[k]=rA[j];	
			j++;
		}
		k++;
	}
	while(i<llen)
	{
		array[k]=lA[i];
		i++;
		k++;
	}
	while(j<rlen)
	{
		array[k]=rA[j];
		j++;
		k++;
	}
}
int mergesort(int A[],int size)
{
	int mid=size/2;
	if(mid<1)
	return 0;
	else
	{
		int leftarray[size-mid],rightarray[mid];
		for(int i=0;i<mid;i++)
		{
			rightarray[i]=A[i];
		}
		for(int i=mid;i<size;i++)
		{
			leftarray[i-mid]=A[i];		
		}
		mergesort(leftarray,size-mid);
		mergesort(rightarray,mid);
		
		merge(leftarray,rightarray,A,sizeof(leftarray)/4,sizeof(rightarray)/4);
	}
}
int main()
{
	int A[]={1,0,4,5,6,2,3,9,5,1,3,9};
	mergesort(A,sizeof(A)/sizeof(*A));
	for(int i=0;i<sizeof(A)/sizeof(*A);i++)
	cout<<A[i]<<" ";
}
