#include<iostream>
using namespace std;
int main()
{
	int n ,n1=1;
	cin>>n;
	char arr[n],copy[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=i+1+64;
		copy[i]=i+1+64;
	}
	int fac=1;
	for(int i=n;i>0;i--)
	{
		fac=fac*i;
	}
	char temp;
	int k=1,g=2;
	for(int l=0;l<n;l++)
		cout<<copy[l];
	while(n1!=n+1)
	{		
		k=1;g=2;
		for(int j=0;j<n-1 && k!=n;j++)
		{
			temp=copy[g];
			copy[g]=copy[k];
			copy[k]=temp;
			g++;
			if(g>=n)
				g=1;
			
			cout<<endl;
			for(int l=0;l<n;l++)
			cout<<copy[l];
			++k;
		}
		if(n1!=n)
		{
			copy[0]=arr[n1];
			copy[n1]=arr[0];
			for(int m=1;m<n;m++)
			{
				if(m!=n1)
				copy[m]=arr[m];
			}
			cout<<endl;
			for(int l=0;l<n;l++)
			cout<<copy[l];
		}
		n1++;
	}
}
