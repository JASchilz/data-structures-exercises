"""
Basic
find-max [or find-min]: find a maximum item of a max-heap, or a minimum item of a min-heap, respectively (a.k.a. peek)
insert: adding a new key to the heap (a.k.a., push[3])
extract-max [or extract-min]: returns the node of maximum value from a max heap [or minimum value from a min heap] after removing it from the heap (a.k.a., pop[4])
delete-max [or delete-min]: removing the root node of a max heap [or min heap], respectively
replace: pop root and push a new key. More efficient than pop followed by push, since only need to balance once, not twice, and appropriate for fixed-size heaps.[5]
Creation
create-heap: create an empty heap
heapify: create a heap out of given array of elements
merge (union): joining two heaps to form a valid new heap containing all the elements of both, preserving the original heaps.
meld: joining two heaps to form a valid new heap containing all the elements of both, destroying the original heaps.
Inspection
size: return the number of items in the heap.
is-empty: return true if the heap is empty, false otherwise.
Internal
increase-key or decrease-key: updating a key within a max- or min-heap, respectively
delete: delete an arbitrary node (followed by moving last node and sifting to maintain heap)
sift-up: move a node up in the tree, as long as needed; used to restore heap condition after insertion. Called "sift" because node moves up the tree until it reaches the correct level, as in a sieve.
sift-down: move a node down in the tree, similar to sift-up; used to restore heap condition after deletion or replacement.
"""

class Item(object):
    
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __repr__(self):
        return "Item({}, {})".format(self.key.__repr__(), self.value.__repr__())

class Heap(object):
    """
    A binary max-heap
    """
    
    def __init__(self, size):
        # A list of instances of Item
        self._size = size
        self._storage = [None]*size
        self._next_free = 0

    @staticmethod
    def _parent(i):
        """
        Returns the index of a node's parent.
        """

        return int((i - 1)/2)

    def _children(self, i):
        """
        Returns a list of all child node indices.
        
        Will not return child node indices that are out of bounds by
        self._size. WILL return indices of child nodes that are empty.
        """

        return [i for i in list(range(i*2 + 1, i*2 + 3)) if i <= self._size - 1]

    def _swap(self, i, j):
        """
        Swap two elements in the heap, by index."
        """

        tmp = self._storage[i]
        self._storage[i] = self._storage[j]
        self._storage[j] = tmp

    def _greatest(self, indices):
        """
        Among a list of given indices, return the index bearing the greatest
        key value.
        """

        greatest = indices[0]

        for index in indices[1:]:
            if self._storage[greatest].key < self._storage[index].key:
                greatest = index

        return greatest

    def _sift_up(self, i):
        """
        Sift a node up to its appropriate index.
        """
        
        if i > 0:
            parent_index = self._parent(i)
            parent_is_smaller = self._storage[parent_index].key < self._storage[i].key

            if parent_is_smaller:
                self._swap(i, parent_index)
                self._sift_up(parent_index)

    def _sift_down(self, i):
        """
        Sift a node down to its appropriate index.
        """

        neighborhood = [k for k in self._children(i) if self._storage[k] is not None]
        neighborhood.append(i)

        greatest = self._greatest(neighborhood)

        if i != greatest:
            self._swap(i, greatest)
            self._sift_down(greatest)


    def push(self, item):
        """
        Push an item onto the heap.
        """

        insertion_index = self._next_free
        self._next_free += 1
        self._storage[insertion_index] = item

        self._sift_up(insertion_index)

    def peek(self):
        """
        View the item at the top of the heap, without deletion.
        """

        return self._storage[0]

    def pop(self):
        """
        View the item at the top of the heap, with deletion.
        """

        result = self._storage[0]

        if self._next_free > 0:

            self._storage[0] = None
            self._next_free -= 1

            self._swap(0, self._next_free)

            if self._storage[0] is not None:
                self._sift_down(0)


        return result

