#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void insert(struct node **&head,int e1,int e2,int v)
{
	struct node *newNode1 = new struct node;
	struct node *newNode2 = new struct node;
	newNode1->data = e1;
	newNode1->next = NULL;
	newNode2->data = e2;
	newNode2->next = NULL;
	if(*(head+e1)==NULL)
		*(head+e1) = newNode2;
	else
	{
		node *temp = *(head+e1);
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = newNode2;
	}
	if(*(head+e2)==NULL)
		*(head+e2)=newNode1;
	else
	{
		node *temp = *(head+e2);
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = newNode1;
	}
}
int main()
{
	int v,a,b,e;
	cout<<"Enter number of vertices : ";
	cin>>v;
	cout<<"Enter number of edges : ";
	cin>>e;
	int mat[v][v] = {0};
	
	struct node **head = new struct node*[v];
	for(int i=0;i<v;i++)
		*(head+i) = NULL;
	for(int i=0;i<e;i++)
	{
		cout<<"Enter 2 vertices of an edge : "<<endl;
		cin>>a>>b;
		mat[a][b]=mat[b][a] = 1;
		insert(head,a,b,v);
	}
	cout<<"ADJACENCY MATRIX IS : "<<endl;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	cout<<"ADJACENCY LIST IS : "<<endl;
	for(int i=0;i<v;i++)
	{
		node *temp = *(head+i);
		cout<<i<<"-->\t";
		while(temp->next!=NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<temp->data;
		cout<<endl;
	}
}
