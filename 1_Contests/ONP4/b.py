T = int(input())
while T > 0:
    T -= 1;
    n,k = [int(x) for x in input().split()]
    lst = []
    for i in range(n):
        lst.append(int(input().split('/')[4]))
    lst.sort()
    for i in range(k):
        print(lst[i],end = ' ' )
    print()