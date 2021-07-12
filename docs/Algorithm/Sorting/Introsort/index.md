# Introsort



## wanweibaike [Introsort](https://en.wanweibaike.com/wiki-Introsort)

**Introsort** or **introspective sort** is a [hybrid](https://en.wanweibaike.com/wiki-Hybrid_algorithm) [sorting algorithm](https://en.wanweibaike.com/wiki-Sorting_algorithm) that provides both fast average performance and (asymptotically) optimal worst-case performance. It begins with [quicksort](https://en.wanweibaike.com/wiki-Quicksort), it switches to [heapsort](https://en.wanweibaike.com/wiki-Heapsort) when the recursion depth exceeds a level based on (the [logarithm](https://en.wanweibaike.com/wiki-Logarithm) of) the number of elements being sorted and it switches to [insertion sort](https://en.wanweibaike.com/wiki-Insertion_sort) when the number of elements is below some threshold. This combines the good parts of the three algorithms, with practical performance comparable to quicksort on typical data sets and worst-case [O](https://en.wanweibaike.com/wiki-Big-O_notation)(*n* log *n*) runtime due to the heap sort. Since the three algorithms it uses are [comparison sorts](https://en.wanweibaike.com/wiki-Comparison_sort), it is also a comparison sort.