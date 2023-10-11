# Median of medians

意思是: 中位数中的中位数

## wikipedia [Median of medians](https://en.wikipedia.org/wiki/Median_of_medians)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), the **[median](https://en.wikipedia.org/wiki/Median) of medians** is an approximate median [selection algorithm](https://en.wikipedia.org/wiki/Selection_algorithm), frequently used to supply a good pivot for an exact selection algorithm, most commonly [quickselect](https://en.wikipedia.org/wiki/Quickselect), that selects the *k*th smallest element of an initially unsorted array. 

Median of medians finds an approximate median in linear time. 

Using this approximate median as an improved pivot, the worst-case complexity of quickselect reduces from quadratic to *linear*, which is also the asymptotically optimal worst-case complexity of any selection algorithm. 

In other words, the median of medians is an approximate median-selection algorithm that helps building an asymptotically optimal, exact general selection algorithm (especially in the sense of worst-case complexity), by producing good pivot elements.

Median of medians can also be used as a pivot strategy in [quicksort](https://en.wikipedia.org/wiki/Quicksort), yielding an optimal algorithm, with worst-case complexity �(�log⁡�)![O(n\log n)](https://wikimedia.org/api/rest_v1/media/math/render/svg/9d2320768fb54880ca4356e61f60eb02a3f9d9f1). Although this approach optimizes the asymptotic worst-case complexity quite well, it is typically outperformed in practice by instead choosing random pivots for its average �(�)![O(n)](https://wikimedia.org/api/rest_v1/media/math/render/svg/34109fe397fdcff370079185bfdb65826cb5565a) complexity for selection and average �(�log⁡�)![O(n\log n)](https://wikimedia.org/api/rest_v1/media/math/render/svg/9d2320768fb54880ca4356e61f60eb02a3f9d9f1) complexity for sorting, without any overhead of computing the pivot.
