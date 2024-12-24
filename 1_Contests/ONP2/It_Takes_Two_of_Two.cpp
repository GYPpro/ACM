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
#define ld long double
int randi(int n){
    return (rand()*n)/RAND_MAX +1;
};

void simulate()
{
    int n;
    cin >> n;
    int cnt = 0,totlop = 0;
    vector<set<char>> cnj(n+1);
    srand(114514);
    auto check = [&]() -> bool {
        int freev = 0;
        // for(auto x:cnj) if(x.size() <= 1) freev ++;
        lop(l,1,n+1)
            lop(r,1,n+1)
                if(cnj[l].find(r) == cnj[l].end() && cnj[l].size() <= 1 && cnj[r].size() <= 1 && l != r) 
                    freev ++;
        if(freev >= 1) return 1;
        else return 0;
    };
    while(cnt <= 1e6)
    {
        cnt ++;
        cnj.clear();
        cnj.resize(n+1);
        while(check())
        {
            int l = randi(n),r = randi(n);
            if(cnj[l].find(r) == cnj[l].end() && cnj[l].size() <= 1 && cnj[r].size() <= 1 && l != r) cnj[l].insert(r),cnj[r].insert(l);
            totlop ++;
        }
    }
    cout << fixed << setprecision(9) << (ld)totlop/cnt << "\n";
}

void talor()
{
    // int n;
    // cin >> n;

}

void solve()
{
    int n;
    cin >> n;
    auto lim = [](ld x) -> ld {
        return (ld)1.0/(1.0-x);
    };
    // int c = n * n,pf = n;
    ld ans = 0;
    using itf = function<ld(int)>;

    map<int,ld> rec;
    rec[1] = 0.0,rec[2] = 2.0;

    itf f = [&](int x) -> ld {//f(x) 剩下X个非连通点的期望
        // if(x == 1) return 0.0;
        // if(x == 2) return 2.0;
        if(rec.find(x) != rec.end()) return rec[x];
        // ld curans = 0;
        int sit = x * x;
        ld curans = lim((ld)1/x);
        ld curp = 1.0 - ((ld)1/x);
        //[1,2]connected
        lop(i,2,x) // 逐个连通剩下的点（i：当前连通块大小）
        {
            // curans += curp;
            //正在连接第i个点和第i+1个点 
            // [1,2] -> [1,2,3]

      //->  curans += curp * (lim((ld)(x + (i-1)*2 )/sit)); //yes
            // // ld ped = (ld)(sz*(sz-1)-sz) / (x*x);
            // cout <<curp << " " << (x + (i-1)*2 ) << " " << sit << "\n";
            ld ped = (ld)(i > 2 ? 2:0)/(x*x); //A(i,2)/x**2
            ld pct = (ld)((x-i)*4.0)/(x*x) ;//(x-i)*2
            curans += lim(1.0 -ped -pct);
            curans += curp * ped * f(x-i);
            curp *= pct;
            // ped = max((ld)0.0,ped);
            // cout << "ct:" << pct << " " << " sf:" << 1.0 -ped -pct << "\n";
            // cout << "ed:" << ped << " " << "f(" << x-i << ")\n";
      //->     curans += curp * (ped * f( x -i ));
            // curp *= (1.0-ped);
        }
        //剩下最后一条边要连
        // cout << curp << " " << (sit-2) << " " << sit << "\n";
        curans += lim((ld)(sit-2)/sit);
        return rec[x] = curans;
    };

    // itf f = [&](int x) -> ld { //f(x) 剩下X个非连通点的期望
    //     //当前有x个非连通的点， 其余点均已经联通
    //     //->自身 1/x 
    //     if(x == 1) return 0.0;
    //     if(x == 2) return 2.0;
    //     ld ans = lim((ld)1/x);
    //     //链接剩余区间
    //     // 首先不选重复的，第一次可以随便选
    //     int c = x * x,pf = n;
    //     ld cur = 1;
    //     lop(i,1,x)
    //     {
    //         // 选出[1,2]以后，下一次：
    //         //立即闭合？不能 ->p = 0 
    //         // [1,2,3]立即闭合 -> [1,3]x2 A(n,2)-n 
    //         int n = i+1;//n:当前连通块大小
    //         ld p = (ld)(n*(n-1)-n) / (x*x); 
    //         ans += p * f(x-n);
    //         // ans += (1.0 - p) * 
    //         // ans += (1-p) * lim()
    //     }
    //     // 强制连通所有节点
    //     return ans;
    // };
    // while(f < c)
    // {
    //     ans += lim((ld)f/c);
    //     f += 2;
    // }
    cout << fixed << setprecision(9) << f(n) << "\n";
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
    // cin >> T;
    while(T--) solve();
    return 0;
}
/*

114
3
8.248251752
4
11.336338664
5
17.039785960
6
26.048727951
 */