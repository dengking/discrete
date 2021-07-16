# Hybrid sorting

参见 [Hybrid algorithm](https://infogalactic.com/info/Hybrid_algorithm) 

一、[Timsort](https://infogalactic.com/info/Timsort), which combines merge sort, insertion sort, together with additional logic (including [binary search](https://infogalactic.com/info/Binary_search)) in the merging logic.

二、[introsort](https://infogalactic.com/info/Introsort) and [introselect](https://infogalactic.com/info/Introselect), which combine one algorithm for fast average performance, falling back on another algorithm to ensure (asymptotically) optimal worst-case performance. Introsort begins with a [quicksort](https://infogalactic.com/info/Quicksort), but switches to a [heap sort](https://infogalactic.com/info/Heap_sort) if quicksort is not progressing well; analogously introselect begins with [quickselect](https://infogalactic.com/info/Quickselect), but switches to [median of medians](https://infogalactic.com/info/Median_of_medians) if quickselect is not progressing well.

