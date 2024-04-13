#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>


#define int long long
#define mod1 998244353
#define pb push_back

using namespace std;

class solution
{
private:
public:
    int solve(int x, int y, int p, int q)
    {
        // int x,y,p,q;
        // cin >> x >> y >> p >> q;
        vector<vector<vector<int>>> sta(x + 1, vector<vector<int>>(y + 1, {0, 0}));
        // auto fst = [&](int lx,int ly,bool ps) -> int&{
        //     return sta[lx][ly][ps];
        // };
        auto chk = [&](int lx, int ly, bool ps) -> bool
        {
            // if(ps)
            if (x - lx + q >= y - ly)
                return 1;
            else if (x - lx != 0)
                return 0;
            else
                return 1;
            // else if(lx + q >= ly) return 1;
            //     else return 0;
        };
        auto dfs = [&](int lx, int ly, bool ps, auto self) -> int
        {
            // if(ps) cout << lx << " " << ly << " " << x - lx <<" " << y-ly << " " << ps << "\n";
            // else cout << x - lx <<" " << y-ly << " " << lx << " " << ly << " " << ps << "\n";
            if (!chk(lx, ly, ps))
            {
                return 1145141919810LL;
            } // cout << "--FL--\n";
            if (sta[lx][ly][ps])
                return sta[lx][ly][ps];
            if (ps == 0 && lx == x)
            {
                return 1;
            } // cout << "--ED--\n";
            sta[lx][ly][ps] = 1145141919810LL;
            int t = 1145141919810LL;
            if (ps)
                for (int i = 0; i <= lx; i++)
                    for (int j = 0; j <= min(ly, p - i); j++)
                        t = min(t, self(x - lx + i, y - ly + j, !ps, self));

            // for(int i = 0;i <= min(p,lx);i ++)
            //     t = min(t,self(x-lx+i,y-ly+min(ly,p-i),!ps,self));
            else
                for (int i = 0; i <= ly; i++)
                    t = min(t, self(x - lx, y - ly + i, !ps, self));
            // cout << "---rt---\n";
            // if(ps) cout << lx << " " << ly << " " << x - lx <<" " << y-ly << " " << ps << "\n";
            // else cout << x - lx <<" " << y-ly << " " << lx << " " << ly << " " << ps << "\n";
            return sta[lx][ly][ps] = t + 1;
        };
        return (dfs(x, y, 1, dfs) >= 1145141919810LL ? -1 : sta[x][y][1] - 1);
    }
};
class solution2
{
private:
public:        const int N = 1e6 + 2050, INF = 0x3f3f3f3f;
        int ans = 1e6;
        int p, q;
        bool ok = 1;
        int f = 0;
    void dfs(int a, int b, int ra, int rb, int cnt, int f1)
    {

        while (ok)
        {
            // cout<<a<<" "<<b<<"          "<<ra<<" "<<rb<<"\n";
            int k = p;
            int cur_a = 0, cur_b = 0;
            if (f1 == 1)
            { // 在左边
                if (p >= a)
                { // 直接运输所有羊
                    cnt++;
                    break;
                }
                if (b - q < a)
                {
                    if (k >= a - (b - q))
                    {
                        k -= (a - (b - q));
                        cur_a += (a - (b - q));
                        a = b - q;
                    }
                }
                else if (b - q > a)
                {
                    if (k >= b - (a + q))
                    {
                        k -= (b - (a + q));
                        cur_b += (b - (a + q));
                        b = a + q;
                    }
                }
                if (a == b - q && k > 0)
                {
                    cur_a += k / 2;
                    cur_b += k / 2;
                    a -= k / 2;
                    b -= k / 2;
                    if (b > 0 && k % 2 == 1 && (ra + cur_a >= rb + cur_b + 1 || ra + cur_a == 0))
                        dfs(a, b - 1, ra + cur_a, rb + cur_b + 1, cnt + 1, -f1);
                }
                if (cur_a == 0)
                {
                    if (f == 4)
                    {
                        ok = 0;
                        break;
                    }
                    f++;
                }
                if (cur_a != 0)
                {
                    f = 0;
                }
                ra += cur_a;
                rb += cur_b;
                cnt++;
            }
            else
            { // 在右边
                if (ra != 0)
                {
                    if (rb - q > ra)
                    {
                        if (k >= rb - (ra + q))
                        {
                            cur_b += (rb - (ra + q));
                            rb = ra + q;
                        }
                        else
                        {
                            ok = 0;
                            break;
                        }
                    }
                    b += cur_b;
                }
                cnt++;
            }
            f1 = -f1;
            // cout<<a<<" "<<b<<"     "<<ra<<" "<<rb<<" f1:"<<f1<<"\n";
        }
        if (ok == 1)
            ans = min(cnt, ans);
        return;
    }
    int solve(int a, int b, int _p, int _q)
    {
        // int a,b;
        p = _p;
        q = _q;
        // cin>>a>>b>>p>>q;
        dfs(a, b, 0, 0, 0, 1);
        if (ans == 1e6)
            // cout << "-1\n";
            return -1;
        else
            // cout << ans << "\n";
            return ans;
        // return;
    }
};

signed main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
    int T = 10000;
    srand(114514);
    // cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        solution2 sl2;
        int x,y,p,q;
        x = rand()%10;
        y = rand()%10;
        p = rand()%10;
        q = rand()%10;
        int ans1 = sl.solve(x,y,p,q);
        int ans2 = sl2.solve(x,y,p,q);
        if(ans1 != ans2)
        {
            cout<<"wa:" << x <<"  " << y << " " << p << " " << q << "\n";
            cout << ans1 << " " << ans2 << "\n";
            system("pause"
            );
        }
        cout << "c";
    }

    // system("pause");

    return 0;
}