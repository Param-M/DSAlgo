//Hashing is prestoring and fetching when required

#include <bits/stdc++.h>
using namespace std;

//appproach 1

// int counter(int arr[], int n, int x)
// {
//     int count = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == x)
//         {
//             count++;
//             return i;
//         }
//     }

    
// }

//character hashing
// done using ASCII coding 
// hash from 0 to 25 and correspond a ==0 and z ==25
// int x = 'a' == 97
// finding anycharacter then we do 'character' - 'a'
// similarly can be done for all ASCII value i.e from 0 to 255  


//number hashing (STL/collection) can also be used in           
// map and unordered map
// map == key and value it's unique and sorted
// map<int, int>mpp iteration is done using auto
// map <char,int> char is  used as key because that what we want to store 
// log(n)


//unordered map it's not unique and not sorted
// O(1) and worst case is O(n)
// mostly use this
//worst case because of internal collision hashing is done
// vector pair etc cannot be used as key

// division, folding, mid square methods for creating hashmaps
// arr[i]%10 and if the number appear more than 1 than LL is used
int main()
{
    int n;
    cin >> n ;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }
    
    int query;
    cin >> query;
    while(query--){
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }
    return 0;
}

//max size int array inside main arr[10^6] segmentation fault (bool 10^7)
// globally arr[10^7] (bool 10^8)