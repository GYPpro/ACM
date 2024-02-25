#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#pragma GCC optimize(2)

#define int long long
#define mod1 998244353
#define pb push_back

using namespace std;

// AC 带懒惰标记线段树
class lazyTree
{
    /*
     *  TYPE_NAME需要支持：+ += != 和自定义的合并运算符
     *  实现了懒惰标记，仅支持区间批量增加
     *  区间批量减需要TYPE_NAME支持-，且有-a = 0 - a
     *  额外处理了一个单点修改为对应值的函数，非原生实现，其复杂度为 4logn
     *  不提供在线
     *  不提供持久化
     */
private:
    vector<int> sum;
    vector<int> a;
    int n;
    const int INI = 0; // 不会影响合并运算的初始值，如max取INF，min取0，mti取1

    void subbuild(int s, int t, int p)
    {

    }

    int subGetSum(int l, int r, int s, int t, int p)
    {

    }

public:
    lazyTree(int _n)
    {
        n = _n;
        sum.resize(n+1);
        a.resize(n+1);
    }

    void build(vector<int> _a)
    {
        a = _a;
        for(int i = 0;i < a.size();i ++) sum[i] = sum[i-1]+a[i];
    }

    int getsum(int l, int r)
    {
        return sum[r]-sum[l-1];
    }

};

class subAns
{
public:
    bool check(int t);
    int maxLim;
    int minLim;
    int getAns()
    {
        int l = minLim,
            r = maxLim + 1;
        while (l + 1 < r)
        {                          // 如果两点不相邻
            int mid = (l + r) / 2; // 取中间值
            if (check(mid))        // 如果可行
                l = mid;           // 升高锯片高度
            else
                r = mid; // 否则降低锯片高度
        }
        return l; // 返回左边值
    }
};

class solution
{
private:
public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        vector<int> pts(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        for (int i = 1; i <= n; i++)
            pts[i] = pts[i - 1] + (arr[i] != arr[i - 1]);
        lazyTree lz(n);
        lz.build(arr);
        vector<int> ans(n + 1);
        arr.pb(0);
        for (int i = 1; i <= n; i++)
        {
            int astr, astl;
            int maxLim = n;
            int minLim = i;
            int l = minLim,
                r = maxLim + 1;
            while (l + 1 < r)
            {                                       // 如果两点不相邻
                int mid = (l + r) / 2;              // 取中间值
                if ((lz.getsum(i + 1, mid) > arr[i]) && ((pts[mid]-pts[i+1] != 0))) // 如果可行
                    r = mid;                        // 左移
                else
                    l = mid; // 右移
            }
            astl = r - i;
            // cout << r << " " << astl << " " << lz.getsum(i+1,i+astl) << " ";
            maxLim = i;
            minLim = 1;
            l = minLim,
            r = maxLim + 1;
            while (l + 1 < r)
            {                                       // 如果两点不相邻
                int mid = (l + r) / 2;              // 取中间值
                if ((lz.getsum(mid, i - 1) > arr[i]) && ((pts[i-1]-pts[mid] != 0))) // 如果可行
                    l = mid;                        // 右移
                else
                    r = mid; // 左移
            }
            astr = i - l;
            // if(i-1 < 1) ; else cout << astr << " " << lz.getsum(max(1LL,i-astr),i-1) << " ";
            // cout << pts[min(n,i+astl)]-pts[i+1] << " " << pts[i-1]-pts[max(1LL,i-astr)] << "\n";
            if (i + 1 > n)
                astl = INT_MAX;
            else if ((lz.getsum(i + 1, min(n, i + astl)) <= arr[i]) || ((astl > 1) && (pts[min(n, i + astl)] - pts[i + 1] == 0)))
                astl = INT_MAX;

            if (i - 1 < 1)
                astr = INT_MAX;
            else if ((lz.getsum(max(1LL, i - astr), i - 1) <= arr[i]) || ((astr > 1) && (pts[i - 1] - pts[max(1LL, i - astr)] == 0)))
                astr = INT_MAX;

            // cout << "\n";
            // cout << astl << " " << astr << " \n";
            ans[i] = min(astl, astr);
            if (ans[i] == INT_MAX)
                ans[i] = -1;
            if((arr[i+1] > arr[i]) || (arr[i-1] > arr[i])) ans[i] = 1; 
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
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