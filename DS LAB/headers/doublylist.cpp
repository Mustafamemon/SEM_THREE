#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
		node *prev;
		node()
		{
			data=0;
			next=NULL;
			prev=NULL;	
		}	
		node(int n)
		{
			data=n;
			next=NULL;
			prev=NULL;
		}
		node (int n , node *ne , node *pre)
		{
			data=n;
			next=ne;
			prev=pre;
		}
};
class doublylist
{
	private :
		node *head;
		node *tail;
	public:
		doublylist()
		{
			head=NULL;
			tail=NULL;
		}
		void add_to_head(int n)
		{
			if (head==NULL)
			{
				head=tail=new node(n);
			}
			else
			{
				head=new node(n,head,NULL);
				head->next->prev=head;
			}
		}
		void add_to_tail(int n)
		{
			if (tail!=NULL)
			{
				tail=new node(n,NULL,tail);
				tail->prev->next=tail;
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
				int c;
				cout<<temp->data<<" ";
				temp=temp->next;
				//cin>>c;
			}
			cout<<"\n";
		}
		void delete_head()
		{
			if (head!=NULL)
			{
				if(head==tail)
					head=tail=NULL;
				else
				{
					head=head->next;
					delete head->prev;
					head->prev=NULL;
				}
			}
			else
				cout<<"List is Empty!";	
		}
		void delete_tail()
		{
			if (tail!=NULL)
			{
				if(head==tail)
					head=tail=NULL;
				else
				{
					tail=tail->prev;
					delete tail->next;
					tail->next=NULL;
				}
			}
			else
				cout<<"List is Empty!";	
		}
		bool search(int n)
		{
			node *temp;
			for(temp=head;temp!=NULL && temp->data!=n;temp=temp->next);
				return temp!=0;
		}
		void add_somewhere(int a,int n)
		{
			/*if (head==tail)
			{
				head=tail=new node(n,NULL,NULL)	;
			}
			else*/
			{
				node *temp = head;
				while(temp!=NULL)
				{
					if (temp->data==a)
					{
						node *place;
						place=new node(n,temp->next,temp);	
						if (temp->next==NULL)
							tail=place;
						else
							temp->next->prev=place;
						temp->next=place;
					}
					temp=temp->next;
				}
			}
		}	
		void delete_somewhere(int a)
		{
			node *temp=head ;
			while (temp!=NULL)
			{
				if(temp->data==a)
				{
					if (head==tail)
						head=tail=NULL;
					else if (temp->next==NULL)
					{
						tail=temp->prev;
						tail->next=NULL;
					}
					else if(temp->prev==NULL)
					{
						head=temp->next;
						head->prev=NULL;
					}
					else
					{
						temp->prev->next=temp->next;
						temp->next->prev=temp->prev;			
					}
				}
				temp=temp->next;
			}
			
		}
		void reversing()
		{ 
			if(head!=NULL)
			{
	            node *temp = NULL;    
	            node *current = head;
	            head=tail;
				tail=current; 
	            while (current !=  NULL)  
				{  
	                temp = current->prev;  
	                current->prev = current->next;  
	                current->next = temp;                
	                current = current->prev;  
	            } 
			}
			else
			cout<<"List is empty!";
        }
        void sort()
        {
        	for (node *i=head;i!=NULL;i=i->next)
       	{
        		for (node *j=head;j!=tail;j=j->next)
        		{	
        			if (j->next->data<j->data)
        			{
        				int temp=j->next->data;
        				j->next->data=j->data;
						j->data=temp;
					}
				}
			}
		}
		void JK()
		{
			node *temp=head;
			swap(temp->next,temp->next->next)
			;cout<<equal(temp,temp->next);
		}
		bool equal (node *A , node*B)
		{
			if(A->next==B)
				return true;
			else if(A->prev==B)
				return true;
			else if(B->next==A)
				return true;
			else
			return false;
		
		}
		void swap(node *A , node *B)
		{
			A->prev->next=B;
			B->next->prev=A;
			B->prev=A->prev;
			A->next=B->next;
			A->prev=B;
			B->next=A;
		}
};

int main()
{
	doublylist l;
	
	l.add_to_head(1);
	l.add_to_head(2);
	l.add_to_head(3);
	l.add_to_tail(4);
	l.display();
//	l.JK();
//	l.display();	
}
