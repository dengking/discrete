# geeksforgeeks [Matrix Chain Multiplication | DP-8](https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/)

## 问题描述



## 算法

**1) Optimal Substructure:**
A simple solution is to place parenthesis at all possible places, calculate the cost for each placement and return the minimum value. In a chain of matrices of size n, we can place the first set of parenthesis in n-1 ways. For example, if the given chain is of 4 matrices. let the chain be ABCD, then there are 3 ways to place first set of parenthesis outer side: (A)(BCD), (AB)(CD) and (ABC)(D). So when we place a set of parenthesis, we divide the problem into subproblems of smaller size. Therefore, the problem has optimal substructure property and can be easily solved using recursion.

Minimum number of multiplication needed to multiply a chain of size n = Minimum of all n-1 placements (these placements create subproblems of smaller size)

**2) Overlapping Subproblems**
Following is a recursive implementation that simply follows the above optimal substructure property.

### 递归

```cpp
/* A naive recursive implementation that simply 
follows the above optimal substructure property */
#include<bits/stdc++.h> 
using namespace std; 

// Matrix Ai has dimension p[i-1] x p[i] 
// for i = 1..n 
int MatrixChainOrder(int p[], int i, int j) 
{ 
	if(i == j) 
		return 0; 
	int k; 
	int min = INT_MAX; 
	int count; 

	// place parenthesis at different places 
	// between first and last matrix, recursively 
	// calculate count of multiplications for 
	// each parenthesis placement and return the 
	// minimum count 
	for (k = i; k < j; k++) 
	{ 
		count = MatrixChainOrder(p, i, k) + 
				MatrixChainOrder(p, k + 1, j) + 
				p[i - 1] * p[k] * p[j]; 

		if (count < min) 
			min = count; 
	} 

	// Return minimum count 
	return min; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, 1, n - 1); 
} 

// This code is contributed by Shivi_Aggarwal 

```

***THINKING*** : 如何记录下最优的乘法顺序呢？

Time complexity of the above naive recursive approach is exponential. It should be noted that the above function computes the same subproblems again and again. See the following recursion tree for a matrix chain of size 4. The function MatrixChainOrder(p, 3, 4) is called two times. We can see that there are many subproblems being called more than once. 

![MatrixChain](https://media.geeksforgeeks.org/wp-content/uploads/matrixchainmultiplication.png) 



###  Dynamic Programming Solution 

 Following is the implementation for Matrix Chain Multiplication problem using Dynamic Programming. 

```c++
/*
 * test.cpp
 *
 *  Created on: 2019年11月14日
 *      Author: dengkai17334
 */

// See the Cormen book for details of the
// following algorithm
#include<bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChainOrder(int p[], int n) {

	/* For simplicity of the program, one
	 extra row and one extra column are
	 allocated in m[][]. 0th row and 0th
	 column of m[][] are not used */
	int m[n][n];

	/* m[i,j] = Minimum number of scalar
	 multiplications needed to compute the
	 matrix A[i]A[i+1]...A[j] = A[i..j] where
	 dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying
	// one matrix.
	for (int i = 1; i < n; i++)
		m[i][i] = 0;
	int start;	//矩阵链的起始位置
	int end;	//矩阵链的终止位置
	int split;	//切分位置
	int chain_length;
	// chain_length is chain length.
	int multiply_time; // 乘法次数

	for (chain_length = 2; chain_length < n; chain_length++) {
		for (start = 1; start < n - chain_length + 1; start++) {
			end = start + chain_length - 1;
			m[start][end] = INT_MAX;
			for (split = start; split <= end - 1; split++) {
				// q = cost/scalar multiplications
				multiply_time = m[start][split] + m[split + 1][end]
						+ p[start - 1] * p[split] * p[end]; // 由子问题直接计算得到大问题
				if (multiply_time < m[start][end])
					m[start][end] = multiply_time;
			}
		}
	}

	return m[1][n - 1];
}

// Driver Code
int main() {
	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
			<< MatrixChainOrder(arr, size);

	getchar();
	return 0;
}

// This code is contributed
// by Akanksha Rai

```

**Time Complexity:** O(n^3)
**Auxiliary Space:** O(n^2)

[Matrix Chain Multiplication (A O(N^2) Solution)](https://www.geeksforgeeks.org/matrix-chain-multiplication-a-on2-solution/)
[**Printing brackets in Matrix Chain Multiplication Problem**](https://www.geeksforgeeks.org/printing-brackets-matrix-chain-multiplication-problem/)

Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.

**Applications:**
[Minimum and Maximum values of an expression with * and +](https://www.geeksforgeeks.org/minimum-maximum-values-expression/)

**References:**
http://en.wikipedia.org/wiki/Matrix_chain_multiplication
http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Dynamic/chainMatrixMult.htm