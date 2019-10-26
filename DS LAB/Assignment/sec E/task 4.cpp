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
		next=NULL;
		data=0;
	}
	node(int n)
	{
		next=NULL;
		prev=NULL;
		data=n;
	}
	node(int n , node *en,node *pre)
	{
		prev=pre;
		next=en;
		data=n;
	}
};
class list
{
	private:
		node *head;
		node *tail;
	public:
		list()
		{
			head=NULL;
			tail=NULL;
		}
		void add_to_head(int n)
		{
			if(head==NULL)
			{
				head=tail=new node(n);
			}
			else
			{
				node *place;
				place=new node(n,head,NULL);
				head->prev=place;
				head=place;
			}
		}
		int count()
		{
			int count=0;
			node *temp=tail;
			do
			{
				count++;
				temp=temp->prev;
			}while(temp!=NULL);
			return count;
		}
		void altnode()
		{
			node *temp;
			int coun=count();
			temp=head;
			for(int i=0;i<coun;i++)
			{
				if(coun%2==0)
				{
					if(i%2!=0)
					cout<<temp->data<<" ";
				}
				else
				{
					if(i%2==0)
					cout<<temp->data<<" ";
				}
				temp=temp->next;
			}
			
			temp=tail;
			for(int i=0;i<coun;i++)
			{
				if(i%2==0)
				cout<<temp->data<<" ";
				temp=temp->prev;
			}
		}
		void display()
		{
			node *temp=tail;
			do
			{
				cout<<temp->data<<" ";
				temp=temp->prev;
			}while(temp!=NULL);
		}
};
int main()
{
	int n,n1;
	list l;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>n1;
		l.add_to_head(n1);
	}
	l.altnode();
}
