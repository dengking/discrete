# CamelCase、`under_score_case` 、`snake_case` 

## wikipedia [Snake case](https://en.wikipedia.org/wiki/Snake_case)



## wikipedia [Camel case](https://en.wikipedia.org/wiki/Camel_case)



## superuser [Use Notepad++ to change under_score_case to CamelCase?](https://superuser.com/questions/312073/use-notepad-to-change-under-score-case-to-camelcase)

### [A](https://superuser.com/a/1002297)

A simple find/replace will do this in NP++:

**Find:** `[_]{1,1}([a-z])`

**Replace:** `\U$1`

You need to select the 'Regular expression' radio button in the Replace panel for this to work.

## stackexchange [Transform snake_case to camelCase](https://codereview.stackexchange.com/questions/85311/transform-snake-case-to-camelcase)



### [A](https://codereview.stackexchange.com/a/85332)

Using regex,

```python
import re
def getJavaName(column):
    return re.sub('_.',lambda x: x.group()[1].upper(),column)
```

### [A](https://codereview.stackexchange.com/a/85334)

Consider writing this as a one-liner regular expression substitution instead.

```python
import re

def get_java_name(column_name):
    return re.sub('_([a-z])', lambda match: match.group(1).upper(), column_name)
```

Since the function is Python code, it should still adhere to PEP 8 naming conventions — `get_java_name()` instead of `getJavaName()`.

## stackoverflow [How can I simplify this conversion from underscore to camelcase in Python?](https://stackoverflow.com/questions/4303492/how-can-i-simplify-this-conversion-from-underscore-to-camelcase-in-python)