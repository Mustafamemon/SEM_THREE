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

int Getnth(node *tmp,int index)
{
	while(index!=0)
	{
		index--;
		if(tmp->next==NULL)
		{
			cout<<"Index Out of Bound!";
			exit(1);	
		}
		tmp=tmp->next;
	}
	return tmp->data;
}

int main()
{
	linkedlist myList;
	for(int i=1;i<10;i++)
	myList.add_node_head(i/2*2);
	cout<<"LIST : \n";
	myList.display() ;
	int index;
	cout<<"\nEnter the index : ";
	cin>>index;
	cout<<Getnth(myList.return_head(),index);
}
