# [Use Parentheses for Grouping and Capturing](https://www.regular-expressions.info/brackets.html)

By placing part of a regular expression inside round brackets or parentheses, you can **group** that part of the regular expression together. This allows you to apply a [quantifier](https://www.regular-expressions.info/repeat.html) to the entire group or to restrict [alternation](https://www.regular-expressions.info/alternation.html) to part of the regex.

Only parentheses can be used for grouping. Square brackets（方括号） define a [character class](https://www.regular-expressions.info/charclass.html), and curly braces（花括号） are used by a [quantifier with specific limits](https://www.regular-expressions.info/repeat.html#limit).

## Parentheses Create Numbered Capturing Groups

Besides grouping part of a regular expression together, parentheses also create a **numbered** capturing group. It stores the part of the string matched by the part of the regular expression inside the parentheses.

The regex `Set(Value)?` matches `Set` or `SetValue`. In the first case, the first (and only) capturing group remains empty. In the second case, the first capturing group matches `Value`.

## Non-Capturing Groups

If you do not need the group to capture its match, you can optimize this regular expression into `Set(?:Value)?`. The **question mark**（问号） and the colon（冒号） after the opening parenthesis are the syntax that creates a **non-capturing group**. The question mark after the opening parenthesis is unrelated to the question mark at the end of the regex. The final question mark is the quantifier that makes the previous token [optional](https://www.regular-expressions.info/optional.html). This quantifier cannot appear after an opening parenthesis, because there is nothing to be made optional at the start of a group. Therefore, there is no ambiguity between the question mark as an operator to make a token optional and the question mark as part of the syntax for non-capturing groups, even though this may be confusing at first. There are other kinds of groups that use the `(?` syntax in combination with other characters than the colon that are explained later in this tutorial.

`color=(?:red|green|blue)` is another regex with a non-capturing group. This regex has no quantifiers.

Regex flavors that support [named capture](https://www.regular-expressions.info/named.html) often have an option to [turn all unnamed groups into non-capturing groups](https://www.regular-expressions.info/named.html#number).

> NOTE:
>
> 一、补充内容: [What is a non-capturing group in regular expressions?](https://stackoverflow.com/questions/3512471/what-is-a-non-capturing-group-in-regular-expressions) 
>
> [A](https://stackoverflow.com/a/3513858)
>
> Let me try to explain this with an example.
>
> Consider the following text:
>
> ```none
> http://stackoverflow.com/
> https://stackoverflow.com/questions/tagged/regex
> ```
>
> Now, if I apply the regex below over it...
>
> ```regex
> (https?|ftp)://([^/\r\n]+)(/[^\r\n]*)?
> ```
>
> > NOTE:
> >
> > 一、上述 `?` 的用法值得借鉴
>
> ... I would get the following result:
>
> ```
> Match "http://stackoverflow.com/"
>      Group 1: "http"
>      Group 2: "stackoverflow.com"
>      Group 3: "/"
> 
> Match "https://stackoverflow.com/questions/tagged/regex"
>      Group 1: "https"
>      Group 2: "stackoverflow.com"
>      Group 3: "/questions/tagged/regex"
> ```
>
> But I don't care about the protocol -- I just want the host and path of the URL. So, I change the regex to include the non-capturing group `(?:)`.
>
> ```regex
> (?:https?|ftp)://([^/\r\n]+)(/[^\r\n]*)?
> ```
>
> Now, my result looks like this:
>
> ```
> Match "http://stackoverflow.com/"
>      Group 1: "stackoverflow.com"
>      Group 2: "/"
> 
> Match "https://stackoverflow.com/questions/tagged/regex"
>      Group 1: "stackoverflow.com"
>      Group 2: "/questions/tagged/regex"
> ```
>
> See? The first group has not been captured. The parser uses it to match the text, but ignores it later, in the final result.
>
> ------
>
> ## EDIT:
>
> As requested, let me try to explain groups too.
>
> Well, groups serve many purposes. They can help you to extract exact information from a bigger match (which can also be named), they let you rematch a previous matched group, and can be used for substitutions. Let's try some examples, shall we?
>
> Ok, imagine you have some kind of XML or HTML (be aware that [regex may not be the best tool for the job](https://stackoverflow.com/questions/1732348/regex-match-open-tags-except-xhtml-self-contained-tags), but it is nice as an example). You want to parse the tags, so you could do something like this (I have added spaces to make it easier to understand):
>
> ```scss
>    \<(?<TAG>.+?)\> [^<]*? \</\k<TAG>\>
> or
>    \<(.+?)\> [^<]*? \</\1\>
> ```
>
> The first regex has a **named group** (TAG), while the second one uses a common group. Both regexes do the same thing: they use the value from the first group (the name of the tag) to match the closing tag. The difference is that the first one uses the name to match the value, and the second one uses the group index (which starts at 1).
>
> Let's try some substitutions now. Consider the following text:
>
> ```none
> Lorem ipsum dolor sit amet consectetuer feugiat fames malesuada pretium egestas.
> ```
>
> Now, let's use this dumb regex over it:
>
> ```regex
> \b(\S)(\S)(\S)(\S*)\b
> ```
>
> This regex matches words with at least 3 characters, and uses groups to separate the first three letters. The result is this:
>
> ```
> Match "Lorem"
>      Group 1: "L"
>      Group 2: "o"
>      Group 3: "r"
>      Group 4: "em"
> Match "ipsum"
>      Group 1: "i"
>      Group 2: "p"
>      Group 3: "s"
>      Group 4: "um"
> ...
> 
> Match "consectetuer"
>      Group 1: "c"
>      Group 2: "o"
>      Group 3: "n"
>      Group 4: "sectetuer"
> ...
> ```
>
> So, if we apply the substitution string:
>
> ```scss
> $1_$3$2_$4
> ```
>
> ... over it, we are trying to use the first group, add an underscore, use the third group, then the second group, add another underscore, and then the fourth group. The resulting string would be like the one below.
>
> ```scss
> L_ro_em i_sp_um d_lo_or s_ti_ a_em_t c_no_sectetuer f_ue_giat f_ma_es m_la_esuada p_er_tium e_eg_stas.
> ```
>
> You can use named groups for substitutions too, using `${name}`.
>
> To play around with regexes, I recommend http://regex101.com/, which offers a good amount of details on how the regex works; it also offers a few regex engines to choose from.
>
> [A](https://stackoverflow.com/a/3512530/10173843)
>
> ```scss
> ([0-9]+)(?:st|nd|rd|th)?
> ```
>
> That will match numbers in the form 1, 2, 3... or in the form 1st, 2nd, 3rd,... but it will only capture the numeric part.

## Using Text Matched By Capturing Groups

**Capturing groups** make it easy to extract part of the regex match. You can reuse the text inside the regular expression via a [backreference](https://www.regular-expressions.info/backref.html). Backreferences can also be used in replacement strings. Please check the [replacement text tutorial](https://www.regular-expressions.info/replacebackref.html) for details. 