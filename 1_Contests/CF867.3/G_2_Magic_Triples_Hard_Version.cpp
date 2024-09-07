#include <iostream>

#define map unordered_map
#define set unordered_set

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#pragma GCC optimize(3)

#define ll long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

vector<int> init(int n)
{
    vector<int> pri;
    vector<bool> vis(n, 0);
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pri.push_back(i);
        for (int j = 0; j < pri.size(); j++)
        {
            if (i * pri[j] > n)
                break;
            vis[pri[j] * i] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    return pri;
}

auto pri = init(1e5);

class solution
{
private:

    // BigIntTiny A(int n,int m)
    // {
    //     BigIntTiny t = 1;
    //     for(int i = n-m;i <= n;i ++) t = t * (i?BigIntTiny(i):BigIntTiny(1));
    //     return t;
    // }

public:
    void solve()
    {
        int n;
        cin >> n;
        map<int,int> cnt;
        int maxn = 0;
        FI {
            int t;
            cin >> t;
            maxn = max(maxn,t);
            cnt[t] ++;
        }
        ll ans = 0;
        

        for(auto x:cnt)
        {
            // factor.clear();
            // amt.clear();
            // pwf.clear();
            map<int,int> factor;
            vector<pair<int,int>> amt;
            vector<int> pwf;
            if(!x.se) continue;
            int t = x.fi;
            if(x.se >= 3) ans += (ll)x.se * (ll)(x.se -1LL) * (ll)(x.se -2LL);

            int p = 0;
            while(p < pri.size() && pri[p] * pri[p] <=  t)
            {
                // if(t % pri[p] == 0)
                // {
                //     factor[pri[p]] ++;
                //     t /= pri[p];
                    
                // } else p ++;
                while(t%pri[p] == 0)
                {
                    factor[pri[p]] ++;
                    t /= pri[p];
                }
                p ++;
            }
            // cout << "--" << x.first << "\n";
            // for(auto xx:factor) cout << xx.first << " " << xx.se << "\n";
            for(auto xx:factor)
                if(!(xx.se / 2))continue;
                else amt.pb({xx.first,xx.se / 2});
            // for(auto xx:amt) cout << xx.fi << " " << xx.se << "\n";
            // vector<int> at;
            // for(auto xx:amt)
            //     for(int i = 0;i < xx.second;i ++)
            //         at.pb(xx.first);
            // if(!at.size()) continue;
            int sum = 0;
            for(auto xx:amt)sum += xx.second;
            if(!sum) continue;

            auto binpow = [](long long a, long long b)->long long {
                long long res = 1;
                while (b > 0) {
                    if (b & 1) res = res * a;
                    a = a * a;
                    b >>= 1;
                }
                return res;
            };
            auto getpwf = [&](auto self,int cur,int crn) -> void {
                // if(cur == amt.size()-1){
                //     vector<int> tmp;
                //     for(int __i = 0; __i <= amt[cur].second;__i ++)
                //         tmp.pb(binpow(amt[cur].fi,__i));
                //     return tmp;
                // } else {
                //     auto tmp = self(self,cur+1);
                //     vector<int> rt;
                //     for(int __i = 0; __i <= amt[cur].second;__i ++)
                //         for(auto x:tmp)
                //             rt.pb(binpow(amt[cur].fi,__i) * x);
                //     return rt;
                // }
                if(cur == amt.size()){
                    pwf.pb(crn);
                    return;
                } else {
                    // crn = 1;
                    for(int __i = 0;__i <= amt[cur].se;__i++)
                    {
                        self(self,cur+1,crn);
                        crn *= amt[cur].fi;
                    }
                }
            };

            getpwf(getpwf,0,1);
            // for(auto &xx:pwf) xx = xx*xx;66
            // for(int i = 0;i < (1<<at.size()) ;i ++)
            // {
            //     int _t = 1;
            //     int _f = i;
            //     int idx = 0;
            //     while (_f)
            //     {
            //         if(_f %2) _t *= at[idx];
            //         _f /= 2;
            //         idx ++;
            //     }
            //     pwf.insert(_t * _t);
            // }

            // for(auto x:pwf) cout << x << " ";
            // cout << "\n";

            // // for(int i = 0;x.fi * pri[i] * pri[i] <= maxn && i < pri.size();i ++)
            // // {
            // //     int wad = pri[i];
            // //     do ans += cnt[wad * x.fi] * cnt[wad * x.fi * pri[i]] * x.se;
            // //     while ((wad *= pri[i] )<= maxn);
            // // }
            // for(int i = 2;i * i * x.fi <= maxn;i ++)
            //     if(cnt.find(i * i * x.fi) != cnt.end() && cnt.find(i * x.fi) != cnt.end())
            //         ans += cnt[i * i * x.fi] * cnt[i * x.fi] * x.se;
            // pwf.erase(1);
            for(auto xx:pwf)
                if(xx <= 1) continue;
                else if(cnt.find(x.fi / (xx * xx)) != cnt.end() && cnt.find(x.fi/xx) != cnt.end())
                        ans += (ll)cnt[x.fi /(xx * xx)] * (ll)cnt[x.fi/xx] * (ll)x.se;
        }
        cout << ans << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    cin >> T;
    // for(auto x:pri) cout << x << " ";
    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}