# Pushdown automaton

中文翻译做: "下推自动机"

---

> References: 
>
> [zhihu-[笔记]下推自动机](https://zhuanlan.zhihu.com/p/669440520) (通俗易懂)
>
> [baike-下推自动机](https://baike.baidu.com/item/%E4%B8%8B%E6%8E%A8%E8%87%AA%E5%8A%A8%E6%9C%BA/10988477?fr=ge_ala) 

---

## gpt-4o

A **Push-Down Automaton (PDA)** is a type of computational model that extends the capabilities of a **finite automaton** by adding a **stack** as an auxiliary storage. This additional stack allows the PDA to recognize a broader class of languages known as **context-free languages**, which include languages that finite automata cannot recognize, such as the **Dyck language** (balanced parentheses).

### Components of a Push-Down Automaton

A PDA can be formally defined as a 7-tuple:

$$
M = (Q, \Sigma, \Gamma, \delta, q_0, Z_0, F)
$$


where:
-  $Q$  is a finite set of states.
- $\Sigma$ is a finite set of input symbols (input alphabet).
-  $\Gamma$  is a finite set of stack symbols (stack alphabet).
- \( $\delta$ \) is the transition function: \( $\delta : Q \times (\Sigma \cup \{\epsilon\}) \times \Gamma \rightarrow \mathcal{P}(Q \times \Gamma^*)$ \).
- \( $q_0$ \) is the initial state.
- \( $Z_0$ \) is the initial stack symbol.
- \( $F$ \) is the set of accepting states.

### How a PDA Works

- The PDA reads an input string symbol by symbol.
- It uses the stack to keep track of additional information.
- The transition function \( $\delta$ \) determines the next state, the symbol to push onto or pop from the stack, based on the current state, the current input symbol, and the top symbol of the stack.
- The PDA accepts the input string if it reaches an accepting state and the stack is in an appropriate configuration (depending on the type of acceptance criteria).

### Types of Acceptance

A PDA can accept a string in two ways:
1. **Acceptance by final state**: The PDA accepts the input string if it reaches an accepting state after reading the entire input.
2. **Acceptance by empty stack**: The PDA accepts the input string if the stack is empty after reading the entire input.

### Example: PDA for Balanced Parentheses

Let's design a PDA to recognize the Dyck language (balanced parentheses).

#### States
- \( $Q = \{q_0, q_1\}$ \)
- \( $q_0$ \) is the initial state.
- \( $q_1$ \) is the accepting state.

#### Input Alphabet
- \( $\Sigma = \{(, )\}$ \)

#### Stack Alphabet
- \( $\Gamma = \{Z_0, ( \}$ \)
- \( $Z_0$ \) is the initial stack symbol.

#### Transition Function
The transition function \( \delta \) can be defined as follows:
- \( \delta(q_0, (, Z_0) = \{(q_0, (Z_0)\} \)
- \( \delta(q_0, (, () = \{(q_0, (( )\} \)
- \( \delta(q_0, ), () = \{(q_0, \epsilon)\} \)
- \( \delta(q_0, \epsilon, Z_0) = \{(q_1, Z_0)\} \)

#### Accepting States
- \( F = \{q_1\} \)

### Python Simulation of PDA

Here's a simple Python simulation of a PDA for balanced parentheses:

```python
class PDA:
    def __init__(self):
        self.stack = []
        self.state = 'q0'
    
    def transition(self, char):
        if self.state == 'q0':
            if char == '(':
                self.stack.append('(')
            elif char == ')' and self.stack:
                self.stack.pop()
            else:
                self.state = 'reject'
    
    def is_accepted(self):
        return self.state == 'q0' and not self.stack

def is_balanced_parentheses(s):
    pda = PDA()
    for char in s:
        pda.transition(char)
    return pda.is_accepted()

# Test cases
print(is_balanced_parentheses(""))        # True
print(is_balanced_parentheses("()"))      # True
print(is_balanced_parentheses("(())"))    # True
print(is_balanced_parentheses("()()"))    # True
print(is_balanced_parentheses("(()(()))"))# True
print(is_balanced_parentheses("("))       # False
print(is_balanced_parentheses(")"))       # False
print(is_balanced_parentheses("(()"))     # False
print(is_balanced_parentheses(")("))      # False
print(is_balanced_parentheses("())("))    # False
```

### Summary

A Push-Down Automaton (PDA) is a computational model that extends finite automata with a stack, allowing it to recognize context-free languages. PDAs are useful for parsing nested structures, such as balanced parentheses, and are fundamental in the theory of formal languages and automata.

## wikipedia [Pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton)

In the [theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation), a branch of [theoretical computer science](https://en.wikipedia.org/wiki/Theoretical_computer_science), a **pushdown automaton** (**PDA**) is a type of [automaton](https://en.wikipedia.org/wiki/Automata_theory) that employs a [stack](https://en.wikipedia.org/wiki/Stack_(data_structure)).

**Pushdown automata** are used in theories about what can be computed by machines. They are more capable than [finite-state machines](https://en.wikipedia.org/wiki/Finite-state_machine) but less capable than [Turing machines](https://en.wikipedia.org/wiki/Turing_machine). [Deterministic pushdown automata](https://en.wikipedia.org/wiki/Deterministic_pushdown_automata) can recognize all [deterministic context-free languages](https://en.wikipedia.org/wiki/Deterministic_context-free_language) while nondeterministic ones can recognize all [context-free languages](https://en.wikipedia.org/wiki/Context-free_language), with the former often used in [parser](https://en.wikipedia.org/wiki/Parser) design.

The term "pushdown" refers to the fact that the [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) can be regarded as being "pushed down" like a tray dispenser at a cafeteria, since the operations never work on elements other than the top element. A **stack automaton**, by contrast, does allow access to and operations on deeper elements. Stack automata can recognize a strictly larger set of languages than pushdown automata.[[1\]](https://en.wikipedia.org/wiki/Pushdown_automaton#cite_note-Hopcroft.Ullman.1967-1) A [nested stack automaton](https://en.wikipedia.org/wiki/Nested_stack_automaton) allows full access, and also allows stacked values to be entire sub-stacks rather than just single finite symbols.

### Informal description

A [finite state machine](https://en.wikipedia.org/wiki/Finite_state_machine) just looks at the **input signal** and the **current state**: it has no stack to work with. It chooses a new state, the result of following the transition. A **pushdown automaton (PDA)** differs from a finite state machine in two ways:

1. It can use the top of the stack to decide which transition to take.
2. It can manipulate the stack as part of performing a transition.

A **pushdown automaton** reads a given input string from left to right. In each step, it chooses a transition by indexing a table by input symbol, current state, and the symbol at the top of the stack. A pushdown automaton can also manipulate the stack, as part of performing a transition. The manipulation can be to push a particular symbol to the top of the stack, or to pop off the top of the stack. The automaton can alternatively ignore the stack, and leave it as it is.

Put together: Given an input symbol, current state, and stack symbol, the automaton can follow a transition to another state, and optionally manipulate (push or pop) the stack.

> NOTE: In fact, without concrete example,  the above description is very difficult to understand. A LL parser is a typical **pushdown automaton**, the Wikipedia entry [LL parser](https://en.wikipedia.org/wiki/LL_parse) give an concrete and concise [example](https://en.wikipedia.org/wiki/LL_parser#Concrete_example) to explain the mechanism of thee parser, that is **pushdown automaton**. After reading it, I think you will grasp what above paragraph describe.



[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/7/71/Pushdown-overview.svg/340px-Pushdown-overview.svg.png)](https://en.wikipedia.org/wiki/File:Pushdown-overview.svg)

> A diagram of a pushdown automaton



## wikipedia [Deterministic pushdown automaton](https://en.wikipedia.org/wiki/Deterministic_pushdown_automaton)

