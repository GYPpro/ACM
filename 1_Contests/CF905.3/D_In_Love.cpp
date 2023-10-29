#define _USE_IOSTREAM_
#define _PRIV_TEST_

#ifndef _USE_IOSTREAM_
#define _USE_STDIO_
#endif

#ifdef _USE_IOSTREAM_
#include <iostream>
#endif
#ifdef _USE_STDIO_
#include <stdio.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define ll long long
#define mod1 998244353
// #define maxn 1000100
#define ull unsigned long long

using namespace std;

// void build(int s, int t, int p, map<int,int> &a,map<int,int> &d) {
//   // 对 [s,t] 区间建立线段树,当前根的编号为 p
//   if (s == t) {
//     d[p] = a[s];
//     return;
//   }
//   int m = s + ((t - s) >> 1);
//   // 移位运算符的优先级小于加减法，所以加上括号
//   // 如果写成 (s + t) >> 1 可能会超出 int 范围
//   build(s, m, p * 2 ,a ,d), build(m + 1, t, p * 2 + 1,a ,d);
//   // 递归对左右区间建树
//   d[p] = min(d[p * 2],d[(p * 2) + 1]);
// }

// int getsum(int l, int r, int s, int t, int p, map<int,int> &a,map<int,int> &d,map<int,int> &b) {
//   // [l, r] 为查询区间, [s, t] 为当前节点包含的区间, p 为当前节点的编号
//   if (l <= s && t <= r) return d[p];
//   // 当前区间为询问区间的子集时直接返回当前区间的和
//   int m = s + ((t - s) >> 1);
//   if (b[p]) {
//     // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
//     d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
//     b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
//     b[p] = 0;                                // 清空当前节点的标记
//   }
//   int sum = 0;
//   if (l <= m) sum = getsum(l, r, s, m, p * 2 ,a ,d,b);
//   if (r > m) sum = min(getsum(l, r, m + 1, t, p * 2 + 1,a ,d,b),sum);
//   return sum;
// }

// void update(int l, int r, int c, int s, int t, int p, map<int,int> &a,map<int,int> &d,map<int,int> &b) {
//   // [l, r] 为修改区间, c 为被修改的元素的变化量, [s, t] 为当前节点包含的区间, p
//   // 为当前节点的编号
//   if (l <= s && t <= r) {
//     d[p] += (t - s + 1) * c, b[p] += c;
//     return;
//   }  // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
//   int m = s + ((t - s) >> 1);
//   if (b[p] && s != t) {
//     // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
//     d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
//     b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
//     b[p] = 0;                                // 清空当前节点的标记
//   }
//   if (l <= m) update(l, r, c, s, m, p * 2,a,d,b);
//   if (r > m) update(l, r, c, m + 1, t, p * 2 + 1,a,d,b);
//   d[p] = min(d[p * 2],d[p * 2 + 1]);
// }

void solve()
{
    int n;
    cin >> n;
    multiset<int> l,r;
    for(int i = 0;i < n;i ++)
    {
        char c;
        cin >> c;
        int al,ar;
        cin >> al >> ar;
        if(c == '+')
        {
            l.insert(al);
            r.insert(ar);
        } else {
            if(l.find(al) != l.end())
                l.erase(l.find(al));
            if(r.find(ar) != r.end())
                r.erase(r.find(ar));
        }
        if(r.empty() && r.empty()){
            cout << "NO\n";
            continue;
        }
        if(*(r.begin()) < *(l.rbegin())) cout << "YES\n";
        else cout << "NO\n";
    }

    // vector<vector<int>> qes;
    // int minn = INT_MAX;
    // int maxn = 0;
    // for(int i = 0;i < n;i ++)
    // {
    //     vector<int> tmpl(3);
    //     char c;
    //     cin >> c;
    //     if(c == '+') tmpl[0] = 1;
    //     else tmpl[0] = 0;
    //     cin >> tmpl[1];
    //     cin >> tmpl[2];
    //     qes.push_back(tmpl);
    //     a[tmpl[1]] = 0;
    //     minn = min(minn,tmpl[1]);
    //     minn = min(minn,tmpl[2]);
    //     a[tmpl[2]] = 0;
    //     maxn = max(maxn,tmpl[1]);
    //     maxn = max(maxn,tmpl[2]);
    // }
    // map<int,int> d,b;
    // build(minn,maxn,1,a,d);
    // for(int i = 0;i < n;i ++)
    // {
    //     if(qes[i][0] == 1)
    //     {
    //         update(qes[i][1],qes[i][2],1,qes[i][1],qes[i][2],1,a,d,b);
    //     } else {
    //         update(qes[i][1],qes[i][2],-1,qes[i][1],qes[i][2],1,a,d,b);
    //     }
    //     if(getsum(minn,maxn,minn,maxn,1,a,d,b) == 0) cout << "YES\n";
    //     else cout << "NO\n";
    // }

}

// #define _WITH_T_

int main()
{
    #ifndef _PRIV_TEST_
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    #endif
    int T = 1;

    #ifdef _WITH_T_
        #ifdef _USE_IOSTREAM_
            cin >> T;
        #endif
        #ifdef _USE_STDIO_
            scanf("%d",&T);
        #endif
    #endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}