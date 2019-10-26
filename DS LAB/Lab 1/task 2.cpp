#include<iostream>
using namespace std;

class Employee
{
	private:
		int Age ;
		int Experience ;
		int Working_hour ;
		int hourly_wage ;
		int salary;
	public:
		Employee()
		{
			Age=0 ;
			Experience=0 ;
			Working_hour=0 ;
			hourly_wage=0 ;
			salary=0 ;
		}
		void setdata(int aAge , int aExperience ,	int aWorking_hour)
		{
			Age=aAge; 
			Experience=aExperience ;
			Working_hour=aWorking_hour ;
		}
		bool Calculate_Hourlywage()
		{
			if (Age>50)
			{
				if(Experience>10)
				{
					if (Working_hour>240)
					{
						hourly_wage=500;
					}
				}
			}
			else if (Age>40 && Age<=50)
			{
				if(Experience>6 && Experience<=10)
				{
					if (Working_hour>200 && Working_hour<=240)
					{
						hourly_wage=425;
					}
				}
			}
			else if (Age>30 && Age<=40)
			{
				if(Experience>3 && Experience<=6)
				{
					if (Working_hour>160 && Working_hour<=200)
					{
						hourly_wage=375;
					}
				}
			}
			else if (Age>22 && Age<=30)
			{
				if(Experience>1 && Experience<=3)
				{
					if (Working_hour>120 && Working_hour<=160)
					{
						hourly_wage=305;
					}
				}
			}
			if (hourly_wage==0)
				return false;
			else 
				return true;
			
		}
		void Calculate_Salary()
		{
			salary=Working_hour*hourly_wage;
		}
		void show_salary()
		{
			if(salary!=0)
			cout<<salary;
			else
			cout<<"Invalid Parameters!";
		}
};

int main()
{
	Employee *e;
	int n;
	int age ,experience , working_hour ;
		
	cout<<"How Many Salary You Want to Calculate : ";
	cin>>n;
	e=new Employee[n];
	for(int i=0;i<n;i++)
	{
		again:
		cout<<endl;
		cout<<"Enter Age : ";
		cin>>age;
		cout<<"Enter Experience :";
		cin>>experience;
		cout<<"Working Hour : ";
		cin>>working_hour;
		e[i].setdata(age , experience , working_hour);
		if(!e[i].Calculate_Hourlywage())
		{
			e[i].show_salary();
			goto again;
		}
	}
	for(int i=0;i<n;i++)
	{
		e[i].Calculate_Hourlywage();
		e[i].Calculate_Salary();
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Salary of "<<i+1<<" Employee : ";
		e[i].show_salary();
		cout<<endl;
	}
}
