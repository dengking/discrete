# wikipedia [Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi)	

The **Tower of Hanoi** (also called the **Tower of Brahma** or **Lucas' Tower**[[1\]](https://en.wikipedia.org/wiki/Tower_of_Hanoi#cite_note-1) and sometimes pluralized as **Towers**) is a [mathematical game](https://en.wikipedia.org/wiki/Mathematical_game) or [puzzle](https://en.wikipedia.org/wiki/Puzzle). It consists of three rods and a number of disks of different sizes, which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a [conical](https://en.wikipedia.org/wiki/Cone)（锥形） shape.

The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
3. No larger disk may be placed on top of a smaller disk.

With 3 disks, the puzzle can be solved in 7 moves. The minimal number of moves required to solve a Tower of Hanoi puzzle is $2^n − 1$, where *n* is the number of disks.



## Solution

The puzzle can be played with any number of disks, although many toy versions have around 7 to 9 of them. The minimal number of moves required to solve a Tower of Hanoi puzzle is $2^n − 1$, where $n$ is the number of disks.[[5\]](https://en.wikipedia.org/wiki/Tower_of_Hanoi#cite_note-5) This is precisely the *n*th [Mersenne number](https://en.wikipedia.org/wiki/Mersenne_number).

> NOTE : 按照我的实践来看，解决这个问题的确是存在递归的过程的：比如有A、B、C三个rob，要移动A上的n个disk到B上；显然首先需要将A上的前n-1个disk移动到C rob上；然后将A上的第n个disk移动到B上；然后将C上的n-1个disk移动到B上；这样就完成了全部的移动；显然按照这个描述，其实就已经能够写出递归公式了：
>
> $ \operatorname {hanoi} (n)={\begin{cases}1&{\mbox{if }}n=1\\2\cdot \operatorname {hanoi} (n-1)+1&{\mbox{if }}n>1\\\end{cases}} $
>
> 上式中的2是因为前n-1个disk被移动两次。1是因为需要将disk n移动到目标rob；
>
> 比如n=1，则直接移动到B上即可；
>
> 比如n=2，则先将disk 1移动到C，然后将disk 2移动到B，然后将disk 1移动到B；
>
> 比如n=3，则先将disk 1和disk 2移动到C，然后再将disk 3移动到B，然后将disk 1和disk 2从C移动到B；





### Iterative solution

A simple solution for the toy puzzle is to alternate moves between the smallest piece and a non-smallest piece. When moving the smallest piece, always move it to the next position in the same direction (to the right if the starting number of pieces is even, to the left if the starting number of pieces is odd). If there is no tower position in the chosen direction, move the piece to the opposite end, but then continue to move in the correct direction. For example, if you started with three pieces, you would move the smallest piece to the opposite end, then continue in the left direction after that. When the turn is to move the non-smallest piece, there is only one legal move. Doing this will complete the puzzle in the fewest moves.[[6\]](https://en.wikipedia.org/wiki/Tower_of_Hanoi#cite_note-6)



### Recursive solution

The key to solving a problem recursively is to recognize that it can be broken down into a collection of smaller sub-problems, to each of which *that same general solving procedure that we are seeking* applies, and the total solution is then found in some *simple* way from those sub-problems' solutions. Each of thus created sub-problems being "smaller" guarantees that the base case(s) will eventually be reached. Thence, for the Towers of Hanoi:

- label the pegs A, B, C,
- let *n* be the total number of disks,
- number the disks from 1 (smallest, topmost) to *n* (largest, bottom-most).

Assuming all *n* disks are distributed in valid arrangements among the pegs; assuming there are *m* top disks on a *source* peg, and all the rest of the disks are larger than *m*, so they can be safely ignored; to move *m* disks from a source peg to a *target* peg using a *spare* peg, without violating the rules:

1. Move *m* − 1 disks from the **source** to the **spare** peg, by *the same general solving procedure*. Rules are not violated, by assumption. This leaves the disk *m* as a top disk on the source peg.
2. Move the disk *m* from the **source** to the **target** peg, which is guaranteed to be a valid move, by the assumptions — *a simple step*.
3. Move the *m* − 1 disks that we have just placed on the spare, from the **spare** to the **target** peg by *the same general solving procedure*, so they are placed on top of the disk *m* without violating the rules.
4. The base case being to move *0* disks (in steps 1 and 3), that is, do nothing – which obviously doesn't violate the rules.

The full Tower of Hanoi solution then consists of moving *n* disks from the source peg A to the target peg C, using B as the spare peg.

This approach can be given a rigorous mathematical proof with [mathematical induction](https://en.wikipedia.org/wiki/Mathematical_induction) and is often used as an example of recursion when teaching programming.

#### Logical analysis of the recursive solution

As in many mathematical puzzles, finding a solution is made easier by solving a slightly more general problem: how to move a tower of *h* (height) disks from a starting peg *f* = **A** (from) onto a destination peg *t* = **C** (to), **B** being the remaining third peg and assuming *t* ≠ *f*. First, observe that the problem is symmetric for permutations of the names of the pegs ([symmetric group *S*3](https://en.wikipedia.org/wiki/Symmetric_group)). If a solution is known moving from peg **A** to peg **C**, then, by renaming the pegs, the same solution can be used for every other choice of starting and destination peg. If there is only one disk (or even none at all), the problem is trivial. If *h* = 1, then simply move the disk from peg **A** to peg **C**. If *h* > 1, then somewhere along the sequence of moves, the largest disk must be moved from peg **A** to another peg, preferably to peg **C**. The only situation that allows this move is when all smaller *h* − 1 disks are on peg **B**. Hence, first all *h* − 1 smaller disks must go from **A** to **B**. Then move the largest disk and finally move the *h* − 1 smaller disks from peg **B**to peg **C**. The presence of the largest disk does not impede any move of the *h* − 1 smaller disks and can be temporarily ignored. Now the problem is reduced to moving *h* − 1 disks from one peg to another one, first from **A** to **B** and subsequently from **B** to **C**, but the same method can be used both times by renaming the pegs. The same strategy can be used to reduce the *h* − 1 problem to *h* − 2, *h* − 3, and so on until only one disk is left. This is called recursion. This algorithm can be schematized as follows.

Identify the disks in order of increasing size by the natural numbers from 0 up to but not including *h*. Hence disk 0 is the smallest one, and disk *h* − 1 the largest one.

The following is a procedure for moving a tower of *h* disks from a peg **A** onto a peg **C**, with **B** being the remaining third peg:

1. If *h* > 1, then first use this procedure to move the *h* − 1 smaller disks from peg **A** to peg **B**.
2. Now the largest disk, i.e. disk *h* can be moved from peg **A** to peg **C**.
3. If *h* > 1, then again use this procedure to move the *h* − 1 smaller disks from peg **B** to peg **C**.

By means of [mathematical induction](https://en.wikipedia.org/wiki/Mathematical_induction), it is easily proven that the above procedure requires the minimal number of moves possible, and that the produced solution is the only one with this minimal number of moves. Using [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation), the exact number of moves that this solution requires can be calculated by: $ 2^{h}-1 $. This result is obtained by noting that steps 1 and 3 take $ T_{h-1} $ moves, and step 2 takes one move, giving $ T_{h}=2T_{h-1}+1 $.



#### Recursive implementation

The following highlights an essential function of the recursive solution, which may be otherwise misunderstood or overlooked. That is, with every level of recursion, the first recursive call inverts the *target* and *auxiliary* stacks, while in the second recursive call the *source* and *auxiliary* stacks are inverted.

```python
A = [3, 2, 1]
B = []
C = []

def move(n, source, target, auxiliary):
    if n > 0:
        # move n - 1 disks from source to auxiliary, so they are out of the way
        move(n - 1, source, auxiliary, target)

        # move the nth disk from source to target
        target.append(source.pop())

        # Display our progress
        print(A, B, C, '##############', sep = '\n')

        # move the n - 1 disks that we left on auxiliary onto target
        move(n - 1, auxiliary, target, source)

# initiate call from source A to target C with auxiliary B
move(3, A, C, B)
```

The following code implements more **recursive functions** for a text-based animation:

```python
import time

A = [i for i in range(5, 0, -1)]
height = len(A)-1 #stable height value for animation
B = []
C = []

def move(n, source, target, auxiliary):
    if n > 0:
        # move n - 1 disks from source to auxiliary, so they are out of the way
        move(n - 1, source, auxiliary, target)

        # move the nth disk from source to target
        target.append(source.pop())

        # Display our progress using a recursive function to draw it out
        drawDisks(A, B, C, height)
        print("") #provide spacing
        time.sleep(0.3) #pause for a moment to animate

        # move the n - 1 disks that we left on auxiliary onto target
        move(n - 1, auxiliary, target, source)

def drawDisks(A, B, C, position, width = 2 * int(max(A))):
    #width parameter defaults to double of the largest sized disk in the initial tower.
    if position >= 0:
        #if A has a value in the list at the given position, create a disk at its position (height)
        valueInA = " " if position >= len(A) else createDisk(A[position])
        #same for B and C
        valueInB = " " if position >= len(B) else createDisk(B[position])
        valueInC = " " if position >= len(C) else createDisk(C[position])

        #print each row
        print("{0:^{width}}{1:^{width}}{2:^{width}}".format(valueInA, valueInB, valueInC, width=width))

        #recursivly call this method again to the next position (height)
        drawDisks(A, B, C, position-1, width)
    else:
        #when done with recurisve, print column labels
        print("{0:^{width}}{1:^{width}}{2:^{width}}".format("A", "B", "C", width=width))

def createDisk(size):
    '''simple recursive method to create a slanted disk.'''
    if size==1:
        return "/\\"
    else:
        return "/" + createDisk(size-1) + "\\"

# initiate call from source A to target C with auxiliary B
move(len(A), A, B, C)
```

