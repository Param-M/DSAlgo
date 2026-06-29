# C++ Basics

This note collects the core C++ ideas you need before moving into DSA: program structure, input and output, data types, operators, control flow, loops, arrays, strings, functions, and a first look at complexity.

## 1. Program Skeleton

Every standard C++ program starts from the same basic shape.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Single-line comment
    /*
        Multi-line comment
        Write your logic here.
    */
    return 0;
}
```

### Headers and Namespace

- `#include <bits/stdc++.h>` is a GCC extension that includes most standard headers at once. It is common in competitive programming, but it is not standard C++.
- Common individual headers include:
  - `<iostream>` for input and output
  - `<vector>` for dynamic arrays
  - `<algorithm>` for helpers such as `sort`, `reverse`, and `binary_search`
- `using namespace std;` lets you write `cout` and `cin` directly instead of prefixing everything with `std::`.

## 2. Input and Output

C++ uses streams to move data into and out of a program.

- `cout <<` sends data to the console.
- `cin >>` reads data from the console into variables.

### Formatting

- `\n` moves to the next line.
- `endl` also moves to the next line, but it flushes the stream, so it is usually slower than `\n`.
- `\t` inserts a tab space.

### Reading Whole Lines

`cin >> str` stops at the first space. Use `getline` when you want a full line.

```cpp
string fullName;
getline(cin, fullName);
```

## 3. Data Types

| Data Type | Size | Typical Use |
| --- | --- | --- |
| `char` | 1 byte | Single characters such as `a` or `#` |
| `int` | 4 bytes | Counting and general-purpose integers |
| `long int` | 4 or 8 bytes | Larger integers, depending on platform |
| `long long` | 8 bytes | Very large integers in DSA problems |
| `float` | 4 bytes | Small decimal values |
| `double` | 8 bytes | More precise decimal values |
| `bool` | 1 byte | True or false values |

### Notes on Range

- `int` is commonly used for values up to about $2 \times 10^9$.
- `long long` is safer when values can exceed $10^9$.
- `double` is usually preferred over `float` when precision matters.

## 4. Operators

### Arithmetic Operators

- `+`, `-`, `*`, `/` for standard arithmetic
- `%` for remainder after integer division

Example:

```cpp
int r = 7 % 3; // 1
```

### Relational Operators

These compare values and return `true` or `false`.

- `<`, `>`, `<=`, `>=`
- `==`, `!=`

### Logical Operators

- `&&` means logical AND
- `||` means logical OR
- `!` means logical NOT

### Assignment Operators

- `=` assigns a value
- `+=`, `-=`, `*=`, `/=`, `%=` update a variable in place

### Increment and Decrement

- Pre-increment and pre-decrement change the value first: `++x`, `--x`
- Post-increment and post-decrement use the value first, then change it: `x++`, `x--`

### Bitwise Operators

- `&`, `|`, `^`, `~` work on bits directly
- `<<` shifts bits left and usually multiplies by 2
- `>>` shifts bits right and usually divides by 2

### Ternary Operator

Use the ternary operator for short conditional expressions.

```cpp
int maxVal = (a > b) ? a : b;
```

## 5. Control Flow

### If, Else If, and Else

```cpp
if (age >= 18) {
    cout << "Adult";
} else {
    cout << "Minor";
}

if (marks >= 90) {
    cout << "Grade A";
} else if (marks >= 75) {
    cout << "Grade B";
} else {
    cout << "Grade C";
}

if (hasPassport) {
    if (hasVisa) {
        cout << "Allowed to travel";
    } else {
        cout << "Visa missing";
    }
}
```

### Switch Case

Use `switch` when one variable is compared against fixed values.

```cpp
switch (dayNum) {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    default:
        cout << "Invalid day number";
}
```

## 6. Loops

Loops repeat a block of code while a condition remains true.

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}

int i = 0;
while (i < 5) {
    cout << i << " ";
    i++;
}

int j = 0;
do {
    cout << j << " ";
    j++;
} while (j < 5);
```

### When to Use Each Loop

- `for` is best when you know the number of iterations in advance.
- `while` is best when the condition depends on changing input or state.
- `do-while` always runs at least once.

## 7. Arrays and Strings

Arrays and strings are both zero-indexed.

### Arrays

Arrays store multiple values of the same type in contiguous memory.

```cpp
int arr[5] = {10, 20, 30, 40, 50};
cout << arr[0];

int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
cout << matrix[1][2];
```

### Strings

In C++, `string` is a class that stores a dynamic sequence of characters.

```cpp
string str = "Striver";
cout << str[0];

cout << str.length();
str.push_back('s');
str.pop_back();

string firstName = "Raj";
string lastName = "Vikramaditya";
string fullName = firstName + " " + lastName;

string sub = str.substr(0, 4);
```

## 8. Functions

Functions break a program into reusable blocks of logic.

```cpp
void greet() {
    cout << "Hello World!" << endl;
}

void printSum(int a, int b) {
    cout << (a + b) << endl;
}

int multiply(int a, int b) {
    return a * b;
}
```

### Pass by Value and Pass by Reference

- Pass by value sends a copy of the variable, so the original value does not change.
- Pass by reference sends the original variable, so changes inside the function affect the caller.

```cpp
void modifyValue(int num) {
    num = 100;
}

void modifyReference(int &num) {
    num = 100;
}
```

## 9. Time and Space Complexity

Writing correct code is only part of DSA. The next step is writing code that is efficient enough for the input limits.

### Time Complexity

Time complexity describes how the running time grows as input size grows.

Common growth rates, from faster to slower, are:

| Notation | Name | Example |
| --- | --- | --- |
| $O(1)$ | Constant | Accessing an array element by index |
| $O(\log N)$ | Logarithmic | Binary search |
| $O(N)$ | Linear | One full loop over the input |
| $O(N \log N)$ | Linearithmic | Merge sort, quick sort on average |
| $O(N^2)$ | Quadratic | Nested loops, bubble sort |
| $O(2^N)$ | Exponential | Brute-force recursion |

### Space Complexity

Space complexity measures how much extra memory an algorithm uses.

- Auxiliary space is the extra memory used during execution.
- Input space is the memory required to store the input itself.
- In interviews, space complexity usually refers to auxiliary space.

If a solution uses no extra data structure, its extra space is often $O(1)$.

### Rule of Thumb

For many competitive programming platforms, a rough guide is that a modern machine can handle around $10^8$ operations per second.

- $O(N^2)$ becomes too slow when $N$ is large, such as $10^5$.
- For bigger inputs, prefer $O(N)$ or $O(N \log N)$ when possible.

## 10. Quick Summary

- Start every program from a clear `main` function.
- Use the right input method for the task, especially `getline` for full lines.
- Choose data types carefully, especially when values may exceed `int`.
- Prefer readable control flow and the right loop for the job.
- Use references when you want a function to modify the original value.
- Always think about time and space complexity early, not after the code is finished.
