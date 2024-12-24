# Problem. Traffic Restriction (Hard Version)

$
\begin{array}{l l}
Time \; limit \; per \; test   & :  1 \; seconds \\
Memory \; limit \; per \; test & :  1024 \; megabytes\\
Input                          & : standard \;  input \\
Output                         & : standard \;  output \\
\end{array}
$

成都市计划对市区内的机动车进行限行，交管部门每天会选择两个数字，规定车牌以这两个数字中的一个为结尾的机动车不能上路。

为了方便市民出行，交管部门希望限行序列符合以下条件：

+ 在整个限行周期内，所有车辆被限行的天数都相同。
+ 将连续的$k$天视为一个周期，如果某辆车在前一个周期的第$i$天被限行，则不会在当前区间的第$i$天被限行，这对于**任意的**$2 \le k \le 60,k \% 5 === 0$都成立

交管部门希望你帮忙写一个程序，输入一个$n$代表需要限行的天数（每个周期从周一开始），输出生成的限行序列。

## Input

第一行两个整数$n,m,1 \le n,m \le 2\times10^5,$分别代表生成序列的长度和给定的周期的数量。

第二行$m$个整数$k_1,k_2,...,k_n,2 \le k_i \le 2\times10^5$，代表每个周期的长度。

## Output

输出两行。

第一行$n$个整数$a_1,a_2,...,a_n$

第二行$n$个整数$b_1,b_2,...,b_n$

代表在第$i$天对尾号为$(a_i,b_i)$的机动车进行限行。

如果不存在合法的序列，输出`noAnswer`

### Input Example 1

```text
15 3
2 7 30
```

### Output Example 1

```text
1 2 3 4 5 9 0 7 6 1 2 3 4 5 8
9 8 7 6 1 2 3 0 5 0 8 7 6 9 4
```

