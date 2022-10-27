# [LeetCode-1429. 第一个唯一数字-中等](https://leetcode.cn/problems/first-unique-number/)



解答:

1、[First Unique Number in Data Stream](https://leetcode.com/discuss/interview-question/algorithms/124822/bloomberg-interview-question-find-first-unique-integer-in-a-stream)

LRU cache logic.
We can use a doubly linked list(which will only store unique numbers and the first one in the front, pointed by the head) and a hashmap (which will have the object reference of the number). Upon seeing a duplicate, go and delete the object from the DLL.



insert(number) --> O(1)
getFirstUniqueInteger() ---> O(1)



Code:



```Python
class Node:
    def __init__(self,val):
        self.val = val
        self.prev = None
        self.next = None

class DLL:
    def __init__(self):
        self.head = Node(-1)
        self.tail = Node(-1)
        self.head.next, self.tail.prev = self.tail, self.head
        self.count = 0

    def insert(self, val):
        newNode = Node(val)
        newNode.prev = self.tail.prev 
        newNode.next = self.tail
        self.tail.prev.next = newNode
        self.tail.prev = newNode
        self.count += 1
        return newNode

    def remove(self, node):
        prev, nxt = node.prev, node.next
        node.prev.next = nxt
        node.next.prev = prev
        self.count -= 1
    
    def isEmpty(self):
        return (self.count == 0)

class firstUnique:
    def __init__(self):
        self.dll = DLL()
        self.numDict = {}
    
    def insert(self, num):
        if num in self.numDict and self.numDict[num] != -1:
            self.dll.remove(self.numDict[num])
            self.numDict[num] = -1
        else:
            self.numDict[num] = self.dll.insert(num)
    
    def getFirstUniqueInteger(self):
        if self.dll.isEmpty():
            return -1
        return self.dll.head.next.val
```



Test cases:



```
fU = firstUnique()
fU.insert(1)
print(fU.getFirstUniqueInteger()) #1
fU.insert(2)
print(fU.getFirstUniqueInteger()) #1
fU.insert(3)
print(fU.getFirstUniqueInteger()) #1
fU.insert(4)
print(fU.getFirstUniqueInteger()) #1
fU.insert(1)
print(fU.getFirstUniqueInteger()) #2
fU.insert(5)
print(fU.getFirstUniqueInteger()) #2
fU.insert(7)
print(fU.getFirstUniqueInteger()) #2
fU.insert(3)
print(fU.getFirstUniqueInteger()) #2
fU.insert(5)
print(fU.getFirstUniqueInteger()) #2
fU.insert(4)
print(fU.getFirstUniqueInteger()) #2
fU.insert(2)
print(fU.getFirstUniqueInteger()) #7
```



2、[Amazon | Phone Screen | First Unique Number in Data Stream](https://leetcode.com/discuss/interview-question/414970/Amazon-or-Phone-Screen-or-First-Unique-Number-in-Data-Stream)

Python solution using doubly linked list.
Logic is similar to the [LRU problem](https://leetcode.com/problems/lru-cache/):



- All nodes in the doubly linked list are unique and nodes closer to `self.head` appears earlier than those closer to `self.tail`, which means new node would always be added right before `self.tail`(`self.add`).
- If certain node in linked list has the value same as the value to be added(`self.hasNode`), remove that node from the linked list (`self.remove`) and add that value to `self.seen`.
- Always return the value of the node right after the head of linked list if such node exists. Otherwise, return `None`(`self.getFirstUnique`)

```
class ListNode:
    
    def __init__(self, x):
        self.val = x
        self.next = None
        self.prev = None

class Stream:
    
    def __init__(self):
        self.head = ListNode(float('-inf'))
        self.tail = ListNode(float('inf'))
        self.head.next = self.tail
        self.tail.prev = self.head
        self.seen = set()
    
    def add(self, num):
        if num not in self.seen:
            node = self.hasNode(num)
            if not node:
                insertNode = ListNode(num)
                temp = self.tail.prev
                # insert node
                insertNode.next = self.tail
                insertNode.prev = temp
                temp.next = insertNode
                self.tail.prev = insertNode
            else:
                self.removeNode(node)
                self.seen.add(num)
                
    def getFirstUnique(self):
        if self.head.next is self.tail:
            return None
        else:
            return self.head.next.val
    
    def hasNode(self, num):
        runner = self.head.next
        while runner is not self.tail:
            if runner.val == num:
                return runner
            runner = runner.next
        return None
    
    def removeNode(self, node):
        preNode = node.prev
        nexNode = node.next
        preNode.next = nexNode
        nexNode.prev = preNode
```



3、medium [[LeetCode] First Unique Number](https://medium.com/@yzhua3/leetcode-first-unique-number-191143a7ca69)



```c++
class FirstUnique {
    private Queue<Integer> queue;
    private Map<Integer,Boolean> map;
    public FirstUnique(int[] nums) {
        queue = new LinkedList<>();
        map = new HashMap<>();
        
        for (int i = 0 ; i < nums.length; i ++)
        {
            if (!map.containsKey(nums[i]))
            {
                map.put(nums[i],false);
            }
            else
            {
                map.put(nums[i],true);
            }
        }
        
        for (int i = 0 ; i < nums.length; i ++)
        {
            if (!map.get(nums[i]))
            {
                queue.add(nums[i]);
            }
        }
    }
    
    public int showFirstUnique() {
        if (queue.isEmpty()) return -1;
        int current = queue.peek();
        while (map.get(current))
        {
            queue.poll();
            if (queue.isEmpty()) return -1;
            current = queue.peek();
        }
        return current;
    }
    
    public void add(int value) {
        if (!map.containsKey(value))
        {
            map.put(value,false);
            queue.add(value);
        }
        else
        {
            map.put(value,true);
        }
    }
}
```

