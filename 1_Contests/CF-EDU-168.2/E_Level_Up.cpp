// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
ordered_multiset o_mset;
    ordered_set o_set;
    ...
    o_set.find_by_order(n);//返回第n+1小的元素的迭代器
                           //即序列增序时下标n对应元素
    o_mset.find_by_order(n);//同理
    o_set.order_of_key(n);//返回容器中严格小于n的元素的数量
    o_mset.order_of_key(n);//同理

*/
// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()


bool comp(int a,int b) {return a < b;}
class solution
{
private:


public:
    void solve()
    {
        int n,q;
        cin >> n >> q;
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        ordered_set prifixK;
        vector<int> mink(n);
        mink[0] = 1;
        prifixK.insert(1);
        lop(i,1,n)
        {
            auto check = [&](int k) -> bool{
                if((i+1-(prifixK.size()-prifixK.order_of_key(k))) > k*arr[i]-1) return 1;
                else return 0;
            };
            int l = 1, r = n+1;   // 因为是左闭右开的，所以 10^9 要加 1
            while (l + 1 < r) {       // 如果两点不相邻
                int mid = (l + r) / 2;  // 取中间值
                if (check(mid))         // 如果可行
                l = mid;              // 升高锯片高度
                else
                r = mid;  // 否则降低锯片高度
            }
            // return l;  // 返回左边值
            mink[i] = l+1;
            prifixK.insert(l-1);
        }
        // for(auto x:mink) cout << x << " ";
        while(q--)
        {
            int i,k;
            cin >> i >> k;
            if(mink[i-1] > k) cout << "NO\n";
            else cout << "YES\n";
        }

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
    // cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

#ifdef D
    system("pause");
#endif

    return 0;
}