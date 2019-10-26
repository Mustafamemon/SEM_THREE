#include<iostream>
using namespace std;

int main()
{
	int row , col , row1 , col1;	
	cout<<"Enter Row of 1st Matrix : ";
	cin>>row;
	cout<<"Enter Column of 1st Matrix : ";
	cin>>col;
	cout<<"Enter Row of 2nd Matrix : ";
	cin>>row1;
	cout<<"Enter Column of 2nd Matrix : ";
	cin>>col1;
	if (col!=row1)
	{
		cout<<"Multiplicaiton is not possilbe!"<<endl ;
		exit(0);
	}
	int **Mat=new int*[row];
	for(int i=0;i<row;i++)
	{
		Mat[i]=new int [col];
	}	
	int **Mat1=new int*[row1];
	for(int i=0;i<row1;i++)
	{
		Mat1[i]=new int [col1];
	}
	cout<<"Enter the Elements of Matrix One : \n";
	for (int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>Mat[i][j];
		}
	}
	cout<<"Enter the Elements of Matrix Two : \n";
	for (int i=0;i<row1;i++)
	{
		for(int j=0;j<col1;j++)
		{
			cin>>Mat1[i][j];
		}
	}
	int **Mat2=new int*[row];
	for(int i=0;i<row;i++)
	{
		Mat2[i]=new int [col1];
	}	
	int sum=0;
	for (int i=0;i<row;i++)
	{
		for(int j=0;j<col1;j++)
		{
			for(int k=0;k<row1;k++)
			{
				sum=sum+(Mat[i][k]*Mat1[k][j]);
			}
			Mat2[i][j]=sum;
			sum=0;
		}
	}
	cout<<"\n\n\t\tMULTPLICATION\n\n";
	for (int i=0;i<row;i++)
	{
		for(int j=0;j<col1;j++)
		{
			cout<<Mat2[i][j]<<"\t";	
		}
		cout<<endl;
	}
	for(int i=row-1;i>=0;i--)
	{
		delete [] Mat[i];
	}	
	delete Mat;
	for(int i=row-1;i>=0;i--)
	{
		delete [] Mat2[i];
	}
	delete Mat2;
	for(int i=row1-1;i>=0;i--)
	{
		delete [] Mat1[i];
	}	
	delete Mat1;
}
