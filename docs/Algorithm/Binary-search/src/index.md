# binary search implementation

## [gcc](https://github.com/gcc-mirror/gcc)/[libiberty](https://github.com/gcc-mirror/gcc/tree/master/libiberty)/[**bsearch.c**](https://github.com/gcc-mirror/gcc/blob/master/libiberty/bsearch.c)

```C++
/*
 * Perform a binary search.
 *
 * The code below is a bit sneaky.  After a comparison fails, we
 * divide the work in half by moving either left or right. If lim
 * is odd, moving left simply involves halving lim: e.g., when lim
 * is 5 we look at item 2, so we change lim to 2 so that we will
 * look at items 0 & 1.  If lim is even, the same applies.  If lim
 * is odd, moving right again involes halving lim, this time moving
 * the base up one item past p: e.g., when lim is 5 we change base
 * to item 3 and make lim 2 so that we will look at items 3 and 4.
 * If lim is even, however, we have to shrink it by one before
 * halving: e.g., when lim is 4, we still looked at item 2, so we
 * have to make lim 3, then halve, obtaining 1, so that we will only
 * look at item 3.
 */
void *
bsearch (const void *key, const void *base0,
         size_t nmemb, size_t size,
         int (*compar)(const void *, const void *))
{
	const char *base = (const char *) base0;
	int lim, cmp;
	const void *p;

	for (lim = nmemb; lim != 0; lim >>= 1) {
		p = base + (lim >> 1) * size;
		cmp = (*compar)(key, p);
		if (cmp == 0)
			return (void *)p;
		if (cmp > 0) {	/* key > p: move right */
			base = (const char *)p + size;
			lim--;
		} /* else move left */
	}
	return (NULL);
}
```



## [glibc](https://code.woboq.org/userspace/glibc/)

### [glibc](https://code.woboq.org/userspace/glibc/)/[bits](https://code.woboq.org/userspace/glibc/bits/)/[stdlib-bsearch.h](https://code.woboq.org/userspace/glibc/bits/stdlib-bsearch.h.html)



```c
__extern_inline void *
bsearch (const void *__key, const void *__base, size_t __nmemb, size_t __size,
         __compar_fn_t __compar)
{
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;
  __l = 0;
  __u = __nmemb;
  while (__l < __u)
    {
      __idx = (__l + __u) / 2;
      __p = (void *) (((const char *) __base) + (__idx * __size));
      __comparison = (*__compar) (__key, __p);
      if (__comparison < 0)
        __u = __idx;
      else if (__comparison > 0)
        __l = __idx + 1;
      else
        return (void *) __p;
    }
  return NULL;
}
```

显然，上述使用的是左闭右开的binary search。

### [chromium](https://chromium.googlesource.com/?format=HTML) / [native_client](https://chromium.googlesource.com/native_client/) / [nacl-newlib](https://chromium.googlesource.com/native_client/nacl-newlib/) / [refs/heads/main](https://chromium.googlesource.com/native_client/nacl-newlib/+/refs/heads/main) / [.](https://chromium.googlesource.com/native_client/nacl-newlib/+/refs/heads/main/) / [newlib](https://chromium.googlesource.com/native_client/nacl-newlib/+/refs/heads/main/newlib) / [libc](https://chromium.googlesource.com/native_client/nacl-newlib/+/refs/heads/main/newlib/libc) / [search](https://chromium.googlesource.com/native_client/nacl-newlib/+/refs/heads/main/newlib/libc/search) / [**bsearch.c**](https://chromium.googlesource.com/native_client/nacl-newlib/+/refs/heads/main/newlib/libc/search/bsearch.c)

```C

#include <stdlib.h>
_PTR
_DEFUN (bsearch, (key, base, nmemb, size, compar),
	_CONST _PTR key _AND
	_CONST _PTR base _AND
	size_t nmemb _AND
	size_t size _AND
	int _EXFNPTR(compar, (const _PTR, const _PTR)))
{
  _PTR current;
  size_t lower = 0;
  size_t upper = nmemb;
  size_t index;
  int result;
  if (nmemb == 0 || size == 0)
    return NULL;
  while (lower < upper)
    {
      index = (lower + upper) / 2;
      current = (_PTR) (((char *) base) + (index * size));
      result = compar (key, current);
      if (result < 0)
        upper = index;
      else if (result > 0)
        lower = index + 1;
      else
	return current;
    }
  return NULL;
}
```

显然，上述使用的是左闭右开的binary search。

## recursive binary search

### geeksforgeeks [Binary Search](https://www.geeksforgeeks.org/binary-search/)

```C++
// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

