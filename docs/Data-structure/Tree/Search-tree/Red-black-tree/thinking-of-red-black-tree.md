在各种各样的DS中都需要维持一些invariant


在red black tree中，它为什么需要为每个node赋予red、black这两种颜色呢？

显然，它这样做的目的在于便于维持整棵树的高度在于$O(ln(n))$，即保持balanced