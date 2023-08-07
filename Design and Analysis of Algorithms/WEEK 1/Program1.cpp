#include <iostream>
using namespace std;
//Priyanshu Panchal - 210968174 - 02-02-2023
//Program for Binary Tree
struct node
{
	int info;
	struct node *left,*right;
};
void insert(struct node *&root,int ele,int after,char choice)
{

	if(root==NULL)
	{
		struct node *newNode = new struct node;
		root=newNode;
		newNode->info = ele;
		newNode->right = NULL;
		newNode->left = NULL;
		
	}
	
	if(root->info == after)
	{ 
		struct node*newNode=new struct node;
		newNode->info=ele;
		newNode->right=NULL;
		newNode->left=NULL;
		if(choice=='R')
			root->right=newNode;
		else if(choice=='L')
		  root->left=newNode;
	
	}
	if(root->right!=NULL)
	{
		insert(root->right,ele,after,choice);
	}
	if(root->left!=NULL)
	{
		insert(root->left,ele,after,choice);
	}
	
}
int create(struct node *&root,int ele)
{
	if(root==NULL)
	{
		struct node*newNode=new struct node;
		newNode->info=ele;
		newNode->left=NULL;
		newNode->right=NULL;
		root=newNode;		
		return newNode->info;
	}
	//cout<<root->info<<" ";
	if(ele<root->info)
	  return create(root->left,ele);
	
	else
	  return create(root->right,ele);
	
}
bool search(struct node *&root,int n)
{
	if(root==NULL)
		return false;
	if(root->info==n)
		return true;
	if(search(root->left,n)) 
		return true;
	bool result = search(root->right,n);
		return result;
}

void postorder(struct node *&root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->info<<" ";
	}
}
void preorder(struct node *&root)
{
	if(root!=NULL)
	{
		cout<<root->info<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *&root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->info<<" ";
		inorder(root->right);
	}
}
int main()
{
	struct node *root=NULL,*bst_root = NULL;
	int choice;
	do
	{
		cout<<"\n1.CREATE 2.SEARCH 3.INORDER 4.POSTORDER 5.PREORDER 6.Print BST 7.EXIT\tEnter Choice : ";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter Element :";
			int ele,after;
			char c;
			cin>>ele;
			cout<<"Enter R or L for right or left or Enter 0 if its a first node : ";
			cin>>c; 
			if(c!='0' && (c=='R' || c=='L'))
			{
				cout<<"Enter Element after which to insert :";
				cin>>after;
			}
			if(c=='0' || c=='L' || c=='R') insert(root,ele,after,c);
		}
		else if(choice==2)
		{
			int find;
			cout<<"Enter a number to find : ";
			cin>>find;
			bool res = search(root,find);
			if(res==true) cout<<"KEY FOUND !";
			else //cout<<"Key Not Found";
			{
				create(bst_root,find);
				inorder(bst_root);
			}
			//cout<<"KEY NOT FOUND";
		}
		else if(choice==3)
		{
			inorder(root);
		}
		else if(choice==4)
		{
			postorder(root);
		}
		else if(choice==5)
		{
			preorder(root);
		}
		else if(choice==6)
		{
			inorder(bst_root);
		}
		
	}while(choice!=7);
}
