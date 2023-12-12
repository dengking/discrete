# Sudoku solving



## wikipedia [Sudoku solving algorithms](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms#Sudoku_brute_force)

**Sudoku** ([/suːˈdoʊkuː, -ˈdɒk-, sə-/](https://en.wikipedia.org/wiki/Help:IPA/English); [Japanese](https://en.wikipedia.org/wiki/Japanese_language): 数独, [romanized](https://en.wikipedia.org/wiki/Romanization_of_Japanese): *sūdoku*, [lit.](https://en.wikipedia.org/wiki/Literal_translation) 'digit-single'; originally called **Number Place**)[[1\]](https://en.wikipedia.org/wiki/Sudoku#cite_note-time_magazine-1) is a [logic](https://en.wikipedia.org/wiki/Logic)-based,[[2\]](https://en.wikipedia.org/wiki/Sudoku#cite_note-2)[[3\]](https://en.wikipedia.org/wiki/Sudoku#cite_note-3) [combinatorial](https://en.wikipedia.org/wiki/Combinatorics)[[4\]](https://en.wikipedia.org/wiki/Sudoku#cite_note-4) number-placement [puzzle](https://en.wikipedia.org/wiki/Puzzle). In classic Sudoku, the objective is to fill a 9 × 9 grid with digits so that each column, each row, and each of the nine 3 × 3 subgrids that compose the grid (also called "boxes", "blocks", or "regions") contains all of the digits from 1 to 9. The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a single solution.

## LeetCode



### [LeetCode-36. 有效的数独](https://leetcode.cn/problems/valid-sudoku/)



### [LeetCode-37. 解数独](https://leetcode.cn/problems/sudoku-solver/)



## Sudoku Solver

[rafal-Solving Sudoku with Dancing Links](https://rafal.io/posts/solving-sudoku-with-dancing-links.html)

### [berkeley-Dancing Links and Sudoku A Java Sudoku Solver](https://www.ocf.berkeley.edu/~jchu/publicportal/sudoku/presentationboard.pdf)

> NOTE:
>
> 一、思考:为什么可以执行这种转换？

In order to apply the **Dancing Links Aglorithm** to **Sudoku**, we need a sparse matrix. To create the sparse matrix of Sudoku, we need to recognize what the rows and columns represent.

The columns represent the constraints of the puzzle. In Sudoku, we have 4:

1、A position constraint: Only 1 number can occupy a cell 

2、A row constraint: Only 1 instance of a number can be in the row 

3、A column constraint: Only 1 instance of a number can be in a column 

4、A region constraint: Only 1 instance of a number can be in a region

Therefore there are $SIZE^{2} \times 4$ columns., where $SIZE$ is the number of candidates/rows/cols. 

In a 4x4, there are 64 columns. 

In a 9x9, there are 324 columns. 

The rows represent every single possible position for every number. Therefore, there are $SIZE ^ {3}$ rows. In a 4x4, this would be 64 columns. In a 9x9, this would be 729 rows. 
