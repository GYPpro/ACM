Here is the content of the provided PDF converted to Markdown format, organized by chapters:



---



# 2024 Nowcoder Multi-University Training Contest 1

**Nowcoder, Tuesday, July 16, 2024**



## Problem A. A Bit Common

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 1024 megabytes



Given two integers $ n $ and $ m $, among all the sequences containing $ n $ non-negative integers less than $ 2^m $, you need to count the number of such sequences $ A $ that there exists a non-empty subsequence of $ A $ in which the bitwise AND of the integers is 1.



Note that a non-empty subsequence of a sequence $ A $ is a non-empty sequence that can be obtained by deleting zero or more elements from $ A $ and arranging the remaining elements in their original order.



Since the answer may be very large, output it modulo a positive integer $ q $.



The bitwise AND of non-negative integers $ A $ and $ B $, $ A $ AND $ B $ is defined as follows:

- When $ A $ AND $ B $ is written in base two, the digit in the $ 2^d $ place ($ d \geq 0 $) is 1 if those of $ A $ and $ B $ are both 1, and 0 otherwise.



For example, we have $ 4 $ AND $ 6 = 4 $ (in base two: 100 AND 110 = 100).



Generally, the bitwise AND of $ k $ non-negative integers $ p_1, p_2, \ldots, p_k $ is defined as

$$ 

(\ldots ((p_1 \text{ AND } p_2) \text{ AND } p_3) \text{ AND } \ldots \text{ AND } p_k) 

$$

and we can prove that this value does not depend on the order of $ p_1, p_2, \ldots, p_k $.



**Input**  

The only line contains three integers $ n $ (1 ≤ $ n $ ≤ 5000), $ m $ (1 ≤ $ m $ ≤ 5000) and $ q $ (1 ≤ $ q $ ≤ 10^9).



**Output**  

Output a line containing an integer, denoting the answer.



**Examples**



standard input 1

```

2 3 998244353 

```

standard output 1

```

17

```

standard input 2

```

5000 5000 998244353

```

standard output 2

```

2274146

```







## Problem B. A Bit More Common

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 1024 megabytes



Given two integers $ n $ and $ m $, among all the sequences containing $ n $ non-negative integers less than $ 2^m $, you need to count the number of such sequences $ A $ that there exists two different non-empty subsequences of $ A $ in each of which the bitwise AND of the integers is 1.



Note that a non-empty subsequence of a sequence $ A $ is a non-empty sequence that can be obtained by deleting zero or more elements from $ A $ and arranging the remaining elements in their original order. Two subsequences are different if they are composed of different locations in the original sequence.



Since the answer may be very large, output it modulo a positive integer $ q $.



The bitwise AND of non-negative integers $ A $ and $ B $, $ A $ AND $ B $ is defined as follows:

- When $ A $ AND $ B $ is written in base two, the digit in the $ 2^d $ place ($ d \geq 0 $) is 1 if those of $ A $ and $ B $ are both 1, and 0 otherwise.



For example, we have $ 4 $ AND $ 6 = 4 $ (in base two: 100 AND 110 = 100).



Generally, the bitwise AND of $ k $ non-negative integers $ p_1, p_2, \ldots, p_k $ is defined as

$$ 

(\ldots ((p_1 \text{ AND } p_2) \text{ AND } p_3) \text{ AND } \ldots \text{ AND } p_k) 

$$

and we can prove that this value does not depend on the order of $ p_1, p_2, \ldots, p_k $.



**Input**  

The only line contains three integers $ n $ (1 ≤ $ n $ ≤ 5000), $ m $ (1 ≤ $ m $ ≤ 5000) and $ q $ (1 ≤ $ q $ ≤ 10^9).



**Output**  

Output a line containing an integer, denoting the answer.



**Examples**

standard input 1

```

2 3 998244353 

```

standard output 1

```

7

```

standard input 2

```

5000 5000 998244353

```

standard output 2

```

530227736

```



---



## Problem C. Sum of Suffix Sums

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 2 seconds  

**Memory limit:** 1024 megabytes



Given an array which is initially empty, you need to perform $ q $ operations:



- Given two non-negative integers $ t $ and $ v $, take out the element from the end of the array for $ t $ times and then append $ v $ to the end of the array. It is guaranteed that $ t $ does not exceed the length of the array before this operation.



After each operation, let $ a_1, a_2, \ldots, a_n $ be the current array, find the sum of $ s_1, s_2, \ldots, s_n $, where $ s_i = a_i + a_{i+1} + \ldots + a_n $ is the sum of the suffix starting from position $ i $.



Since the answers may be very large, output them modulo 1,000,000,007.



**Input**  

The first line contains an integer $ q $ (1 ≤ $ q $ ≤ 5×10^5), denoting the number of operations.



**Output**  

Output $ q $ lines each containing an integer, denoting the answer after each operation.



**Example**


standard input 1

```
3
2 1
0 1
2 2

```

standard output 1

```

1
2
1
4

```



**Note**  

For the first operation, the array is [1, 2], the suffix sum array is [3, 2], and the sum of the suffix sums is 5.  

After the second operation, the array is [1, 2, 2], the suffix sum array is [5, 4, 2], and the sum of the suffix sums is 11.



---



## Problem D. Double Queries

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 1024 megabytes



Little Q is the only employee of the 3rd company on the first day of his work. Now he needs to handle $ q $ queries. Each query has the format:

- Given four integers $ x $, $ y $, $ l $, $ r $, return the number of integers in the interval $[l, r]$ that can be formed by exactly two queries among the first $ x $ years and $ y $ years respectively.



**Input**  

The first line contains three integers $ n $ (1 ≤ $ n $ ≤ 5000), $ m $ (1 ≤ $ m $ ≤ 5000), and $ q $ (1 ≤ $ q $ ≤ 5×10^5).



**Output**  

Output $ q $ lines each containing an integer, denoting the answer for each query.



**Example**

standard input 1

```
3
2 1 5 2
1 2 3 5
```

standard output 1

```
2 1 2

```


**Note**  

For the first query, the numbers 2 and 5 can be formed.  

For the second query, the numbers 3 and 5 can be formed.



---



## Problem E. Product of Suffix Sums

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 1024 megabytes



Given an array which is initially empty, you need to perform $ q $ operations:



- Given two non-negative integers $ t $ and $ v $, take out the element from the end of the array for $ t $ times and then append $ v $ to the end of the array. It is guaranteed that $ t $ does not exceed the length of the array before this operation.



After each operation, let $ a_1, a_2, \ldots, a_n $ be the current array, find the product



 of $ s_1, s_2, \ldots, s_n $, where $ s_i = a_i + a_{i+1} + \ldots + a_n $ is the sum of the suffix starting from position $ i $.



Since the answers may be very large, output them modulo 1,000,000,007.



**Input**  

The first line contains an integer $ q $ (1 ≤ $ q $ ≤ 5×10^5), denoting the number of operations.



**Output**  

Output $ q $ lines each containing an integer, denoting the answer after each operation.



**Example**


standard input 1

```
3
2 1
0 1
2 2
```

standard output 1

```
1
2
1
4
```


**Note**  

For the first operation, the array is [1, 2], the suffix sum array is [3, 2], and the product of the suffix sums is 6.  

After the second operation, the array is [1, 2, 2], the suffix sum array is [5, 4, 2], and the product of the suffix sums is 40.



---



## Problem F. Fast Suffix Product

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 1024 megabytes



Given an array which is initially empty, you need to perform $ q $ operations:



- Given two non-negative integers $ t $ and $ v $, take out the element from the end of the array for $ t $ times and then append $ v $ to the end of the array. It is guaranteed that $ t $ does not exceed the length of the array before this operation.



After each operation, let $ a_1, a_2, \ldots, a_n $ be the current array, find the product of $ s_1, s_2, \ldots, s_n $, where $ s_i = a_i + a_{i+1} + \ldots + a_n $ is the sum of the suffix starting from position $ i $.



Since the answers may be very large, output them modulo 1,000,000,007.



**Input**  

The first line contains an integer $ q $ (1 ≤ $ q $ ≤ 5×10^5), denoting the number of operations.



**Output**  

Output $ q $ lines each containing an integer, denoting the answer after each operation.



**Example**

standard input 1

```
3
2 1
0 1
2 2
```

standard output 1

```
1
2
1
4
```


| standard input | standard output |

|----------------|------------------|

| 3              | 1               |

| 2 1            | 2               |

| 0 1            | 1               |

| 2 2            | 4               |



**Note**  

For the first operation, the array is [1, 2], the suffix sum array is [3, 2], and the product of the suffix sums is 6.  

After the second operation, the array is [1, 2, 2], the suffix sum array is [5, 4, 2], and the product of the suffix sums is 40.



---



## Problem G. Graph Queries

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 1024 megabytes



Given a directed graph with $ n $ nodes and $ m $ edges, you need to perform $ q $ queries. Each query has the format:

- Given two nodes $ x $ and $ y $, return whether there exists a path from node $ x $ to node $ y $ in the graph.



**Input**  

The first line contains three integers $ n $ (1 ≤ $ n $ ≤ 5000), $ m $ (1 ≤ $ m $ ≤ 5000), and $ q $ (1 ≤ $ q $ ≤ 5×10^5).  

The following $ m $ lines each contain two integers $ u $ and $ v $ (1 ≤ $ u, v $ ≤ $ n $), denoting a directed edge from node $ u $ to node $ v $.  

The following $ q $ lines each contain two integers $ x $ and $ y $ (1 ≤ $ x, y $ ≤ $ n $), denoting a query.



**Output**  

Output $ q $ lines each containing a string "Yes" or "No", denoting whether there exists a path from node $ x $ to node $ y $.



**Example**



| standard input | standard output |

|----------------|------------------|

| 3              | 2               |

| 1 2            | Yes             |

| 2 3            | Yes             |

| 1 3            | Yes             |

| 3 1            | No              |



---



## Problem H. Hamiltonian Paths

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 1024 megabytes



Given a directed graph with $ n $ nodes and $ m $ edges, you need to find the number of Hamiltonian paths in the graph.



A Hamiltonian path is a path that visits each node exactly once.



**Input**  

The first line contains two integers $ n $ (1 ≤ $ n $ ≤ 18), $ m $ (1 ≤ $ m $ ≤ 5000).  

The following $ m $ lines each contain two integers $ u $ and $ v $ (1 ≤ $ u, v $ ≤ $ n $), denoting a directed edge from node $ u $ to node $ v $.



**Output**  

Output a line containing an integer, denoting the number of Hamiltonian paths in the graph.



**Example**



| standard input | standard output |

|----------------|------------------|

| 3              | 2               |

| 1 2            | 1               |

| 2 3            |                 |

| 1 3            |                 |

| 3 1            |                 |



**Note**  

For the first query, there are 2 Hamiltonian paths: 1→2→3 and 2→1→3.  

For the second query, there is 1 Hamiltonian path: 1→3→2.



---



## Problem I. Interval Queries

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 1024 megabytes



Given an array of $ n $ integers, you need to perform $ q $ queries. Each query has the format:

- Given two integers $ l $ and $ r $, return the sum of the integers in the interval $[l, r]$ inclusive.



**Input**  

The first line contains two integers $ n $ (1 ≤ $ n $ ≤ 5000), $ q $ (1 ≤ $ q $ ≤ 5×10^5).  

The following line contains $ n $ integers, denoting the array.  

The following $ q $ lines each contain two integers $ l $ and $ r $ (1 ≤ $ l \leq r \leq n $), denoting a query.



**Output**  

Output $ q $ lines each containing an integer, denoting the answer for each query.



**Example**



| standard input | standard output |

|----------------|------------------|

| 3              | 1               |

| 1 2 3          | 6               |

| 1 3            |                 |



**Note**  

For the first query, the sum of the integers in the interval [1, 3] is 6.



---



## Problem J. Jumping Robots

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 1024 megabytes



Given an array of $ n $ integers representing the heights of $ n $ robots, you need to perform $ q $ queries. Each query has the format:

- Given an integer $ x $, return the maximum height a robot can jump to.



**Input**  

The first line contains two integers $ n $ (1 ≤ $ n $ ≤ 5000), $ q $ (1 ≤ $ q $ ≤ 5×10^5).  

The following line contains $ n $ integers, denoting the heights of the robots.  

The following $ q $ lines each contain an integer $ x $ (1 ≤ $ x \leq n $), denoting a query.



**Output**  

Output $ q $ lines each containing an integer, denoting the maximum height a robot can jump to.



**Example**



| standard input | standard output |

|----------------|------------------|

| 3              | 3               |

| 1 2 3          | 1               |

| 1              | 2               |

| 2              | 3               |

| 3              |                 |



**Note**  

For the first query, the robot can jump to height 1.  

For the second query, the robot can jump to height 2.  

For the third query, the robot can jump to height 3.



---



## Problem K. Kth Ancestor

**Input file:** standard input  

**Output file:** standard output  

**Time limit:** 3 seconds  

**Memory limit:** 102