# Data Structures Exercises

Various data structures implemented in Python and C, with notes.

The following notes are **rough**: they are mostly for my own benefit and they are definitely not designed to instruct. They pull out only some details of my exercises.

## Heap

A heap is a data structure which:

1. is a collection of nodes
2. where each node has a _sort key_ and a _payload value_
3. with the heap offering (at the very least) a _push_ and _pop_ method
4. such that _pop_ will always return the node with the lowest sort key

Alternately, the pop method may be designed to always return the node with the _highest_ sort key. This would be known as a _maxheap_. The difference between implementing a maxheap and a minheap is trivial. The notes that follow will discuss the details of a _minheap_.

To support this interface, a heap:
1. must be complete, up to the bottom row of leaves
2. the bottom row of leaves must be filled from left to right
3. the root of the tree must bear the node with the lowest sort key
4. every sub-tree of the root node must satisfy these heap conditions, including condition (4).

Maintaining the "completeness" described in conditions (1) and (2) is the key to keeping the heap balanced and putting a lower bound on the time required to complete the push and pop operations.

A heap generally implements two _internal_ methods to implement push and pop: filter up and filter down. Both are methods of a single node within the heap.

The _filter up_ method examines a given node. If the sort key of that node is _smaller_ than its parent (ie: its parent node violates condition 3) then the method swaps the two nodes. If the event of a swap, the method will again check if the node has a smaller sort key than its new parent, and so on, until it finds that the sort key of the node is greater than its current parent.

The _filter down_ method is similar: it examines a given node and will swap it with a child node if either of its children have a smaller sort key. If both of the given node's children have a smaller sort key, then the method will swap the given node with the child that has the smallest sort key. As with _filter up_, _filter down_ will keep swapping the given node down until it has a sort key that is smaller than both of its children.

Then _push_ is accomplished by placing the given node into the next free location--by rules (1) and (2)--and then _filtering the node up_.

And _pop_ is accomplished by popping the root node, swapping the node in the ultimate position--the rightmost node on the bottom row--up into the root position, and then filtering it down.

Without proof, these implementations of push and pop maintain the four heap conditions described above.

### Python

### C

