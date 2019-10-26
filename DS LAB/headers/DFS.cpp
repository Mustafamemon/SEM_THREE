#include<iostream>
#include<stack>
using namespace std; 
int main()
{
	int m , n ,k = 0 ;
	cin>>m>>n;
	int array[m][n];
	int result[m]={0};
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>array[i][j];
	}
	int j; 
	stack <int> s; 
	s.push(0);
	result[0]=1;
	j=s.top();
	cout<<j<<" ";
	s.pop();
	while(1)
	{
		for(int i=0;i<m;i++)
		{
			if(array[j][i]==1 && result[i]==0)
			{	
				result[i]=1;
				s.push(i);
			}
		}
		if(s.empty())
		{
			break;
		}
		else
		{
			j=s.top();
			cout<<j<<" ";
			s.pop();
		}
	}
}
