#include<iostream>
using namespace std;
class node
{
	public:
		node *next;
		node *prev;	
		int data;
		node()
		{
			next=NULL;
			prev=NULL;	
			data=0;
		}
		node(int n)
		{
			next=NULL;
			prev=NULL;	
			data=n;
		}
		node(int n , node *ne , node *pre)
		{
			next=ne;
			prev=pre;	
			data=n;
		}
};
class cdoublylist
{
	private:
		node *tail;	
	public:
		cdoublylist()
		{
			tail=NULL;
		}
		void add_to_head(int n)
		{
			if(tail!=NULL)
			{
				node *place;
				place=new node(n,tail->next,tail);
				tail->next->prev=place;
				tail->next=place;
			}
			else
			{
				tail=new node(n);
				tail->next=tail;
				tail->prev=tail;
			}
		}
		void add_to_tail(int n)
		{
			if (tail!=NULL)
			{
				node *place;
				place=new node(n,tail->next,tail);
				tail->next->prev=place;
				tail->next=place;
				tail=place;
			}
			else
			{
				tail=new node(n);
				tail->next=tail;
				tail->prev=tail;
			}
		}
		void delete_head()
		{
			if (tail!=NULL)
			{
				if (tail->next==tail)
					tail=NULL;
				else
				{
					node *temp=tail->next;
					tail->next=tail->next->next;
					tail->next->prev=tail->next;
					delete temp;
				}
			}
			else
				cout<<"List is Empty!";
		}
		void delete_tail()
		{
			if(tail!=NULL)
			{
				if (tail->next==tail)
					tail=NULL;
				else
				{
					node *temp=tail;
					tail=temp->prev;
					tail->next=temp->next;
					delete temp;
				}
			}
			else
				cout<<"List is Empty!";
		}
		void reversing()
		{
			if (tail!=NULL)
			{
				node *current=tail ,*temp=NULL;
				tail=tail->next;
				tail->prev=current;
				do  
				{  
	                temp = current->prev;  
	                current->prev = current->next;  
	                current->next = temp;                
	                current = current->prev;  
	            }while (current !=  tail->next);    
			}
			
		}
		void display()
		{
			if (tail!=NULL)
			{
				node *temp=tail->next;
				do 
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}while(temp!=tail->next);
				cout<<"\n";
			}
		}
	
};
int main()
{
	cdoublylist l;
	l.add_to_tail(3);
	l.display();
	l.delete_head();
	l.display();
	l.delete_tail();
	l.display();
	l.add_to_head(1);
	l.add_to_tail(2);
	l.display();
	l.add_to_head(3);
	l.add_to_head(4);
	l.display();
	
	l.add_to_tail(5);
	l.display();
	l.delete_head();
	l.display();
	l.delete_tail();
	l.display();
	l.add_to_head(2);
	l.display();
	l.reversing();
	l.display();
}

