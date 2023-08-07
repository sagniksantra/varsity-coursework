 #include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node* head=NULL;
void enqueue(int ele)
{
	struct node *newNode=new struct node;
	newNode->data=ele;
	newNode->next=NULL;
	
	struct node *temp=head;
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
	
	while(temp->next!=NULL)
	  temp=temp->next;
	temp->next=newNode;
}
}
int dequeue()
{
	struct node *temp=head;
	int ele;
	if(head==NULL)
	{
	//	cout<<"queue is empty"<<endl;
		return -1;
	}
	if(head->next==NULL)
	{
		ele=temp->data;
		head=NULL;
	   return ele;
	}
	ele=temp->data;
	head=head->next;
	return ele;
}
int top_ele()
{
	int ele;
	struct node *temp=head;
	if(head==NULL)
	{
		//cout<<"queue is empty"<<endl;
		return -1;
	}
	ele=temp->data;
	return ele;
}
void bfs(int mat[][10],int visited[],int v)
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
					enqueue(j);
					visited[j]=1;
					break;
				}
				if(j==v-1)
				{
					int ele=dequeue();
					cout<<ele<<" ";
					i=top_ele();
				}	
			}
		}
		else
		{
			while(true)
			{
				int ele=dequeue();
				if(ele==-1)
					break;
				else
					cout<<ele<<" ";
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
	enqueue(0);
	int visited[v]={0};
	visited[0]=1;
	bfs(mat,visited,v);
}
