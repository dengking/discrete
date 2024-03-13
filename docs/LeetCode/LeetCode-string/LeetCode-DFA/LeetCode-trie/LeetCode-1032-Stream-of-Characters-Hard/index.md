# [LeetCode-1032. Stream of Characters-Hard](https://leetcode.cn/problems/stream-of-characters/)



## Python



```python
import unittest
from collections import deque
from typing import *


class AhoCorasickAutomataNode:
    def __init__(self, value: str = ''):
        self.value: str = value  # 当前node对应的substring
        self.next_states: Dict[str, AhoCorasickAutomataNode] = {}  # children
        self.fail_state: Optional[AhoCorasickAutomataNode] = None  # suffix link
        self.output: List[str] = []  # output link


class AhoCorasickAutomata:
    def __init__(self):
        self.root: AhoCorasickAutomataNode = AhoCorasickAutomataNode()

    def add_word(self, word: str):
        node = self.root
        for char in word:
            if char not in node.next_states:
                node.next_states[char] = AhoCorasickAutomataNode(node.value + char)
            node = node.next_states[char]
        node.output.append(word)

    def build_failure_states(self):
        queue = deque()
        for node in self.root.next_states.values():
            queue.append(node)
            node.fail_state = self.root

        while queue:
            current_node: AhoCorasickAutomataNode = queue.popleft()
            for char, next_node in current_node.next_states.items():
                queue.append(next_node)
                fail_state_node: AhoCorasickAutomataNode = current_node.fail_state
                # root node的fail_state_node是Node，所以下面的判定条件: fail_state_node is not None 表示的是到达了root node
                while fail_state_node is not None and char not in fail_state_node.next_states:
                    fail_state_node = fail_state_node.fail_state
                next_node.fail_state = fail_state_node.next_states[char] if fail_state_node else self.root
                next_node.output += next_node.fail_state.output

    def search(self, text: str, node: Optional[AhoCorasickAutomataNode] = None) -> Tuple[AhoCorasickAutomataNode, List]:
        node = node if node else self.root
        results = []
        for i in range(len(text)):
            while node is not None and text[i] not in node.next_states:
                node = node.fail_state
            if node is None:
                node = self.root
                continue
            node = node.next_states[text[i]]
            for pattern in node.output:
                results.append((i - len(pattern) + 1, pattern))
        return node, results


class StreamChecker:

    def __init__(self, words: List[str]):
        self.automata = AhoCorasickAutomata()
        self.automata_current_node = self.automata.root
        for word in words:
            self.automata.add_word(word)
        self.automata.build_failure_states()

    def query(self, letter: str) -> bool:
        self.automata_current_node, matches = self.automata.search(letter, self.automata_current_node)
        return len(matches) > 0

# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)

```

