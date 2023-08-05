# Connected-component labeling

在阅读 wikipedia [Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm) 时，它的See also中给出了这篇文章的链接，在 wikipedia [Connected-component labeling](https://en.wikipedia.org/wiki/Connected-component_labeling) 中，我又发现了之前阅读过的 [Flood fill](https://en.wikipedia.org/wiki/Flood_fill)、[Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm)，其实它们两者代表了不同的解决改问题的算法。



## wikipedia [Connected-component labeling](https://en.wikipedia.org/wiki/Connected-component_labeling) 



### Overview

**Connectivity** is determined by the medium; image graphs, for example, can be [4-connected neighborhood](https://en.wikipedia.org/wiki/4-connected_neighborhood) or [8-connected neighborhood](https://en.wikipedia.org/wiki/8-connected_neighborhood).



### Algorithms

The algorithms discussed can be generalized to arbitrary dimensions, albeit with increased time and space complexity.

> NOTE:
>
> 一、"所讨论的算法可以推广到任意维度，尽管增加了时间和空间的复杂性。"

#### One component at a time

> NOTE:
>
> 一、"One component at a time"的含义是: 一次处理一个component，具体来说，算法会根据connectivity将一个component的所有的node全部找到:
>
> > once the first pixel of a **connected component** is found, all the connected pixels of that **connected component** are labelled before going onto the next pixel in the image
>
> 从下面的算法可知，它是通过BFS来实现的，这种algorithm paradigm可以归纳为 "graph-repeated-BFS-flood-fill"。



This is a fast and very simple method to implement and understand. It is based on [graph traversal](https://en.wikipedia.org/wiki/Graph_traversal#Graph_traversal_algorithms) methods in graph theory. In short, once the first pixel of a **connected component** is found, all the connected pixels of that **connected component** are labelled before going onto the next pixel in the image. This algorithm is part of Vincent and Soille's [watershed segmentation](https://en.wikipedia.org/wiki/Watershed_(image_processing)) algorithm,[[11\]](https://en.wikipedia.org/wiki/Connected-component_labeling#cite_note-11) other implementations also exist.

> NOTE:
>
> 一、"Vincent and Soille's [watershed segmentation](https://en.wikipedia.org/wiki/Watershed_(image_processing)) algorithm"即"分水岭算法"

In order to do that a [linked list](https://en.wikipedia.org/wiki/Linked_list) is formed that will keep the indexes of the pixels that are connected to each other, steps (2) and (3) below. The method of defining the linked list specifies the use of a [depth](https://en.wikipedia.org/wiki/Depth-first_search) or a [breadth](https://en.wikipedia.org/wiki/Breadth-first_search) first search. For this particular application, there is no difference which strategy to use. The simplest kind of a [last in first out](https://en.wikipedia.org/wiki/LIFO_(computing)) queue implemented as a [singly linked list](https://en.wikipedia.org/wiki/Linked_list#Singly_linked_list) will result in a depth first search strategy.

It is assumed that the input image is a [binary image](https://en.wikipedia.org/wiki/Binary_image), with pixels being either **background** or **foreground** and that the **connected components** in the **foreground pixels** are desired. The algorithm steps can be written as:

1、Start from the first pixel in the image. Set current label to 1. Go to (2).

2、If this pixel is a **foreground pixel** and it is not already labelled, give it the current label and add it as the first element in a **queue**, then go to (3). If it is a **background pixel** or it was already labelled, then repeat (2) for the next pixel in the image.

3、Pop out an element from the queue, and look at its neighbours (based on any type of **connectivity**). If a neighbour is a foreground pixel and is not already labelled, give it the current label and add it to the queue. Repeat (3) until there are no more elements in the queue.

4、Go to (2) for the next pixel in the image and increment current label by 1.

> NOTE:
>
> 一、上述algorithm是典型的BFS

Note that the pixels are labelled before being put into the queue. The queue will only keep a pixel to check its neighbours and add them to the queue if necessary. This algorithm only needs to check the neighbours of each **foreground pixel** once and doesn't check the neighbours of **background pixels**.

The [pseudocode](https://en.wikipedia.org/wiki/Pseudocode) is :

```pseudocode
     algorithm OneComponentAtAtime(data)
     input : imageData[xDim][yDim]
     initialization : label = 0, labelArray[xDim][yDim] = 0, statusArray[xDim][yDim] = false, queue1, queue2;
     for i = 0 to xDim do 
           for j = 0 to yDim do
                 if imageData[i][j] has not been processed do
                      if imageData[i][j] is a foreground pixel do
                           check it four neighbors(north, south, east, west) :
                           if neighbor is not processed do
                                if neighbor is a foreground pixel do
                                      add it to the queue1
                                else 
                                       update its status as processed
                                end if
                                labelArray[i][j] = label (give label)
                                statusArray[i][j] = true (update status)
                                While queue1 is not empty do
                                        For each pixel in the queue do :
                                        check it fours neighbors 
                                        if neighbor is not processed do
                                             if neighbor is a foreground pixel do
                                                  add it to the queue2
                                             else
                                                    update its status as processed
                                             end if
                                             give it the current label
                                             update it status as processed
                                             remove the current element from queue1
                                             copy queue2 into queue1
                                end While
                                increase the label
                                end if
                        else
                               update its status as processed
                        end if
                 end if
               end if
             end for
     end for

```

> NOTE:
>
> 一、上述算法可以概括为: "graph-repeated-BFS-flood-fill"



#### Two-pass

Relatively simple to implement and understand, the two-pass algorithm,[[13\]](https://en.wikipedia.org/wiki/Connected-component_labeling#cite_note-Shapiro2002-13) (also known as the [Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen–Kopelman_algorithm)) iterates through 2-dimensional binary data. The algorithm makes two passes over the image: the first pass to assign temporary labels and record equivalences, and the second pass to replace each temporary label by the smallest label of its equivalence class.



## LeetCode

[LeetCode-733. 图像渲染-简单](https://leetcode.cn/problems/flood-fill/) 

[LeetCode-1034. 边框着色-中等](https://leetcode.cn/problems/coloring-a-border/) 
