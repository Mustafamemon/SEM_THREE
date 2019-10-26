#include<iostream>
#include<stack>
using namespace std ;
class node
{	
	public:
		node* left ;
		int data ;
		node* right ;
		node()
		{
			data=0;
			left=NULL; 
			right=NULL;
		}
};
node *FindMax(node *root)
{
	if(root!=NULL)
	{
		FindMax(root->right);
	}
	return root ;
	
}
/*
bool isCycle(node *root)
{
	int i=0;node array[10] ;
	stack<node*> s;
	if(root)
	{
		do{
			node *current=root ;
			if(current)
			{	
				if(current->left!=NULL)
					s.push(current->left);
				if(current->right!=NULL)
					s.push(current->right);
			}
			for(int j=0;j<i;j++)
			{
				if(&array[i]==current)
				{
					return true ;
				}
			}
			(array[i])=*current;
			++i;
			current=s.top();
			s.pop();
		}while(s.empty());
		return false; 
	}
	else
		return false ;
	
}*/

node* delete_node(node *r,int adata)
{
	if(r!=NULL)
	{
		if(r->data!=adata)
		{
			if(r->data>adata)
			{
				r->left=delete_node(r->left,adata);
			}
			else
			{
				r->right=delete_node(r->right,adata);
			}
		}
		else
		{
			if(r->left!=NULL && r->right!=NULL)
			{
				node *temp=FindMax(r->left);
				r->data=temp->data;
				r->left=delete_node(r->left,temp->data);
			}
			else if(r->left!=NULL)
			{
				node *temp=r;
				r=r->left;
				delete temp ;
				return r ;
			}
			else if(r->right!=NULL)
			{
				node *temp=r;
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
node* insert(node *r , int adata)
{
	if(r==NULL)
	{
		r=new node ;
		r->data=adata;
	}
	else 
	{
		if(r->data>adata)
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
void InOrder(node *root)
{
	if(root!=NULL)
	{
		InOrder(root->left);
		cout<<root->data<<" ";
		InOrder(root->right);
	}
}
void PostOrder(node *root)
{
	if(root!=NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<root->data<<" ";
	}
}
void PreOrder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
int main()
{
	node *root=NULL; 
	root=insert(root,7);
	root=insert(root,4);
	root=insert(root,12);
	root=insert(root,2);
	root=insert(root,6);
	root=insert(root,9);
	root=insert(root,19);
	root=insert(root,3);
	root=insert(root,5);
	root=insert(root,8);
	root=insert(root,11);
	root=insert(root,15);
	root=insert(root,20);
	InOrder(root);
	cout<<endl;
	PreOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;
	root=delete_node(root,9);
	InOrder(root);
	cout<<endl;
	cout<<isCycle(root);
	cout<<endl;
}
