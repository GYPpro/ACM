#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lop(i,a,b) for(int i = a;i < b;i ++)
#define map unordered_map
#pragma GCC optimize(3)
#define pb push_back

vector<int> pri;

void init(int n)
{
    vector<bool> vis(n+1,0);
    for(int i = 2;i <= n;i ++)
    {
        if(!vis[i]) pri.pb(i);
        for(int j = 0;j < pri.size();j ++)
        {
            if(i * pri[j] > n) break;
            vis[pri[j] * i] = 1;
            if(i%pri[j] == 0) break;
        }
    }
}

void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    vector<int> forall(m+1);
    vector<int> cntpri(m+1);
    vector<int> cnt(m+1);
    for(auto x:a) cnt[x]++;
    lop(i,1,m+1)
    {
        // if(!cnt[i]) continue;
        for(int p = 1;p * i <= m;p ++)
            cntpri[i] += cnt[p * i];
    }
    // auto factor = [&](int x) -> void {
    //     for(int i = 1;i * i <= x;i ++)
    //     {
    //         if(x%i != 0) continue;
    //         if(i * i != x) cntpri[x/i] ++;
    //         cntpri[i] ++;
    //     }
    // };
    // for(auto x:a) factor(x);
    // lop(i,1,10) cout << i << " : " << cntpri[i] << "\n";
    // lop(i,1,m+1)
    for(int i = m;i >= 1;i --)
    {
        // int k = m/i+1;
        forall[i] += cntpri[i] * cntpri[i];
        for(int pi = 2;pi * i <= m;pi ++)
            // forall[i] -= cntpri[pri[pi] * i] * cntpri[pri[pi] * i];
            forall[i] -= forall[pi * i];
    }


    // map<>
     
    // for(auto x:a) cnt[x] ++;
    // lop(i,1,n+1)
    // {
    //     int k = m/i +1;
    //     lop(p1,1,k)
    //         lop(p2,1,k)
    //             if(__gcd(p1,p2) != 1) continue;
    //             else forall[i] += cnt[p1]*cnt[p2];
    // }
    while(q--)
    {
        int x;
        cin >> x;
        cout << forall[x] << "\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init(5e5);
    int t = 1;
    cin >> t;
    while(t--) solve();
}