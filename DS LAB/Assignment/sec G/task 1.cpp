#include<iostream>
using namespace std;
int i=0,a;
int gcd(int x , int y)
{
	i++;
	if(i>x || i>y)
	{
		return a ;
	}
	else if(x%i==0 && y%i==0)
	{
		a=i;
	}
	gcd(x,y);
}
int main()
{
 	cout<<gcd(100,20);
}
