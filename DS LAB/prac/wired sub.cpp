#include<iostream>
using namespace std;
int main()
{
	long long int a,b;
	cin>>a>>b;
	step:
	if(a==0 || b==0)
	{
		cout<<a<<" "<<b;
		return 0;
	}
	else if(a>=2*b)
	{
		a=a%(2*b);
		goto step;
	}
	else if(b>=2*a)
	{
		b=b%(2*a);
		goto step;
	}
	cout<<a<<" "<<b;
	return 0;
}
