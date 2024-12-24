from decimal import *
setcontext(Context(prec=2000000, Emax=2000000, Emin=0)) 
INF = open("P19191.in","r")
a,b = INF.read().split()
print(Decimal(a) * Decimal(b))
# print((Decimal(sys.stdin.readline())*Decimal(sys.stdin.readline())))