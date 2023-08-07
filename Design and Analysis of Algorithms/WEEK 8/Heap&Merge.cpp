#include <iostream>
using namespace std;
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) 
	{
        //swap(arr[i], arr[largest]);
        int t = arr[i]; 
		arr[i] = arr[largest]; 
		arr[largest] = t;
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)//6 8 1 2 9 , 5
{
    for (int i = N / 2 - 1; i >= 0; i--)//i=1  
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) //i= 4
	{
        //swap(arr[0], arr[i]);
        int t = arr[0]; 
		arr[0] = arr[i]; 
		arr[i] = t;
        heapify(arr, i, 0);
    }
}
int deleted(int arr[], int N)//2 6 7 8 9 
{
	cout<<"\nSmallest Element (Root Node after HeapSort) : "<<arr[0];
	int t = arr[0]; 
	arr[0] = arr[N-1]; 
	arr[N-1] = t;
	N--;
	heapSort(arr,N);
        
	return N;
}
int main()
{
	int arr[5];
    cout<<"Input array of 5 elements : "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Input element"<<i+1<<endl;
		cin>>arr[i];
	}
	int ch;
	cout<<"1.HEAPSORT \nENTER CHOICE : ";
	cin>>ch;
	//6 8 1 2 9
	if(ch==1)
    	heapSort(arr, 5);//
		
    cout << "Sorted array is \n";
    for (int i = 0; i <5; ++i)
        cout << arr[i] << " ";
    int N = deleted(arr,5);
    cout << "\nSorted array after deletion of smallest element is \n";
    for (int i = 0; i <N; ++i)
        cout << arr[i] <<" ";
    
}
