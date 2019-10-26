
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int match=1 , m_match =0 ,  gap=0 , flag=0;
stack<int> s ;

int backtrack(int **array,int i,int j,string seq1,string seq2);
int **fill_array(int row , int col)
{
	int **array = new int*[row+1];
	for(int i=0;i<row+1;i++)
	array[i]=new int[col+1];
	
	int gap1=0;
	
	for(int i=0;i<col+1;i++)
	{
		array[0][i]=gap1;
	
	}
	for(int i=1;i<row+1;i++)
	{
		array[i][0]=gap1;
	
	}
	
	return array ;
}


int **Local_alignment(string sequence1 , string sequence2 , int row , int col)
{
	int left , top , diagonal , greater ;
	
	
	int **array=fill_array(row,col);
	
	for(int i=1;i<row+1;i++)
	{
		for(int j=1;j<col+1;j++)
		{
			left=array[i][j-1]+gap;
			top=array[i-1][j]+gap;
			
			if(sequence1[i-1]==sequence2[j-1])
			{
				diagonal=array[i-1][j-1]+match;	
			}
			else
			{	
				diagonal=array[i-1][j-1]+m_match;	
			}
			
			if(left>top)
			{
				greater=left;
			}
			else
			{
				greater=top;
			}
			
			if(greater<diagonal)
			{
				greater=diagonal;
			}
			
			if(greater>0)
			array[i][j]=greater;
			else
			array[i][j]=0;
		}
	}


	for(int i=0;i<=row;i++)
	{
		for(int j=0;j<=col;j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	return array;
	
}


void func(int **array,int i,int j,string seq1,string seq2)
{
	char *out1=new char[i+j];
	char *out2=new char[i+j];
	int t=i+j;
	int x1=t;
	int y1=t;
	y1--;
	x1--;
	int temp=array[1][1];
	int x=0;
	int y=0;
	for(int a=1;a<=i;a++)
	{
		for(int b=1;b<=j;b++)
		{
			if(temp<array[a][b])
			{
				temp=array[a][b];
				x=a;
				y=b;
			}
		}
	}
	
	i=x;
	j=y;
	int place=0;
	int temp1=array[i][j];
		
	while(temp!=0)
	{
		place=backtrack(array,i,j,seq1,seq2);
		if(place==1)
		{
			out1[x1]='-';
			out2[y1]=seq2[j-1];
			j--;
			x1--;
			y1--;	
		}
		else if(place==2)
		{
			out1[x1]=seq1[i-1];
			out2[y1]='-';
			i--;
			x1--;
			y1--;
		}
		else if(place==3)
		{
			out1[x1]=seq1[i-1];
			out2[y1]=seq2[j-1];
			i--;
			j--;
			x1--;
			y1--;
		}
		temp=array[i][j];
	}
	
	for(int z=x1;z<t;z++)
	cout<<out1[z]<<" ";
	cout<<endl;
	
	for(int z=y1;z<t;z++)
	{
		cout<<out2[z]<<" ";
	}
}


int backtrack(int **array,int i,int j,string seq1,string seq2)
{
	int up;
	int left;
	int diagnol;
	int greater;
	int direction;
	
	left=array[i][j-1]+gap;
	up=array[i-1][j]+gap;
	
	if(seq1[i-1]==seq2[j-1])
	diagnol=array[i-1][j-1]+match;
	
	else
	diagnol=array[i-1][j-1]+m_match;
	
	if(left>up)
	{
		direction=1;
		greater=left;
	}
	else
	{
		direction=2;
		greater=up;
	}
	
	if(diagnol>greater)
	{
		direction=3;
		greater=diagnol;
	}
	return direction;
}

int main()
{
	string sequence1 , sequence2 ;
	cin>>sequence1;
	cin>>sequence2;
	int row=sequence1.length();
	int col=sequence2.length();
	int **array=Local_alignment(sequence1,sequence2,row,col);	
	func(array,row,col,sequence1,sequence2);
}

