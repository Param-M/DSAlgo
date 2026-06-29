```python
markdown_content = """# Master Guide to C++ Standard Template Library (STL)

Welcome to the definitive, in-depth reference guide for the **C++ Standard Template Library (STL)**. This guide contains everything required to write minimized, highly optimized, and robust production-ready code for data structures, algorithms, and technical interviews.

---

## 1. Introduction to C++ STL
The Standard Template Library (STL) is a powerful compilation of pre-defined algorithms, data containers, iterators, and functions minimized into a library. Instead of writing lengthy, reinvented code for common data structures (like custom dynamic arrays, linked lists, or sorting functions), STL provides generic template classes and functions that seamlessly work with any data type. 

STL is broadly categorized into four primary components:
1. **Containers**: Objects that store data (e.g., `vector`, `set`, `map`).
2. **Iterators**: Pointer-like objects used to traverse across elements in containers.
3. **Algorithms**: Built-in, high-performance functions to manipulate data (e.g., `sort`, `reverse`).
4. **Functions** (or Functors): Objects that act like functions, altering container behaviors.

---

## 2. Standard C++ Skeleton & Pre-requisites

### The Universal Boilerplate

```

```text
File 'C++_STL_Comprehensive_Guide.md' generated successfully.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}

```

### Key Components Explained:

* `#include <bits/stdc++.h>`: A specialized internal header file that includes **all** standard libraries automatically (e.g., `iostream`, `vector`, `algorithm`, `map`, `cmath`). It saves valuable time during competitive programming or coding rounds by eliminating individual declarations.
* `using namespace std;`: Defines the default scope for identifiers. If omitted, standard command inputs/outputs require explicit scoping prefixing like `std::cin` and `std::cout`.

---

## 3. Utility Container: Pairs

Part of the `<utility>` library, `pair` is a simple wrapper capable of holding two distinct objects together as a single unit. It is highly effective for returning dual values from a function or creating pairs inside arrays and graphs.

### Syntax & Basic Usage

```cpp
// Initialization
pair<int, int> p1 = {1, 3};
pair<int, string> p2 = make_pair(10, "Striver");

// Accessing Values
cout << p1.first << " " << p1.second; // Outputs: 1 3

```

### Advanced Nested Pairs

To store three or more correlated elements within a single wrapper, pairs can be seamlessly nested inside each other:

```cpp
// Storing (1, 3, 4)
pair<int, pair<int, int>> p = {1, {3, 4}};

// Accessing values
cout << p.first;         // Outputs: 1
cout << p.second.first;  // Outputs: 3
cout << p.second.second; // Outputs: 4

```

### Array of Pairs

An incredibly useful representation for structural lookup matrices or graph coordinates:

```cpp
pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
cout << arr[1].second; // Outputs: 5

```

---

## 4. Sequence Containers

### Dynamic Arrays: Vectors

A standard array is static and constant in size. A `std::vector` is a sequence container representing a dynamic array that automatically handles memory allocation and resizes itself when elements are appended or removed.

#### Initialization Variations

```cpp
vector<int> v; // Empty vector
vector<int> v1(5, 100); // Size 5, pre-filled with 100: {100, 100, 100, 100, 100}
vector<int> v2(5); // Size 5, pre-filled with 0 or garbage value depending on compiler
vector<int> v3(v1); // Creates a separate deep-copy of v1

```

#### Inserting Elements: `push_back` vs `emplace_back`

* `push_back()` inserts a copy of an object by appending it to the rear.
* `emplace_back()` constructs the object directly in place inside the vector's underlying memory slot without creating temporary copies. It is syntactically lighter and faster.

```cpp
vector<pair<int, int>> vec;
vec.push_back({1, 2});     // Requires explicit braces to form a pair
vec.emplace_back(1, 2);    // Automatically assumes data type and constructs it natively

```

#### Understanding Iterators

Iterators act as structured memory address pointers pointing to specific elements inside a container.

* `v.begin()`: Points to the **first** element.
* `v.end()`: Points to the memory address **immediately following the last** element.
* `v.rbegin()` / `v.rend()`: Reverse iterators used to traverse from rear to front.

```cpp
vector<int> v = {20, 10, 15, 5};

// Declaring iterator explicitly
vector<int>::iterator it = v.begin(); 
cout << *it; // Dereferencing accesses the value: 20

it++; // Shifts to the contiguous neighboring address
cout << *it; // Outputs: 10

```

#### Traversing Vectors

```cpp
vector<int> vec = {10, 20, 30};

// Method 1: Standard index-based loop
for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";

// Method 2: Iterator based loop using 'auto' keyword for type deduction
for(auto it = vec.begin(); it != vec.end(); it++) {
    cout << *(it) << " ";
}

// Method 3: Clean Range-based 'for-each' loop
for(auto element : vec) {
    cout << element << " "; // 'element' copies each element directly, not an iterator
}

```

#### Deletion Operations

* `pop_back()`: Removes the single element at the very end.
* `erase()`: Removes elements via explicit iterator addresses.

```cpp
// Vector: {10, 20, 12, 23, 35}
v.erase(v.begin() + 1); // Erases 20 -> Vector becomes: {10, 12, 23, 35}

// Block Erase: erase(start_iterator, end_iterator) -> [start, end)
// Vector: {10, 20, 30, 40, 50}
v.erase(v.begin() + 1, v.begin() + 4); // Erases index 1, 2, and 3. (4 is excluded)
// Vector becomes: {10, 50}

```

#### Insertion Operations

```cpp
vector<int> v(2, 100); // {100, 100}
v.insert(v.begin(), 300); // {300, 100, 100}
v.insert(v.begin() + 1, 2, 10); // Insert 2 instances of 10 at index 1 -> {300, 10, 10, 100, 100}

```

#### Miscellaneous Core Functions

* `v.size()`: Returns current element count.
* `v.empty()`: Returns boolean `true` if the vector contains zero elements.
* `v.clear()`: Destroys all elements, reducing container size to 0.
* `v1.swap(v2)`: Efficiently swaps entire memory contexts between two structural vectors.

---

### Lists & Deques

`std::list` and `std::deque` share almost all standard member functions with `std::vector` but differ significantly in internal memory layouts and time complexity architectures.

#### 1. Lists (`std::list`)

Unlike vectors, which use a contiguous flat array block, lists are built on an internal **Doubly Linked List** sequence.

* **Advantage**: Because elements are not stored sequentially in unified blocks, inserting or removing elements from the front of the list takes `O(1)` constant time.
* **Drawback**: Does not support continuous random index lookups (`arr[i]`).

```cpp
list<int> ls;
ls.push_back(2);
ls.push_front(5); // O(1) time complexity - pushes directly to head

```

#### 2. Deques (`std::deque`)

A double-ended queue that aggregates benefits of both vectors and lists. It allows dynamic scaling and provides constant-time structural insertion/deletion at **both** front and back ends, while still maintaining indexing functionality (`dq[i]`).

---

## 5. Container Adaptors

### Stacks (LIFO)

Stacks operate on a strict **Last-In, First-Out (LIFO)** policy. Elements can only be manipulated from a single localized side (the top). Random index mapping is completely prohibited.

```cpp
stack<int> st;
st.push(1);   // {1}
st.push(2);   // {2, 1}
st.push(3);   // {3, 2, 1}
st.emplace(5); // {5, 3, 2, 1}

cout << st.top(); // Returns current topmost item without deleting -> Outputs: 5
st.pop();         // Erases topmost item -> stack becomes {3, 2, 1}
cout << st.size(); // Outputs: 3
cout << st.empty(); // Outputs: false (0)

```

* **Time Complexity**: Every structural modification and lookup function inside `std::stack` (`push`, `pop`, `top`) runs instantly in **$O(1)$ constant time**.

---

### Queues (FIFO)

Queues operate on a structural **First-In, First-Out (FIFO)** paradigm, perfectly mirroring real-world checkout lines. The element added first is always processed and removed first.

```cpp
queue<int> q;
q.push(1); // {1}
q.push(2); // {1, 2}
q.push(4); // {1, 2, 4}

q.back() += 5; // Accesses the last item (4) and adds 5 -> Last item becomes 9
cout << q.back(); // Outputs: 9

cout << q.front(); // Accesses the front items -> Outputs: 1
q.pop(); // Deletes the oldest front element -> queue becomes {2, 9}
cout << q.front(); // Outputs: 2

```

* **Time Complexity**: All fundamental queue methods execute in **$O(1)$ time**.

---

### Priority Queues

A complex, incredibly powerful container adaptor where elements are structured in a non-linear format using an internal tree-like heap structure. Elements are fetched based on assigned numeric priority instead of insertion sequences.

#### 1. Max-Heap (Default)

The largest element automatically floats to the absolute top of the container.

```cpp
priority_queue<int> pq;
pq.push(5);  // {5}
pq.push(2);  // {5, 2}
pq.push(8);  // {8, 5, 2}
pq.push(10); // {10, 8, 5, 2}

cout << pq.top(); // Outputs: 10
pq.pop();         // Removes 10 -> priority queue rearranges internally
cout << pq.top(); // Outputs: 8

```

#### 2. Min-Heap

To force the absolute minimum element to always float to the top, modify the instantiation template using the built-in greater comparator:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(5);
pq.push(2);
pq.push(8);

cout << pq.top(); // Outputs: 2

```

#### Performance Metrics:

* `push()`: $O(\log N)$
* `pop()`: $O(\log N)$
* `top()`: $O(1)$

---

## 6. Associative Containers

### Sets (Sorted & Unique)

A mathematical implementation container that obeys two strict rules:

1. **Sorted Order**: Everything inside is arranged in ascending sequence.
2. **Unique Values**: Every single value can exist exactly once. No duplicates are allowed.

```cpp
set<int> s;
s.insert(1); // {1}
s.insert(2); // {1, 2}
s.insert(2); // Duplicate ignored -> {1, 2}
s.insert(4); // {1, 2, 4}
s.insert(3); // Automatically sorted -> {1, 2, 3, 4}

// Find Function: returns an iterator pointing to the item if found
auto it = s.find(3); 

// If the item does NOT exist, find() returns the end() iterator boundary
auto it_not_found = s.find(6);
if(it_not_found == s.end()) {
    cout << "6 is not present in the set\n";
}

// Count Function: returns 1 if element exists, 0 if not (since values are unique)
int occurrences = s.count(2); // Returns 1

// Erasing by Value or Iterator
s.erase(4); // Erases value 4 directly -> {1, 2, 3}
auto target = s.find(2);
s.erase(target); // Erases via iterator link -> {1, 3}

```

* **Complexity**: Every operation (`insert`, `find`, `erase`) runs on a logarithmic time scale: **$O(\log N)$**. Sets are internally maintained via balanced binary search trees (Red-Black Trees).

---

### Multisets

A variant of sets that retains the internal **sorted property** but discards uniqueness, allowing you to store multiple identical elements.

```cpp
multiset<int> ms;
ms.insert(1);
ms.insert(1);
ms.insert(1); // Content: {1, 1, 1}

// Crucial Distinction when Erasing
ms.erase(1); // Calling erase by VALUE deletes EVERY single instance of 1 -> clears multiset

// To delete ONLY one single specific instance:
ms.insert(1); ms.insert(1); ms.insert(1); // Refill {1, 1, 1}
ms.erase(ms.find(1)); // Passing the iterator deletes ONLY that exact singular slot

```

---

### Unordered Sets

Unordered sets prioritize absolute speed by dropping the requirement of sorted arrangements. Data structures are arranged in randomized slots using internal **Hash Tables**.

* **Properties**: Contains strictly unique values but with no deterministic internal ordering sequence.
* **Time Complexity**: Fundamental functions (`insert`, `find`, `erase`) run in **$O(1)$ Constant Time** on average.
* *Note*: In rare worst-case scenarios where excessive hash collisions occur (once in a blue moon), execution can degrade to linear time $O(N)$.

---

## 7. Key-Value Mapping Containers

### Maps (`std::map`)

Maps are associative containers that store data in structural **Key-Value Pairs**. Keys are structurally unique and kept in a highly disciplined **sorted order** based on the key value.

```cpp
// Syntax: map<Key_DataType, Value_DataType>
map<int, string> mpp;

mpp[1] = "Raj";         // Key 1 maps to "Raj"
mpp.insert({3, "Sam"}); // Key 3 maps to "Sam"
mpp.emplace(2, "Asif"); // Key 2 maps to "Asif"

// Internally sorted by Keys: {{1, "Raj"}, {2, "Asif"}, {3, "Sam"}}

// Traversing a Map
for(auto pr : mpp) {
    cout << pr.first << " -> " << pr.second << "\n";
}

// Accessing map values safely
cout << mpp[2]; // Outputs: "Asif"
cout << mpp[5]; // Returns blank or 0 since Key 5 does not exist (and implicitly instantiates it)

```

* **Time Complexity**: Accessing, lookup, and insertion operations require **$O(\log N)$** time.

---

### Unordered Maps & Multimaps

* **Unordered Maps (`std::unordered_map`)**: Stores unique structural key-value associations but completely randomized without sorting constraints. Achieves exceptional average lookups in **$O(1)$ constant time**.
* **Multimaps (`std::multimap`)**: Permits multiple duplicate identical mapping keys while preserving sorted constraints. Index bracket assignments (`mpp[key]`) are not usable here.

---

## 8. Essential STL Algorithms

### Advanced Sorting Methods

The generic `std::sort` algorithm uses IntroSort (a hybrid blend of QuickSort, HeapSort, and Insertion Sort), providing a guaranteed optimal runtime.

```cpp
int arr[] = {4, 1, 3, 5, 2};
int n = sizeof(arr)/sizeof(arr[0]);

// Sort full array range: [start_address, end_address)
sort(arr, arr + n); // Array becomes: {1, 2, 3, 4, 5}

// Sort specific sub-vectors
vector<int> v = {5, 2, 9, 1};
sort(v.begin(), v.end()); // {1, 2, 5, 9}

// Sorting in Descending Order using built-in comparator
sort(v.begin(), v.end(), greater<int>()); // {9, 5, 2, 1}

```

---

### Custom Building Comparators

When simple ascending or descending rules are insufficient, custom comparators can define specific sorting logic. A comparator is a boolean function returning `true` if elements are in the desired order and `false` otherwise.

#### Problem Statement:

Sort an array of pairs such that:

1. Pairs are sorted in **increasing order** based on their second element.
2. If the second elements match, sort them in **decreasing order** based on their first element.

```cpp
bool customComparator(pair<int, int> p1, pair<int, int> p2) {
    // Condition 1: Second elements differ
    if (p1.second != p2.second) {
        return p1.second < p2.second; // Returns true if p1 should come before p2
    }
    // Condition 2: Second elements are identical -> Sort first element descending
    return p1.first > p2.first;
}

int main() {
    vector<pair<int, int>> vec = {{1, 2}, {2, 1}, {4, 1}};
    
    sort(vec.begin(), vec.end(), customComparator);
    
    // Resulting Order: {{4, 1}, {2, 1}, {1, 2}}
    return 0;
}

```

---

### Bitwise Utility Functions

```cpp
int num = 7; // Binary equivalent: 000...0111
int totalSetBits = __builtin_popcount(num); // Counts number of active 1s -> Returns: 3

long long largeNum = 777777777777LL;
int totalLargeSetBits = __builtin_popcountll(largeNum); // Version for 64-bit long long ints

```

---

### Permutations & Iterators

Generates lexicographically ordered dictionary permutations. For comprehensive tracking, ensure the target sequence is initially sorted.

```cpp
string s = "123";
sort(s.begin(), s.end());

do {
    cout << s << "\n";
} while(next_permutation(s.begin(), s.end()));

/* Outputs:
123
132
213
231
312
321
*/

```

---

### Dynamic Bound Locators

```cpp
vector<int> v = {1, 5, 6, 6, 7};

// Returns an iterator pointing to maximum element
auto max_it = max_element(v.begin(), v.end()); 
cout << *max_it; // Outputs: 7

// Returns an iterator pointing to minimum element
auto min_it = min_element(v.begin(), v.end());
cout << *min_it; // Outputs: 1

```

---

## 9. Comprehensive Performance Matrix

| Container / Algorithm | Core Operation | Average Time Complexity | Worst Case Time Complexity | Space Complexity | Underlying Architecture |
| --- | --- | --- | --- | --- | --- |
| **`std::vector`** | `push_back` / `pop_back` | $O(1)$ | $O(1)$ (Amortized) | $O(N)$ | Dynamic Contiguous Array |
| **`std::list`** | `push_front` / `push_back` | $O(1)$ | $O(1)$ | $O(N)$ | Doubly Linked List |
| **`std::stack`** | `push` / `pop` / `top` | $O(1)$ | $O(1)$ | $O(N)$ | Container Adaptor |
| **`std::queue`** | `push` / `pop` / `front` | $O(1)$ | $O(1)$ | $O(N)$ | Container Adaptor |
| **`std::priority_queue`** | `push` / `pop` | $O(\log N)$ | $O(\log N)$ | $O(N)$ | Binary Heap Tree |
| **`std::set`** | `insert` / `find` / `erase` | $O(\log N)$ | $O(\log N)$ | $O(N)$ | Balanced Red-Black Tree |
| **`std::unordered_set`** | `insert` / `find` / `erase` | $O(1)$ | $O(N)$ | $O(N)$ | Hash Table Architecture |
| **`std::map`** | `insert` / `find` / Lookup | $O(\log N)$ | $O(\log N)$ | $O(N)$ | Balanced Red-Black Tree |
| **`std::unordered_map`** | `insert` / `find` / Lookup | $O(1)$ | $O(N)$ | $O(N)$ | Hash Table Architecture |
| **`std::sort`** | Range Sorting Function | $O(N \log N)$ | $O(N \log N)$ | $O(\log N)$ | IntroSort (Hybrid Algorithm) |

---

"""

```