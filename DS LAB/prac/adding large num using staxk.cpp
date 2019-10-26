#include<iostream>
#include<stack>
using namespace std;
int main()
{
	string num1,num2 ;
	int carry=0,result=0;
	stack<int> s1 , s2 ,result1;
	cin>>num1;
	cin>>num2;
	for(int i=0;i<num1.length();i++)
	{
		s1.push(num1[i]-48);
	}
	for(int i=0;i<num2.length();i++)
	{
		s2.push(num2[i]-48);
	}
	while(!s1.empty() && !s2.empty())
	{
		result=s1.top()+s2.top()+carry;
		if(result<10)
		{
			result1.push(result);
			carry=0;	
		}
		else
		{
			carry=result/10;
			result=result%10;
			result1.push(result);
		}
		s1.pop();
		s2.pop();
	}
	while((!s1.empty()))
	{
		result=s1.top()+carry;
		if(result<10)
		{
			result1.push(result);
			carry=0;	
		}
		else
		{
			carry=result/10;
			result=result%10;
			result1.push(result);
		}
		s1.pop();
	}
	while((!s2.empty()))
	{
		result=s2.top()+carry;
		if(result<10)
		{
			result1.push(result);
			carry=0;	
		}
		else
		{
			carry=result/10;
			result=result%10;
			result1.push(result);
		}
		s2.pop();
	}
	if(carry!=0)
	result1.push(carry);
	while(!result1.empty())
	{
		cout<<result1.top();
		result1.pop();
	}
}
