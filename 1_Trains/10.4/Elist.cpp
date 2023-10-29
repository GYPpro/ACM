#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

unsigned long long f(unsigned long long x)
{
    if(x == 0)return 1;
    else if(x%3 == 0) return f(x/3)+1;
    else return f(x-1)+1;
}

int main()
{
    unsigned long long n;
    cin >> n;
    unsigned long long pvmx = 0;
    for(unsigned long long i = n;i <= n;i ++){
        unsigned long long mt = i;
        pvmx = max(pvmx,f(i));
        printf("%4lld:%4lld,%4lld ",i,pvmx,f(i));
        unsigned long long t = 0;
        do{
            t += mt%3+1;
            cout << mt%3;
            mt /= 3;
        }while(mt);
        cout <<" " << t << " "<< endl;
        
    }
    // system("pause");
    return 0;
}