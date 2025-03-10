# Merge k sorted arrays



## geeksforgeeks [Merge k sorted arrays | Set 1](https://www.geeksforgeeks.org/merge-k-sorted-arrays/)

> NOTE: 
>
> 1、其实和 [LeetCode-23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/) 官方解题中给出的各种思路是一致的

### Naive Approach: 暴力解法 

```C++
// C++ program to merge k sorted arrays of size n each.
#include<bits/stdc++.h>
using namespace std;
#define n 4

// A utility function to print array elements
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
void mergeKArrays(int arr[][n], int a, int output[])
{
	int c = 0;

	//traverse the matrix
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < n; j++)
			output[c++] = arr[i][j];
	}

	//sort the array
	sort(output, output + n * a);

}

// Driver program to test above functions
int main()
{
	// Change n at the top to change number of elements
	// in an array
	int arr[][n] = { { 2, 6, 12, 34 }, { 1, 9, 20, 1000 }, { 23, 34, 90, 2000 } };
	int k = sizeof(arr) / sizeof(arr[0]);

	int output[n * k];

	mergeKArrays(arr, 3, output);

	cout << "Merged array is " << endl;
	printArray(output, n * k);

	return 0;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

> NOTE: 
>
> ```C++
> test.cpp:40:18: warning: ISO C++ forbids variable length array 'output' [-Wvla]
> ```



### Efficient Approach 分治合并

```C++
// C++ program to merge k sorted arrays of size n each.
#include<bits/stdc++.h>
using namespace std;
#define n 4

// Merge arr1[0..n1-1] and arr2[0..n2-1] into
// arr3[0..n1+n2-1]
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
	int i = 0, j = 0, k = 0;

	// Traverse both array
	while (i < n1 && j < n2)
	{
		// Check if current element of first
		// array is smaller than current element
		// of second array. If yes, store first
		// array element and increment first array
		// index. Otherwise do same with second array
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	// Store remaining elements of first array
	while (i < n1)
		arr3[k++] = arr1[i++];

	// Store remaining elements of second array
	while (j < n2)
		arr3[k++] = arr2[j++];
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
void mergeKArrays(int arr[][n], int i, int j, int output[])
{
	//if one array is in range
	if (i == j)
	{
		for (int p = 0; p < n; p++)
			output[p] = arr[i][p];
		return;
	}

	//if only two arrays are left them merge them
	if (j - i == 1)
	{
		mergeArrays(arr[i], arr[j], n, n, output);
		return;
	}

	//output arrays
	int out1[n * (((i + j) / 2) - i + 1)], out2[n * (j - ((i + j) / 2))];

	//divide the array into halves
	mergeKArrays(arr, i, (i + j) / 2, out1);
	mergeKArrays(arr, (i + j) / 2 + 1, j, out2);

	//merge the output array
	mergeArrays(out1, out2, n * (((i + j) / 2) - i + 1), n * (j - ((i + j) / 2)), output);

}

// Driver program to test above functions
int main()
{
	// Change n at the top to change number of elements
	// in an array
	int arr[][n] = { { 2, 6, 12, 34 }, { 1, 9, 20, 1000 }, { 23, 34, 90, 2000 } };
	int k = sizeof(arr) / sizeof(arr[0]);
	int output[n * k];
	mergeKArrays(arr, 0, 2, output);

	cout << "Merged array is " << endl;
	printArray(output, n * k);

	return 0;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

### Alternative Efficient Approach: The idea is to use [Min Heap](https://www.geeksforgeeks.org/binary-heap/).

```C++
// C++ program to merge k sorted
// arrays of size n each.
#include<bits/stdc++.h>
using namespace std;

#define n 4

// A min-heap node
struct MinHeapNode
{
// The element to be stored
	int element;

// index of the array from which the element is taken
	int i;

// index of the next element to be picked from the array
	int j;
};

// Prototype of a utility function to swap two min-heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);

// A class for Min Heap
class MinHeap
{

// pointer to array of elements in heap
	MinHeapNode *harr;

// size of min heap
	int heap_size;
public:
	// Constructor: creates a min heap of given size
	MinHeap(MinHeapNode a[], int size);

	// to heapify a subtree with root at given index
	void MinHeapify(int);

	// to get index of left child of node at index i
	int left(int i)
	{
		return (2 * i + 1);
	}

	// to get index of right child of node at index i
	int right(int i)
	{
		return (2 * i + 2);
	}

	// to get the root
	MinHeapNode getMin()
	{
		return harr[0];
	}

	// to replace root with new node x and heapify() new root
	void replaceMin(MinHeapNode x)
	{
		harr[0] = x;
		MinHeapify(0);
	}
};

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
int* mergeKArrays(int arr[][n], int k)
{

// To store output array
	int *output = new int[n * k];

	// Create a min heap with k heap nodes.
	// Every heap node has first element of an array
	MinHeapNode *harr = new MinHeapNode[k];
	for (int i = 0; i < k; i++)
	{

// Store the first element
		harr[i].element = arr[i][0];

// index of array
		harr[i].i = i;

// Index of next element to be stored from the array
		harr[i].j = 1;
	}

// Create the heap
	MinHeap hp(harr, k);

	// Now one by one get the minimum element from min
	// heap and replace it with next element of its array
	for (int count = 0; count < n * k; count++)
	{
		// Get the minimum element and store it in output
		MinHeapNode root = hp.getMin();
		output[count] = root.element;

		// Find the next elelement that will replace current
		// root of heap. The next element belongs to same
		// array as the current root.
		if (root.j < n)
		{
			root.element = arr[root.i][root.j];
			root.j += 1;
		}
		// If root was the last element of its array
// INT_MAX is for infinite
		else
			root.element = INT_MAX;

		// Replace root with next element of array
		hp.replaceMin(root);
	}

	return output;
}

// FOLLOWING ARE IMPLEMENTATIONS OF
// STANDARD MIN HEAP METHODS FROM CORMEN BOOK
// Constructor: Builds a heap from a given
// array a[] of given size
MinHeap::MinHeap(MinHeapNode a[], int size)
{
	heap_size = size;
	harr = a; // store address of array
	int i = (heap_size - 1) / 2;
	while (i >= 0)
	{
		MinHeapify(i);
		i--;
	}
}

// A recursive method to heapify a
// subtree with root at given index.
// This method assumes that the subtrees
// are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l].element < harr[i].element)
		smallest = l;
	if (r < heap_size && harr[r].element < harr[smallest].element)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

// A utility function to swap two elements
void swap(MinHeapNode *x, MinHeapNode *y)
{
	MinHeapNode temp = *x;
	*x = *y;
	*y = temp;
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

// Driver program to test above functions
int main()
{
	// Change n at the top to change number of elements
	// in an array
	int arr[][n] = { { 2, 6, 12, 34 }, { 1, 9, 20, 1000 }, { 23, 34, 90, 2000 } };
	int k = sizeof(arr) / sizeof(arr[0]);

	int *output = mergeKArrays(arr, k);

	cout << "Merged array is " << endl;
	printArray(output, n * k);

	return 0;
}

// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



## geeksforgeeks [Merge K sorted arrays | Set 3 ( Using Divide and Conquer Approach )](https://www.geeksforgeeks.org/merge-k-sorted-arrays-set-3-using-divide-and-conquer-approach/)