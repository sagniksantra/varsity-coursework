#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node* head=NULL;
void push(int ele)
{
	struct node *newNode=new struct node;
	newNode->data=ele;
	newNode->next=NULL;
	
	struct node *temp=head;
	if(head==NULL)
		head=newNode;
		
	else
	{
		while(temp->next!=NULL)
	  		temp=temp->next;
		temp->next=newNode;
	}
}
int pop()
{
	struct node*temp=head;
	int popped;
	if(temp==NULL)
	{
	   return -1;
	}

	if(temp->next==NULL)
	{
		popped=temp->data;
		head=NULL;
		return popped;
	}
	
	if(temp->next->next==NULL)
	{
		popped=temp->next->data;
		temp->next=NULL;
	}
	
	else
	{
		while(temp->next->next!=NULL)
			temp=temp->next;
		popped=temp->next->data;
		temp->next=NULL;
	}
	return popped;
}
int top_ele()
{
	struct node*temp=head;
	int top;
	if(temp==NULL)
	{
	   //cout<<"stack is empty:"<<endl;
	   return 0;
	}

	if(temp->next==NULL)
	{
		top=temp->data;
		//cout<<"stack is now empty:"<<endl;
		return top;
	}
	
	if(temp->next->next==NULL)
	{
		temp=temp->next;
		top=temp->data;
	}
	
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		top=temp->data;
	}
	return top;
}
//void display()
//{
//	struct node*temp=head;
//	while(temp->next!=NULL)
//	{
//		cout<<temp->data<<" ";
//		temp=temp->next;
//	}
//	cout<<temp->data<<endl;
//}
void dfs(int mat[][10],int visited[],int v)
{
	
	int i=0;
	while(i<v)
	{
		int flag=0;
		for(int l=0;l<v;l++)
		{
			if(visited[l]==0)
			{
				flag=1;
				break;
			}
				
		}
		if(flag==1)
		{
		
			for(int j=0;j<v;j++)
			{
				if(mat[i][j]==1 && visited[j]==0)
				{
					push(j);
					cout<<j<<" ";
					visited[j]=1;
					i=j;
					break;
				}
				if(j==v-1)
				{
					int ele=pop();
					//cout<<ele<<" ";
					i=top_ele();
				}	
			}
		}
		else
		{
			while(true)
			{
				int ele=pop();
				if(ele==-1)
					break;
				//else
					//cout<<ele<<" ";
			}
			break;
		}	
		
		
	}
	
}
int mat[10][10];
int main()
{
	int v,e,a,b;
	cout<<"enter no. of vertices:";
	cin>>v;
	cout<<"enter no. of edges:";
	cin>>e;	
	for(int i=0;i<e;i++)
	{
		cout<<"enter 2 vertices of an edge"<<endl;
		cin>>a>>b;
		mat[a][b]=1;
		mat[b][a]=1;
	}
	push(0);
	int visited[v]={0};
	visited[0]=1;
	dfs(mat,visited,v);
}
