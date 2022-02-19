# binary search complexity analysis

## stackoverflow [how to calculate binary search complexity](https://stackoverflow.com/questions/8185079/how-to-calculate-binary-search-complexity)

I heard somebody say that since binary search halves the input required to search hence it is log(n) algorithm. Since I am not from a mathematics background I am not able to relate to it. Can somebody explain it in a little more detail? does it have to do something with the logarithmic series? 

### [A](https://stackoverflow.com/questions/8185079/how-to-calculate-binary-search-complexity/8185382#8185382)

Here a more mathematical way of seeing it, though not really complicated. IMO much clearer as informal ones:

  

The question is, how many times can you divide N by 2 until you have 1? This is essentially saying, do a binary search (half the elements) until you found it. In a formula this would be this:


$$
1 = N / 2^x
$$


multiply by 2x:


$$
2^x = N
$$


now do the $log_2$:


$$
log_2{(2^x)}    = log_2{ N} \\
    x * log_2{(2)} = log_2{ N} \\
    x * 1         = log_2{ N}\\
$$


this means you can divide log N times until you have everything divided. Which means you have to divide $log N$ ("do the binary search step") until you found your element.