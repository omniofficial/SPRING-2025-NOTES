// -------------------------------
// Assignment: HW2 Question 1: Reversing a double linked list
// Due date: 3/4/25
// Purpose: Write an algorithm that reverses a double linked list. Make sure it does not create any new node objects.
// -------------------------------
#include <iostream>
using namespace std;

struct node
{
  int data;       // Our node contains data
  node *next;     // Our node contains a pointer to the address of the next node. This is just for initialization, we do not know the memory address yet. Think of it as a pointer named next that has type node.
  node *previous; // Our node contains a pointer to the address of the previous node.
};

// Global pointers for head and tail
node *head = nullptr;
node *tail = nullptr;

// Traverses from head to tail
void traverseForward()
{
  node *temp = head; // Beginning from the head. Pointer named temp with type node is initialized to the memory address of head (which is the memory address of the first node created).
  while (temp != nullptr)
  {
    cout << (*temp).data << " "; // Access data by dereferencing temp. Originally, it points to the memory address of head, since temp was initialized to the memory address of head. Once derefrencing, we can find the data at the specified node. EX: *temp becomes node1 object, which grants us node1.data
    temp = (*temp).next;         // Temp now points to the next node's memory address. *temp becomes the object of wherever the memory address of head is pointing to, in this case node1. So, node1.next displays the memory address node1 points to. This value is stored in our pointer variable temp with type node, meaning temp becomes the memory address node2 is located in.
  }
  cout << endl;
}

// Traverses from tail to head
void traverseBackward()
{
  node *temp = tail; // Beginning from the tail. Pointer named temp with type node is initialized to the memory address of tail (which is the memory address of the last node created)
  while (temp != nullptr)
  {
    cout << (*temp).data << " "; // Similar to the previous function, see above for explanation..
    temp = (*temp).previous;     // Similar to previous function, see above for explanation.
  }
  cout << endl;
}

int main()
{
  node *newNode = nullptr; // A pointer with type node is created named newNode.

  // CREATE FIRST NODE
  newNode = new node;            // This newNode pointer is initialized. The operation on the right (new node) grabs the address of the newly created node and stores it in the pointer named newNode.
  (*newNode).data = 10;          // Derefrence newNode pointer to acquire object. object.data = 10.
  (*newNode).next = nullptr;     // Derefrence newNode pointer to acquire the object given by the memory address within the newNode pointer. Must initialize to null since this struct value will store a memory address.
  (*newNode).previous = nullptr; // Similar to previous operation. See above.
  head = newNode;                // Head is set to the memory address of the newNode.
  tail = newNode;                // Tail is set to the memory address of the newNode.

  // NODE CREATION AND LINKING NEXT AND PREVIOUS
  for (int i = 20; i <= 40; i += 10)
  {
    node *temp = new node; // Create a new node

    (*temp).data = i;        // Iterator to keep track of node.
    (*temp).next = nullptr;  // Set the next pointer of the current node to null, showing that it is the last node in the list (shoulnd't point to anything yet)
    (*temp).previous = tail; // The node objects previous pointer should be linked to tail. (node2.previous). Recall that tail is the memory address of the last node before this node was added, where tail = node1 (the first node if we are running this loop the first time).
    (*tail).next = temp;     // Tail is the memory address of the last created node. To find the next memory address our new node points to, we need to assign the value of temp to *tail.next, since temp points to the newly created node.
    tail = temp;             // Finally, update the tail pointer (the last node in the list) to be the current node in the list, since we added the new node.
  }

  // OUTPUT
  cout << "Forward traversal: ";
  traverseForward();

  // OUTPUT
  cout << "Backward traversal: ";
  traverseBackward();

  return 0;
}
