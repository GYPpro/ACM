import numpy as np
n = int(input())
P = []
B = []
for i in range(n):
    tmp = [int(x) for x in input().split()]
    P.append(tmp[:-1])
    B.append(tmp[-1])
P = np.array(P)
B = np.array(B)
sol = np.linalg.lstsq(P,B,rcond=None)
print(sol[0])