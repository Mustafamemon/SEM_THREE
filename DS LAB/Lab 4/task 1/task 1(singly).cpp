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
		node* return_head()
		{
			return head;
		}
};

int Count(node *tmp,int a)
{
	int count=0; 
    for(;tmp!=NULL;tmp=tmp->next)
    {
    	if(tmp->data==a)
    	count++;
	}
   	return count; 
}
void Counttest()
{
	int num;
	cout<<"Enter the Element to search in list : ";
	cin>>num;
	linkedlist myList;
	for(int i=1;i<10;i++)
	myList.add_node_head(i/2*2);
	cout<<"LIST : \n";
	myList.display() ;
	cout<<"\nCOUNT : "<<Count(myList.return_head(), num); 
}

int main()
{
	Counttest();
}
