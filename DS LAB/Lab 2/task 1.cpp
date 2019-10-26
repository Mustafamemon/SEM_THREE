#include<iostream>
#include<cstdlib>
using namespace std;
const int  size=10;
template <class T>
class safearray
{
	private:
		T  a[size];
	public:
		safearray()
		{
			register int i ;
			for (int i=0;i<size;i++)
			{
				a[i]=rand()%11;
			}
		}
		T& operator[](int i)
		{
			if (i<0 || i>size-1)
			{
				cout<<"\nArray out of bound\n" ;
				exit(0);
			}
			else
				return a[i];
		}
};
int main()
{
	safearray<int>obj;
	safearray<int> *ptr=new safearray<int>;
	safearray<int> *ptr1=new safearray<int>;
	for (int i=0;i<size;i++)
	{	
		(*ptr)[i]=obj[i];
		(*ptr1)[i]=obj[i];
	}
	for (int i=0;i<size;i++)
	{
		for (int j=0;j<size-1;j++)
		{
			if ((*ptr)[j]<(*ptr)[j+1])
			{
				(*ptr)[j]=(*ptr)[j]+(*ptr)[j+1];
				(*ptr)[j+1]=(*ptr)[j]-(*ptr)[j+1];
				(*ptr)[j]=(*ptr)[j]-(*ptr)[j+1];
			}
			if ((*ptr1)[j]>(*ptr1)[j+1])
			{
				(*ptr1)[j]=(*ptr1)[j]+(*ptr1)[j+1];
				(*ptr1)[j+1]=(*ptr1)[j]-(*ptr1)[j+1];
				(*ptr1)[j]=(*ptr1)[j]-(*ptr1)[j+1];
			}
		}
	}
	cout<<"Original Array\tAscending Order\tDescending Order\n";
	for(int i=0;i<size;i++)
	cout<<obj[i]<<"\t\t "<<(*ptr1)[i]<<"\t\t"<<(*ptr)[i]<<"\n";
	delete []ptr1;
	delete []ptr;
}	
