# Problem. tee's Array

$\begin{array}{l l}Time \; limit \; per \; test & :  1 seconds\\ Memory \; limit \; per \; test &:  512 megabytes\\Input& : standard\;  input \\Output & :standard\;  output \\ \end{array}$

池化，是一种经典的神经网络降采样技术，用于减少特征图的维度，同时保留最重要的特征。

tee有一个 $n\times m$ 的矩阵A，现在他想对A进行池化。

直观地讲，池化操作为在原矩阵A中选取一个大小为 $2\times 2$ 的窗口，随后计算当前窗口中元素的某个信息，将其作为新矩阵B中对应位置的元素。接下来，将窗口向右移，逐行扫描原矩阵，直到形成一个 $(n-1)\times (m-1)$ 的新矩阵B。

形式化地，对于原矩阵 $A_{n\times m} = [a_{i,j}]$，定义一个从 $2\times 2$矩阵到自然数的映射$f:M_{2\times2} \stackrel{f}{\mapsto} b$，则池化后的新矩阵为 $B_{(n-1)\times (m-1)} = [b_{i,j}],1\le i \le n-1,1\le j \le m-1$ ，其中 $b_{i,j} = f(\begin{bmatrix}
a_{i,j} & a_{i,j+1}\\
a_{i+1,j} & a_{i+1,j+1}\end{bmatrix})$ 。

可以参考样例解释以更好地理解池化操作。

现在，tee想要实现两种池化操作：

+ Max：取窗口中的最大值；

+ Floor：取窗口中的平均值并向下取整。

形式化地，对于映射 $f$ ，定义：

+ $f_\text{Max}(\begin{bmatrix} a_{i,j} & a_{i,j+1}\\ a_{i+1,j} & a_{i+1,j+1}\end{bmatrix}) = max(a_{i,j},a_{i+1,j},a_{i,j+1},a_{i+1,j+1})$

+ $f_\text{Floor}(\begin{bmatrix} a_{i,j} & a_{i,j+1}\\ a_{i+1,j} & a_{i+1,j+1}\end{bmatrix}) = \lfloor \frac{a_{i,j}+a_{i+1,j}+a_{i,j+1}+a_{i+1,j+1}}{4} \rfloor$

$^+$ 注意：本题中的池化与神经网络中的池化操作有一定程度的区别。

$^+$ 注意：本题输入输出规模较大，如果使用`cin`/`cout`，建议在主函数最前加上：

```cpp
std::ios::sync_with_stdio(false);
std::cin.tie(0);
std::cout.tie(0);
```

解除与`stdio`的绑定并关闭缓冲区强制刷新，以提高输入输出效率。

## Input

第一行两个整数$n,m$，$2\le n,m \le 1\times 10^6$，表示矩阵A的大小

接下来n行，每行m个整数，表示矩阵A中的元素 $a_{i,j}$ ，其中 $0\le a_{i,j} \le 10^9$

最后一行为一个字符串 $s$ ，表示池化操作的种类，$s$ 可能为`Max`或`Floor`。

## Output

输出$n-1$行，每行$m-1$个整数，表示矩阵B

### Input Example 1

```text
4 4
1 2 3 0
4 5 6 1
7 8 9 2
3 4 5 6
Max
```

### Output Example 1

```text
5 6 6
8 9 9
8 9 9
```

### Input Example 2

```text
3 3
1 2 3
4 5 6
7 8 9
Floor

```

### Output Example 2

```text
3 4
6 7
```

## Note：

例1中池化操作如下图所示：

![image](file://8Jt75tPdfHFI3sXXgEmpJ.gif)
