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
    }

    double randf(double l,double r) { return std::uniform_real_distribution<double>(l,r)(mt); }

    vector<double> randf(int n,double l,double r) {
        vector<double> rt;
        while(n--) rt.push_back(randf(l,r));
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

class XOR_Hash{
public:
    const int RG = 1e6+7;
    vector<int> V;

    XOR_Hash(){init();}
    void init()
    {
        V.resize(RG);
        for(auto &x:V) x = gc.randi(1e17,1e19);
    }
    int inh(int v){return V[v];};
} xh;

void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int> arr(n+1);
    lop(i,1,n+1) cin >> arr[i];
    for(auto &x:arr) x = xh.inh(x); 
    lop(i,1,n+1) arr[i] = arr[i-1] ^ arr[i];
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        // l --,r --;
        if(arr[l-1] ^ arr[r]) cout << "NO\n";
        else cout << "YES\n";
    }
    // lop(i,1,n+1) cout << arr[i] << " ";
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif

    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
