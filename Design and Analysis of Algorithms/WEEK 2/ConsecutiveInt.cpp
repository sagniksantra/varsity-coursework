#include <iostream>
using namespace std;
int gcd(int a,int b)//6,10
{
	int ans = 0,t = 0;
	t = a>b?b:a;//6
	while(t>=1)
	{
		if(a%t==0)//0,1
		{
			if(b%t==0)//4
				return ans = t;
			else
				t--;//5
		}
		else 
			t--;//4
	}
}
int main()
{
	int a,b,t=0;
	cout<<"Enter two +ve numbers to find their gcd : "<<endl;
	cin>>a>>b;
	cout<<"GCD = "<<gcd(a,b);
	
}
