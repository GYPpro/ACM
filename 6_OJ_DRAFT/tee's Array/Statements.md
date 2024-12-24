# Problem. tee's Array

$\begin{array}{l l}Time \; limit \; per \; test & :  1 seconds\\ Memory \; limit \; per \; test &:  512 megabytes\\Input& : standard\;  input \\Output & :standard\;  output \\ \end{array}$

定义 $\text{tee}$ 数列为：
$$
f_i = \begin{cases}
1 & i = 1\\
1 & i = 2\\
a \times f_{i-1} + b\times f_{i-2} & i > 2
\end{cases}
$$

定义 $\text{tee}$ 小数为：
$$
x = \sum_{i=1}^{\infty} \frac{f_i}{10^i} = \frac{f_1}{10^1} + \frac{f_2}{10^2} + \frac{f_3}{10^3} + \cdots
$$

你的任务是，对于给定的 $a,b$ ，求$x$的**最简分数表示**$^+$。

\+ 最简分数表示：任何有理数都可以表示成 $\frac{p}{q}$ 的形式，其中 $p,q$ 互质。如果结果不是有理数，输出-1即可。

## Input

输入包含多组测试数据。

第一行包含一个整数 $t(1\le t \le 10^4)$，表示测试数据的组数。

接下来 $t$ 行，每行包含两个数 $a,b$ ，满足 $0 \le a,b \le 1\times 10^{18}$ 

## Output

对于每组测试数据，输出两个值 $p,q$ ，代表分子和分母

### Input Example 1

```text
1
1 1
```

### Output Example 1

```text
10 89
```
