#include<iostream>
#include<string.h>
#include<fstream>
#include<cmath>
#include<stack>

using namespace std;
int i_ans(char ch[])
{
	stack <int>s ;
	int con=0,ans=0;
	for(int i=0;i<strlen(ch);i++)
	{
		if(ch[i]>='0' && ch[i]<='9')
		{
			con=(con*10)+(ch[i]-48);
		}
		else if(ch[i]==' ')
		{
			if(con!=-1)
			s.push(con);
			con=0;
		}
		else if(ch[i]=='/' || ch[i]=='*' || ch[i]=='+' || ch[i]=='-' || ch[i]=='^' || ch[i]=='%')
		{
			ans=s.top();
			s.pop();
			con=s.top();
			s.pop();
			if(ch[i]=='^')	
				s.push(pow(con,ans));
			else if(ch[i]=='%')
				s.push(con%ans);
			else if(ch[i]=='*')
				s.push(ans*con);
			else if(ch[i]=='/')
				s.push(con/ans);
			else if(ch[i]=='+')
				s.push(ans+con);
			else if(ch[i]=='-')
				s.push(con-ans);
			con=-1;
		}
	}
	return s.top();
}
int O_precedence(char O) 
{
	if(O=='^')
	 	return 3;
	else if(O == '*' || O == '/' || O == '%') 
    	return 2; 
    else if(O == '+' || O == '-') 
    	return 1; 
    else
    	return -1; 
} 
void infix_to_postfix(char infix[])
{
	fstream fout;
	fout.open("output.txt",ios::out | ios::app);
	char output[strlen(infix)+strlen(infix)];
	stack <char>s;
	int k=0;
	for(int i=0;i<strlen(infix);i++)
	{
		if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(s.top()!='(')
			{
				output[k]=' ';
				k++;
				if(s.top()!=')' && s.top()!='(')
				{
					output[k]=s.top();
					k++;
				}
				s.pop();
			}
			s.pop();
		}
		else if((infix[i]>='0' && infix[i]<='9') || (infix[i]>='a' && infix[i]<='z'))
		{
			output[k]=infix[i];
			k++;
		}
		else if(!s.empty())
		{
			output[k]=' ';
			k++;
			again:
			if(O_precedence(s.top())<O_precedence(infix[i]))
			{
				s.push(infix[i]);
			}
			else
			{
				output[k]=s.top();
				k++;
				output[k]=' ';
				++k;
				s.pop();
				if(!s.empty())
				goto again;
				s.push(infix[i]);
			}
		}
		else
		{
			output[k]=' ';
			k++;
			s.push(infix[i]);
		}   
	}
	while(!s.empty())
	{
		output[k]=' ';
		k++;
		if(s.top()!=')' && s.top()!='(')
		{
			output[k]=s.top();
			k++;
		}
		s.pop();
	}
	output[k]='\0';
	for(int i=0;i<k;i++)
	{
		cout<<output[i];
		fout<<output[i];
	}
	if((output[0]>='a' && output[0]<='z'))
	cout<<endl<<endl;
	else
	{
		k=i_ans(output);
		fout<<endl<<k<<endl;
		cout<<endl<<k<<endl<<endl;
	}
	fout.close();
}
int main()
{
	string ch1;
	fstream fin;
	fin.open("input.txt", ios::in);
	if(fin.is_open())
	{
		while(!fin.eof())
		{
			fin>>ch1;
			char ch[ch1.length()];
			for(int i=0;i<ch1.length();i++)
			{			
				ch[i]=ch1[i];	
			}
			ch[ch1.length()]='\0';
			infix_to_postfix(ch);
		}
	}
	else
		cout<<"File Not Found!";
}
