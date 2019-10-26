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
		int top;
		linkedlist<T> l;
	public:
		Stack()
		{
			top=-1;		
		}
		void push(T data)
		{
			++top;
			l.add_node_tail(data);
		}
		void pop()
		{
			if(top>=0)
			{
				top--;
				l.delete_tail();
			}
		}
		T peak()
		{
			if(top>=0)
			{
				return l.peak();
			}
			else
			{
				cout<<"List is Empty!";
				return 0;
			}
		}
		int size()
		{
			return top;	
		}
};
int main()
{
	Stack <int>s ;
	for(int i=0;i<10;i++)
	s.push(i);
	for(int i=0;i<10;i++)
	{
		cout<<s.peak()<<" ";
		s.pop();
	}
}
