# Randomized algorithm

在下面算法、数据结构中，使用了randomized algorithm:

1、quick sort

2、skip list

3、Stochastic-Gradient-Descent

## wikipedia [Randomized algorithm](https://en.wikipedia.org/wiki/Randomized_algorithm)

## Gemini 2.5 Pro Randomized algorithm

Of course. **Randomized algorithms** are a fascinating and powerful class of algorithms that incorporate an element of randomness as part of their logic. Unlike deterministic algorithms, which follow a predictable sequence of steps for a given input, a randomized algorithm will behave differently each time it is run, even on the exact same input.

This might sound like a disadvantage, but it's often a brilliant trade-off that can lead to simpler, faster, or more robust solutions.

### The Core Idea

A **deterministic algorithm** is like a perfect recipe: follow the steps exactly, and you'll get the same cake every time.

A **randomized algorithm** is like a chef who, at a certain step, decides to "grab a random spice from the rack." The resulting dish might be slightly different each time, but it's often excellent and the process might be much faster than meticulously measuring a complex blend of 20 specific spices.

### Why Use Randomness? The Main Advantages

1. **Simplicity:** Randomized algorithms can be significantly simpler to design and implement than the best known deterministic algorithms for the same problem.
2. **Performance:** They are often faster. While their worst-case performance might be poor, the probability of the worst-case actually happening is infinitesimally small. Their *expected* or *average-case* performance is typically excellent.
3. **Avoiding Worst-Case Scenarios:** This is a key benefit. Many deterministic algorithms have a "kryptonite" input that forces them into their worst-case performance (e.g., a sorted array for a naive Quicksort). An adversary could intentionally provide this input. By introducing randomness, the algorithm's performance no longer depends on the input pattern, but on the random choices it makes. It effectively defeats the adversary.

---

### Types of Randomized Algorithms

There are two main categories, distinguished by what they guarantee.

#### 1. Las Vegas Algorithms

A Las Vegas algorithm **always produces the correct answer**, but its running time is a random variable. It trades certainty in runtime for guaranteed correctness.

* **Analogy:** A meticulous gambler who plays until they win. You know they will eventually win (get the right answer), but you don't know if it will take one game or a hundred.
* **Guarantee:** The answer is always correct.
* **Uncertainty:** The execution time varies. We analyze its *expected* runtime.

**Classic Example: Randomized Quicksort**

* **Problem:** Sort an array.
* **Deterministic Quicksort:** Always picks the last element as the pivot. If the array is already sorted, this leads to the worst-case $O(n^2)$ time.
* **Randomized Quicksort:** Instead of a fixed pivot, it picks a **random element** from the array to be the pivot.
* **Why it's Las Vegas:**
  * It *always* correctly sorts the array.
  * The runtime depends on how "good" the random pivots are. On average, the pivots will be reasonably balanced, leading to an expected runtime of $O(n \log n)$. The chance of consistently picking bad pivots and hitting the $O(n^2)$ worst case is astronomically low for a large array.

#### 2. Monte Carlo Algorithms

A Monte Carlo algorithm has a **deterministic (fixed) running time**, but its answer has a small probability of being incorrect. It trades correctness for guaranteed runtime.

* **Analogy:** A speed-chess player who has one minute per game. They will always finish in one minute, but they might make a mistake and lose.
* **Guarantee:** The execution time is fixed.
* **Uncertainty:** The answer might be wrong with a known, small probability. This error can usually be reduced by running the algorithm multiple times.

**Classic Example: Estimating the value of $\pi$**

* **Problem:** Calculate $\pi$.
* **Monte Carlo Method:**
  1. Imagine a 1x1 square with a quarter-circle of radius 1 inscribed in it.
  2. The area of the square is $1^2 = 1$.
  3. The area of the quarter-circle is $\frac{1}{4} \pi r^2 = \frac{\pi}{4}$.
  4. The ratio of the areas is $\frac{\text{Area of Quarter-Circle}}{\text{Area of Square}} = \frac{\pi/4}{1} = \frac{\pi}{4}$.
  5. **Algorithm:**
     * Generate a large number, $N$, of random points $(x, y)$ inside the square.
     * Count how many of those points, $C$, also fall inside the quarter-circle. A point is inside if $x^2 + y^2 \le 1$.
     * The ratio $\frac{C}{N}$ should approximate the ratio of the areas, $\frac{\pi}{4}$.
     * Therefore, $\pi \approx 4 \times \frac{C}{N}$.
* **Why it's Monte Carlo:**
  * The runtime is fixed (it depends on how many points, $N$, you decide to generate).
  * The answer is an approximation. The more points you generate, the lower the probability of a significant error.

---

### More Famous Examples

1. **Miller-Rabin Primality Test (Monte Carlo):** A cornerstone of modern cryptography (e.g., in RSA). It determines if a large number is prime.
   
   * If the algorithm says "composite," the number is **definitely composite**.
   * If it says "probably prime," there is a tiny, controllable probability it's actually composite. By running the test multiple times, this probability can be made smaller than the chance of a hardware error.

2. **Karger's Min-Cut Algorithm (Monte Carlo):** Finds the minimum cut (the smallest number of edges that can be removed to split a graph into two components). The algorithm is stunningly simple: repeatedly pick a random edge and contract it until only two vertices remain. The edges between them are a cut. This process is repeated, and the smallest cut found is returned as the answer.

### Summary: Advantages vs. Disadvantages

| Advantages                                                                                                      | Disadvantages                                                                                                                                                   |
|:--------------------------------------------------------------------------------------------------------------- |:--------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Simplicity:** Often much easier to design and code.                                                           | **Non-Deterministic:** The same input can produce different behavior/results, making debugging harder.                                                          |
| **Speed:** Excellent average-case or expected performance.                                                      | **Possibility of Error (Monte Carlo):** There's a chance the answer is wrong, which may not be acceptable for all applications.                                 |
| **Robustness to Input:** Avoids worst-case performance traps by relying on randomness, not input patterns.      | **Unbounded Runtime (Las Vegas):** While highly improbable, the algorithm could theoretically run for a very long time.                                         |
| **Wide Applicability:** Used in cryptography, machine learning, data structures (skip lists), and optimization. | **Complex Analysis:** Proving the correctness and performance bounds requires probability theory, which can be more difficult than standard algorithm analysis. |

## Books about randomized algorithm

A foundational and highly-regarded book is "Randomized Algorithms" by Rajeev Motwani and Prabhakar Raghavan, which covers the design and analysis of these algorithms for advanced students and professionals. For a more hands-on and practical approach, "The Art of Randomness" by Ronald T. Kneusel focuses on applying randomized algorithms to real-world problems using Python. Other options include specialized books like "Concentration of Measure for the Analysis of Randomized Algorithms" for a theoretical focus and "Math Girls 4: Randomized Algorithms" for a more accessible, story-based introduction.

## mit course [Randomized Algorithms](https://ocw.mit.edu/courses/6-856j-randomized-algorithms-fall-2002/)
