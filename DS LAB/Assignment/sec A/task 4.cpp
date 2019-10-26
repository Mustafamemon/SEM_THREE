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
		node *head , *tail;
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
			node *temp=rhs.head;
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
				node *temp=rhs.head;
				while(temp!=NULL)
				{
					add_node_tail(temp->data);
					temp=temp->next;
				}
			}
				return *this;
		}
		void add_node_head(int n)
		{
			if (head==NULL)
			{
				head=tail=new node(n);
			}
			else 
			{
				head=new node(n,head);
			}
		}
		void add_node_tail(int n)
		{
			if (tail!=NULL)
			{
				tail->next= new node (n);
				tail=tail->next;
			}
			else
			{
				head=tail=new node(n);
			}
		}
		void display()
		{
			node *temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		void add_somewhere(int pdata , int ndata)
		{
			if(head!=NULL)
			{
				node *temp = head;
				while (temp!=NULL)
				{
					if (temp->data==pdata)
					{
						if (temp==tail)
						{
							tail->next=new node(ndata);
							tail=tail->next;
						}
						else
						temp->next=new node(ndata,temp->next);
					}
					temp=temp->next;
				}
			}
			else
			cout<<"List is Empty";
		}
		void delete_head()
		{
			if(head!=NULL)
			{
				node *temp=head;
				if (head==tail)
					head=tail=NULL;
				else
					head=head->next;
				delete temp;
			}
			else
			cout<<"List is Empty!";
		}
		void delete_tail()
		{
			if (head!=NULL)
			{
				node *temp=head; 
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
		void delete_largest()
		{
			int ndata=largest();
			if (head!=NULL)
			{
				node *temp=head , *prev=NULL;
				while(temp!=NULL)
				{
					if (temp->data==ndata)
					{
						if (temp==head)
							head=temp->next;
						else if (temp==tail)
						{
							tail=prev;
							tail->next=NULL;
						}
						else
						prev->next=temp->next;	
					}
					prev=temp;
					temp=temp->next;
				}
			}
			else
			cout<<"List is Empty!";
		}
		void reverse()
		{
			node *current=head , *next=NULL  , *prev=NULL;
			while (current!=NULL)
			{
				next=current->next;
				current->next=prev;
				prev=current;
				current=next;
			}
			head=prev;
		}
		bool searching(int a)
		{ 
            node *tmp; 
            for(tmp=head;tmp!=NULL && tmp->data!=a;tmp=tmp->next); 
           		return tmp!=NULL; 
        }
        ~linkedlist()
        {
        	node *ptr; 
            while(head!=NULL)
			{ 
                ptr=head->next; 
                delete head; 
                head=ptr; 
            } 
		}
		int largest()
		{
			int temp2=0; 
			node *temp1=head;
			while(temp1!=NULL)
			{
				if(temp2<temp1->data)
				{
					temp2=temp1->data;
				}
				
				temp1=temp1->next;
			}
			return temp2;
		}
		void palindrome()
		{
			node *temp=head,*temp1;
			linkedlist reverse;
			while(temp!=NULL)
			{
				reverse.add_node_head(temp->data);
				temp=temp->next;
			}
			temp=head; temp1=reverse.head;
			while(temp!=NULL)
			{
				if(temp->data!=temp1->data)
				{
					cout<<"not";
					break;
				}
				temp=temp->next; temp1=temp1->next; 
			}
			cout<<"Yes";
		}
};

int main()
{
	linkedlist l;
	l.add_node_head(1);
	l.add_node_head(2);
	l.add_node_head(0);
	l.add_node_head(2);
	l.add_node_head(0);
	cout<<"List : ";l.display();
	cout<<"\nLargest Element: "<<l.largest();
	l.delete_largest();
	cout<<"\nList : ";l.display();
	
}
