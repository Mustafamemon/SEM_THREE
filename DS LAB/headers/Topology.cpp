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
	
	int i=0;
	result[k]=i;
	i++;
	k++;
	while(k<=m)
	{
		int f1=0;
		for(int j=0;j<n;j++)
		{
			if(array[j][i]==0)
			{
				f1=1;		
			}
			else
			{
				f1=0;
				break;
			}
		}
		if(f1==1)
		{
			result[k]=i;
			k++;
		}
		int f=0;
		if(i==m-1)
		{
			for(int g=0;g<n;g++)
			{
				for(int l=0;l<k;l++)
				{
					if(result[l]==g)
					{
						f=1;
						break; 
					}
				}
				if(f==0)
				{
					i=g;
					break;
				}
			}
		}
		else
			++i;
	}
	for(int p=0;p<=k;p++)
		cout<<result[p]<<" "<<endl ; 
}
