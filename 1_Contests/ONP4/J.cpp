#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lop(i,a,b) for(int i = a;i < b;i ++)
// #define map unordered_map
#pragma GCC optimize(3)
#define pb push_back
const int INF = 100;

// pii cel(vector<string> &mtx,bool f)
// {// f=0:当前O，反之当前X
//     vector<pair<int,pii>> cels;
//     map<char,int> cnt;
//     auto cacu = [&](int i,int j) -> int {
//         cnt.clear();
//         int con = 0;
//         lop(k,0,3) cnt[mtx[i][k]] ++;
//         if(cnt['O'] == 2 || cnt['X'] == 2) con += INF;
//         con += max(0LL,cnt['O']-cnt['X']);
//         cnt.clear();
//         lop(k,0,3) cnt[mtx[k][j]] ++;
//         if(cnt['O'] == 2 || cnt['X'] == 2) con += INF;
//         con += max(0LL,cnt['O']-cnt['X']);
//         if(i == j)
//         {
//             // if(mtx[0][0] == mtx[2][2])
//             cnt.clear();
//             lop(k,0,3) cnt[mtx[k][k]] ++;
//             if(cnt['O'] == 2 || cnt['X'] == 2) con += INF;
//             con += max(0LL,cnt['O']-cnt['X']);
//         }
//         if(i == 2-j)
//         {
//             cnt.clear();
//             lop(k,0,3) cnt[mtx[k][2-k]] ++;
//             if(cnt['O'] == 2 || cnt['X'] == 2) con += INF;
//             con += max(0LL,cnt['O']-cnt['X']);
//         }
//         // cnt.clear();
//         // lop(k,0,3) cnt[mtx[k][j]] ++;
//         // if(cnt['O'] == 2 || cnt['X'] == 2) con += 1;
//         return con;
//     };
//     // cout << cacu(2,0) << " " << cacu(2,2) << "\n";
//     lop(i,0,3)
//         lop(j,0,3)
//         {
//             if(mtx[i][j] == '.') cels.pb({cacu(i,j),{i,j}});
//         }
//     sort(all(cels));
//     if(cels.back().fi > 0) return cels.back().se;
//     if(mtx[1][1] == '.') return {1,1};
//     return cels.back().se;
// }
 
// void solve()
// {
//     int f;
//     cin >> f; //f = 0:O先手,反之X先手
//     vector<string> mtx(3);
//     for(auto &s:mtx) cin >> s;
//     int steps = 0;
//     for(auto s:mtx)
//         for(auto x:s) if(x == '.') steps ++;
//     while(steps --)
//     {
//         auto cur = cel(mtx,f);
//         mtx[cur.fi][cur.se] = (f?'X':'O');
//         f = !f; 
//         // for(auto x:mtx) cout << x << "\n";
//         // cout << "--\n";
//     }
//     int ans = 0;
//     map<char,int> cnt;
//     lop(i,0,3)
//     {
//         cnt.clear();
//         lop(k,0,3) cnt[mtx[i][k]] ++;
//         if(cnt['O'] == 3) ans ++;
//         if(cnt['X'] == 3) ans --;
//     }
//     lop(j,0,3)
//     {
//         cnt.clear();
//         lop(k,0,3) cnt[mtx[k][j]] ++;
//         if(cnt['O'] == 3) ans ++;
//         if(cnt['X'] == 3) ans --;
//     }
//     cnt.clear();
//     lop(k,0,3) cnt[mtx[k][k]] ++;
//     if(cnt['O'] == 3) ans ++;
//     if(cnt['X'] == 3) ans --;
//     cnt.clear();
//     lop(k,0,3) cnt[mtx[k][2-k]] ++;
//     if(cnt['O'] == 3) ans ++;
//     if(cnt['X'] == 3) ans --;
//     cout << ans << "\n";
// }

class ali{
public:
    vector<string> mtx;
    bool curflag = 0;
    int cur = 1;
    int freeval = 1;
    int cacu()
    {
        int ans = 0;
        map<char,int> cnt;
        lop(i,0,3)
        {
            cnt.clear();
            lop(k,0,3) cnt[mtx[i][k]] ++;
            if(cnt['O'] == 3) ans ++;
            if(cnt['X'] == 3) ans --;
        }
        lop(j,0,3)
        {
            cnt.clear();
            lop(k,0,3) cnt[mtx[k][j]] ++;
            if(cnt['O'] == 3) ans ++;
            if(cnt['X'] == 3) ans --;
        }
        cnt.clear();
        lop(k,0,3) cnt[mtx[k][k]] ++;
        if(cnt['O'] == 3) ans ++;
        if(cnt['X'] == 3) ans --;
        cnt.clear();
        lop(k,0,3) cnt[mtx[k][2-k]] ++;
        if(cnt['O'] == 3) ans ++;
        if(cnt['X'] == 3) ans --;
        return ans;
    }

    void input()
    {
        mtx.resize(3);
        cin >> curflag;
        for(auto &s:mtx) cin >> s;
        for(auto s:mtx)
            for(auto x:s) if(x == '.') freeval ++;
    }

    ali nextTar()
    {
        ali nxt = *this;
        int thi = 0;
        lop(i,0,3)
            lop(j,0,3)
            {
                if(mtx[i][j] == '.') thi ++;
                else continue;
                if(thi >= cur){
                    nxt.mtx[i][j] = curflag?'O':'X';
                    cur ++;
                    goto FORTCESEND;
                }
            }
        FORTCESEND:;
        nxt.freeval --;
        nxt.cur = 1;
        nxt.curflag = !nxt.curflag;
        return nxt;
    }

    void print() const
    {
        cout << curflag << "-" << freeval << " " << cur << "\n";
        for(auto s:mtx) cout << s << "\n";
        cout << "\n";
    }

    bool check()
    {
        return freeval > cur;
    }

    // bool operator<(const ali &b) {
    //     if(this->mtx != b.mtx)
    //     return this->mtx < b.mtx;
    //     else return this->curflag < b.curflag;
    // }
    // bool operator>(const ali &b) {
    //     return !(*this < b);
    // }

    bool operator==(const ali &b) const {
        // if(this->mtx != b.mtx)
        return this->mtx == b.mtx && this->curflag == b.curflag;
        // return this->mtx == b.mtx;
        // else return this->curflag < b.curflag;
    }
};

struct cmp{
    size_t operator()(const ali &a) const {
        int sta = 0;
        int cur = 1;

        for(auto x:a.mtx)
            for(auto ch:x) 
            {
                if(ch == '.') sta += cur;
                if(ch == 'O') sta += 2*cur;
                cur *= 3;
            }
        sta <<= 1;
        sta += a.curflag;
        return sta;
        // if(a.mtx == b. mtx && a.curflag == b.curflag) return 0;
        // if(a.mtx > b.mtx) return 1;
        // if(a.mtx == b.mtx && a.curflag > b.curflag) return 1;
        // else return -1;
    }
};

unordered_map<ali,int,cmp> stu;

int dfs(ali p)
{
    // p.print();
    // system("pause");
    if(stu.find(p) != stu.end()) return stu[p];
    if(!p.check()) {
        // cout << "rt:" << p.cacu () << "\n";
        return p.cacu();
    }
    int ans = -INF;
    if(p.curflag) // 当前1（A）先走，则最大化答案
    {
        while(p.check())
            ans = max(dfs(p.nextTar()),ans);
    } else {
        ans = INF;
        while(p.check())
            ans = min(dfs(p.nextTar()),ans);
    }
    // cout << 
    // cout << "rt:" << ans << "\n";
    return stu[p] = ans;
}

void solve()
{
    ali cur;
    cur.input();
    // while(cur.check()) cur.nextTar().print();
    cout << dfs(cur) << "\n";
    // for(auto [ch,v]:stu) ch.print(),cout <<v << "\n";
}
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // init(5e5);
    int t = 1;
    cin >> t;
    while(t--) solve();
}