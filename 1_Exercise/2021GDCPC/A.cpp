#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// #define map unordered_map
// #define set unordered_set

#include <queue>
#include <map>
#include <set>
#include <unordered_set>
// #include <queue>
#include <stack>
#include <math.h>

#pragma GCC optimize(2)

using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define lop(i, a, b) for (int i = a; i < b; i++)
#define rlop(i, a, b) for (int i = a; i >= b; i--)
#define all(x) x.begin(), x.end()

signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    set<pair<int,pair<int,int>>> pq;
    pq.insert({m*n,{max(m,n),min(m,n)}});
    unordered_set<pair<int,int>> s;
    s.insert({m,n});
    vector<int> ansL(k+5);
    int curt = 0;
    int i = m,j = n;
    while(curt < k && i > 0 && j > 0)
    {
        auto t = *pq.rbegin();
        pq.erase(t);
        i = t.se.fi;
        j = t.se.se;
//         cout << i << " " << j << "\n";
        if(i <= n && j <= m) {ansL[curt] = i*j;curt ++;};
//         if(j <= n && i <= m) ansL.pb(i*j);
        if(i != j) {swap(i,j);
        if(i <= n && j <= m) {ansL[curt] = i*j;curt ++;};
//         if(j <= n && i <= m) ansL.pb(i*j);
        swap(i,j);}
        if(s.find({max(i-1,j),min(i-1,j)}) == s.end())
        {
            pq.insert({(i-1)*j,{max(i-1,j),min(i-1,j)}});
            s.insert({max(i-1,j),min(i-1,j)});
        }
        if(i != j)if(s.find({max(i,j-1),min(i,j-1)}) == s.end())
        {
            pq.insert({i*(j-1),{max(i,j-1),min(i,j-1)}});
            s.insert({max(i,j-1),min(i,j-1)});
        }
        // pq.push({i*(j-1),{i,j-1}});
        // if(j >= 2)pq.push({i*(j-2),{i,j-2}});
    }
    cout << ansL[min(k-1,(int)ansL.size())] << "\n";
//     for(auto x:ansL) cout << x <<" ";
}