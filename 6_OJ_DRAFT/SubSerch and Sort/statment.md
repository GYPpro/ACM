# Problem. SubSerch_Sort

$\begin{array}{l l}Time \; limit \; per \; test & :  1 seconds\\Memory \; limit \; per \; test &:  1024 megabytes\\Input& : standard\;  input \\Output & :standard\;  output \\ \end{array}$

在平面上给定$n$个点，你会收到$q$次询问，每次询问会给定一个平面上的点$a$，你需要在原先的所有点中找到一个点$b$，满足$a$和$b$在同一个以原点为圆心的圆上。

具体的，对于输入的$a : (ax,ay)$你需要找到一个$b = (bx,by)$ ,使得 $\sqrt{ax^2+ay^2} = \sqrt{bx^2+by^2}$

## Input

第一行输入两个整数$n,q$，$1\le n,q \le 1\times10^5$

接下来$n$行，每行两个**整数** $ax_i,ax_i$，$-1\times10^9 \le ax_i,ax_i \le 1\times10^9$

接下来$q$行，每行代表一个询问，询问包含$bx,by$两个**整数**，$-1\times10^9 \le bx,bx \le 1\times10^9$

## Output

输出$q$行，每行两个整数，代表答案。

如果有多个点符合条件，你需要输出$x$轴坐标最小的点。如果有多个$x$坐标相同的点，你需要输出这些点中$y$坐标最小的点。

### Input Example 1

```text
4 1
1 -1
-1 1
1 1
-1 -1
1 1
```

### Output Example 1

```text
-1 -1
```
