#include <iostream>
using namespace std;
int main()
{
	int m1,m2,n1,n2;
	cout<<"Enter matrix dimensions for 1st matrix"<<endl;
	cin>>m1>>n1;
	cout<<"Enter matrix dimensions for 2nd matrix"<<endl;
	cin>>m2>>n2;
	
	
	
	if(n1!=m2)
		cout<<"Multiplication not possible"<<endl;
	else
	{
		int mat1[m1][n1],mat2[m2][n2];//32 23
	cout<<"Matrix 1";
	for(int i=0;i<m1;i++)
	{
		for(int j=0;j<n1;j++)
		{
			cout<<"Enter values : "<<endl;
			cin>>mat1[i][j];
		}
	}
	cout<<"Matrix 2";
	for(int i=0;i<m2;i++)
	{
		for(int j=0;j<n2;j++)
		{
			cout<<"Enter values"<<endl;
			cin>>mat2[i][j];
		}
	}
	int ans[m1][n2];
	for(int i=0;i<m1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			int sum=0;
			for(int k=0;k<n1;k++)
			{
				sum += mat1[i][k] * mat2[k][j];
				ans[i][j] = sum;
			}
		}
	}
	
	for(int i=0;i<n2;i++)
	{
		for(int j=0;j<n2;j++)
		{
			cout<<ans[i][j]<<" ";
		
		}
		cout<<"\n";
	}
	}
	return 0;
}
