// when a function calls itself
// until a specific condition is met
// patterns in recursion (take/not-take) acche se padh lena
//recursion trees are in the form of inorder traversal

#include <bits/stdc++.h>
using namespace std;
int my_count = 1;

void recursion(int &n)
{
    if (n == 3)
    {
        return;
    }
    else
    {
        cout << n << endl;
    }
    n++;
    recursion(n);
}
// stored in a form of stack
void P1(int n, string s)
{
    cout << s << endl;
    my_count++;
    if (my_count <= n)
        P1(n, s);
    // if condition is the base case
    else
        return;
}

void P1a(int i, int x)
{
    if (i > x)
        return;
    printf("Param \n");
    P1a(i + 1, x);
}

void P2(int i, int x)
{
    if (i > x)
        return;
    cout << i;
    P2(i + 1, x);
}

void P2reverse(int i, int x)
{
    if (i < 1)
        return;
    cout << i;
    P2reverse(i - 1, x);
}

// bt == backtracking

void P2bt(int i, int x)
{
    if (i < 1)
        return;
    P2bt(i - 1, x);
    cout << i;
}

void P2revbt(int i, int x)
{
    if (i > x)
        return;
    P2revbt(i + 1, x);
    cout << i;
}

void sump(int n, int s)
{
    if (n < 1)
    {
        cout << s;
        return;
    }
    sump(n - 1, s + n);
}

int sumf(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sumf(n - 1);
}

int factf(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factf(n - 1);
}

void factp(int n, int f)
{
    if (n < 1)
    {
        cout << f;
        return;
    }
    factp(n - 1, f * n);
}

// reverse an array using 2 pointers by swapping the i=a[0] and j=a[n-1] and decrement it and break when index i=j
//  by using for loop
void revarray(int a[], int l, int r)
{
    if (l >= r)
        return;
    swap(a[l], a[r]);
    revarray(a, l + 1, r - 1);
}

void singlearr(int a[], int l, int r)
{
    if (l >= r / 2)
        return;
    swap(a[l], a[r - l - 1]);
    singlearr(a, l + 1, r);
}

bool palindrome(string s, int i)
{
    int n = s.size();
    if (i >= n / 2)
        return true;
    if (s[i] != s[n - i - 1])
    {
        return false;
    }
    else
        return palindrome(s, i + 1);
}

// multiple recursion calls
/*
f[0] = 0 f[1]=1
for(i -> 2, i++)
f[i] = f[i-1] + f[i-2]
*/
int fibonacci(int i)
{
    if (i <= 1)
        return i;
    else
        return fibonacci(i - 1) + fibonacci(i - 2);
}

// recursion tree is imp
/*
subsequence = a contagious/non-contagious  (spreading in order) which follows the order
arr = 3,1,2
3;1;2;31;12;32;312 but 12 and 32 non contagious as they are not in order as well as subsequence
can be done using powerset

example trailroom of mall
*/

int subsequence(int s, vector<int> &v, int a[], int n)
{
    if (s >= n)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return 0;
    }
    // take or put in the particular index
    v.push_back(a[s]);
    subsequence(s + 1, v, a, n);
    v.pop_back();
    // not pick or not take condition
    subsequence(s + 1, v, a, n);
}

// patterns in recursion
void subsumk(int ind, vector<int> &v,int s, int sum, int a[], int n)
{// whenever carrying the datastructure match the sum of it with the required sum and then print it

      if (ind == n)
        {if(s==sum){
            for(auto it: v){
                cout << it << " ";    
            }
            cout << endl;
        }
        return;
    }
    // take or put in the particular index
    v.push_back(a[ind]);
        s+=a[ind];

        subsumk(ind + 1, v, s, sum, a, n);

    s-= a[ind];

    v.pop_back();
    // not pick or not take condition
    subsumk(ind + 1, v, s, sum , a, n);
}

//not all should be given;
//give any one 

int main()
{
    // pass the arguments and create variables according to the question
    // understand what task is to be done and how recursion will be passed
    int x;
    cin >> x;
    int arr[x];
    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }
    int sum =2;
    vector<int> v;
    subsumk(0, v, 0, sum, arr, x);

    return 0;
}

// sump sumf are kind of patterns