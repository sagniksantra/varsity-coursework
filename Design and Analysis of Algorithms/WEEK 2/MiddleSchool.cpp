#include <iostream>
using namespace std;
bool prime_check(int n)
{
	for(int i = 2;i<n;i++)
	{
		if(i==2) return true;
		if(n%i==0) return false;	
	}
	return true;	
}
int gcd(int num1,int num2)//24 36 
{
	int n1=num1,n2=num2,prod=1;
	for(int i=2;i<=n1 && i<=n2;i++)
	{
		if(prime_check(i))//i=2
		{
			while(n1%i==0 && n2%i==0)
			{
				prod*=i;//2*2*3
				n1/=i;//12 6 2
				n2/=i;//18 9 3
			}
		}
	}
	return prod;
}
int main()
{
	int a,b;
	cout<<"Enter two +ve numbers to find their gcd : "<<endl;
	cin>>a>>b;//6 10
	int prime_a[10],prime_b[10];
	
	cout<<"GCD = "<<gcd(a,b);  
}

