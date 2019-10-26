#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

template<class T>
class safearray
{
	private:
		T *ptr;
		int ncol;
	public:
		safearray(int col)
		{
			ncol=col;
			ptr=new T[ncol];
		}
		
		~safearray()
		{
			delete []ptr;
		}
		
		T &operator [](int i)
		{
			if (i<0 || i>ncol)
			{
				cout<<"Out Of Bound";
				exit(1);
			}
			return ptr[i];
		}
		
		safearray<T> &operator = (const safearray<T> &rhs)
		{
			cout<<"a";
			if (this==&rhs)
			return *this;
			
			delete[] ptr;
			ncol = rhs.ncol;
			ptr = new char[ncol];
			memcpy(ptr,rhs.ptr, sizeof(char)*ncol);
			return *this;
		}
};
int main()
{
	string s;  //input from file
	ifstream fin;
	fin.open("task 2 .txt",ios::in);
	if (fin.is_open())
	{
		fin>>s;
		int size = s.length();
		
		safearray<char> s1(size);
		
		for (int i=0;i<size;i++)
		{
			s1[i]=s[i];
		}
		fin>>s;
		int size1 = s.length();
		safearray<char> s2(size1);
		
		for (int i=0;i<size1;i++)
		{
			s2[i]=s[i];
		}
		int j=0,k=0,l=0; // for loop purpose
		string s3,output;// to store matching string
		for (int i=0;i<size && j<size1;i++)
		{
			if(s1[i]!=s2[j])
			{
				if (i>=1 && j>=1)
				{
					if ( s1[i-1]==s2[j-1] && s1[i-1]==s1[i])
					{
						s3[k]='*';
						k++;
					}
					else
					{
						s3[k]='\0';
						if (l<k)
						{
							for (int g=0;g<=k;g++)
								output[g]=s3[g];
							l=k;
						}
						j=0;
						k=0;
						--i;
					}
				}
			}	
			else
			{
				s3[k]=s1[i];
				j++;
				k++;
			}
			if (i<size && l<k)
			{
				for (int g=0;g<=k;g++)
					output[g]=s3[g];
					l=k;
			}
		}
		for (int i=0;i<=l;i++)
		cout<<output[i];
		fin.close();
	}
	else
	cout<<"File Not Found!";
	return 0;
}
