#include<iostream>

using namespace std;
int arr[100]={0},n,a=0;
int Recaman(int i)
{
	if(a!=n)
	{
		cout<<i<<" ";
		arr[a]=i;
		a++;
		if(i-a>0)
		{
			for(int j=0;j<a-1;j++)
			{
				if(arr[j]==(i-a))
				{
					Recaman(i+a);
				}
			}
			Recaman(i-a);
		}
		else
		{
			Recaman(i+a);
		}
	}
}
int main()
{
	cin>>n;
	Recaman(0);
}
