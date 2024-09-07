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
    int n,m;
    cin >> n >> m;
    // vector<string> 
    string PASSWORD = "";
    bool ifcmp = 0;
    vector<pair<string,int>> args;
    while(m--)
    {
        string s;
        int t;
        cin >> s >> t;
        args.pb({s,t});
    }
    lop(i,0,pow(10,n))
    {
        // function<bool(string,string,int)> check = [&](string tar,string s,int t) -> bool {
        //     int minn = 10;
        //     vector<int> dev;
        //     lop(i,0,n) dev.pb(((tar[i]-'0')-(s[i]-'0') + 10) % 10);
        //     // for(auto x:dev) cout << x << " ";cout << "\n";
        //     for(auto x:dev) minn = min(x,minn);
        //     // if(minn < t) return 0;
        //     // if(t > 25) return 1;
        //     minn = 25;
        //     int cur = 0;
        //     int MEX = 1 << (n+1);
        //     lop(i,0,MEX)
        //     {
        //         cur = 0;
        //         lop(j,0,n)
        //         {
        //             if(i >> j & 1) //1 : +
        //             {
        //                 if(j >= 1)
        //                 {
        //                     if((i >> (j-1)&1) ^ (i >> j & 1)) {
        //                         cur += dev[j];
        //                     } else {
        //                         cur += min(dev[j],max(0LL,dev[j]-dev[j-1]));
        //                     }
        //                 } else {
        //                     cur += dev[j];
        //                 }
        //             } else {
        //                 if(j >= 1)
        //                 {
        //                     if((i >> (j-1)&1) ^ (i >> j & 1)) {
        //                         cur += 10 - dev[j];
        //                     } else {
        //                         cur += min(10 - dev[j],max(0LL,(10 - dev[j])-(10 - dev[j-1])));
        //                     }
        //                 } else {
        //                     cur += 10 - dev[j];
        //                 }
        //             }
        //         }
        //         minn = min(minn,cur);
        //     }
        //     // cout << "check:" << tar << " " << s << " " << t << " : " << minn << "\n";
        //     if(n == 1) {
        //         if(t < minn) return 0;
        //         else if(( t - minn )%2 == 0 )return 1;
        //         else return 0;
        //     }
        //     return minn <= t;
        // };
            vector<int> a(n);

        function<bool(string,string,int)> check = [&](string tar,string s,int t) -> bool {
            // if(tar == s) return 1;
            // int minn = 10;
            // for(auto x:a) minn = min(x,minn);
            // if(minn < t) return 0;
            // if(t > 25) return 1;
            // minn = 0;
            int MEX = 1 << (n+1);
            int ans=30;
            for(auto &x:s) x -= '0';
            for(auto &x:tar) x -= '0';
                for(int i=0;i<n;i++){
                    a[i]=(10+s[i]-tar[i])%10;
                }
            lop(i,0,MEX)
            {
                // bitset<n>
                // for(auto x:a) cout << x << " ";cout << "\n";
                int mi=0;
                int cur=0;
                for(int j=0;j<n;j++){
                    if((i>>j&1)==0){
                        mi = max(0LL,mi);
                        cur+=(int)(a[j]-mi);
                        if(j==n-1) break;
                        if((i>>(j+1)&1)==0) mi=min(a[j],a[j+1]);
                        else mi=0;
                    }
                    else{
                        mi = max(0LL,mi);
                        cur+=(int)(10-a[j]-mi);
                        if(j==n-1) break;
                        if((i>>(j+1)&1)==1) mi=min(10-a[j],10-a[j+1]);
                        else mi=0;
                    }
                }
                ans=min(ans,cur);
            }
            if(ans == 0 && t == 1) return 0;
            // cout << "check:" << tar << " " << s << " " << t << " : " << ans << "\n";
            if(n == 1) {
                if(t < ans) return 0;
                else if(( t - ans )%2 == 0 )return 1;
                // else if((t - (10-ans )) %2 == 0) return 1;
                else return 0;
            }
            return ans <= t;
        };
        
        string s;
        int t = i;
        while(t) {
            s.pb(t%10+'0');
            t /= 10;
        }
        while(s.size() < n) s.pb('0');
        reverse(all(s));
        bool ALLPASS = 1;
        for(auto x:args)
        {
            if(check(s,x.fi,x.se)) continue;
            ALLPASS = 0;
            break;
        }
        if(ALLPASS) 
            // cout << s << ":passed\n";
            if(ifcmp) {
                cout << "MANY\n";return;
            } else {
                ifcmp = 1;
                PASSWORD = s;
            }
    }
    if(ifcmp) cout << PASSWORD << "\n";
    else cout << "IMPOSSIBLE\n";
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
