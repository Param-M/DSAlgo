#include <bits/stdc++.h>
using namespace std;

int countdigits(int n)
{
    int count = int(log10(n)) + 1;
    if (n == 0)
        return 1;
    n = abs(n);
    // while (n>0)
    // {
    //     n = n/10;
    //     count ++;
    //     }
    return count;
}

int reverse(int n)
{
    int no = 0;
    while (n > 0)
    {
        int ld = n % 10;
        n = n / 10;
        no = (no * 10) + ld;
    }
    return no;
}

bool palindrome(int n)
{
    int no = 0;
    int x = n;
    while (n > 0)
    {
        int ld = n % 10;
        n = n / 10;
        no = (no * 10) + ld;
    }
    return (no == x);
}

bool armstrong(int n)
{
    int x = n;
    int sum = 0;
    while (n > 0)
    {
        int ld = n % 10;
        n = n / 10;
        sum = sum + ld * ld * ld;
    }
    return (sum == x);
}

void divisors(int n)
{
    vector<int> v;
    // for(int i=1;i<n;i++){
    //     if(n%i == 0)
    //     cout << i << "\n";
    // }
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);

            if (n / i != i)
                v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    for (auto it : v)
        cout << it << endl;
}

int prime(int n)
{
    // no has exactly 2 factors 1 and itself
    int count = 0;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if (n / i != i)
                count++;
        }
    }
    return count;
}

int GCD(int x, int y)
{
    int gcd;
    //     for (int i = 1; i<min(x,y); i++)
    //     {
    //         if(x%i==0 && y%i==0){
    //             gcd = i;
    //         }
    //     }
    //    return gcd;

    for (int i = min(x, y); i >= 1; i--)
    {
        if (x % i == 0 && y % i == 0)
        {
            gcd = i;
            break;
        }
    }
    return gcd;
}

int euclidean(int x, int y)
{
    // gcd (x,y) = gcd (x-y, y)
    // gcd (x,y) = gcd (x%y, y)
    while (x > 0 && y > 0)
    {
        if (x > y)
            x = x % y;
        else
            y = y % x;
    }
    if (x == 0)
        return y;
    else
        return x;
}

int main()
{
    int t;
    cout << "No of test cases: ";
    cin >> t;
    while (t > 0)
    {
        int n, m;
        cout << "Enter the value: ";
        cin >> n >> m;
        // change cout accordingly
        cout << GCD(n, m);
        t--;
    }
}