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

int k=0;
int ending_point(int flag , int i , int j , safearray<char> &obj,int output[])
{
	if(obj(i+1,j)=='e' || obj(i-1,j)=='e' || obj(i,j+1)=='e' || obj(i,j-1)=='e')
	{
		if(obj(i,j+1)=='e')
		j++;
		else if(obj(i,j-1)=='e')
		j--;
		else if(obj(i+1,j)=='e')
		i++;
		else if(obj(i-1,j)=='e')
		i--;
		flag=0;
	}
	else if(obj(i+1,j)=='-')
	{
		flag=0;
		i++;
	}
	else if(obj(i-1,j)=='-')
	{
		flag=0;
		i--;			
	}
	else if(obj(i,j+1)=='-' )
	{
		flag=0;
		j++;						
	}
	else if(obj(i,j-1)=='-')
	{
		flag=0;
		j--;					
	}
	else if (obj(i,j)=='!') 
	{
		obj(i,j)='x';
		--k;
		j=output[k-1];
		i=output[k-2];
		--k;
		if(k<0)
		{
			ofstream fout;
			fout.open("task 1output.txt",ios::out);
			fout<<"No Ending point!";
			fout.close();
			exit(0);
		}
	}
	if(flag==0)
	{
		output[++k]=i;
		output[++k]=j;
		if (obj(i,j)=='e')
				return 0;
		obj(i,j)='!';
		flag=1;
	}
	ending_point(flag,i,j,obj,output);
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
			fout.open("task 1output.txt",ios::out);
			fout<<"No starting Point";
			fout.close();
			exit(0);
		}
		starting_point(i,++j,m,n,obj,output);
	}
	else
	{
		obj(i,j)='!';
		output[k]=i;
		output[++k]=j;
		ending_point(0,i,j,obj,output);	
	}
}

int main()
{
	ifstream fin;
	fin.open("task 1.txt", ios::in); 
	if (fin.is_open())
	{
		int m , n ;
		fin>>m>>n;
		safearray<char> obj(m,n);
		char c;
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
			{
				fin>>c;
				obj(i,j)=c;
			}
		}
		int *output=new int[m*n];
		starting_point(0,0,m,n,obj,output);
		ofstream fout;
		fout.open("task 1output.txt",ios::out);
		for (int i=0;i<=k;i++)
		{
			fout<<output[i]<<" ";
			if (i%2!=0)
			fout<<endl;	
		}
		fout.close();
		delete [] output;
		fin.close();
	}
	else
	cout<<"File not found!";
	return 0;
}
