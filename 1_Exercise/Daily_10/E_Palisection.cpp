    // #pragma GCC optimize(2)

    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    using namespace std;
    using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
                        tree_order_statistics_node_update>;
    #define int long long
    #define pii pair<int, int>
    #define pb push_back
    #define fi first
    #define se second
    const int INF = 1145141919810LL;
    #define lop(i, a, b) for (int i = a; i < b; i++)
    #define all(x) x.begin(), x.end()
    #define ord(u, v) {min(u, v), max(u, v)}
    // #define set unordered_set
    // #define map unordered_map


    pair<vector<int>,vector<int>> Manacher(string s){
        // d1: a b [c:3] b a
        // d2: a b [b:2] a
        int n = s.size();
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
            d1[i] = k--;
            if (i + k > r) l = i - k,r = i + k;
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
            d2[i] = k--;
            if (i + k > r) l = i - k - 1, r = i + k;
        }
        return {d1,d2};
    }

    const int mod = 51123987;

    int exgcd(int a,int b,int &x,int &y) {
        if(b  == 0) {
            x = 1,y = 0;
            return 0;
        } exgcd(b,a%b,y,x);
        y -= a/b * x;
        return 0;
    }
    int INV2,ty;

    const int tz = exgcd(2,mod,INV2,ty);

    class prefx{
    public:
        vector<int> a;
        prefx(int _n) {
            a.resize(_n+1);
        }
        void update(int l,int r) {
            l ++,r ++;
            a[l]++,a[r+1]--;
        }
        void run(){
            for(int i = 1;i < a.size();i ++) a[i] = a[i-1] + a[i] % mod;
        }
        int get(int i) {
            i ++;
            return a[i];
        }
    };

    void solve()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto [d1,d2] = Manacher(s);
        // for(auto x:d1) cout << x << " ";cout << "\n";
        // for(auto x:d2) cout << x << " ";cout << "\n";
        vector<int> pre(n),sef(n);
        // d1: a b [c:3] b a
        // d2: a b [b:2] a
        // ord_set
        // map<int,int> cnt;
        prefx segpre(n+2),segsef(n+2);
        // segpre.build(vector<int>(n+2,0));
        // segsef.build(vector<int>(n+2,0));
        int ttlcnt = 0;
        lop(i,0,n){
            ttlcnt += d1[i] + d2[i];
            ttlcnt %= mod;
            segpre.update(i,d1[i]+i-1);
            // segpre[i+1]++,segpre[d1[i]+i]--;
            // if(d2[i])segpre[i+1]++,segpre[d2[i]+i]--;
                segpre.update(i,d2[i]+i-1);
                
            segsef.update(i - d1[i]+1,i);
            // segsef[i-d1[i]+2] ++,segsef[d1[i]+2] --;
            if(d2[i])segsef.update( i - d2[i] ,i-1);
            // if(d2[i]) segsef[i-d2[i]+1]++,segsef[i-1]--;
        }
        // lop(i,1,n+1) segsef[i] = segsef[i-1]+segsef[i],segpre[i] = segpre[i-1]+segpre[i];
        segpre.run(),segsef.run();
        // ttlcnt = (ttlcnt * (ttlcnt-1) >> 1) % mod;
        ttlcnt = ((ttlcnt * (ttlcnt-1) % mod) * INV2) % mod;
        // cout << ttlcnt << " \n";
        // cout <<( INV2 * 2 )% mod << "\n";
        lop(i,0,n) pre[i] = segpre.get(i),sef[i] = segsef.get(i);
        vector<int> presum = pre;
        lop(i,1,n) presum[i] += presum[i-1],presum[i] %= mod;
        // for(int i = n-2;i >= 0;i --) sefsum[i] += sefsum[i+1];
        int ans = 0;
        // for(auto x:presum) cout << x <<" " ;cout << "\n";
        // for(auto x:sef) cout << x <<" " ;cout << "\n";
        lop(i,0,n-1)
            ans = (ans + ( presum[i] %mod )* sef[i+1] % mod )%mod;
        cout << (ttlcnt - ans + mod) % mod << "\n";
    }

    signed main()
    {
    #ifdef FC
        freopen("G.A.in", "r", stdin);
        freopen("G.A.ptc", "w", stdout);
    #endif
    #ifndef FC
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
    #endif
        int T = 1;
        INV2 = (INV2 + mod) % mod;
        // cin >> T;
        while (T--)
            solve();
        return 0;
    }
