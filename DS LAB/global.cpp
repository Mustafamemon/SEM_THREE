#include<iostream>
#include<string>
#include<stack>
using namespace std;
int match=10 , m_match = -2 ,  gap=-5 , flag=0;
stack<int> s ;
int **fill_array(int row , int col)
{
	int **array = new int*[row+1];
	for(int i=0;i<row+1;i++)
	array[i]=new int[col+1];
	int gap1=0;
	for(int i=0;i<col+1;i++)
	{
		array[0][i]=gap1;
		gap1=gap1+gap;
	}
	gap1=gap;
	for(int i=1;i<row+1;i++)
	{
		array[i][0]=gap1;
		gap1=gap1+gap;
	}
	return array ;
}
int **Global_alignment(string sequence1 , string sequence2 , int row , int col)
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
			
			array[i][j]=greater;
		}
	}
	return array; 
}
int trace_back(string sequence1 , string sequence2 , int i , int j,int **array)
{
	int left , top , diagonal , greater,direction;
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
//	cout<<left<<" "<<top<<" "<<diagonal<<endl;
	if(left>top)
	{
		direction=1;
		greater=left;
	}
	else
	{
		direction=2;
		greater=top;
	}
	if(greater<diagonal)
	{
		direction=3;
		greater=diagonal;
	}
	if(flag==0)
	{
		if(greater==diagonal && direction!=3)
		{
			flag=1;
			s.push(i-1); s.push(j-1);
		}
		else if(greater==top && direction!=2)
		{
			flag=1;
			s.push(i-1); s.push(j);
		}
		else if(greater==left && direction!=1)
		{
			flag=1;
			s.push(i); s.push(j-1);
		}
		if(flag==1)
		{
			s.push(i) ; s.push(j);
		}
	}
	return direction ;
}
void Ouput_Sequence(string sequence1 , string sequence2 , int row , int col)
{
	char *O_sequence1 , *O_sequence2 ;
	int **array=Global_alignment(sequence1,sequence2,row,col);
	int i,j,temp=gap*col*row,high=row+col;
	O_sequence1=new char[high];
	O_sequence2=new char[high];
	i=row; j=col; 
	high--;
	again:
	while(i>0 && j>0)
	{
		int direction=trace_back(sequence1,sequence2,i,j,array);
		if(flag==1)
		{
			s.push(high);
			flag=2;
		}
			
		if(direction==1)
		{
			O_sequence1[high]='-';
			O_sequence2[high]=sequence2[j-1];
			j--;
		}
		else if(direction==2)
		{
			O_sequence1[high]=sequence1[i-1];
			O_sequence2[high]='-';
			i--;
		}
		else if(direction==3)
		{
			O_sequence1[high]=sequence1[i-1];
			O_sequence2[high]=sequence2[j-1];
			i--;
			j--;
		}
		high--;
	}
	while(i>0)
	{
		O_sequence1[high]=sequence1[i-1];
		O_sequence2[high]='-';
		i--;
		high--;
	}
	while(j>0)
	{
		O_sequence1[high]='-';
		O_sequence2[high]=sequence2[j-1];
		j--;
		high--;
	}
	for(int c=high+1;c<row+col;c++)
		cout<<O_sequence1[c];
	cout<<endl;
	for(int c=high+1;c<row+col;c++)
		cout<<O_sequence2[c];
	if(!s.empty())
	{
		flag=0;
		cout<<endl<<endl;
		high=s.top(); s.pop();
		int b=s.top(); s.pop();
		int a=s.top(); s.pop();
		j=s.top(); s.pop();
		i=s.top(); s.pop();
		if(a-1==i && b-1==j)
		{
			O_sequence1[high]=sequence1[a-1];
			O_sequence2[high]=sequence2[b-1];
		}
		else if(a-1==i)
		{
			O_sequence1[high]=sequence1[a-1];
			O_sequence2[high]='-';
		}
		else if(b-1==j)
		{
			O_sequence1[high]='-';
			O_sequence2[high]=sequence2[b-1];
		} 
		high--;
		goto again ;
	}
}
int main()
{
	string sequence1 , sequence2 ;
	cin>>sequence1;
	cin>>sequence2;
	int row=sequence1.length();
	int col=sequence2.length();
	Ouput_Sequence(sequence1,sequence2,row,col);
}
