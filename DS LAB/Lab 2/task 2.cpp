#include<iostream>
#include<vector>

using namespace std;

int  main()
{
	vector < vector <int> > vec;
	int m ;
	cout<<"Enter No of Rows : ";
	cin>>m;
	int n[m];
	for (int i=0;i<m;i++)
	{
		vector <int> t;
		cout<<"Enter No of Columns : ";
		cin>>n[i];
		for(int j=0;j<n[i];j++)
		{
			int a;
			cin>>a;
		 	t.push_back(a);
		}
		vec.push_back(t);
	}	
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n[i];j++)
		{
			cout<<vec[i][j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}
