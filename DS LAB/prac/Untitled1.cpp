#include<iostream>
#include<string.h>
#include<fstream>
#include<cmath>
#include<stack>

using namespace std;



int findpath(int x1,int y1,int x2,int y2,int r,int c,char **a)
	{
		if((y1==y2)&&(x1==x2))
		{
			cout<<endl<<"("<<x1<<","<<y1<<")";
				
			
			return 1;
		}
		else
		{
				if((a[x1][y1+1]=='-')||(a[x1][y1+1]=='e')||(a[x1][y1+1]=='E'))
				{
				
					y1++;
						cout<<endl<<"("<<x1<<","<<y1<<")";
				
					return findpath(x1,y1,x2,y2,r,c,a);
				
				}
				else if((a[x1+1][y1]=='-')||(a[x1+1][y1]=='e')||(a[x1+1][y1]=='E'))
				{
					x1++;
					cout<<endl<<"("<<x1<<","<<y1<<")";
				
					return findpath(x1,y1,x2,y2,r,c,a);
				 
			
				}
				else if((a[x1][y1-1]=='-')||(a[x1][y1-1]=='e')||(a[x1][y1-1]=='E'))
				{
				
					y1--;
						cout<<endl<<"("<<x1<<","<<y1<<")";
				
					return findpath(x1,y1,x2,y2,r,c,a);
				
				}
				else if((a[x1-1][y1]=='-')||(a[x1-1][y1]=='e')||(a[x1-1][y1]=='E'))
				{
					x1--;
					cout<<endl<<"("<<x1<<","<<y1<<")";
				
					return findpath(x1,y1,x2,y2,r,c,a);
				 
			
				}
				
			//}
	}
}

int main()
{
int columns;
int rows;
cout<<"Enter The Number of Rows and Columns:"<<endl;
cin>>rows>>columns;
//atype ob1(rows,columns);
//ob1.fillArray();
int i,j,k1=0,l1=0,k2=0,l2=0;
char **a=new char *[rows];
for(int i=0;i<rows;i++)
{
	a[i]=new char [columns];	
}
for(i=0;i<rows;i++)
{
	for(j=0;j<columns;j++)
	{
		cin>>a[i][j];	
	}
}
for(i=0;i<rows;i++)
{
	for(j=0;j<columns;j++)
	{
		cout << a[i][j]<<"  ";
	//	a[i][j]=obj1(i,j);
		if((a[i][j]=='S' )||( a[i][j]=='s'))
		{
			//cout<<endl<<"("<<i<<","<<j<<")";
			k1=i;
			l1=j;
					//break;		
		}
		if((a[i][j]=='E' )||( a[i][j]=='e'))
		{
			//cout<<endl<<"("<<i<<","<<j<<")";
			k2=i;
			l2=j;
			//break;		
		}
	
	}
	cout<<endl<<endl;
}
int val=0;		
cout<<endl<<"Start point"<<"("<<k1<<","<<l1<<")"<<endl;
cout<<endl<<"ENd point"<<"("<<k2<<","<<l2<<")"<<endl;

				
val=findpath(k1,l1,k2,l2,rows-1,columns-1,a);
if(val==1)
{
	cout<<"Path exists";
}
else{
	cout<<"No Path";
}
return 0;
}

