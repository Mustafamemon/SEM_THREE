#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin;
	int c , no_of_element , queries;
	fin.open("task 3.txt" , ios :: in);
	if (fin.is_open())
	{
		fin>>c;
		no_of_element=c;
		int *array = new int[no_of_element];
		for (int i=0;i<no_of_element;i++)
		{
			fin>>c;
			array[i]=c;
		}
		fin>>c;
		queries=c;
		int **ptr = new int*[queries];
		for (int i=0;i<queries;i++)
		{
			ptr[i]=new int [3];
		}
		for(int i=0;i<queries;i++)
		{
			for(int j=0;j<3;j++)
			{
				fin>>c;
				ptr[i][j]=c;
			}
		}
		for (int i=0;i<queries;i++)
		{
			int count =0;
			for (int j=ptr[i][0];j<=ptr[i][1];j++)
			{
				if (array[j]>ptr[i][2])
				{
					++count;
				}
			}
			cout<<count<<endl;
		}
		delete []array;
		array=0;
		for (int i=queries-1;i>=0;i--)
		{
			delete []ptr[i];
			ptr[i]=0;
		}
		ptr=0;
		fin.close();
	}
	else
	cout<<"File not Found!";
	return 0;
}
