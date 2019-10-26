#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
 
template <class T>
class safearray 
{
	private:
		T **ptr;
		int row;
		int col;
	public:
		safearray()
		{
			row=0;
			col=0;
			ptr=0;
		}
		safearray(int mrow , int ncol)
		{
			row=mrow;
			col=ncol;
			ptr=new T*[row];
			for (int i=0;i<row;i++)
				ptr[i]=new T[col];
		}
		~safearray()
		{
			if (ptr!=0)
			{
				for (int i=row-1;i>=0;i--)
				{
					if (ptr[i]!=0)
					{
						delete []ptr[i];
					 	ptr[i]=0;
					}
				}
				delete []ptr;
				ptr=0; 
			}
		}
		T &operator ()(int i, int j)
		{	
			if(j>=col)
			{
				j--;
			}
			else if (j<0)
			{
				j++;
			}
		
			if (i>=row)
			{
				i--;
			}
			else if (i<0)
			{
				i++;
			}	
			return ptr[i][j];
		}
};
int k=0;
int ptr[100];
void ending_point(int a , int count , int i , int j ,int m , int n , safearray<char> &obj)
{
	if (count==0)
	{
		j++;
		a++;
		count=1;
	}
	else if (count==1)
	{
		j--;
		a++;
		count=2;
	}
	else if (count==2)
	{
		i++;
		a++;
		count=3;
	}
	else if (count==3)
	{
		i--;
		a++;
		count=0;
	}
	
	if(obj(i,j)=='-')
	{
		obj(i,j)='!';					
		k++;
		ptr[k]=i;
		k++;
		ptr[k]=j;
		count=0;
		a=0;
	}
	else if (obj(i,j)=='e')
	{
		obj(i,j)='!';
		k++;
		ptr[k]=i;
		k++;
		ptr[k]=j;
		return;
	}
	else
	{
		if (count==1)
			j--;
		else if (count==2)
			j++;
		else if (count==3)
			i--;
		else if (count==0)
			i++;
	}
	if (a>4)
	{
		cout<<"No Path Found!";
		exit(1);
	}
	
	ending_point(a,count,i,j,m,n,obj);
}



void starting_point(int i , int j ,int m , int n , safearray<char> &obj)
{
	if(obj(i,j)!='s')
	{
		j++;
		if (j>=n)
		{
			i++;
			j=0;
		}
		if (i>=m)
		{
			cout<<"No starting Point";
			exit(1);
		}
		starting_point(i,j,m,n,obj);
	}
	else
	{
		obj(i,j)='!';
		ptr[k]=i;
		k++;
		ptr[k]=j;
		ending_point(0,0,i,j,m,n,obj);	
	}
}
int main()
{
	int m , n ;
	ifstream fin ;
	fin.open("task1.txt", ios::in); 
	fin>>m>>n;
	char c;
	safearray<char> obj(m,n) ;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			fin>>c;		
			obj(i,j)=c;
		}
	}
	starting_point(0,0,m,n,obj);
	for (int i=0;i<=k;i++)
	{
		cout<<ptr[i]<<" ";
		if (i%2!=0)
		cout<<endl;	
	}
	fin.close();
	return 0;
}
