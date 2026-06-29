#include <bits/stdc++.h>
using namespace std;

void P1(int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        for (int j = 0; j < n; j = j + 1)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void P2(int n)
{
    for (int i = 0; i <= n; i = i + 1)
    {
        for (int j = 0; j < i; j = j + 1)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void P3(int n)
{
    for (int i = 1; i <= n; i = i + 1)
    {
        for (int j = 1; j <= i; j = j + 1)
        {
            cout << j;
        }
        cout << "\n";
    }
}
void P4(int n)
{
    for (int i = 1; i <= n; i = i + 1)
    {
        for (int j = 1; j <= i; j = j + 1)
        {
            cout << i;
        }
        cout << "\n";
    }
}
void P5(int n)
{
    for (int i = 1; i <= n; i = i + 1)
    {
        for (int j = 1; j <= n + 1 - i; j = j + 1)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void P6(int n)
{
    for (int i = 1; i <= n; i = i + 1)
    {
        for (int j = 1; j <= n + 1 - i; j = j + 1)
        {
            cout << j;
        }
        cout << "\n";
    }
}
void P7(int n)
{
    for (int i = 1; i <= n; i = i + 1)
    {
        // space
        for (int j = 1; j <= n - i; j = j + 1)
        {
            cout << " ";
        }
        // value
        for (int j = 1; j <= (2 * i - 1); j = j + 1)
        {
            cout << "*";
        }
        // space
        for (int j = 1; j <= n - i; j = j + 1)
        {
            cout << " ";
        }
        cout << "\n";
    }
}
// void P8(int n){
//  for(int i=n; i>=1; i=i-1){
//     //space
//     for(int j=1; j<=n-i; j=j+1){
//         cout << " ";
//     }
//     // value
//     for(int j=1; j<=(2*i-1); j=j+1){
//         cout << "*";
//     }
//     //space
//     for(int j=1; j<=n-i; j=j+1){
//         cout << " ";
//     }
//     cout << "\n";
//  }
// }
void P8(int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        // space
        for (int j = 0; j < i; j = j + 1)
        {
            cout << " ";
        }
        // value
        for (int j = 0; j < (2 * n - (2 * i + 1)); j = j + 1)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < i; j = j + 1)
        {
            cout << " ";
        }
        cout << "\n";
    }
}
void P9(int n)
{

    for (int i = 1; i <= 2 * n - 1; i = i + 1)
    {
        int x = 1;
        if (i > n)
            x = {2 * n - i};
        else
            x = i;
        for (int j = 1; j <= x; j = j + 1)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void P10(int n)
{
    int x = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
            x = 1;
        else
            x = 0;

        for (int j = 0; j <= i; j = j + 1)
        {
            cout << x;
            x = 1 - x;
        }
        cout << "\n";
    }
}
void P11(int n)
{
    int y = 2 * (n - 1);
    for (int i = 1; i <= n; i = i + 1)
    {
        // number
        for (int j = 1; j <= i; j = j + 1)
        {
            cout << j;
        }
        // space
        for (int j = 1; j <= y; j++)
        {
            cout << " ";
        }

        // number
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << "\n";
        y -= 2;
    }
}
void P12(int n)
{
    int a = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << a << " ";
            a++;
        }
        cout << "\n";
    }
}
void P13(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch;
        }
        cout << "\n";
    }
}
void P14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
        {
            cout << ch;
        }
        cout << "\n";
    }
}
void P15(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j = j + 1)
        {
            cout << ch;
        }
        cout << "\n";
    }
}
void P16(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // letter
        char ch = 'A';
        int x = (2 * i + 1) / 2;
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch;
            if (j < x)
            {
                ch++;
            }
            else
                ch--;
        }
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << "\n";
    }
}
void P17(int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch;
        }
        cout << "\n";
    }
}
void P18(int n)
{
    int space = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        space += 2;
        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        space -= 2;
        cout << "\n";
    }
}
void P19(int n)
{
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i = i + 1)
    {
        int stars = i;
        if (i > n)
        {
            stars = 2 * n - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << "\n";
        if (i < n)
        {
            spaces -= 2;
        }
        else
        {
            spaces += 2;
        }
    }
}
int main()
{
    int t;
    cout << "Enter the number of rows: ";
    cin >> t;
    // call whichever patterns you want to see
    P19(t);
    return 0;
}