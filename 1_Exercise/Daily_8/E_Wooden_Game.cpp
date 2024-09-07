// #define D
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <bitset>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
// #pragma GCC optimize(2)
#define bits(x) bitset<64>(x)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

bool comp(int a,int b) {return a < b;}
class solution
{
private:

// 17 16
public:
    void solve()
    {
        int n,t;
        cin >> n;
        vector<int> weis(n);
        lop(i,0,n)
        {
            cin >> weis[i];
            lop(j,2,weis[i]+1)
                cin >> t;
        }
        // int ans = 0;
        // sort(all(weis));
        vector<int> bincnt(32);
        lop(i,0,n)
        {
            vector<int> bins;
            int t = weis[i];
            while(t)
            {
                bins.pb(t%2);
                t >>= 1;
            }
            lop(j,0,bins.size()) bincnt[j] += bins[j];
        }
        int ans = 0;
        for(int i = 31;i >= 0;i --)
        {
            // cout << i << " " << bincnt[i] << "\n";
            if(bincnt[i] >= 2)
            {
                ans += (1<<(i+1))-1;
                break;
            } else ans += bincnt[i] * (1<<i);
        }
        // cout << ans << "\n";
        // for(int i = n-1;i >= 0;i --)
        // {
        //     int t = (1 << 64-__builtin_clzll(weis[i])-1)-1;
        //     // cout << t << "-\n";
        //     ans =max(ans|weis[i],ans|t);
        // }
        // cout << ans << "\n";
        // int ansi = 0;
        // lop(i,0,n)
        //     if(weis[i] > weis[ansi])
        //         ansi = i;
        // int ans = weis[ansi];
        // lop(i,0,n)
        // {
        //     int t = (1 << 64-__builtin_clzll(weis[i])-1)-1;
        //     ans |= (i == ansi ? 0:t);
        // }

        // bitset<64> a(8);
        // cout << a[3] << " " <<
        //         (a<<1)[3] << " " <<
        //         (a^bitset<64>(8))[3] << " " <<
        //         (a<<1).to_ullong() << "\n";

        // cout << ans << "\n";
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}