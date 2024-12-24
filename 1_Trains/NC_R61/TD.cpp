// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map
class generator{
public:
    // using std::mt19937 
    std::mt19937 mt;
    generator(){ mt.seed(std::random_device()()); };
    generator(int n) { mt.seed(n); };

    int randi(int l,int r) { return std::uniform_int_distribution<int>(l,r)(mt); }

    vector<int> randi(int n,int l,int r) {
        vector<int> rt;
        while(n--) rt.push_back(randi(l,r));
        return rt;
    }

    double randf(double l,double r) { return std::uniform_real_distribution<double>(l,r)(mt); }

    vector<double> randf(int n,double l,double r) {
        vector<double> rt;
        while(n--) rt.push_back(randf(l,r));
        return rt;
    }

    string rands(int l,bool ifa = 1,bool ifA = 0,bool ifd = 0) {
        string rt;
        while(l--) {
            int t = randi(0,61);
            if(t < 26) rt.push_back('a'+t);
            else if(t < 52) rt.push_back('A'+t-26);
            else rt.push_back('0'+t-52);
        }
        return rt;
    }

    vector<int> randp(int n) {
        vector<int> rt;
        for(int i = 1;i <= n;i ++) rt.push_back(i);
        std::shuffle(rt.begin(),rt.end(),mt);
        return rt;
    }

    vector<int> randt(int n) {
        vector<int> rt;
        for(int i = 2;i <= n;i ++) rt.push_back(randi(1,i-1));
        return rt;
    }

    vector<vector<int>> randg(int n,int m,bool forceconnected = 0) {
        vector<vector<int>> rt(n+1);
        vector<int> p = randp(n);
        for(int i = 2;i <= n;i ++) {
            int t = randi(1,i-1);
            rt[p[i]].push_back(p[t]);
            rt[p[t]].push_back(p[i]);
        }
        for(int i = n+1;i <= m;i ++) {
            int t = randi(1,n);
            rt[p[t]].push_back(p[i]);
            rt[p[i]].push_back(p[t]);
        }
        if(forceconnected) {
            vector<int> vis(n+1);
            std::queue<int> q;
            q.push(1);
            vis[1] = 1;
            while(q.size()) {
                int x = q.front();q.pop();
                for(auto y:rt[x]) if(!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                }
            }
            for(int i = 1;i <= n;i ++) if(!vis[i]) {
                int t = randi(1,n);
                rt[i].push_back(t);
                rt[t].push_back(i);
            }
        }
        return rt;
    }
} gc;
int checker(int n,int d)
{
    // int n,d;
    // cin >> n >> d;
    vector<int> arr(n);
    iota(all(arr),1);
    int mians = INF;
    int lrg = 0;
    lop(l,-500,500) {
        int cnt = 0;
        lop(i,0,n) {
            cnt += min(abs(arr[i]-l),abs(arr[i]-(l+d)));
        }
        if(cnt < mians) lrg = l,mians = cnt;
    }
    // cout << lrg << " " << lrg+d << " " << mians << "\n";
    return mians;
}

// int solve(int n,int d)
void solve()
{
    int n,d;
    cin >> n >> d;
    // d ++; // range length : [l,l+d-1]
    int l = (n+1)/2;
    if(d < n) l =((n-d) >> 1) +1;
    cout << l << " " << l+d-1 << " ";
    auto rgsum = [&](int l,int r) -> int {
        // l = abs(l),r = abs(r);
        l = max(0LL,l);
        r = max(0LL,r);
        if(l > r) swap(l,r);
        int n = r-l+1;
        // cout << n << " " << (n*(n+1))/2 << " " << n*(l-1) << "\n";
        return ((n*(n+1))/2)+n*(l-1);
    };
    int r = l+d;
    int sum = 0;
    if(d < n) {
        sum += rgsum(0,l-1);
        int mid = (d >> 1);
        sum += rgsum(mid-(d%2 == 0),0);
        sum += rgsum(mid,0);
        sum += rgsum(0,n-r);
    } else {
        int mid = (n+1 >> 1);
        sum += rgsum(0,mid-1+(n%2 == 0));
        sum += rgsum(0,mid-1);
    }
    // return sum;
    cout << sum << "\n";
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while(T--) solve();
    // while(T--) cout << solve(6,4);
    // lop(i,0,T)
    // {
    //     int n = gc.randi(1,10),d = gc.randi(n,12);
    //         cout << n << " " << d << " : ";
    //     if(solve(n,d) == checker(n,d)) cout << "AC\n";
    //     else cout << "WA\n";
    // }
    // cout << "------\n";
    // lop(i,0,T)
    // {
    //     int n = gc.randi(3,10),d = gc.randi(1,n);
    //         cout << n << " " << d << " : ";
    //         cout << solve(n,d) << " " << checker(n,d) << "\n";
    //     if(solve(n,d) == checker(n,d)) cout << "Status: AC\n";
    //     else cout << "Status: WA\n";
    // }
    return 0;
}
