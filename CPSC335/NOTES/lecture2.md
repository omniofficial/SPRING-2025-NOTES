# LECTURE 2: Efficiency Analysis

## RAM

In order to predict a running time, a simple computation model is used: the RAM.

Each basic insturction takes a constant amount of time.

## Functions for Measuring resources

A algorithm is efficient when it consumes few resources

Time: measured in units of seconds, CPU instructions, or generic steps

Space: measured in bits, bytes, gigabytes, or generic words

Input / Output bandwith (I/O): measured in units of bytes of blocks

Cache: measured in units of integers

Energy: measured in units of kilowatt - hours

## Measuring the quality of an algorithm

-   Quality of an algorithm is measured in terms of resources it consumes when it is executed on a computer
-   Of interest in the class are the execution time and the memory need

    -   Shorter the execution time, better quality of the algorithm - **time complexity**
    -   Smaller the amount of memory needed for execution, better the quality of the algorithm - **space complexity**

-   The complexity of an algorithm A, with respect to a specific instance I and resource R, is a non-negative real number representing the maout of R that is consumed by A when run on I.

-   Time complexity is an indicatuion of the run time of an algorithm in terms of how quickly it grows relative to the input 'n'.

    -   Denoted by the amount of time taken by an algorithm to run, as a function of the length of the input.
    -   It measures the time taken to execute each statement of code in an algorithm.

-   It is not useful to measure the execution time of an algorithm in absolute terms (10sec, 30 u sec, 1 hr, etc.) as execution time depends on a lot of factors.

## Counting Operations

-   Step count (or Running Time): the number of primitive operations or "steps".
-   For our RAM model, assume that executing each instruction (or statement) takes a constant amount of time. The constant values may differ but they are the same for the two similar instrucitons
-   Step count: the sum of steps (or running times) for each executable statement

## General Rules for Computing the S.C.

Simple operations take (1) unit of time:

-   Addition, multiplication, assignment, comparison, read/write a value.

Consecutive statements add up.

If/Else: For the fragment

```c++
if (condition)
S1
else
S2
```

-   The step count is equal to the number of steps to evaluate the condition plus the maximum of the step count of S1 and S2.

For loops: The step count of a for-loop is at most the step count of the statements inside the for loop times the number of interations.

## Analysis by Case Complexities

**Best-case complexity:** minimum number of steps

-   E.g. sorting a sequence of sorted or almost sorted numbers using insertion sort.

**Worst-case complexity:** maximum number of steps

-   E.g. sorting a sequence of fully unsorted numbers using insertion sort

**Average case complexity:** the input is random, the average number of steps.

The worst case running time of an algorithm is an upper bound on the running time for any input.

The average case running time is often as bad as the worst-case running time

-   E.g. insertion sort has a quadratic time for both, and a linear time for best case.

## Asymptotic Notations

Mathematical notations of an efficiency class of an algorithm

-   f(n) <= O(g(n)) implies that C x g(n) is an upper bound of f(n)
-   f(n) >= OMEGA(g(n)) implies that C x g(n) is a lower bound of f(n)
-   f(n) = THETA(g(n)) implies that C1 x g(n) is an upper bound of f(n) and C2 x g(n) is a lower bound of f(n)

C, C1 and C2 are positive constants, and there exist a positive n > n0 for which these relationships hold.

## Categorizing Functions

Big-Oh can be used to categorize functions.

Only the leading term is considered when analyzing the run time of a algorithm. Constants are ignored, and a solution that takes constant time has a run time of O(1).

An algorithm A is more efficient than another algorithm B if the r.t. of A has a lower order of growth.

-   Examples: n, log(n), n^2, n^2log(n)

**O(n)** is the set of all functions that are equivalent to f(n) = n for the purposes of measuring algorithms complexity

**O(n^2)** is the set of all functions that are equivalent to f(n) = n^2 for the purposes of measuring algorithmic complexity

For example,

-   2n + 3 is O(n) and 5n is O(n), places 2n+3 and 5n in the same category
-   Both functions are less than or equal to g(n) = n, up to a constant factor, for large values of n

## Step Counts

Not all steps take the same amount of time

For example,

```c++
return a+b+b*+c+(a+b-c)/(a+b)+4
```

The entire statement can be regarded as a single step if it execution time is independent of the problem size.

We may also count statements such as x = y as a single step.

**TO DO: UNDERSTAND HOW TO CALCULATE STEP COUNTS FOR PROGRAMMING EXERCISES. FIND THE TIME COMPLEXITY BASED ON THESE STEP COUNTS ADDED TOGETHER**

## Growth Rate of Algorithms

For large inputs, the order of growth is relevant

-   To determine the asymptotic efficiency of algorithms

We are concerned with how the running time of an algorithm increases with an increase in input size

## Logarithms

A logarithm is simply an inverse exponential function.

-   E.g. b^x = y is equivalent to saying that x = logb y

Logarithms reflect how many times we can double something until we get to n or divide by 2 until we get to 1.

## The Big Eight Efficiency Classes

**O(1)**: A constant. The complexity can be bounded, no matter how big n is. Example: adding 10 to an integer or accessing an array element.

**O(log n)**: Logarithmic growth. This compelxity growns very slowly. Example: binary search of a sorted list.

**O(n)**: Linear growth. Example: traversing a linked list with n nodes, or sequential search of an array.

**O (n log n)**: Slightly worse than linear. Usually occurs when you break a problem down into two problems of half the size that must both be solved. Example: merge sort.

**O(n^2)**: Quadradic growth. Grows with the square of the porblem size. Often two nested loops. exmaple: Insertion sort.

**O(n^3)**: Cubic growth. Worse than quadradic. Often three nested loops. Example: Matrix multiplication (straighforward approach)

**O(c^n)**: Exponential growth. All subset of an n-element set.

**O(n!)**: Factorial growth. All permutations of an n-element sequence.

n! >> 2^n >> n^3 >> n2 >> n log n >> n >> log n >> 1

Where n! is slowest, 1 is fastest.
