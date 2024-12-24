
## Problem A. A Bit Common

**Input file**: standard input  
**Output file**: standard output  
**Time limit**: 3 seconds  
**Memory limit**: 1024 megabytes  

Given two integers \( n \) and \( m \), among all the sequences containing \( n \) non-negative integers less than \( 2^m \), you need to count the number of such sequences \( A \) that there exists a non-empty subsequence of \( A \) in which the bitwise AND of the integers is 1.

Note that a non-empty subsequence of a sequence \( A \) is a non-empty sequence that can be obtained by deleting zero or more elements from \( A \) and arranging the remaining elements in their original order.

Since the answer may be very large, output it modulo a positive integer \( q \).

The bitwise AND of non-negative integers \( A \) and \( B \), \( A \text{ AND } B \) is defined as follows:

- When \( A \text{ AND } B \) is written in base two, the digit in the \( 2^d \) place (\( d \geq 0 \)) is 1 if those of \( A \) and \( B \) are both 1, and 0 otherwise.

For example, we have \( 4 \text{ AND } 6 = 4 \) (in base two: \( 100 \text{ AND } 110 = 100 \)).

Generally, the bitwise AND of \( k \) non-negative integers \( p_1, p_2, \ldots, p_k \) is defined as:

\[ (\ldots((p_1 \text{ AND } p_2) \text{ AND } p_3) \text{ AND } \ldots \text{ AND } p_k) \]

and we can prove that this value does not depend on the order of \( p_1, p_2, \ldots, p_k \).

### Input

The only line contains three integers \( n \) (\( 1 \leq n \leq 5\,000 \)), \( m \) (\( 1 \leq m \leq 5\,000 \)) and \( q \) (\( 1 \leq q \leq 10^9 \)).

### Output

Output a line containing an integer, denoting the answer.

### Examples

#### Example 1

```plaintext
standard input
2 3 998244353

standard output
17
```

#### Example 2

```plaintext
standard input
5000 5000 998244353

standard output
2274146
```
```