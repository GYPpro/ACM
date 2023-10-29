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
#include <set>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

class segTree
{
public:
    vector<int> d;
    int S;

public:
    segTree(int n, int _S)
    {
        S = _S;
        d.resize(4 * n + 1, S);
    }

    // void build(int s,int t,int p)
    // {
    //     if(s == t){
    //         d[p] = S;
    //         return;
    //     }
    //     int m = s+((t - s) >> 1);
    //     build(s,m,p*2);
    //     build(m+1,t,p*2+1);
    //     d[p] = max(d[p*2] + d[(p*2) +1]);
    // }

    pair<int, int> getNum(int s, int t, int p, int TR)
    {
        if (s == t)
        {
            // pair<int, int> mpL = pair<int, int>(d.size(), S);
            if(TR <= d[p]) return pair<int,int>(t,d[p]);
            return pair<int, int>(d.size(), S);
        }
        int m = s + ((t - s) >> 1);
        // pair<int, int> mpL = pair<int, int>(t, 0);
        // pair<int, int> mpR = pair<int, int>(t, 0);
        if (TR <= d[p * 2])
            return getNum(s, m, p * 2, TR);
        else if (TR <= d[p * 2 + 1])
            return getNum(m + 1, t, p * 2 + 1, TR);
        else return pair<int,int>(d.size(),0);
        // if (mpL.first < mpR.first)
        //     return mpL;
        // else
        //     return mpR;
    }

    int update(pair<int, int> c, int s, int t, int p)
    {
        if (s == t)
            return d[p] = c.second;
        int m = s + ((t - s) >> 1);
        if (c.first > m)
            update(c, m + 1, t, p * 2 + 1);
        else
            update(c, s, m, p * 2);
        d[p] = max(d[p * 2], d[p * 2 + 1]);
        return 0;
    }
};

void solve()
{
    int n, S;
    cin >> n >> S;
    set<pair<int, int>> arrset;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    int ansa = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     auto it = arrset.lower_bound(pair<int, int>(ansa, arr[i]));
    //     if (it == arrset.end())
    //     {
    //         arrset.insert(pair<int, int>(ansa, S - arr[i]));
    //         ansa++;
    //     }
    //     else
    //     {
    //         int t = (*it).second;
    //         int id = (*it).first;
    //         arrset.erase(it);
    //         arrset.insert(pair<int, int>(id, t - arr[i]));
    //     }
    // }

    int ansb = 1;
    segTree segtree(n, S);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> tar = segtree.getNum(1, n, 1, arr[i]);
        // if (tar.first != segtree.d.size())
        segtree.update(pair<int, int>(tar.first, tar.second - arr[i]), 1, n, 1);
        ansb = max(ansb,tar.first);
        // else
        // {
        //     ansb++;
        //     for (int j = segtree.d.size(); j <= 4*ansb; j++)
        //         segtree.d.push_back(S);
        //     // segtree.update(pair<int,int>(ansb,S),1,ansb,1);,.
        // }
    }    
    cout << ansb << " ";
    
    for (int i = 0; i < n; i++)
    {
        auto it = arrset.lower_bound(pair<int, int>(arr[i],ansa));
        if (it == arrset.end())
        {
            arrset.insert(pair<int, int>(S - arr[i]+1,ansa));
            ansa++;
        }
        else
        {
            int id = (*it).second;
            int t = (*it).first;
            arrset.erase(it);
            arrset.insert(pair<int, int>( t - arr[i],id));
        }
    }

    cout << ansa << endl;
    // cout << ansb - (ansb == 4) << endl;

    // for(int i = 0;i < n;i ++)
    // {
    //     auto it = arrst2.lower_bound(arr[i]);
    //     if(it == arrst2.end())
    //     {
    //         arrst2.insert(S-arr[i]);
    //         ansb ++;
    //     }
    //     else
    //     {
    //         int t = *it;
    //         arrst2.erase(it);
    //         arrst2.insert(S-t);
    //     }
    // }

}

#define _WITH_T_

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
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}