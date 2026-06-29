# Pattern Problems

Pattern problems are mostly solved with loops. The main idea is to understand how rows, columns, and printed characters change from one line to the next.

## Core Idea

Before writing code, observe how the pattern grows or shrinks.

1. Use the outer loop for the number of lines or rows.
2. Use the inner loop for the columns, and connect it to the current row.
3. Print inside the inner loop.
4. Observe the pattern carefully before coding.

## How To Think

Most pattern questions can be broken into these checkpoints:

- How many rows are there?
- What should be printed in each row?
- Does the number of spaces, stars, or numbers change with every row?
- Does the pattern grow, shrink, or stay the same?

Once you answer these, the loop logic becomes easier.

## Standard Template

```cpp
for (int row = 1; row <= n; row++) {
	for (int col = 1; col <= row; col++) {
		cout << "*";
	}
	cout << endl;
}
```

This template works when the number of printed items depends on the current row.

## Worked Examples

For full code examples, see [Code/patterns.cpp](Code/patterns.cpp). It contains reusable implementations for the common pattern.

Use the C++ file alongside this note when you want to see the loops in a complete program.

## Common Pattern Types

### 1. Solid Square

Every row has the same number of stars.

```cpp
for (int row = 1; row <= n; row++) {
	for (int col = 1; col <= n; col++) {
		cout << "* ";
	}
	cout << endl;
}
```

### 2. Right Triangle

The number of stars increases with each row.

```cpp
for (int row = 1; row <= n; row++) {
	for (int col = 1; col <= row; col++) {
		cout << "* ";
	}
	cout << endl;
}
```

### 3. Inverted Right Triangle

The number of stars decreases with each row.

```cpp
for (int row = n; row >= 1; row--) {
	for (int col = 1; col <= row; col++) {
		cout << "* ";
	}
	cout << endl;
}
```

### 4. Number Triangle

Instead of stars, print numbers in sequence.

```cpp
for (int row = 1; row <= n; row++) {
	for (int col = 1; col <= row; col++) {
		cout << col << " ";
	}
	cout << endl;
}
```

## Quick Checklist Before Coding

- Identify the row count.
- Decide what the inner loop should print.
- Check whether the row value controls the column count.
- Add spaces or new lines only where needed.
- Test with a small value like `n = 3` or `n = 4`.

## Final Tip

If you get stuck, draw the pattern on paper first and write the row and column count beside each line. That usually reveals the loop condition quickly.
