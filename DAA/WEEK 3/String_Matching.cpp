#include <iostream>
using namespace std;
int main()
{
	cout<<"Enter a string(text) : ";
	char text[100],pattern[100];
	cin.getline(text,100,'\n');
	int l1=0,l2=0;
	while(text[l1]!='\0') l1++;
	cout<<"Enter pattern to find : ";
	cin.getline(pattern,100,'\n');
	while(pattern[l2]!='\0') l2++;
	int i=0,j=0,k=0,flag=0,p=0;
	for(i=0;text[i]!='\0';i++)
	{
		k=i;
		while(text[i]==pattern[j])
		{
			i++,j++;
			if(j==l2)
			{
				flag=1;p=1;
				cout<<"String Found";
				break;
			}
		}
		j=0;
		
		if(flag==0)
			i=k;
		
		else
			flag=0;
		
	}
	if(p==0) cout<<"Not Found";
	return 0;
	
}
