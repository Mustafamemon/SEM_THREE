#include<iostream>
#include<string.h>
#include<fstream>
#include<cmath>
#include<stack>

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
int main()
{
	string input ;
	cin>>input;
	Stack <char>s ;
	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='(' || input[i]=='{' || input[i]=='[')
		s.push(input[i]);
		else if(input[i]==')' || input[i]=='}' || input[i]==']')
		{
			if(s.top()=='(')
			{
				if(input[i]==')')
					s.pop();
				else
				{	
					cout<<"Not Balance!";
					exit(0);
				}
			}
			else if(s.top()=='[')
			{
				if(input[i]==']')
					s.pop();
				else
				{	
					cout<<"Not Balance!";
					exit(0);
				}
			}
			else if(s.top()=='{')
			{
				if(input[i]=='}')
					s.pop();
				else
				{	
					cout<<"Not Balance!";
					exit(0);
				}
			}
		}
	}
	if(s.empty())
	cout<<"Balance!";
	else
	cout<<"Not Balance!";
}
