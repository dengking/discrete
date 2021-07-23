# Space–time tradeoff



## infogalactic [Space-time tradeoff](https://infogalactic.com/info/Space%E2%80%93time_tradeoff)



### Types of tradeoff

#### Lookup tables vs. recalculation

> NOTE: 
>
> 这是典型的以空间，换时间换时间

The most common situation is an algorithm involving a [lookup table](https://infogalactic.com/info/Lookup_table): 

an implementation can include the entire table, which reduces computing time, but increases the amount of memory needed, or it can compute table entries as needed, increasing computing time, but reducing memory requirements.

#### Compressed vs. uncompressed data

A space–time tradeoff can be applied to the problem of data storage. If data is stored uncompressed, it takes more space but less time than if the data were stored compressed (since compressing the data reduces the amount of space it takes, but it takes time to run the [decompression algorithm](https://infogalactic.com/info/Data_compression)). Depending on the particular instance of the problem, either way is practical. There are also rare instances where it is possible to directly work with compressed data, such as in the case of compressed [bitmap indices](https://infogalactic.com/info/Bitmap_index), where it is faster to work with compression than without compression.



#### Re-rendering vs. stored images

Storing only the [LaTeX](https://infogalactic.com/info/LaTeX) source and rendering it as an image every time the page is requested would be trading time for space; more time used, but less space. Rendering the image when the page is changed and storing the rendered images would be trading space for time; more space used, but less time. This technique is more generally known as [caching](https://infogalactic.com/info/Cache_(computing)).



#### Smaller code vs. loop unrolling

Larger code size can be traded for higher program speed when applying [loop unrolling](https://infogalactic.com/info/Loop_unrolling). This technique makes the code longer for each iteration of a loop, but saves the computation time required for jumping back to the beginning of the loop at the end of each iteration.