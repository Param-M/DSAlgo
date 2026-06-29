# Comprehensive Guide to Recursion: From Basics to Multiple Recursion Calls
## Strivers A2Z DSA Course Companion Notes

---

## 1. Introduction to Recursion & Core Principles

### What is Recursion?
Recursion is a programming technique where a function **calls itself** directly or indirectly to solve a problem by breaking it down into smaller, manageable sub-problems. 


```

```

Function F() {
// Some code...
F(); // Self-call (Recursion)
}

```

### The Base Condition
If a function continuously calls itself without any boundary, it will execute indefinitely, leading to an infinite loop of function invocations. To prevent this, every recursive function must contain a specified stopping condition known as the **Base Condition**. Once this condition is met, the function stops calling itself and begins returning control back to its previous callers.


```

Function F() {
If (specified condition is met) {
Return; // Stoppage / Termination
}
// Code...
F();
}

```

### Memory Architecture: The Stack Space & Stack Overflow
When a program executes a function call, the computer allocates a block of temporary memory within a structure called the **Activation Stack** (or Stack Space). This memory block keeps track of the function's parameters, local variables, and the execution line number where it must return after completion.

In recursion, if a function `F` calls itself, the initial invocation is **not yet completed**. Therefore, it remains waiting in the stack while a fresh copy of the function is pushed onto the top of the stack.

#### Stack Overflow (Segmentation Fault)
If an infinite recursion occurs due to a missing or faulty base case, the computer keeps piling up unfinished function calls inside the stack memory. Since stack space has a strictly limited capacity, it eventually runs out of memory. This triggers a crash known as **Stack Overflow** (commonly presenting as a *Segmentation Fault* in systems like C++).

---

## 2. Basic Recursion Problems & Parameter Alterations

To track states across recursive call frames without relying on restricted global variables, values are directly adjusted and forwarded through function arguments (parameters).

### Problem 1: Print Name $N$ Times
* **Goal**: Output a string exactly $N$ times using recursion.
* **Algorithmic Rule**: Start a counter pointer `i` at $1$. Increment `i` by $1$ at each recursive frame until `i` exceeds $N$.

#### Pseudocode (C++ / Java Agnostic):
```cpp
void printName(int i, int n) {
    // Base Case
    if (i > n) return;
    
    print("Raj");
    
    // Parameter Alteration: Pass the incremented state forward
    printName(i + 1, n);
}

int main() {
    int n = 3;
    printName(1, n);
}

```

### Problem 2: Print Linearly from $1$ to $N$

* **Goal**: Output numbers sequentially from $1$ up to $N$.
* **Strategy**: Print the current state `i`, then invoke the next frame with `i + 1`.

#### Pseudocode:

```cpp
void print1ToN(int i, int n) {
    if (i > n) return;
    print(i);
    print1ToN(i + 1, n);
}

```

### Problem 3: Print Linearly from $N$ to $1$

* **Goal**: Output numbers backward starting from $N$ down to $1$.
* **Strategy**: Start the tracking argument `i` at $N$. At each subsequent step, decrement `i` by $1$ (`i - 1`) and terminate when `i < 1`.

#### Pseudocode:

```cpp
void printNTo1(int i, int n) {
    if (i < 1) return;
    print(i);
    printNTo1(i - 1, n);
}

int main() {
    int n = 3;
    printNTo1(n, n); // Called with (3, 3)
}

```

---

## 3. The Power of Backtracking in Recursion

**Backtracking** is a conceptual paradigm where a function defers its primary operational task (such as printing or accumulating values) until **after** the next recursive call frame has been initiated and fully completed. By placing the print statement after the function call, you force execution to occur in reverse order as the frames pop off the stack space.

### Problem 4: Print $1$ to $N$ using Decrement (`i - 1`)

* **Restriction**: You are explicitly forbidden from using an incrementing operator (`+1`).
* **Solution via Backtracking**: Start the recursive call frame at $N$. Continually cascade down to `i - 1` without printing. When the base case hits, the functions return, executing the print lines sequentially from the bottom-most completed frame up to the top.

#### Pseudocode:

```cpp
void print1ToN_Backtrack(int i, int n) {
    if (i < 1) return;
    
    // Cascade downward first
    print1ToN_Backtrack(i - 1, n);
    
    // Task executed on the way back up (Backtracking)
    print(i);
}

int main() {
    print1ToN_Backtrack(3, 3);
}

```

#### Step-by-Step Backtracking Execution Matrix:

1. `print1ToN_Backtrack(3, 3)` calls frame `(2, 3)` $\rightarrow$ *Line 6 (print 3) is suspended.*
2. `print1ToN_Backtrack(2, 3)` calls frame `(1, 3)` $\rightarrow$ *Line 6 (print 2) is suspended.*
3. `print1ToN_Backtrack(1, 3)` calls frame `(0, 3)` $\rightarrow$ *Line 6 (print 1) is suspended.*
4. `print1ToN_Backtrack(0, 3)` triggers `i < 1`, returning instantly.
5. Frame `(1, 3)` resumes execution, prints **`1`**, and terminates.
6. Frame `(2, 3)` resumes execution, prints **`2`**, and terminates.
7. Frame `(3, 3)` resumes execution, prints **`3`**, and terminates.

---

## 4. Parameterized vs. Functional Recursion

Recursion can be categorized into two structural patterns based on how values are calculated and transported.

### Pattern A: Parameterized Recursion

In this approach, the running answer is updated dynamically and passed **downward** into subsequent frames through a dedicated tracking parameter. The final value is typically printed or captured once the base case is triggered.

#### Example: Sum of First $N$ Numbers

```cpp
void calculateSum(int i, int currentSum) {
    if (i < 1) {
        print(currentSum); // Output the accumulated value at the end
        return;
    }
    calculateSum(i - 1, currentSum + i);
}

int main() {
    calculateSum(3, 0); // Outputs 6
}

```

### Pattern B: Functional Recursion

In functional recursion, the function does not carry an explicit accumulator parameter. Instead, it **returns a value** back to its previous caller. The problem is broken down into a mathematical formula mapping a full state to a sub-state:


$$\text{Solve}(N) = N + \text{Solve}(N-1)$$

#### Example 1: Sum of First $N$ Numbers (Functional)

```cpp
int getSum(int n) {
    if (n == 0) return 0; // Base Case
    return n + getSum(n - 1);
}

```

#### Example 2: Factorial of $N$ ($N!$)

* **Mathematical Definition**: $N! = N \times (N-1) \times \dots \times 1$
* **Trap Reminder**: Returning `0` as the base case in multiplication will collapse the entire result to zero. The base product identity must return `1` at state `0` or `1`.

```cpp
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

```

---

## 5. Functional Array & String Manipulations

Recursive concepts apply cleanly to modifying multi-element sequential structures like arrays and strings.

### Problem A: Reverse an Array

Reversing an array involves swapping symmetrical elements from the edges moving toward the center.

#### Method 1: Symmetrical Two-Pointer Approach

```cpp
void reverseArrayTwoPointers(int l, int r, int arr[]) {
    if (l >= r) return;
    swap(arr[l], arr[r]);
    reverseArrayTwoPointers(l + 1, r - 1, arr);
}

```

#### Method 2: Single Parameter Mathematical Optimization

Instead of passing two separate index arguments, you can track the entire reversal swap mapping using a single variable `i`, leveraging the mathematical index inversion formula:


$$\text{Complementary Index} = N - i - 1$$

```cpp
void reverseArraySinglePointer(int i, int arr[], int n) {
    if (i >= n / 2) return; // Stop at the exact midpoint
    swap(arr[i], arr[n - i - 1]);
    reverseArraySinglePointer(i + 1, arr, n);
}

```

### Problem B: Check String Palindrome

A string is a palindrome if it reads identically forward and backward (e.g., `"madam"`).

#### Strategy:

Implement a functional check that returns `true` or `false`. Symmetrically check the indices. If a mismatch is discovered at any point, terminate early and return `false`.

```cpp
bool isPalindrome(int i, string &s) {
    int n = s.size();
    if (i >= n / 2) return true; // Symmetrically sound up to the middle
    
    if (s[i] != s[n - i - 1]) return false; // Immediate mismatch failure
    
    return isPalindrome(i + 1, s); // Delegate down to remaining indices
}

```

---

## 6. Multiple Recursive Calls: Non-Linear Branching

When a function frame initiates **two or more** separate recursive calls within its block body, the execution layout transitions from a simple linear sequence to a complex, non-linear branched structure.

### Crucial Execution Rule: Line-by-Line Serial Execution

Multiple recursive calls **never execute simultaneously**. The computer strictly completes the first recursive call statement, cascading all the way down to its respective base case and returning, before it ever moves to execute the second recursive call line underneath it.

### The Prototype Example: Fibonacci Numbers

The Fibonacci sequence is defined as: $0, 1, 1, 2, 3, 5, 8, 13, 21, \dots$

* **Base Cases**: $\text{Fib}(0) = 0, \text{Fib}(1) = 1$
* **Recurrence Relation**: $\text{Fib}(N) = \text{Fib}(N-1) + \text{Fib}(N-2)$

#### Functional Implementation:

```cpp
int fibonacci(int n) {
    if (n <= 1) return n; // Direct mapping base values
    
    int last = fibonacci(n - 1);        // Call Line 1 (Executes entirely first)
    int secondLast = fibonacci(n - 2);  // Call Line 2 (Executes after Line 1 returns)
    
    return last + secondLast;
}

```

---

## 7. The Concept of a Recursion Tree

A **Recursion Tree** is a hierarchical node diagram that tracks and visualizes the sequential branching path of execution frames.

### Visualized Recursion Tree for `fibonacci(4)`:

```
                  f(4) [Returns 3]
                 /    \
         f(3) [Ans:2]  f(2) [Ans:1]
        /    \          /    \
     f(2)    f(1)     f(1)   f(0)
    /    \    [1]      [1]    [0]
 f(1)    f(0)
  [1]    [0]

```

### Order of Real-Time Execution:

1. `f(4)` starts $\rightarrow$ Invokes LHS `f(3)`.
2. `f(3)` starts $\rightarrow$ Invokes LHS `f(2)`.
3. `f(2)` starts $\rightarrow$ Invokes LHS `f(1)`.
4. `f(1)` hits base case, returns `1` back to `f(2)`.
5. `f(2)` transitions to its RHS call, invokes `f(0)`.
6. `f(0)` hits base case, returns `0` back to `f(2)`.
7. `f(2)` sums values (`1 + 0`), returns `1` to `f(3)`.
8. `f(3)` transitions to its RHS call, invokes `f(1)`.
9. `f(1)` hits base case, returns `1` to `f(3)`.
10. `f(3)` sums values (`1 + 1`), returns `2` to `f(4)`.
11. `f(4)` transitions to its RHS call, invokes `f(2)`.
12. `f(2)` executes its complete tree block independently, returning `1` to `f(4)`.
13. `f(4)` returns the absolute structural total: `2 + 1 = 3`.

---

## 8. Definitive Complexity & Performance Matrix

| Problem Type | Algorithmic Approach / Pattern | Time Complexity | Space Complexity (Auxiliary Stack Space) | Memory Profile Insight |
| --- | --- | --- | --- | --- |
| **Print Name / 1 to N** | Parameterized / Linear Decay | $O(N)$ | $O(N)$ | Piles $N$ unreturned execution frames. |
| **Array Reversal** | Symmetrical Single/Double Pointer | $O(N)$ | $O(N/2) \approx O(N)$ | Iterates precisely up to the midpoint threshold. |
| **Palindrome Check** | Symmetrical Functional Early Stop | $O(N)$ | $O(N/2) \approx O(N)$ | Halved stack overhead; fast termination on mismatch. |
| **Factorial / Sum** | Pure Functional Linear Accumulation | $O(N)$ | $O(N)$ | $N$ frames deep allocation footprint. |
| **Fibonacci Numbers** | Multi-Branch Non-Linear Expansion | $O(2^N)$ | $O(N)$ | **Exponential Time**: Every frame spawns 2 sub-frames. **Linear Space**: Stack maximum depth equals tree height $N$. |

---

"""
