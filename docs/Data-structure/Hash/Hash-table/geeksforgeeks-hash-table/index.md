# geeksforgeeks hashing



## geeksforgeeks [Hashing | Set 1 (Introduction)](https://www.geeksforgeeks.org/hashing-set-1-introduction/)



## geeksforgeeks [Hashing | Set 2 (Separate Chaining)](https://www.geeksforgeeks.org/hashing-set-2-separate-chaining/)

![hashChaining](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2015/07/hashChaining1.png)



## geeksforgeeks [Load Factor and Rehashing](https://www.geeksforgeeks.org/load-factor-and-rehashing/)

### Rehashing:

As the name suggests, **rehashing means hashing again**. Basically, when the load factor increases to more than its pre-defined value (default value of load factor is 0.75), the complexity increases. So to overcome this, the size of the array is increased (doubled) and all the values are hashed again and stored in the new double sized array to maintain a low load factor and low complexity.

#### How Rehashing is done?

Rehashing can be done as follows:

1、For each addition of a new entry to the map, check the load factor.

2、If it’s greater than its pre-defined value (or default value of 0.75 if not given), then Rehash.

3、For Rehash, make a new array of double the previous size and make it the new `bucketarray`.

4、Then traverse to each element in the old `bucketArray` and call the `insert()` for each so as to insert it into the new larger bucket array.

