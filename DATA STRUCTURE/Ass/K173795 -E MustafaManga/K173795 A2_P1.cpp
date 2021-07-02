#include<iostream>
#include<cstdlib>
#include<fstream>
#include<stack>
#include<vector>
#include<algorithm>
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
				j--;
			else if (j<0)
				j++;
		
			if (i>=row)
				i--;
			else if (i<0)
				i++;
			return ptr[i][j];
		}
};
int **sort1=new int*[1000];
int *sort2=new int[1000]; 
int k=0,l=0,a=0;
stack<int> v ;
void store(int output[])
{
	sort1[l]=new int[k+2];
	sort1[l][0]=k;
	sort2[l]=k;
	for (int i=1;i<=k+1;i++)
	{
		sort1[l][i]=output[i-1];
	}
}
void _output()
{
	ofstream fout;
	fout.open("output.txt",ios::out | ios::app);
	for(int i=0;i<l;i++)
	{
		for(int j=i+1;j<l;j++)
		{
			int temp; 
			if(sort2[i]<sort2[j])
			{
				temp=sort2[i];
				sort2[i]=sort2[j];
				sort2[j]=temp;
			}
		}
	}
	int b=0;
	for(int a=1;a<l;a++)
	{
		if(sort2[b]!=sort2[a])
		{
			int c=b;
			b++;
			for(int g=a;g<l;g++)
			{
				c++;
				sort2[c]=sort2[g];
			}
		}
	}
	int c=0;
	for(int g=b;g>=0;g--)
	{
		for(int j=0;j<l;j++)
		{	
			if(sort2[g]==sort1[j][0])
			{
				c++;
				k=sort1[j][0];
				cout<<endl;
				fout<<"PATH#"<<c<<"={";
				cout<<"PATH#"<<c<<"={";
				for (int i=1;i<=k+1;i++)
				{
					if(i%2!=0)
					{
						fout<<'(';
						cout<<'(';
					}
					fout<<sort1[j][i];
					cout<<sort1[j][i];
					if(i%2!=0)
					{
						fout<<',';
						cout<<',';
					}
					if (i%2==0)
					{
						fout<<')';
						cout<<')';
					}
				}
				fout<<"} Cost = "<<k/2+1<<endl;
				cout<<"} Cost = "<<k/2+1<<endl;
			}
		}
	}
	fout.close();
		
}
int ending_point(int flag , int i , int j , int g , safearray<char> &obj,int output[])
{
	g=0;
	if(obj(i+1,j)=='e' || obj(i-1,j)=='e' || obj(i,j+1)=='e' || obj(i,j-1)=='e')
	{
		if(obj(i+1,j)=='e')
			g=1;
		else if(obj(i-1,j)=='e')
			g=2;
		else if(obj(i,j+1)=='e')
			g=3;
		else if(obj(i,j-1)=='e')
			g=4;
		flag=0;
	}
	if(obj(i+1,j)=='1' || obj(i-1,j)=='1' || obj(i,j+1)=='1' || obj(i,j-1)=='1')
	{
		if(obj(i+1,j)=='1')
		{
			if(flag==0)
			{
				v.push(output[k-1]);
				v.push(output[k]);		
				v.push(i+1);
				v.push(j);
			}
			else
			{
				g=1;
				flag=0;	
			}	
		}
		if(obj(i-1,j)=='1')
		{
			if(flag==0)
			{	
				v.push(output[k-1]);
				v.push(output[k]);
				v.push(i-1);
				v.push(j);	
			}
			else
			{
				g=2;
				flag=0;	
			}				
		}
		if(obj(i,j+1)=='1' )
		{
			if(flag==0)
			{		
				v.push(output[k-1]);
				v.push(output[k]);
				v.push(i);
				v.push(j+1);
			}
			else
			{
				g=3;
				flag=0;
			}						
		}
		if(obj(i,j-1)=='1')
		{
			if(flag==0)
			{
				v.push(output[k-1]);
				v.push(output[k]);
				v.push(i);
				v.push(j-1);
			}
			else
			{
				g=4;
				flag=0;	
			}					
		}
	}
	if(g!=0)
	{
		if(g==1)
		i++;
		else if(g==2)
		i--;
		else if(g==3)
		j++;
		else if (g==4)
		j--;
		g=0;
	}
	else if (obj(i,j)=='!') 
	{
		goto again;
	}
	if(obj(i,j)=='1')
	{
		output[++k]=i;
		output[++k]=j;
		obj(i,j)='!';
		flag=1;
	}
	if (obj(i,j)=='e')
	{
		flag=1;
		output[++k]=i;
		output[++k]=j;
		store(output);
		l++;
		k-=2;
		again:
		if(v.empty())
		{	
			if(l==0)
			{
				ofstream fout;
				fout.open("output.txt",ios::out);
				cout<<"No Ending Point!";
				fout<<"No Ending Point!";
				fout.close();
			}
			_output();
			return 0;
		}
		j=v.top();
		v.pop();
		i=v.top();
		v.pop();
		g=v.top();
		v.pop();
		while(output[k-1]!=v.top() || output[k]!=g)
		{
			obj(output[--k],output[k])='1';
			--k;
		}
		v.pop();
		output[++k]=i;
		output[++k]=j;
		obj(i,j)='!';
	}	
	ending_point(flag,i,j,g,obj,output);
}

void starting_point(int i , int j ,int m , int n , safearray<char> &obj,int output[])
{
	if(obj(i,j)!='s')
	{
		if (j>=n)
		{
			i++;
			j=-1;
		}
		if (i>=m)
		{
			ofstream fout;
			fout.open("output.txt",ios::out);
			cout<<"No starting Point";
			fout<<"No starting Point";
			fout.close();
			exit(1);
		}
		starting_point(i,++j,m,n,obj,output);
	}
	else
	{
		obj(i,j)='!';
		output[k]=i;
		output[++k]=j;
		ending_point(1,i,j,0,obj,output);	
	}
}

int main()
{
	fstream fin;
	fin.open("output.txt",ios::out);
	fin.close();
	fin.open("A2P1-in-01.txt", ios::in); 
	if (fin.is_open())
	{
		int m , n ;
		fin>>m>>n;
		safearray<char> obj(m,n);
		char c ;
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
			{
				fin>>c;
				obj(i,j)=c;
			}
		}
		int *output=new int[m*n*2];
		starting_point(0,0,m,n,obj,output);
		fin.close();
	}
	else
	cout<<"File not found!";
	return 0;
}
