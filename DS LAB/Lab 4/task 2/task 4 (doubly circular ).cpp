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
		node* return_tail()
		{
			return tail;
		}
	
};
int Getnth(node *tmp,int index)
{
	node *tail=tmp->prev;
	while(index!=0)
	{
		index--;
		if(tmp==tail)
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
	cdoublylist myList;
	for(int i=1;i<10;i++)
	myList.add_to_head(i/2*2);
	cout<<"LIST : \n";
	myList.display() ;
	int index;
	cout<<"Enter the index : ";
	cin>>index;
	cout<<Getnth(myList.return_tail()->next,index);
}
