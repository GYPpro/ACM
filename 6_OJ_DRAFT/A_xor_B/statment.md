<!-- # Problem. Ltee's XOR -->
<!--  -->
<!-- $\begin{array}{l l}Time \; limit \; per \; test & :  2 seconds\\Memory \; limit \; per \; test &:  1024 megabytes\\Input& : standard\;  input \\Output & :standard\;  output \\ \end{array}$ -->

Ltee声称自己是异或高手，但是他不会计算两个数的按位异或，希望你帮助他。

> 在数字逻辑中，逻辑算符异或（英语：Exclusive or）是对两个运算元的一种逻辑分析类型。与一般的逻辑或不同，当两两数值相同时为否，而数值不同时为真。

具体的，对于两个布尔值$a,b$，我们将两个值的异或记作 $a\; XOR\; b$，其中$a,b \mapsto a\; XOR\; b$ 的映射表如下：

| $a\; XOR\; b$ | $a = 0$ | $a = 1$ |
| - | -- | -- |
| $b = 0$ | $0$ | $1$ | 
| $b = 1$ |$1$ |$0$ | 

接下来，我们定义**按位异或**，$a\oplus b$，为对无符号整数$a,b$所有二进制位两两对应进行二进制异或运算。

例如$a = 4,b = 7$,其二进制为$a = (100)_2,b = (111)_2$，则：

$
\begin{array}{l l}
a & b & \mapsto & a \oplus b \\
1 & 1 & & 0 \\
0 & 1 & & 1 \\
0 & 1 & & 1 \\ - & - &  & - \\
4 & 7 & & 3
\end{array}
$

<!-- ## Input

先输入一个整数$n$，代表数位的长度，$1 \le n \le 1\times 10^5$。

接下来输入两行，分别代表 $a,b$ 的二进制位。

## Output

输出一行，代表$a \oplus b$

### Input Example 1

```text
3
100
111
```

### Output Example 1

```text
011
```

### Note

输入样例1的具体运算过程如题面描述。 -->
