#define _USE_IOSTREAM_
// #define _USE_STDIO_

#ifdef _USE_IOSTREAM_
#include <iostream>
#endif
#ifdef _USE_STDIO_
#include <stdio.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

class mpair{
public:
    int ta,tb;

    mpair operator^(mpair b)
    {
        mpair c;
        c.ta = ta ^ b.ta;
        c.tb = tb ^ b.tb;
        return c;
    }
    void operator^=(mpair b)
    {
        this->ta ^= b.ta;
        this->tb ^= b.tb;
    }
    mpair() {
        ta = 0;
        tb = 0;
    }
    mpair(int n,bool bin)
    {
        ta = 0;
        tb = 0;
        if(bin) ta = n;
        else tb = n;
    }
    void swp(mpair t)
    {
        ta ^= t.ta;
        tb ^= t.tb;
        ta ^= t.tb;
        tb ^= t.ta;
    }
};

void buildSegtree(int s,int t,int p,vector<int> &arr,vector<bool> &bin,vector<mpair> &segTree)
{
    if(s == t) segTree[p] = mpair(arr[s],bin[s]);
    else {
        int mid = (s+t) >> 1;
        buildSegtree(s,mid,p*2,arr,bin,segTree);
        buildSegtree(mid+1,t,p*2+1,arr,bin,segTree);
        segTree[p] = segTree[p*2+1] ^ (segTree[p*2]);
    }
    return;
}

mpair msearch(int l,int r,int s,int t,int p,vector<mpair> &segTree)
{
    if(s >= l && t <= r) return segTree[p];
    int mid = (s+t) >> 1;
    mpair ans;
    if(l <= mid) ans ^= msearch(l,r,s,mid,p*2,segTree);
    if(r > mid) ans ^= msearch(l,r,mid+1,t,p*2+1,segTree);
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<bool> bin(1);
    for(int i = 1;i <= n;i ++) cin >> arr[i];
    for(int i = 1;i <= n;i ++){
        char c;
        cin >> c;
        bin.push_back(c-'0');
    }
    vector<mpair> segTree(4*n);
    buildSegtree(1,n,1,arr,bin,segTree);
    mpair ans = msearch(1,n,1,n,1,segTree);
    int q;
    cin >> q;
    for(int i = 0;i < q;i ++)
    {
        int flag;
        cin >> flag;
        if(flag == 1)
        {
            int l,r;
            cin >> l >> r;
            ans.swp(msearch(l,r,1,n,1,segTree));
        } else {
            cin >> flag;
            if(flag) cout << ans.ta;
            else cout << ans.tb;
            cout << endl;
        }
    }
    return;
}

#define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
    int T = 1;

    #ifdef _WITH_T_
        #ifdef _USE_IOSTREAM_
            cin >> T;
        #endif
        #ifdef _USE_STDIO_
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}