#include <iostream>
using namespace std;

int knapsack(int cap, int wt[], int val[], int n) 
{
    int i, w;
    int K[n+1][cap+1];
    for (i = 0; i <= n; i++) 
	{
        for (w = 0; w <= cap; w++) 
		{
            if (i == 0 || w == 0) 
                K[i][w] = 0;
                
            else if (wt[i-1] <= w) 
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
                
            else 
                K[i][w] = K[i-1][w];
        }
    }
    for (i = 0; i <= n; i++) 
	{
        for (w = 0; w <= cap; w++) 
			cout<<K[i][w]<<" ";
		cout<<endl;
		
	}
    
    return K[n][cap];
}

int main() 
{
	int n,cap;
	cout<<"Enter n : ";
	cin>>n;
	
	cout<<"Enter Weights : "<<endl;
	int wt[n],val[n];
	
	for(int i=0;i<n;i++)
		cin>>wt[i];
		
	cout<<"Enter values : "<<endl;
	for(int i=0;i<n;i++)
		cin>>val[i];
		
    cout<<"Enter cap : ";
    cin>>cap;
    //int n = sizeof(val)/sizeof(val[0]);
    cout << "Optimal knapsack soln is : "<<knapsack(cap, wt, val, n) << endl;
    return 0;
}

