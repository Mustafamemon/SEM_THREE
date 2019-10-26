#include<iostream>
using namespace std;
int main()
{
	int array[4]={1,2,3,4};
	char array1[4]={'a','b','c','d'};
	int *ptr=(int *)array1;
	char *ptr1=(char *)array;
	for(int i=0;i<4;i++)
	{
		cout<<(char)(*ptr+i)<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<(int)(*ptr1+i)<<" ";
	}
}
