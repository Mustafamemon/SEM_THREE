#include<iostream>
using namespace std;
int fib(int n)
{
	if(n<=2 )
	 	return 1 ;
	else if(n%2!=0)
	{
		int k=(n+1)/2; 
		int k1=(n-1)/2;
		return ((fib(k)*fib(k))+(fib(k1)*fib(k1)));
	}
	else if(n%2==0)
	{
		int k=n/2+1;
		int k1=n/2-1;
		return ((fib(k)*fib(k))-(fib(k1)*fib(k1)));	
	}
	
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
		cout<<fib(i)<<" ";
}
