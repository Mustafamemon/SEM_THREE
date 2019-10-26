#include <iostream>
#include <cstdlib>
#include<cstring>

using namespace std;

class Safearray{
private:
	int n;
	int m;
	int *ptr;
public:
	Safearray()
	{
		m=0;
		n=0;
		ptr=0;
	}
	Safearray(int row, int col)
	{
		m=row;
		n=col;
		ptr = new int[(-m+n)];
	}
	~Safearray()
	{
		delete []ptr;
	}
	void input()
	{
		for (int i=m;i<n;i++)
		{
			cout<<"Enter values at "<<i<<" : ";
			cin>>ptr[i];
		}
	}
	int &operator [](int i)
	{	
		if(i<m || i>=n
		) 
		{
			cout << "Boundary Error\n";
			exit(1);
		}
		return ptr[i];
	}
	Safearray(const Safearray& rhs)
	{
		m = rhs.m;
		n = rhs.n;
		ptr = new int[-m+n];
		for (int i=m;i<n;i++)
		{
			ptr[i]=rhs.ptr[i];
		}
	}
	Safearray& operator=(const Safearray& rhs)
	{
		if (this == &rhs)
		return *this;
		delete [] ptr;
		m = rhs.m;
		n = rhs.n;
		ptr = new int[-m+n];
		for (int i=m;i<n;i++)
		{
			ptr[i]=rhs.ptr[i];
		}
		return *this;
	}
};
int main()
{
	int column;
	int row;
	cout<<"enter number of low and high index : "<<endl;
	cin>>row>>column;
	Safearray obj(row,column);
	obj.input();
	Safearray obj1=obj;
	cout <<"obj["<<row<<"] :"<< obj1[row]<< endl;
	cout<<"objobj["<<row-1<<"] :";cout<<obj[row-1];
	return 0;
}
