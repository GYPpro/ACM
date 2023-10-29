#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define ll long long
const ll int maxn = (ll)(5e8+5e7);

void list()
{
    ll int a1 = (ll)(1e18)+1;
    ll int a2 = (ll)(1e18);
    int t = 1;
    do{
        a2 %= a1;
        a2 %= a1;
        t ++;
    }while(t <= maxn);
}

int main()
{
    std::ios::sync_with_stdio("false");
    cin.tie(0);
    cout.tie(0);
    clock_t begin = clock();
    list();
    begin = clock()- begin;
    cout << (double)begin/CLOCKS_PER_SEC << endl;
    system("pause");
}