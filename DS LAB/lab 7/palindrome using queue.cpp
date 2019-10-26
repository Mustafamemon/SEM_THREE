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
			return head->data;	
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
	int length;
	string input;
	cin>>input;
	Queue <char> c;
	if(input.length()%2==0)
		length=input.length()/2;
	else
		length=(input.length()+1)/2;
	for(int i=0;i<length;i++)
	{
		c.EnQueue(input[i]);
	}
	cout<<"\n";
	for(int i=input.length()-1;i>=(length-1)&&!c.empty();i--)
	{
		if(input[i]==c.peak())
			c.DeQueue();
		else
		{
			cout<<"Not Palindrome!";
			exit(0);
		}
	}
	if(c.empty())
	cout<<"Palindrome";
}
