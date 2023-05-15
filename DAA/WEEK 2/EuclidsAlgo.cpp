#include <iostream>
using namespace std;
int gcd(int a,int b)
{
	if(a==0) return b;
	if(b==0) return a;
	
	return gcd(b,a%b);
}
int main()
{
	int a,b;
	cout<<"Enter two numbers to find their gcd : "<<endl;
	cin>>a>>b;
	cout<<"GCD = "<<gcd(a,b);
	
}
