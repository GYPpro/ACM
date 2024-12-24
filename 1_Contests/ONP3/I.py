import math as mt
mod = 998244353

pwv = int(1e6)

def truv(x:str):
    x = x.split('.')
    pw = int(x[0])
    ps = int(x[1])
    ff = pw*pwv + ps
    ee = pwv
    tt = mt.gcd(ff,ee)
    return ff//tt,ee//tt
    

def binpow(x:int,y:int):
    res = 1
    while y > 0 :
        if y % 2 == 1 :
            res = res * x % mod
        x = x * x % mod
        y >>= 1
    return res % mod

def inv(x:int):
    return binpow(x,mod-2)

def fracadd(x,y):
    ff = (x[0] *y[1] %mod + x[1] * y[0] %mod)%mod
    ee = (x[1] *y[1])%mod
    tt = mt.gcd(ff,ee)
    return (ff//tt,ee//tt)

T = 0
T = int(input())
while T:
    T -= 1
    #--------MAIN-------
    n = int(input())
    verlst = []
    celdict = {}
    for i in range(n):
        tmp = input().split()
        verlst.append(tmp[0])
        celdict[tmp[0]] = []
        # [y]-[i]-[u,v]
        j = 2
        rg = len(tmp)
        while j < rg:
            celdict[tmp[0]].append((int(tmp[j]),truv(tmp[j+1])))
            j += 2
    # for c in range(n):
        # c = 'a'
    func = input()
    def cacu(x,cat):
        cap = len(x)
        if(cap >= 1) : A = x[0]
        if(cap >= 2) : B = x[1]
        if(cap >= 3) : C = x[2]
        if(cap >= 4) : D = x[3]
        return eval(cat)

    # cat = compile(func,None,'Auto')
    if(n >= 1) :
        celdict['A'] = celdict[verlst[0]]
        func = func.replace(verlst[0],'A')
        verlst[0] = 'A'
    if(n >= 2) :
        celdict['B'] = celdict[verlst[1]]
        func = func.replace(verlst[1],'B')
        verlst[1] = 'B'
    if(n >= 3) :
        celdict['C'] = celdict[verlst[2]]
        func = func.replace(verlst[2],'C')
        verlst[2] = 'C'
    if(n >= 4) :
        celdict['D'] = celdict[verlst[3]]
        func = func.replace(verlst[3],'D')
        verlst[3] = 'D'
    # print(func)
    func = func.replace("*","%mod*")
    ctrb = [0,1]
    verbalCelLis = []
    def dfs(i:int,curp):
        thissumctr = [0,1]
        if i >= n:
            res = cacu(verbalCelLis,func)
            expc = (curp[0] * res % mod,curp[1])
            thissumctr = fracadd(thissumctr,expc)
            return thissumctr
        curc = verlst[i]
        for j in celdict[curc]:
            tmp = (curp[0] * j[1][0] % mod,curp[1] * j[1][1] % mod)
            verbalCelLis.append(j[0])
            thissumctr = fracadd(thissumctr,dfs(i+1,tmp))
            verbalCelLis.pop()
        return thissumctr
    ctrb = dfs(0,(1,1))
    # print(ctrb)
    print(ctrb[0] * inv(ctrb[1]) % mod)


