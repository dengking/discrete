# Heap select

一、素材:

1、[michaelpollmeier-Selecting top k items from a list efficiently in Java / Groovy](https://www.michaelpollmeier.com/selecting-top-k-items-from-a-list-efficiently-in-java-groovy) 

2、[stevehanov-Finding the top K items in a list efficiently](http://stevehanov.ca/blog/index.php?id=122) 

这篇文章对heap select的介绍非常好

3、[malyasova-Solving the Selection Problem using a Heap](https://malyasova.github.io/data_structures/2020/09/06/selection-problem-heap.html)



二、

源自: [stevehanov-Finding the top K items in a list efficiently](http://stevehanov.ca/blog/index.php?id=122) 

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

