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
class Queue
{
	private:
		node<T> *head , *tail;
	public:	
		Queue()
		{
			head=NULL;
			tail=NULL;
		}
		Queue(const Queue &rhs)
		{
			head=NULL;
			tail=NULL;
			node <T>*temp=rhs.head;
			while(temp!=NULL)
			{
				EnQueue(temp->data);
				temp=temp->next;
			}
		}
		Queue& operator=(const Queue &rhs)
		{
			if (this!=&rhs)
			{
				this->~Queue();
				head=NULL;
				tail=NULL;
				node <T>*temp=rhs.head;
				while(temp!=NULL)
				{
					EnQueue(temp->data);
					temp=temp->next;
				}
			}
				return *this;
		}
		void EnQueue(int n)
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
			cout<<endl;
		}
		void DeQueue()
		{
			if(head!=NULL)
			{
				node <T>*temp=head;
				if (head==tail)
					head=tail=NULL;
				else
					head=head->next;
				delete temp;
			}
			else
			cout<<"Queue is Empty!\n";
		}
		bool empty()
		{
			if(head!=NULL)
				return false;
			else
				return true;
		}
		T peak()
		{
			return tail->data;	
		}
		~Queue()
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
int main()
{
	string input ;
	cin>>input;
	Queue <char>Q ;
	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='(' || input[i]=='{' || input[i]=='[')
		Q.EnQueue(input[i]);
		else if(input[i]==')' || input[i]=='}' || input[i]==']')
		{
			if(Q.peak()=='(')
			{
				if(input[i]==')')
					Q.DeQueue();
				else
				{	
					cout<<"Not Balance!";
					exit(0);
				}
			}
			else if(Q.peak()=='[')
			{
				if(input[i]==']')
					Q.DeQueue();
				else
				{	
					cout<<"Not Balance!";
					exit(0);
				}
			}
			else if(Q.peak()=='{')
			{
				if(input[i]=='}')
					Q.DeQueue();
				else
				{	
					cout<<"Not Balance!";
					exit(0);
				}
			}
		}
	}
	if(Q.empty())
	cout<<"Balance!";
	else
	cout<<"Not Balance!";
}
