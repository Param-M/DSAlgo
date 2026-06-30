#include <bits/stdc++.h>
using namespace std;

/* we select the minimum value and place then over the first index 
swap with smallest with the first index
then leave the first index and repeat same process to the remaining array
*/
void selectionsort(int arr[], int n)
{
    for (int i = 0; i <= n-2; i++)
    {
        int mini  = i;
        for (int j = i; j <= n-1; j++)
        {
            if(arr[j]<arr[mini]) mini = j;     
        }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr [i] = temp;
    }
}

void SelectionR(int i , int arr[], int n){
    if(i == n-1) return;
int min = i;
    for(int j =i+1 ; j<n ; j++){
        if(arr[j]<arr[min]) min = j;
    }
    int temp = arr[min];
    arr[min] = arr[i];
    arr [i] = temp;

    SelectionR(i+1, arr , n);
}

void BubbleSort(int arr[], int n)
{
    // push max to the last
// adjacent swap
for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
    cin >> arr[i];
    }

BubbleSort(arr,n);
for(int i= 0; i<n ;i++){
    cout << arr[i] << " ";
} 

return 0;
}