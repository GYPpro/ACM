# Problem. tee's Array

$\begin{array}{l l}Time \; limit \; per \; test & :  1 seconds\\ Memory \; limit \; per \; test &:  512 megabytes\\Input& : standard\;  input \\Output & :standard\;  output \\ \end{array}$

给定两个数a,b。如果$\lfloor \frac{a}{b} \rfloor = \lceil \frac{a}{b} \rceil$，输出`Yes`，否则输出`No`。

## Input

输入包含多组测试数据。

第一行包含一个整数 $t(1\le t \le 10^4)$，表示测试数据的组数。

接下来 $t$ 行，每行包含两个数 $a,b$ ，满足 $0 \le a,b \le 1\times 10^{18}$ 

## Output

对于每组测试数据，输出`Yes`或`No`。

$^+$ 输出大小写敏感。

### Input Example 1

```text
1
2 1
3 2
```

### Output Example 1

```text
Yes
No
```
