from sys import stdout


def equal(x, y):
    if x == y or x == '?' or y == '?':
        return True
    else:
        return False


for i in range(int(input())):
    s = input()
    result = 0
    for i in range((len(s) >> 1), 0, -1):
        f = False
        for l in range(len(s) - i - i + 1):
            flag = True
            p = l
            for j in range(l + i, l + i + i):
                if equal(s[p], s[j]):
                    p += 1
                else:
                    flag = False
                    break
            if flag:
                result = i
                f = True
                break
        if f:
            break

    stdout.write(str(result * 2) + '\n')

stdout.flush()