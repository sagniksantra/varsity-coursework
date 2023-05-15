 #include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of numbers : ";
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter Value  : ";
		cin>>arr[i];
	}
	cout<<"1.Selection Sort 2.Bubble Sort ";
	int ch;
	cin>>ch;
	if(ch==1)
	{
		for(int i =0 ; i<n;i++)
		{
			int min = arr[i],minpos =i;
			for(int j=i+1;j<n;j++)
			{
				if(min>arr[j])
				{
					min = arr[j];
					minpos = j;
				}
			}
			int temp = arr[i];
			arr[i] = arr[minpos];
			arr[minpos] = temp;
			
		}
	}
	else if(ch==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	cout<<"ARRAY IS : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
