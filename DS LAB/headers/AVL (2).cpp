#include<iostream>
using namespace std ;
class node
{	
	public:
		node* left ;
		int data ;
		int height;
		node* right ;
		node()
		{
			height=0;
			data=0;
			left=NULL; 
			right=NULL;
		}
};
int height(node *root)
{
	if(root!=NULL)
	{
		height++;
		Get_height(root->right)
	}
	return height;
}

node *FindMax(node *root)
{
	if(root!=NULL)
	{
		FindMax(root->right);
	}
	return root ;
	
}
node *FindMin(node *root)
{
	if(root!=NULL)
	{
		FindMin(root->left);
	}
	return root ;
}
node* singleRightRotate(node* &r)
{
    node* temp = r->left;
    r->left = r->right;
    temp->right = r;
    r->height = max(height(r->left), height(r->right))+1;
    temp->height = max(height(temp->left), r->height)+1;
    return temp;
}
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
			if(height(r->left)-height(r->right)==2)
			{
				if(adata < r->left->data)
                    r = singleRightRotate(r);
                else
                    r = doubleRightRotate(r);
			}
		}
		else if(r->data<adata)
		{
			r->right=insert(r->right,adata);
			if(height(r->right)-height(r->left)==2)
			{
				
				if(adata < r->right->data)
                    r = singleLeftRotate(r);
                else
                    r = doubleLeftRotate(r);
			}
		}
		r->height = max(height(r->left), height(r->right))+1;	
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
}

