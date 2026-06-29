```python
markdown_content = """# Strivers A2Z DSA Course: Basic Mathematics for DSA

This comprehensive guide covers the fundamental mathematical concepts required for Data Structures and Algorithms (DSA), based on the Strivers A2Z DSA Course. Mastering these concepts provides the foundation for solving complex algorithmic problems, particularly those involving number theory, digit manipulation, and optimal time complexity analysis.

---

## 1. The Digit Extraction Concept

Digit extraction is a fundamental building block for many basic math problems. It allows you to break down an integer into its individual digits from right to left (reverse order).

### Mathematical Principles
1. **Modulo Operator (`% 10`):** Any integer divided by 10 leaves a remainder equal to its last digit. For example, $7789 \\pmod{10} = 9$.
2. **Integer Division (`/ 10`):** Dividing an integer by 10 removes the last digit by shifting the decimal point to the left and truncating the fractional part. For example, $\\lfloor 7789 / 10 \\rfloor = 778$.

### Extraction Process Flow
By repeating the modulo and division operations in a loop until the number becomes zero, you can extract every digit:
* $7789 \\pmod{10} = 9 \\longrightarrow \\lfloor 7789 / 10 \\rfloor = 778$
* $778 \\pmod{10} = 8 \\longrightarrow \\lfloor 778 / 10 \\rfloor = 77$
* $77 \\pmod{10} = 7 \\longrightarrow \\lfloor 77 / 10 \\rfloor = 7$
* $7 \\pmod{10} = 7 \\longrightarrow \\lfloor 7 / 10 \\rfloor = 0$ (Extraction Complete)

### Pseudocode Template

```

```text
Markdown file successfully created.

```text
while (n > 0) {
    lastDigit = n % 10;
    // Process or store lastDigit here
    n = n / 10;
}

```

---

## 2. Problem 1: Count Digits

Given an integer $N$, count and return the total number of digits present in it.

### Approach 1: Iterative Digit Extraction (Brute Force)

We can use a counter variable inside a digit extraction loop. The number of times the loop executes before $N$ reaches $0$ corresponds to the total digit count.

* **C++ Code:**

```cpp
int countDigits(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n = n / 10;
    }
    return cnt;
}

```

* **Time Complexity:** $O(\log_{10} N)$ — Because the number is divided by 10 in each iteration.
* **Space Complexity:** $O(1)$ — Only a single counter variable is used.

### Approach 2: Logarithmic Formula (Optimal)

Mathematically, the number of digits in a base-10 number $N$ is given by the formula:


$$\text{Digits} = \lfloor \log_{10} N \rfloor + 1$$

* **C++ Code:**

```cpp
#include <cmath>
int countDigitsOptimal(int n) {
    if (n == 0) return 1;
    return (int)(log10(n) + 1);
}

```

* **Time Complexity:** $O(1)$ — Assuming the math library computes logarithms in constant time.
* **Space Complexity:** $O(1)$

> **Time Complexity Note on Division:** Whenever a loop variable is divided by a constant factor $K$ at each step, the total number of iterations follows a logarithmic scale: $O(\log_K N)$.
> * Division by 2 $\rightarrow O(\log_2 N)$
> * Division by 5 $\rightarrow O(\log_5 N)$
> * Division by 10 $\rightarrow O(\log_{10} N)$
> 
> 

---

## 3. Problem 2: Reverse a Number

Given an integer $N$, return its digits reversed. If the number has trailing zeros, they should be omitted in the final reversed integer (e.g., $10400 \rightarrow 401$).

### Algorithmic Strategy

To construct the reversed number dynamically during digit extraction, initialize a `revNum = 0`. At each step, multiply the existing `revNum` by 10 to shift its place values to the left, and add the newly extracted `lastDigit`.

$$\text{revNum} = (\text{revNum} \times 10) + \text{lastDigit}$$

### Step-by-Step Execution ($N = 7789$)

1. Extract $9$: $\text{revNum} = (0 \times 10) + 9 = 9$
2. Extract $8$: $\text{revNum} = (9 \times 10) + 8 = 98$
3. Extract $7$: $\text{revNum} = (98 \times 10) + 7 = 987$
4. Extract $7$: $\text{revNum} = (987 \times 10) + 7 = 9877$

### C++ Implementation

```cpp
int reverseNumber(int n) {
    int revNum = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n / 10;
    }
    return revNum;
}

```

* **Time Complexity:** $O(\log_{10} N)$
* **Space Complexity:** $O(1)$

---

## 4. Problem 3: Check Palindrome

A palindrome number is an integer that reads the same backward as forward (e.g., $121$, $1331$).

### Key Trap: Destruction of Original Input

During digit extraction or reversal, the value of the loop variable $N$ is continually divided until it reaches $0$. Therefore, you cannot simply check `if (n == revNum)` at the end of your logic because $N$ will always be $0$.

### Solution

Store a copy or a duplicate of the original number in a separate variable (`duplicate = n`) before starting the loop, then compare the duplicate with the final reversed number.

### C++ Implementation

```cpp
bool isPalindrome(int n) {
    int duplicate = n;
    int revNum = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n / 10;
    }
    return (duplicate == revNum);
}

```

* **Time Complexity:** $O(\log_{10} N)$
* **Space Complexity:** $O(1)$

---

## 5. Problem 4: Armstrong Numbers

An Armstrong number (also known as a narcissistic number) is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
*(Note: The video explicitly demonstrates it using cubes of digits for 3-digit numbers like $371$, where $3^3 + 7^3 + 1^3 = 371$.)*

### Approach

Extract each digit using the modulo operator, compute its cube ($d \times d \times d$), and add it to a running summation variable. Finally, use a duplicate variable to compare the original input with the calculated sum.

### C++ Implementation

```cpp
bool isArmstrong(int n) {
    int duplicate = n;
    int sum = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        sum += (lastDigit * lastDigit * lastDigit);
        n = n / 10;
    }
    return (sum == duplicate);
}

```

* **Time Complexity:** $O(\log_{10} N)$
* **Space Complexity:** $O(1)$

---

## 6. Problem 5: Print All Divisors

A divisor (or factor) is a number that divides an integer completely without leaving a remainder ($N \pmod{I} == 0$).

### Approach 1: Brute Force Linear Scan

Iterate through every integer from $1$ up to $N$ and print the numbers that leave a remainder of $0$.

* **Time Complexity:** $O(N)$

### Approach 2: Optimized Square Root $\sqrt{N}$ Scan

Factors always occur in pairs. If $I$ is a factor of $N$, then there is a matching factor equal to $N / I$.
For example, the factor pairs of $36$ are:

* $(1, 36), (2, 18), (3, 12), (4, 9), (6, 6)$

Notice that beyond $\sqrt{36} = 6$, the pairs simply repeat in reverse order ($(9, 4), (12, 3), \dots$). Therefore, we only need to scan numbers up to $\sqrt{N}$.

#### Mathematical Optimization

Instead of calling the computationally heavy `sqrt(n)` function inside the loop condition at each iteration, use the condition:

```cpp
for (int i = 1; i * i <= n; i++)

```

#### Handling Edge Cases

When $I \times I = N$ (such as $6 \times 6 = 36$), the factor $I$ and its pair $N / I$ are identical. To avoid duplicates, check `if (n / i != i)` before including the secondary factor.

#### C++ Implementation (Sorting and Printing)

Because factors extracted this way are not in sorted sequence (e.g., extracting $1, 36, 2, 18 \dots$), we store them in a dynamic array (`std::vector`), sort them, and then output them.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void printDivisors(int n) {
    std::vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if ((n / i) != i) {
                divisors.push_back(n / i);
            }
        }
    }
    // Sort to print in ascending order
    std::sort(divisors.begin(), divisors.end());
    
    for (int val : divisors) {
        std::cout << val << " ";
    }
}

```

* **Time Complexity:** $O(\sqrt{N}) + O(K \log K)$, where $K$ is the number of factors found.
* **Space Complexity:** $O(K)$ to store the factors in a list.

---

## 7. Problem 6: Check for Prime

A prime number is an integer greater than 1 that has **exactly two distinct factors**: $1$ and itself.

### Optimized $\sqrt{N}$ Approach

Instead of checking factors up to $N$ ($O(N)$), apply the square root property. If a number has no factors up to $\sqrt{N}$, it cannot have factors greater than $\sqrt{N}$, and is therefore prime.

### C++ Implementation

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    int counter = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            counter++;
            if ((n / i) != i) {
                counter++;
            }
        }
    }
    return (counter == 2);
}

```

* **Time Complexity:** $O(\sqrt{N})$
* **Space Complexity:** $O(1)$

---

## 8. Problem 7: Greatest Common Divisor (GCD) / Highest Common Factor (HCF)

The GCD of two numbers is the largest integer that completely divides both numbers.

### Approach 1: Linear Scan from Behind (Brute Force)

Start scanning backward from $\min(N_1, N_2)$ down to $1$. The first number that divides both inputs is the greatest common divisor.

* **Worst-Case Time Complexity:** $O(\min(N_1, N_2))$ — Happens when the GCD is $1$ (co-prime numbers like 11 and 13).

### Approach 2: Optimal Euclidean Algorithm

The Euclidean Algorithm is based on the principle that the greatest common divisor of two numbers does not change if the larger number is replaced by its difference with the smaller number:


$$\text{gcd}(a, b) = \text{gcd}(a - b, b) \quad \text{(where } a > b\text{)}$$

#### Modulo Optimization

Repeated subtraction can be unacceptably slow when one number is significantly larger than the other (e.g., $a = 52, b = 10$). Subtraction takes multiple steps ($52 \rightarrow 42 \rightarrow 32 \rightarrow 22 \rightarrow 12 \rightarrow 2$).
We can bypass this linear reduction directly by using the **modulo operator**:


$$\text{gcd}(a, b) = \text{gcd}(a \pmod b, b) \quad \text{(where } a > b\text{)}$$

Repeat this process until one of the parameters hits $0$. The non-zero parameter left over is the calculated GCD.

### C++ Implementation

```cpp
int findGCD(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a == 0) return b;
    return a;
}

```

### Complexity Metrics

* **Time Complexity:** $O(\log_{\phi}(\min(a, b)))$
* The time complexity is logarithmic because the modulo operation cuts down the value of variables drastically at each step.
* $\phi$ represents the golden ratio, which rules the worst-case behavior of the Euclidean algorithm (occurring when finding the GCD of consecutive Fibonacci numbers).


* **Space Complexity:** $O(1)$
"""

```