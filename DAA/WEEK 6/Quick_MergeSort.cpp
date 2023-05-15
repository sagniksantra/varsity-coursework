#include <iostream>
using namespace std;
int N,x[1000];
void merge(int array[], int left, int mid,int right)
{
    int a1 = mid - left + 1;
    int a2 = right - mid;
 
    // Create temp arrays
    int *leftArray = new int[a1] , *rightArray = new int[a2];
 
    for (int i = 0; i < a1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < a2; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int pos_a1= 0, pos_a2= 0; 
    int merged = left;
 
    // Merge the temp arrays back into array[left..right]
    while (pos_a1 < a1 && pos_a2 < a2) 
	{
        if (leftArray[pos_a1] <= rightArray[pos_a2]) 
		{
            array[merged] = leftArray[pos_a1];
            pos_a1++;
        }
        else 
		{
            array[merged] = rightArray[pos_a2];
            pos_a2++;
        }
        merged++;
    }
    while (pos_a1 < a1) 
	{
        array[merged] = leftArray[pos_a1];
        pos_a1++;
        merged++;
    }
    while (pos_a2 < a2) 
	{
        array[merged] = rightArray[pos_a2];
        pos_a2++;
        merged++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int a[], int begin, int end)
{
    if (begin >= end)
        return; 
 	
	int mid = begin + (end - begin) / 2;
    mergeSort(a, begin, mid);
    mergeSort(a, mid + 1, end);
    merge(a, begin, mid, end);
}
int partition(int a[],int low,int high)
{
	int key = a[low];
	int i = low+1,j=high;
	while(i<high && key>=a[i])
		i++;
	while(key<a[j]) 
		j--;
	if(i<j)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	else
	{
		int temp = a[low];
		a[low] = a[j];
		a[j] = temp;
	}
	return j;
}
void quick_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid = partition(a,low,high);
		quick_sort(a,low,mid-1);
		quick_sort(a,mid+1,high);
	}
	for(int i=0;i<N;i++)
	{
		x[i] = a[i];
	}
}
int main()
{
	int n;
	cout<<"Enter Array Length : ";
	cin>>n;
	N=n;
	int arr[n];
    cout<<"Input array of N elements : "<<endl;
	for(int i=0;i<N;i++)
	{
		cout<<"Input element"<<i+1<<endl;
		cin>>arr[i];
	}
	int ch;
	cout<<"1.QUICK SORT 2.MERGE SORT\nENTER CHOICE : ";
	cin>>ch;
	if(ch==1)
    	quick_sort(arr,0,N-1);
    else if(ch==2)
		mergeSort(arr,0,N-1);    
		
    cout << "Sorted array is \n";
    for (int i = 0; i < N; ++i)
    {
    	if(ch==1)
			arr[i] = x[i];
        cout << arr[i] << " ";
    }
}

