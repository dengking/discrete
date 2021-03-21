# [Reverse individual words](https://www.geeksforgeeks.org/reverse-individual-words/)

## 问题描述

 Given a string str, we need to print reverse of individual words. 

**Examples:**

```
Input : Hello World
Output : olleH dlroW
 
Input :  Geeks for Geeks
Output : skeeG rof skeeG
```

[Recommended: Please try your approach on ***{IDE}\*** first, before moving on to the solution.](https://ide.geeksforgeeks.org/)

## 算法

**Method 1 (Simple):** Generate all words separated by space. One by one reverse words and print them separated by space.

**Method 2 (Space Efficient):** We use a stack to push all words before space. As soon as we encounter a space, we empty the stack.

```c
// C++ program to reverse individual words in a given 
// string using STL list 
#include <bits/stdc++.h> 
using namespace std; 

// reverses individual words of a string 
void reverseWords(string str) 
{ 
	stack<char> st; 

	// Traverse given string and push all characters 
	// to stack until we see a space. 
	for (int i = 0; i < str.length(); ++i) { 
		if (str[i] != ' ') 
			st.push(str[i]); 

		// When we see a space, we print contents 
		// of stack. 
		else { 
			while (st.empty() == false) { 
				cout << st.top(); 
				st.pop(); 
			} 
			cout << " "; 
		} 
	} 

	// Since there may not be space after 
	// last word. 
	while (st.empty() == false) { 
		cout << st.top(); 
		st.pop(); 
	} 
} 

// Driver program to test function 
int main() 
{ 
	string str = "Geeks for Geeks"; 
	reverseWords(str); 
	return 0; 
} 

```

 [Python | Reverse each word in a sentence](https://www.geeksforgeeks.org/python-reverse-word-sentence/) 

```c++
#include<bits/stdc++.h> 
using namespace std; 

void printWords(string str) 
{ 
	// word variable to store word 
	string word; 

	// making a string stream 
	stringstream iss(str); 

	// Read and print each word. 
	while (iss >> word){ 
		reverse(word.begin(),word.end()); 
		cout<<word<<" "; 
	} 
} 

// Driver code 
int main() 
{ 
	string s = "GeeksforGeeks is good to learn"; 
	printWords(s); 
	return 0; 
} 
// This code is contributed by Nikhil Rawat 

```

# [Reverse individual words with O(1) extra space](https://www.geeksforgeeks.org/reverse-individual-words-with-o1-extra-space/)

## 问题描述

 Given a string **str**, the task is to reverse all the individual words. 

**Examples:**

> **Input:** str = “Hello World”
> **Output:** olleH dlroW

[Recommended: Please try your approach on ***{IDE}\*** first, before moving on to the solution.](https://ide.geeksforgeeks.org/)

**Approach:** A solution to the above problem has been discussed in [this](https://www.geeksforgeeks.org/reverse-individual-words/) post. It has a time complexity of O(n) and uses O(n) extra space. In this post, we will discuss a solution which uses O(1) extra space.

- Traverse through the string until we encounter a space.
- After encountering the space, we use two variables ‘start’ and ‘end’ pointing to the first and last character of the word and we reverse that particular word.
- Repeat the above steps until the last word.

 Below is the implementation of the above approach: 

```c++
// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to resturn the string after 
// reversing the individual words 
string reverseWords(string str) 
{ 

	// Pointer to the first character 
	// of the first word 
	int start = 0; 
	for (int i = 0; i <= str.size(); i++) { 

		// If the current word has ended 
		if (str[i] == ' ' || i == str.size()) { 

			// Pointer to the last character 
			// of the current word 
			int end = i - 1; 

			// Reverse the current word 
			while (start < end) { 
				swap(str[start], str[end]); 
				start++; 
				end--; 
			} 

			// Pointer to the first character 
			// of the next word 
			start = i + 1; 
		} 
	} 

	return str; 
} 

// Driver code 
int main() 
{ 
	string str = "Geeks for Geeks"; 

	cout << reverseWords(str); 

	return 0; 
} 

```

