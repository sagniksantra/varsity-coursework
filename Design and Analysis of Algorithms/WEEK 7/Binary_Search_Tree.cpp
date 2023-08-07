#include<iostream>
using namespace std;
struct node
{
	int info;
	struct node *left;
	struct node *right;
};
//struct node node;
int create(struct node *&root,int ele)
{
	
	//struct node *temp=root;

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
	{
	  
	  return create(root->left,ele);
	}
	else
	{
	  return create(root->right,ele);
	}
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
int height(struct node*&root)
{
	if(root==NULL)
		return 0;
	else
	{
		int left_height=height(root->left);
		int right_height=height(root->right);
		
		if(left_height>right_height)
			return (left_height+1);
		else
			return (right_height+1);
	}
}
int main()
{
	struct node *root=NULL;
	int choice;
	do
	{
		cout<<"\n1.Enter 2.Preorder 3.Postorder 4.Inorder:";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter Ele:";
			int ele;
			cin>>ele;
			create(root,ele);
		}
		else if(choice==2)
			preorder(root);
		else if(choice==3)
			postorder(root);
		else if(choice==4)
			inorder(root);
		else if(choice==5)
			cout<<"Height : "<<height(root);
	}while(choice!=6);
}
