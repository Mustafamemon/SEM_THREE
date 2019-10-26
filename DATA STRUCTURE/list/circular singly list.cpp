#include<iostream>

using namespace std;
 
class node
{
	public:
		int data;
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
class linkedlist
{
	private:
		node *tail;
	public:	
		linkedlist()
		{
			tail=NULL;
		}
		linkedlist(const linkedlist &rhs)
		{
			tail=NULL;
			node *temp=rhs.tail->next;
			do
			{
				add_to_tail(temp->data);
				temp=temp->next;
			}while(temp!=rhs.tail->next);			
		}
		/*linkedlist& operator=(const linkedlist &rhs)
		{
			if (this!=&rhs)
			{
				this->~linkedlist();
				head=NULL;
				tail=NULL;
				node *temp=rhs.head;
				while(temp!=NULL)
				{
					add_to_tail(temp->data);
					temp=temp->next;
				}
			}
				return *this;
		}*/
		void add_to_head(int n)
		{
			if (tail==NULL)
			{
				tail=new node(n);
				tail->next=tail;
			}
			else
			{
				tail->next=new node(n,tail->next);
			}
		}
		void add_to_tail(int n)
		{
			if (tail==NULL)
			{
				tail=new node(n);
				tail->next=tail;
			}
			else
			{
				tail->next=new node(n,tail->next);
				tail=tail->next;
			}
		}
		void add_before(int a, int n)
		{
			if(tail!=NULL)
			{
				node *temp=tail->next;
				do 
				{
					if (temp->next->data==a)
					{
						temp->next=new node(n,temp->next);
						temp=temp->next;
					}
					temp=temp->next;
				}while (temp!=tail->next);	
			}
			else
			cout<<"List is Empty!";
		}
		void add_after(int a, int n)
		{
			if(tail!=NULL)
			{
				node *temp=tail->next;
				do 
				{
					if (temp->data==a)
					{
						temp->next=new node(n,temp->next);
						if (temp==tail)
						{
							tail=temp->next;
						}
					}
					temp=temp->next;
				}while (temp!=tail->next);	
			}
			else
			cout<<"List is Empty!";
		}
		void delete_head()
		{
			if (tail!=NULL)
			{
				node *temp=tail->next;
				if(tail->next==tail)
					tail=NULL;
				else
				{
					tail->next=tail->next->next;	
				}
				delete temp;
			}
			else
			cout<<"List is Empty!";
		}
		void delete_tail()
		{
			if(tail!=NULL)
			{
				node *temp;
				if (tail->next==tail)
					tail=NULL;	
				else 
				{	
					node *temp1=tail->next;
					for(temp=tail->next;temp->next!=tail;temp=temp->next);
					delete tail;
					tail=temp;
					tail->next=temp1;
				}
			}
			else
			cout<<"List is Empty!";
		}
		void delete_somewhere(int n)
		{
			if (tail!=NULL)
			{
				node *temp=tail->next;
				do
				{
					if (temp->next->data==n)
					{
						node *temp1 = temp->next;
						temp->next=temp->next->next;
						if (temp1==tail)
						{
							tail=temp;
						}	
						delete temp1;
					}
					temp=temp->next;
				}while(temp!=tail->next);
			}
			else
			cout<<"List is Empty!";
		}
		void display()
		{
			if(tail!=NULL)
			{
				node *temp=tail->next;
				cout<<temp->data<<" ";
				while(temp!=tail)
				{
					temp=temp->next;
					cout<<temp->data<<" ";
				}
				cout<<"\n";
			}
		}
		void reversing()
		{
			if (tail!=NULL)
			{		
				node *current = tail->next  , *temp , *temp1=NULL;
				do
				{
					temp=current->next;
					current->next=temp1;
					temp1=current;
					current=temp;
				}while(current->next!=NULL);
				current->next=tail;
				tail=current;
			}
			else
			cout<<"List is Empty!"	;
		}
		
};
int main()
{
	linkedlist l;
	l.add_to_head(1);
	l.delete_head();
	l.display();
	cout<<"A";
	l.delete_tail();
	l.display();
	l.add_to_head(2);
	l.add_to_head(3);
	l.add_to_head(4);
	l.add_to_head(5);
	l.display();
	l.add_before(5,6);
	l.display();
	l.delete_somewhere(1);
	l.display();
	l.reversing();	
	l.display();
	l.add_to_head(1);
	l.display();
	l.add_to_tail(2);
	l.display();
	l.add_to_head(3);
	l.display();
	l.add_to_tail(4);
	l.display();
	l.add_to_tail(5);
	l.display();
	linkedlist l2=l;
	l2.display();
	/*l.delete_head();
	l.display();
	l.delete_tail();
	l.display();
	*/
}
