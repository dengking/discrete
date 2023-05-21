# Connected-component labeling

在阅读 wikipedia [Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm) 时，它的See also中给出了这篇文章的链接，在 wikipedia [Connected-component labeling](https://en.wikipedia.org/wiki/Connected-component_labeling) 中，我又发现了之前阅读过的 [Flood fill](https://en.wikipedia.org/wiki/Flood_fill)、[Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm)，其实它们两者代表了不同的解决改问题的算法。



## wikipedia [Connected-component labeling](https://en.wikipedia.org/wiki/Connected-component_labeling)



### Algorithms

The algorithms discussed can be generalized to arbitrary dimensions, albeit with increased time and space complexity.

> NOTE:
>
> 一、"所讨论的算法可以推广到任意维度，尽管增加了时间和空间的复杂性。"

#### One component at a time

This is a fast and very simple method to implement and understand. It is based on [graph traversal](https://en.wikipedia.org/wiki/Graph_traversal#Graph_traversal_algorithms) methods in graph theory. In short, once the first pixel of a **connected component** is found, all the connected pixels of that **connected component** are labelled before going onto the next pixel in the image. This algorithm is part of Vincent and Soille's [watershed segmentation](https://en.wikipedia.org/wiki/Watershed_(image_processing)) algorithm,[[11\]](https://en.wikipedia.org/wiki/Connected-component_labeling#cite_note-11) other implementations also exist.



#### Two-pass

Relatively simple to implement and understand, the two-pass algorithm,[[13\]](https://en.wikipedia.org/wiki/Connected-component_labeling#cite_note-Shapiro2002-13) (also known as the [Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen–Kopelman_algorithm)) iterates through 2-dimensional binary data. The algorithm makes two passes over the image: the first pass to assign temporary labels and record equivalences, and the second pass to replace each temporary label by the smallest label of its equivalence class.

