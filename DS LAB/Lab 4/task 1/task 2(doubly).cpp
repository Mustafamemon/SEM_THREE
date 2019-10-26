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
		node* return_head()
		{
			return head;
		}
		node* return_tail()
		{
			return tail;
		}
		~doublylist()
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
};
int Count(node *tmp , int a)
{
	int count=0; 
    do     
	{
    	if(tmp->data==a)
    	count++;
    	tmp=tmp->next;
	}while(tmp!=NULL);
   	return count; 
}
void Counttest()
{
	int num;
	cout<<"Enter the Element to search in list : ";
	cin>>num;
	doublylist myList;
	for(int i=1;i<10;i++)
	myList.add_to_head(i/2*2);
	cout<<"LIST : \n";
	myList.display() ;
	cout<<"\nCOUNT : "<<Count(myList.return_head(),num); 
}

int main()
{
	Counttest();
}
