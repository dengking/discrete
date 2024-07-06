# Dyck language

## gpt-4o

The **Dyck language** is a formal language that consists of **balanced strings of parentheses**. It is named after the German mathematician **Walther von Dyck**. The Dyck language is an important concept in the theory of **formal languages** and **automata**, and it is often used to model **nested structures** such as those found in **programming languages**, **arithmetic expressions**, and **XML documents**.

### Definition

A string belongs to the **Dyck language** if it consists of **balanced parentheses**. For example, the strings `""` (the empty string), `"()"`, `"(())"`, and `"()()"` are all in the **Dyck language**, while the strings `"("`, `")("`, and `"(()"` are not.

### Formal Definition

The Dyck language can be defined using a context-free grammar. A common grammar for the Dyck language over the alphabet `{ '(', ')' }` is:

```
S -> ε
S -> (S)S
```

Here, `S` is the **start symbol**, and `ε` represents the **empty string**.

### Examples

- Valid strings: `""`, `"()"`, `"(())"`, `"()()"`, `"(()(()))"`
- Invalid strings: `"("`, `")"`, `"(()"`, `")("`, `"())("`

### Recognizing Dyck Language in Python

You can use a stack to recognize whether a given string belongs to the **Dyck language**. The idea is to push an opening parenthesis `(` onto the stack and pop it when a closing parenthesis `)` is encountered. If the stack is empty at the end and all parentheses have been matched correctly, the string is in the **Dyck language**.

Here's a Python function to check if a string belongs to the **Dyck language**:

```python
def is_dyck_string(s):
    stack = []
    for char in s:
        if char == '(':
            stack.append(char)
        elif char == ')':
            if not stack:
                return False
            stack.pop()
    return len(stack) == 0


if __name__ == '__main__':
    # Test cases
    print(is_dyck_string(""))  # True
    print(is_dyck_string("()"))  # True
    print(is_dyck_string("(())"))  # True
    print(is_dyck_string("()()"))  # True
    print(is_dyck_string("(()(()))"))  # True
    print(is_dyck_string("("))  # False
    print(is_dyck_string(")"))  # False
    print(is_dyck_string("(()"))  # False
    print(is_dyck_string(")("))  # False
    print(is_dyck_string("())("))  # False

```



### Push-Down Automaton for Dyck Language

A **Push-Down Automaton (PDA)** can be used to recognize the **Dyck language**. The PDA uses a stack to keep track of the parentheses.

### Summary

The Dyck language is a formal language consisting of balanced strings of parentheses. It can be defined using a **context-free grammar** and recognized using a stack-based approach or a **Push-Down Automaton (PDA)**. This concept is widely used in computer science for parsing and validating nested structures.

## wikipedia [Dyck language](https://en.wikipedia.org/wiki/Dyck_language)

In the theory of [formal languages](https://en.wikipedia.org/wiki/Formal_languages) of [computer science](https://en.wikipedia.org/wiki/Computer_science), [mathematics](https://en.wikipedia.org/wiki/Mathematics), and [linguistics](https://en.wikipedia.org/wiki/Linguistics), a **Dyck word** is a balanced [string](https://en.wikipedia.org/wiki/String_(computer_science)#Formal_theory) of brackets. The set of Dyck words forms a **Dyck language**. The simplest, D1, uses just two matching brackets, e.g. ( and ).

### Formal definition

#### Context-free grammar

$$
S \rightarrow \epsilon | '[' S ']' S
$$

$$
S \rightarrow ('[' S ']')^*
$$





### Properties

- The Dyck language is closed under the operation of [concatenation](https://en.wikipedia.org/wiki/Concatenation).

- By treating $ \Sigma ^{*} $ as an algebraic [monoid](https://en.wikipedia.org/wiki/Monoid) under concatenation we see that the monoid structure transfers onto the [quotient](https://en.wikipedia.org/wiki/Quotient_monoid) $ \Sigma ^{*}/R $, resulting in the **[syntactic monoid](https://en.wikipedia.org/wiki/Syntactic_monoid) of the Dyck language**. The class $ \operatorname {Cl} (\epsilon ) $ will be denoted $ 1 $.

- The syntactic monoid of the Dyck language is not [commutative](https://en.wikipedia.org/wiki/Commutative): if $ u=\operatorname {Cl} ([) $ and $ v=\operatorname {Cl} (]) $ then $ uv=\operatorname {Cl} ([])=1\neq \operatorname {Cl} (][)=vu $.

- With the notation above, $ uv=1 $ but neither $ u $ nor $ v $ are invertible in $ \Sigma ^{*}/R $.

- The syntactic monoid of the Dyck language is isomorphic to the [bicyclic semigroup](https://en.wikipedia.org/wiki/Bicyclic_semigroup) by virtue of the properties of $ \operatorname {Cl} ([) $ and $ \operatorname {Cl} (]) $ described above.

- By the [Chomsky–Schützenberger representation theorem](https://en.wikipedia.org/wiki/Chomsky–Schützenberger_representation_theorem), any [context-free language](https://en.wikipedia.org/wiki/Context-free_language) is a homomorphic image of the intersection of some [regular language](https://en.wikipedia.org/wiki/Regular_language) with a Dyck language on one or more kinds of bracket pairs.

  > NOTE: 提过Dyck language，引入hierarchy。

- The Dyck language with two distinct types of brackets can be recognized in the [complexity class](https://en.wikipedia.org/wiki/Complexity_class) [$ TC^{0} $](https://en.wikipedia.org/wiki/TC0).[[2\]](https://en.wikipedia.org/wiki/Dyck_language#cite_note-2)

- The number of distinct Dyck words with exactly *n* pairs of parentheses is the *n*-th [Catalan number](https://en.wikipedia.org/wiki/Catalan_number).