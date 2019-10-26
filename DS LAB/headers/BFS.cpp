#include<iostream>
#include<queue>
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
	queue <int> Q;
	result[0]=1;
	Q.push(0);
	j=Q.back();
	Q.pop();
	cout<<j<<" ";
	while(1)
	{
		for(int i=0;i<m;i++)
		{
			if(array[j][i]==1 && result[i]==0)
			{
				result[i]=1;
				Q.push(i);	
			}
		}
		if(Q.empty())
		{
			break ;
		}
		else
		{
			j=Q.front();
			Q.pop();
			cout<<j<<" ";
		}
	}
}
