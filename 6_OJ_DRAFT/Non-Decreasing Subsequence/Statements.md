# Problem. Non-Decreasing Subsequence

$\begin{array}{l l}Time \; limit \; per \; test & :  1 seconds\\ Memory \; limit \; per \; test &:  512 megabytes\\Input& : standard\;  input \\Output & :standard\;  output \\ \end{array}$

给定一个二进制串，每次询问会给定一个区间 $l,r$ ，你需要回答区间内**最长不下降子序列**$^+$的长度。

$+$ 不下降子序列：形式化地，对于一个序列 $a_1,a_2,a_3,...,a_n$ ，如果存在 $i_1<i_2<...<i_k$ 使得 $a_{i_1}\leq a_{i_2}\leq...\leq a_{i_k}$ ，则称 $a_{i_1},a_{i_2},...,a_{i_k}$ 是 $a_1,a_2,a_3,...,a_n$ 的一个不下降子序列。

## Input

第一行两个整数 $n,q$ ，其中 $1\le n,q \le 1\times 10^5$，表示二进制串的长度和询问的次数。

第二行一个长度为 $n$ 的二进制串。

接下来 $q$ 行，每行两个整数 $l,r$ ，$1\le l,r \le n$ 表示一个询问。

## Output

对于每个询问，输出一个整数代表答案。

### Input Example 1

```text
3 2
010
1 3
2 3
```

### Output Example 1

```text
2
1
```
