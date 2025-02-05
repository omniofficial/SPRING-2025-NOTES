# LECTURE 3: Proving the Efficiency Class of an Algorithm

## Proving by Induction

_We can prove that T(n) is a member of a class O(f(n)) by carefully picking a particular pair of constants c and n0, and showing that T(n)≤ c . f(n) for any n > n0._

1. Make an informed guess about which efficiency class O(f(n) to use.
2. Use algebra to solve for constant values c and no that seem
   likely to work.
3. Prove the base case, that T(n)
   ≤ c . f(n) when n = no
4. Prove the inductive step, that for any n > no, T(n)
   ≤ c . f(n)
   implies T(n + 1)
   ≤ c . f(n + 1).
5. Conclude that T(n) ε O(f(n))

## Fundamental Data Structures

An abstract data type (ADT) is a logical description of data.

-   It includes the views and the allowed operations (without implementation details)

An ADT is defined by its behavior (its operations).

-   The implementation may vary.
-   Eg a priority queue may be implemented with an array or heap

Some Common Abstract Data Types (ADTs): List, Set, Graph, Stack, Queue,
Priority queue.

A set of objects that are related to each other together with a set of
operations:

-   Description of the data type object
-   Description of the relationships between the individual objects
-   Description of the operations to be performed on the objects

An abstract data type defines a data representation for objects of the type and
the set of operations that can be performed on these objects.

