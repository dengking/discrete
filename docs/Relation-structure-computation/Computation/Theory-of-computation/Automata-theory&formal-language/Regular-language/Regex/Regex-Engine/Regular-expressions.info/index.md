# [regular-expressions.info](https://www.regular-expressions.info/)



## Capturing group VS non-capturing group VS look around



### stackoverflow [what is the difference between ?:, ?! and ?= in regex?](https://stackoverflow.com/questions/10804732/what-is-the-difference-between-and-in-regex)



[A](https://stackoverflow.com/a/10804791/10173843)

| regex | meaning              |
| ----- | -------------------- |
| `?:`  | non capturing group  |
| `?=`  | positive look ahead  |
| `?!`  | negative look ahead  |
| `?<=` | positive look behind |
| `?<!` | negative look behind |



[A](https://stackoverflow.com/a/38963903/10173843)

| regex  |                     |                                                              |
| ------ | ------------------- | ------------------------------------------------------------ |
| `()`   | capturing group     | the regex inside the parenthesis must be matched and the match create a capturing group |
| `(?:)` | non-capturing group | the regex inside the parenthesis must be matched but does not create the capturing group |
| `(?=)` | positive lookahead  | asserts that the regex must be matched                       |
| `(?!)` | negative lookahead  | asserts that it is impossible to match the regex             |

