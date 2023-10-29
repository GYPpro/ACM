#include <iostream>
// #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 100010

#define ull unsigned long long
using namespace std;

struct stone
{
    ll int a, b;
    ll int ttl;
};

bool comp(stone a, stone b)
{
    return a.ttl > b.ttl;
}

void slove()
{
    stone st[maxn];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> st[i].a >> st[i].b;
        st[i].ttl = st[i].a + st[i].b;
    }
    sort(st, st + n, comp);
    ll int ansa = 0;
    ll int ansb = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            ansa += st[i].a;
        else
            ansb += st[i].b;
    }
    cout << ansa - ansb << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    // scanf("%d",&T);
    cin >> T;
    for (int i = 0; i < T; i++)
        slove();
    // system("pause");
    return 0;
}