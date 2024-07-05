# Percentage 



## stackoverflow [Regular Expression for Percentage of marks](https://stackoverflow.com/questions/30072184/regular-expression-for-percentage-of-marks)



### [A](https://stackoverflow.com/a/30072239)

You haven't double-escaped your dot, which means it's a wildcard for any character, including whitespace.

Use something like:

```java
 ┌ integer part - any 1+ number of digits
 |   ┌ dot and decimal part (grouped)
 |   |┌ double-escaped dot
 |   ||  ┌ decimal part = any 1+ number of digits
 |   ||  |    ┌ 0 or 1 greedy quantifier for whole group
 |   ||  |    |
"\\d+(\\.\\d+)?%"
```

For instance:

```java
String[] inputs = { "100%", "56.78%", "56 78.90%", "34.6789%" };
Matcher m = null;
for (String s: inputs) {
    m = p.matcher(s);
    if (m.find())
        System.out.printf("Found: %s%n", m.group());
}
```

**Output**

```java
Found: 100%
Found: 56.78%
Found: 78.90%
Found: 34.6789%
```

**Note**

This still matches the 3rd input, but only the last part.

If you want the 3rd input to just not match, you can surround your pattern with input boundaries, such as `^` for start of input, and `$` for end of input.

That would become: `"^\\d+(\\.\\d+)?%$"`

Or, you can simply invoke `Matcher#matches` instead of `Matcher#find`.

**Next step**

You may want to do *something* with the numerical value you're retrieving.

In this case, you can surround your pattern with a group (`"(\\d+(\\.\\d+)?)%"`) and invoke either `Double.parseDouble` or `new BigDecimal(...)` on your back-reference:

- `Double.parseDouble(m.group(1))`
- `new BigDecimal(m.group(1))`