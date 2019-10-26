#include<iostream>
#include<string.h>
#include<fstream>
#include<cmath>
#include<stack>
#include<iostream>

using namespace std;
template <class T>
class node
{
	public:
		T data;
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
template <class T>
class Stack
{
	private:
		node<T> *head , *tail;
	public:	
		Stack()
		{
			head=NULL;
			tail=NULL;
		}
		void push(int n)
		{
			if (tail!=NULL)
			{
				tail->next= new node<T> (n);
				tail=tail->next;
			}
			else
			{
				head=tail=new node<T>(n);
			}
		}
		void display()
		{
			node <T>*temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		void pop()
		{
			if (head!=NULL)
			{
				node <T>*temp=head; 
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
				cout<<"Stack is Empty!\n";
		}
		T top()
		{
			if(tail!=NULL)
			return tail->data;
			else
			cout<<"Stack is Empty!\n";
			return 0 ;
		}
		bool empty()
		{
			if(head==NULL)
				return true ;
			else
				return false ;
		}
		~Stack()
        {
        	node <T>*ptr; 
            while(head!=NULL)
			{ 
                ptr=head->next; 
                delete head; 
                head=ptr; 
            } 
		}
};
class BST
{	
	public:
		BST* left ;
		char data ;
		BST* right ;
		BST()
		{
			data=0;
			left=NULL; 
			right=NULL;
		}
};
BST *FindMax(BST *root)
{
	if(root!=NULL)
	{
		FindMax(root->right);
	}
	return root ;
	
}
BST* delete_BST(BST *r,char adata)
{
	if(r!=NULL)
	{
		if(r->data!=adata)
		{
			if(r->data>adata)
			{
				r->left=delete_BST(r->left,adata);
			}
			else
			{
				r->right=delete_BST(r->right,adata);
			}
		}
		else
		{
			if(r->left!=NULL && r->right!=NULL)
			{
				BST *temp=FindMax(r->left);
				r->data=temp->data;
				r->left=delete_BST(r->left,temp->data);
			}
			else if(r->left!=NULL)
			{
				BST *temp=r;
				r=r->left;
				delete temp ;
				return r ;
			}
			else if(r->right!=NULL)
			{
				BST *temp=r;
				r=r->right;
				delete temp ;
				return r ;
			}
			else
			{
				delete r ;		
				r=NULL;
				return r; 
			}
		}
	}
	return r ;
}
int prec(char c) 
{
	if(c=='^')
	 	return 3;
	else if(c == '*' || c == '/') 
    	return 2; 
    else if(c == '+' || c == '-') 
    	return 1; 
    else
    	return -1; 
} 
BST* insert(BST *r , char adata)
{
	if(r==NULL)
	{
		r=new BST ;
		r->data=adata;
	}
	else 
	{
		if(r->data
		
		{
			r->left=insert(r->left,adata);
		}
		else
		{
			r->right=insert(r->right,adata);
		}
	}
	return r ;
}
void InOrder(BST *root)
{
	if(root!=NULL)
	{
		InOrder(root->left);
		cout<<root->data<<" ";
		InOrder(root->right);
	}
}
void PostOrder(BST *root)
{
	if(root!=NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<root->data<<" ";
	}
}
void PreOrder(BST *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
BST  *root=NULL ;
void infix_to_postfix(char exp[])
{
	Stack <char> operato;
	Stack <char> operand;
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(')
		{
			operato.push(exp[i]);
		}
		else if(exp[i]==')')
		{
			while(operato.top()!='(')
			{
				if(operato.top()!=')' && operato.top()!='(')
				{
					root=insert(root,operato.top());
					if(!operand.empty())
					{
						root->right=insert(root->right,operand.top());
						operand.pop();
						if(!operand.empty())
						{
							root->left=insert(root->left,operand.top());
							operand.pop();
						}
					}
				}
				operato.pop();
			}
			operato.pop();
		}
		
		else if((exp[i]>='0' && exp[i]<='9') || (exp[i]>='a' && exp[i]<='z'))
		{
			operand.push(exp[i]);
		}
		else if(!operato.empty())
		{
			again:
			if(prec(operato.top())<prec(exp[i]))
			{
				operato.push(exp[i]);
			}
			else
			{
				root=insert(root,operato.top());
				if(!operand.empty())
				{
					root->right=insert(root->right,operand.top());
					operand.pop();
					if(!operand.empty())
					{
						root->left=insert(root->left,operand.top());
						operand.pop();
					}
				}
					
				operato.pop();
				if(!operato.empty())
				goto again;
				operato.push(exp[i]);
			}
		}
		else
		{
			operato.push(exp[i]);
		}   
	}
	while(!operato.empty())
	{	
		if(operato.top()!=')' && operato.top()!='(')
		{
			root=insert(root,operato.top());
			if(!operand.empty())
			{
				root->right=insert(root->right,operand.top());
				operand.pop();
				if(!operand.empty())
				{
					root->left=insert(root->left,operand.top());
					operand.pop();
				}
			}
		}
		operato.pop();
	}
}
int main()
{
	char ch[100];
	cin>>ch;
	infix_to_postfix(ch);
	InOrder(root);
}
