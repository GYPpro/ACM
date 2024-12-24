# Problem. Non-Decreasing Substring

$\begin{array}{l l}Time \; limit \; per \; test & :  1 seconds\\ Memory \; limit \; per \; test &:  512 megabytes\\Input& : standard\;  input \\Output & :standard\;  output \\ \end{array}$

给定一个由 `0`,`1` 构成的二进制字符串，你需要构造一个新的二进制字符串，使得它符合以下三个条件。

- 新字符串的长度与原字符串相同；
- 对于任意一个区间 $l,r$ ，新串和原串在这个区间上的**不下降子串**$^+$长度应相同；
- 新串的`0`的数量尽量大。

如果有多个符合条件的解，任意输出一个即可。

$+$ 不下降子串：形式化地，对于字符串$s$和每个符合条件的区间$1\le l,r \le |s|$，会生成一个新的字符串$s' = {s_l,s_{l+1},...,s_r}$，并且满足$s_l \le s_{l+1} \le ... \le s_r$。

## Input

输入包含多组测试数据。

第一行包含一个整数 $t(1\le t \le 10^4)$，表示测试数据的组数。

接下来 $t$ 行，每行包含一个二进制字符串 $s(1\le |s| \le 10^5)$。

## Output

对于每组测试数据，输出所构造的新二进制串。

### Input Example 1

```text
2
110
0111001100111011101000
```

### Output Example 1

```text
010
0001000100001000101000
```
