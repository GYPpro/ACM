# Problem. Finding Circle

$\begin{array}{l l}Time \; limit \; per \; test & :  2 seconds\\Memory \; limit \; per \; test &:  1024 megabytes\\Input& : standard\;  input \\Output & :standard\;  output \\ \end{array}$

这是一个**交互问题**$^+$。

在一个平面上，有一个隐藏的圆，其圆心和半径均为整数。你需要通过询问来找到这个圆。

每次询问为一个整数点，交互器会告诉你，这个点到圆心的距离的平方，以及这个点是否在圆内或者圆上。

## Interaction

由你首先提出询问，询问格式为`? x y`，其中 $x$ 和 $y$ 是整数，表示询问点 $(x, y)$ 的相关信息。

接下来，交互器会返回两个数 $a,b$ ，$a$ 分别表示点 $(x, y)$ 到圆心的距离的平方，$b = 1$，表示点 $(x, y)$ 在圆内或者圆上，反之 $b = 0$

当你找到了圆的圆心和半径后，输出`! x y r`，其中 $x$ 和 $y$ 是圆心的坐标，$r$ 是圆的半径。

### Input Example 1

```text

```

### Output Example 1

```text

```

### Note

