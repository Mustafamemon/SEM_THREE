#include<iostream>
#include<string.h>
#include<fstream>
#include<cmath>
#include<stack>
#include<iostream>

using namespace std;
template <class T>
class node
{
	public:
		T data;
		node *next;
		node()
		{
			data = 0;
			next=NULL;
		}
		node(int ndata)
		{
			data=ndata;
			next=NULL;
		}
		node(int ndata , node *a)
		{
			data=ndata;
			next=a;
		}
};
template <class T>
class linkedlist
{
	private:
		node<T> *head , *tail;
	public:	
		linkedlist()
		{
			head=NULL;
			tail=NULL;
		}
		linkedlist(const linkedlist &rhs)
		{
			head=NULL;
			tail=NULL;
			node <T>*temp=rhs.head;
			while(temp!=NULL)
			{
				add_node_tail(temp->data);
				temp=temp->next;
			}
		}
		linkedlist& operator=(const linkedlist &rhs)
		{
			if (this!=&rhs)
			{
				this->~linkedlist();
				head=NULL;
				tail=NULL;
				node <T>*temp=rhs.head;
				while(temp!=NULL)
				{
					add_node_tail(temp->data);
					temp=temp->next;
				}
			}
				return *this;
		}
		void add_node_tail(int n)
		{
			if (tail!=NULL)
			{
				tail->next= new node<T> (n);
				tail=tail->next;
			}
			else
			{
				head=tail=new node<T>(n);
			}
		}
		void display()
		{
			node <T>*temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		void delete_tail()
		{
			if (head!=NULL)
			{
				node <T>*temp=head; 
				if (head==tail)
				{
					head=tail=NULL;
					delete head;
				}
				else
				{
					while (temp->next!=tail)
						temp=temp->next;
					delete tail;		
					tail=temp;
					tail->next=NULL;
				}
			}
			else
				cout<<"List is Empty!";
		}
		T peak()
		{
			return tail->data;	
		}
		~linkedlist()
        {
        	node <T>*ptr; 
            while(head!=NULL)
			{ 
                ptr=head->next; 
                delete head; 
                head=ptr; 
            } 
		}
};
template<class T>
class Stack
{
	private:
		int top1;
		linkedlist<T> l;
	public:
		Stack()
		{
			top1=-1;		
		}
		void push(T data)
		{
			++top1;
			l.add_node_tail(data);
		}
		void pop()
		{
			if(top1>=0)
			{
				top1--;
				l.delete_tail();
			}
		}
		T top()
		{
			if(top1>=0)
			{
				return l.peak();
			}
		}
		bool empty()
		{
			if(top1>=0)
				return false;
			else
				return true;
		}
		int size()
		{
			return top1;	
		}
};
int i_ans(char ch[])
{
	Stack <int>s ;
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
		else if(ch[i]=='/' || ch[i]=='*' || ch[i]=='+' || ch[i]=='-' || ch[i]=='^')
		{
			ans=s.top();
			s.pop();
			con=s.top();
			s.pop();
			if(ch[i]=='^')	
				s.push(pow(con,ans));
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
int prec(char c) 
{
	if(c=='^')
	 	return 3;
	else if(c == '*' || c == '/') 
    	return 2; 
    else if(c == '+' || c == '-') 
    	return 1; 
    else
    	return -1; 
} 
void infix_to_postfix(char exp[])
{
	
	char output[strlen(exp)+strlen(exp)];
	Stack <char>s;
	int k=0;
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(')
		{
			s.push(exp[i]);
		}
		else if(exp[i]==')')
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
		else if((exp[i]>='0' && exp[i]<='9') || (exp[i]>='a' && exp[i]<='z'))
		{
			output[k]=exp[i];
			k++;
		}
		else if(!s.empty())
		{
			output[k]=' ';
			k++;
			again:
			if(prec(s.top())<prec(exp[i]))
			{
				s.push(exp[i]);
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
				s.push(exp[i]);
			}
		}
		else
		{
			output[k]=' ';
			k++;
			s.push(exp[i]);
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
	output[k]=' ';
	output[++k]='\0';
	for(int i=0;i<k;i++)
	{
		cout<<output[i];
	}
	if((output[0]>='a' && output[0]<='z'))
	cout<<endl<<endl;
	else
	{
		k=i_ans(output);
		cout<<endl<<k<<endl<<endl;
	}
}
int main()
{
	char ch[100];
	cin>>ch;
	infix_to_postfix(ch);
}


