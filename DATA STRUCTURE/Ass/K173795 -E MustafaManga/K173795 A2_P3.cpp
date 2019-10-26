#include<iostream>
#include<fstream>
#include<queue>
#include<iomanip>
using namespace std;
int main()
{	
	string line ;
	int busy=0,store=0,No_of_customer=0,customer=0,AvgW_time=0,Avg_customer=1, time=0,j=0,POS=0 ;
	fstream fin;
	fin.open("input.txt",ios::in);
	if(fin.is_open())
	{
		while(!fin.eof())
		{
			getline(fin,line);
			No_of_customer++;
		}		
		fin.close();
	}
	else
	{
		cout<<"File Not Found!";
		exit(1);
	}
	int a_time[No_of_customer+1]={0} , w_time[No_of_customer+1]={0} , s_time[No_of_customer+1]={0};
	fin.open("input.txt",ios::in);
	for(int i=0;i<No_of_customer;i++)
	{
		fin>>customer>>a_time[i]>>s_time[i];
		POS=POS+s_time[i];
	}
	fin.close();
	fin.open("output.txt",ios::out);
	fin<<"Number of customers : "<<No_of_customer<<endl<<endl;
	cout<<"Number of customers : "<<No_of_customer<<endl<<endl;
	fin<<"Avg Service Time : "<<POS<<"->"<<setprecision(3)<<(float)POS/No_of_customer<<endl<<endl;
	cout<<"Avg Service Time : "<<POS<<"->"<<setprecision(3)<<(float)POS/No_of_customer<<endl<<endl;
	int cnt=0;
	float busy_hour=0.0; 
	j=0;
	for(int i=1;i<=No_of_customer;i++)
	{
		if(a_time[i]>=a_time[i-1])
		{	
			Avg_customer++;
			time=(a_time[i-1]+s_time[i-1]+w_time[i-1]);
			w_time[i]=time-a_time[i];
			if(w_time[i]<=0)
			{
				w_time[i]=0;
			}
			if(time>=60)
			{
				cnt++;
				time=time-60;
				store=store+time;
			}
			else
			{
				time=0;
			}
			AvgW_time=AvgW_time+w_time[i]-time;
		}
		else
		{
			j++;
			fin<<"No of Customer at "<<j<<" hour : "<<Avg_customer<<endl;
			cout<<"No of Customer at "<<j<<" hour : "<<Avg_customer<<endl;
			fin<<"Avg Waiting time at "<<j<<" hour : "<<AvgW_time<<"->"<<Avg_customer<<"->"<<setprecision(3)<<(float)AvgW_time/(Avg_customer)<<endl<<endl;
			cout<<"Avg Waiting time at "<<j<<" hour : "<<AvgW_time<<"->"<<Avg_customer<<"->"<<setprecision(3)<<(float)AvgW_time/(Avg_customer)<<endl<<endl;
			if(busy_hour<AvgW_time/(Avg_customer))
			{
				busy=j;
				busy_hour=(float)AvgW_time/(Avg_customer) ;
			}
			AvgW_time=store;
			store=0;
			time=(a_time[i-1]+s_time[i-1]+w_time[i-1]);
			w_time[i]=time-a_time[i];
			if(time>=60)
				cnt++; 
			if(w_time[i]>=60)
			{
				w_time[i]=w_time[i]-60;
			}
			else
			{
				w_time[i]=0;
			}
			if(w_time[i]<=0)
			{
				w_time[i]=0;
			}
			
			Avg_customer=cnt+1;
			cnt=0;
			AvgW_time=AvgW_time+w_time[i];
		}
	}
	fin<<"Busy Hour :"<<busy<<"->Avg Waiting time :"<<setprecision(3)<<busy_hour<<endl ;
	cout<<"Busy Hour :"<<busy<<"->Avg Waiting time : "<<setprecision(3)<<busy_hour<<endl ;		
	fin.close();
}
