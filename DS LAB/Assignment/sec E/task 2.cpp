#include<iostream>
using namespace std ;
void _swap (int &a , int &b)
{
	int temp ;
	temp=a;
	a=b;
	b=temp;
}
int permutation(int num,int i,int array[])
{
	if(i==num)
	{
		for(int j=0;j<num;j++)
			cout<<array[j]<<" ";
			cout<<endl;
	}
	else
	{
		for(int k=i;k<num;k++)
		{
			swap(array[i],array[k]);
			permutation(num,i+1,array);
			swap(array[i],array[k]);
		}
	}
}

int main()
{
	int num ;
	cout<<"Enter the Number : ";
	cin>>num;
	int array[num]; 
	for(int i=1;i<=num;i++)
		array[i-1]=i;
	permutation(num,0,array);
}
