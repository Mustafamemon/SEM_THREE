#include <iostream> 
#include <new> 
#include <cstdlib> 
 
using namespace std; 
int fib1(int n)
{
	return n;
}

int fib(int n, int a , int b,int sum)
{ 
		if (n>2)
		{
			sum=a+b;
			cout<<fib1(sum)<<" ";
			a=b;
			b=sum;
			
		}
		else
		 	return 0;
		fib(--n,a,b,0);
}  
int main()
{
	int n;
	cout<<"Enter the number : ";
	cin>>n;
	cout<<"0 1 ";
	fib(n,0,1,0);
} 

