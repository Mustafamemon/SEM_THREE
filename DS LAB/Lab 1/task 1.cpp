#include<iostream>
using namespace std;

class Student
{
	private:
		string name;
		int roll_no;
	public:
		Student()
		{
			name='\0' ;
			roll_no=0 ;
		}
		void setdata(string aname ,int aroll_no)
		{
			name=aname;
			roll_no=aroll_no;
		}
		void showdata()
		{
			cout<<name<<"\t\t\t\t"<<roll_no;
		}
		string getname()
		{
			return name;
		}
		int  getroll_no()
		{
			return roll_no;
		}
};
int main()
{
	Student *s=new  Student[5];
	string name;
	int roll_no;
	for (int i=0;i<5;i++)
	{
		cout<<"Enter Name : ";
		cin>>name;
		cout<<"Enter Roll No : ";
		cin>>roll_no;
		s[i].setdata(name,roll_no);
		
	}
	cout<<"\n\t\tBefore Sort\n\n";
	cout<<"NAME\t\t\t\t Roll-No\n";
	for (int i=0;i<5;i++)
	{
		s[i].showdata();
		cout<<endl;
	}
	for (int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			if((s[j].getname()).compare(s[j+1].getname())<0)
			{
				Student temp;
				temp.setdata(s[j].getname(),s[j].getroll_no());
				s[j].setdata(s[j+1].getname(),s[j+1].getroll_no());
				s[j+1].setdata(temp.getname(),temp.getroll_no());
			}
		}
	}
	cout<<"\n\t\tAfter Sort\n\n";
	cout<<"NAME\t\t\t\t Roll-No\n";
	
	for (int i=0;i<5;i++)
	{
		s[i].showdata();
		cout<<endl;
	}
	delete []s;
	
}
