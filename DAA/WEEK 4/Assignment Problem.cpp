#include <iostream>
using namespace std;

int N; 
int cost[10][10]; 
int permutation[10]; 
int bestCost = 2147483647; 
int bestPermutation[10]; 


void generatePermutations(int depth) //0,1
{
    if (depth == N) //0==4,1==4,2==4
	{
        int currentCost = 0;
        for (int i = 0; i < N; i++) 
		{
            currentCost += cost[i][permutation[i]];
            cout<<permutation[i]<<" ";
        }
        cout<<endl;
        if (currentCost < bestCost) 
		{
            bestCost = currentCost;
            for (int i = 0; i < N; i++) 
                bestPermutation[i] = permutation[i];
            
        }
    }
	else 
	{
        for (int i = 0; i < N; i++) //0<4,0<4,0<4,
		{
            bool used = false;
            for (int j = 0; j < depth; j++) //0<0,	0<1,1<1,	0<2,1<2,2<2
			{
                if (permutation[j] == i) 
				{
                    used = true;
                    break;
                }
            }
            if (!used) 
			{
                permutation[depth] = i;//0,1,2,3
                generatePermutations(depth + 1);//1,2,3
            }
        }
    }
}

int main()
 {
	cout<<"Enter the size of square matrix ";
    cin >> N;//4
    for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < N; j++) 
		{
        	cout<<"Enter the cost of each ";
            cin >> cost[i][j];
        }
    }
    generatePermutations(0);
    
    cout << "Best cost: " << bestCost << endl;
    cout << "Best permutation: ";
    
    for (int i = 0; i < N; i++) 
        cout << bestPermutation[i] << " ";
    
    cout << endl;
    return 0;
}
