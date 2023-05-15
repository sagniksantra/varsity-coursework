#include <iostream>
using namespace std;
struct node
{
	int info;
	struct node *left,*right;
	//struct node *right;
};
int nodes=0;
void insert(struct node *&root,int ele,int after,char choice)
{

	if(root==NULL)
	{
		struct node *newNode = new struct node;
		root = newNode;
		newNode->info = ele;
		newNode->right = NULL;
		newNode->left = NULL;
	}
	
	if(root->info == after)
	{ 
		struct node *newNode = new struct node;
		newNode->info=ele;
		newNode->right=NULL;
		newNode->left=NULL;
		
		if(choice=='R')
			root->right=newNode;
			
		else if(choice=='L')
		    root->left=newNode;
		//return 0;
	}
	
	//else
	if(root->right!=NULL)
	{
		insert(root->right,ele,after,choice);
	
	}
	if(root->left!=NULL)
	{
		insert(root->left,ele,after,choice);
		
	}
}
void display(struct node *&root)
{
	if(root!=NULL)
	{
		display(root->left);
		cout<<root->info<<" ";
		nodes++;
		display(root->right);
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
		cout<<"\n1.CREATE 2.DISPLAY NODES 3.HEIGHT 4.EXIT \tEnter Choice : ";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter Element : ";
			int ele,after;
			char c;
			cin>>ele;
			cout<<"Enter R or L for right or left or Enter 0 if its a first node : ";
			cin>>c; 
			if(c!='0')
			{
				cout<<"Enter Element after which to insert :";
				cin>>after;
			}
			insert(root,ele,after,c);
		}
		else if(choice==2)
			display(root);
		else if(choice==3)
			cout<<"Height : "<<height(root);
	}while(choice!=4);
}
