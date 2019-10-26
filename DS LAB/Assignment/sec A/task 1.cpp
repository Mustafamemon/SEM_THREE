#include<iostream>

using namespace std ;
int collatz (int n)
{
	if(n==1)
	{
		cout<<n;
		return 0;
	}
	else
	{
		cout<<n<<" ";
		if(n%2!=0)
		{
			collatz((3*n)+1);
		}
		else
		{
			collatz(n/2);
		}
	}
}
int main()
{
	cout<<"Enter The Number : "; 
	int num ;
	cin>>num ;
	collatz(num);
}
