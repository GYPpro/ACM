// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int tmp = INF;
    if(n%2 == 0)
    {
        map<int,int> oddcnt,evencnt;
        lop(i,0,n)
        {
            if(i%2 == 0) oddcnt[s[i]] ++;
            else evencnt[s[i]] ++;
        }
        int oddmx = 0,evenmx = 0;
        for(auto x:oddcnt) oddmx = max(oddmx,x.se);
        for(auto x:evencnt) evenmx = max(evenmx,x.se);
        cout << ans + (n - oddmx - evenmx) << "\n";
    } else {
        map<int,int> po,pe,so,SE;
        // n --;
        lop(i,0,n) if(i%2 == 0) so[s[i]] ++;
        else SE[s[i]] ++;
            map<int,int> t;
        auto getans = [&]() -> int{
            int om = 0,em = 0;
            t.clear();
            for(auto x:so) t[x.fi] += x.se; 
            for(auto x:po) t[x.fi] += x.se; 
            for(auto x:t) om = max(om,x.se);
            t.clear();
            for(auto x:SE) t[x.fi] += x.se; 
            for(auto x:pe) t[x.fi] += x.se; 
            for(auto x:t) em = max(em,x.se);
            // cout << om+em << "\n";
            return n - om - em-1;
        };
        so[s[0]] --;
        swap(so,SE);
        tmp = min(tmp,getans());
        // se[s[1]] --;
        for(int i = 1;i < n;i ++)
        {
            // for(auto x:so) cout << (char)x.fi << " " << x.se << "\n";
            // cout << "----\n";
            // for(auto x:SE) cout << (char)x.fi << " " << x.se << "\n";
            // cout << "----\n";
            // for(auto x:po) cout << (char)x.fi << " " << x.se << "\n";
            // cout << "----\n";
            // for(auto x:pe) cout << (char)x.fi << " " << x.se << "\n";
            // cout << "----\n";

            if(i%2 != 0) so[s[i]] --;
            else SE[s[i]] --;
            if((i-1)%2 == 0) po[s[i-1]] ++;
            else pe[s[i-1]] ++;
            tmp = min(tmp,getans());
            // swap(so,se);
        }
        cout << tmp+1 << "\n";
    }
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
