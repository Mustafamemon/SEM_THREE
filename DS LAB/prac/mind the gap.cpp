#include<iostream>

using namespace std;
int main()
{
	int n,s;
	
	cin>>n>>s;
	int h[n] ,m[n],time[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>h[i]>>m[i];
		time[i]=(h[i]*60)+m[i];
	}
	if(s+1<=time[0])
	{
		cout<<"0 0";
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		int t=(s*2)+2+time[i];
		if(t<=time[i+1])
		{
			time[i]=time[i]+s+1;
			cout<<time[i]/60<<" "<<time[i]%60;
			return  0;
		}
		
		
	}
	time[n-1]=time[n-1]+s+1;
	cout<<time[n-1]/60<<" "<<time[n-1]%60;
	
	return 0;
}
