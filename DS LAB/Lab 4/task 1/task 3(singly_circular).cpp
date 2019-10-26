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
		linkedlist& operator=(const linkedlist &rhs)
		{
			if (this!=&rhs)
			{
				this->~linkedlist();
				tail=NULL;
				node *temp=rhs.tail->next;
				do
				{
					add_to_tail(temp->data);
					temp=temp->next;
				}while(temp!=rhs.tail->next);
			}
			return *this;
		}
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
		node* return_tail()
		{
			return tail;
		}
		
};

int Count(node *tmp,node *tail ,int a)
{
	int count=0; 
    do
	{
    	if(tmp->data==a)
    	count++;
    	tmp=tmp->next;
	}while(tmp!=tail->next);
  	return count; 
}
void Counttest()
{
	int num;
	cout<<"Enter the Element to search in list : ";
	cin>>num;
	linkedlist myList;
	for(int i=1;i<10;i++)
	myList.add_to_head(i/2*2);
	cout<<"LIST : \n";
	myList.display() ;
	cout<<"\nCOUNT : "<<Count(myList.return_tail()->next,myList.return_tail(),num); 
}

int main()
{
	Counttest();
}
