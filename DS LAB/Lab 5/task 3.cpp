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
class linkedlist
{
	private :
		node *head;
		node *tail;
	public:
		linkedlist()
		{
			head=NULL;
			tail=NULL;
		}
		~linkedlist()
		{
			node *ptr; 
            while(head!=tail)
			{ 
                ptr=head->next; 
                delete head; 
                head=ptr; 
            }
            delete tail;
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
				cout<<temp->data<<" ";
				temp=temp->next;
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
		node * return_head()
		{
			return head;
		}
		node * return_tail()
		{
			return tail;
		}
		
};
void swap(int &a , int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
linkedlist* Selection_sort(linkedlist *List)
{
	node  *temp1=List->return_head(),*temp=temp1,*temp2=NULL ;
	while(temp1!=List->return_tail())
	{
		temp=temp1->next;
		temp2=temp1;
		while(temp!=NULL)
		{
			if(temp->data < temp2->data)
			{
				temp2=temp;
			}
			temp=temp->next;
		}
		temp=temp2;
		if(temp1->data!=temp2->data)
		swap(temp1->data,temp2->data);
		temp1=temp1->next;
	}
	return List;
}
int main()
{
	linkedlist l;
	l.add_to_head(9);
	l.add_to_head(3);
	l.add_to_head(8);
	l.add_to_head(1);
	l.add_to_head(0);
	l.add_to_tail(5);
	cout<<"Before Sort : ";
	l.display();
	cout<<"\n\t\t\tSelection Sort \n";
	cout<<endl<<"After  Sort : ";
	linkedlist *l1;
	l1=Selection_sort(&l);
	l1->display();
}
