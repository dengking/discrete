# [stevehanov-Finding the top K items in a list efficiently](http://stevehanov.ca/blog/index.php?id=122)



Algorithms will always matter. Sure, processor speeds are still increasing. But the problems that we want to solve using those processors are increasing in size faster. People who are dealing with social network graphs, or analyzing twitter posts, or searching images, or solving any of the hundreds of problems in vogue would be wasting time without the fastest possible hardware. But they would sitting around forever if they weren't using the right tools.

That's why I get sad when I see code like this:

```python
# find the top 10 results
results = sorted(results, reverse=True)[:10]
```

Anything involving a sort will usually take O(nlogn) time, which, when dealing with lots of items, will keep you waiting around for several seconds or even minutes. An O(nlogn) algorithm, for large N, simply cannot be run in realtime when users are waiting.



## The Heap

Finding the top K items can be done in O(nlogk) time, which is much, much faster than O(nlogn), using a heap ([wikipedia](http://en.wikipedia.org/wiki/Heap_(data_structure))). Or, since [I usually end up rewriting everything in C++ eventually](http://stevehanov.ca/blog/index.php?id=95), a [priority queue](http://www.cplusplus.com/reference/stl/priority_queue/).

The strategy is to go through the list once, and as you go, keep a list of the top k elements that you found so far. To do this efficiently, you have to always know the smallest element in this top-k, so you can possibly replace it with one that is larger. The heap structure makes it easy to maintain this list without wasting any effort. It is like a lazy family member who always does the absolute minimum amount of work. It only does enough of the sort to find the smallest element, and that is why it is fast.

Here's some code to demonstrate the difference between a **linear search**, and a **heap search** to find the top K elements in a large array. The heap search is 4 times faster, despite the test being biased in favour of the linear search. The linear search ends up executing in compiled C inside python itself, while the heap search is completely in interpreted python. If they were both in C, the difference in performance would be more pronounced.



```python
#!/usr/bin/python
import heapq
import random
import time

def createArray():
    array = range( 10 * 1000 * 1000 )
    random.shuffle( array )
    return array

def linearSearch( bigArray, k ):
    return sorted(bigArray, reverse=True)[:k]

def heapSearch( bigArray, k ):
    heap = []
    # Note: below is for illustration. It can be replaced by 
    # heapq.nlargest( bigArray, k )
    for item in bigArray:
        # If we have not yet found k items, or the current item is larger than
        # the smallest item on the heap,
        if len(heap) < k or item > heap[0]:
            # If the heap is full, remove the smallest element on the heap.
            if len(heap) == k: heapq.heappop( heap )
            # add the current element as the new smallest.
            heapq.heappush( heap, item )
    return heap

start = time.time()
bigArray = createArray()
print "Creating array took %g s" % (time.time() - start)

start = time.time()
print linearSearch( bigArray, 10 )    
print "Linear search took %g s" % (time.time() - start)

start = time.time()
print heapSearch( bigArray, 10 )    
print "Heap search took %g s" % (time.time() - start)
```



Also, if you see stuff like this, you should go directly to the wikipedia page on the [Selection Algorithm](http://en.wikipedia.org/wiki/Selection_algorithm)

```python
# find the median
median = sorted(results)[len(results)/2]
```