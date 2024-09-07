// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

bool comp(int a,int b) {return a < b;}
class solution
{
private:


public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        vector<int> a = arr;
        int MEX = 0;
        sort(all(a));
        lop(i,0,n) if(a[i] == MEX) MEX ++;

        map<int,int> cnt;
        for(auto x:a) cnt[x] ++;
        int sum = 0;
        // for(auto x:arr) if(x < MEX) sum ++;
        for(auto x:cnt) if(x.fi < MEX) sum += x.se;
        if(cnt[MEX+1] == 0 )
        {
            if(n > MEX)
            {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            return;
        }
        int l = n-1,r = 0;
        lop(i,0,n)
        {
            if(arr[i] == MEX+1)
            {
                l = min(l,i);
                r = max(r,i);
            }
        }
        // cout << l << " " << r << "\n";
        lop(i,l,r+1) arr[i] = MEX;
        a = arr;
        // MEX = 0;
        int MEXN = 0;
        sort(all(a));
        lop(i,0,n) if(a[i] == MEXN) MEXN ++;
        if(MEXN == MEX+1) cout << "Yes\n";
        else cout << "No\n";
        // if(sum < MEX)
        // {
        //     cout << "No\n";
        // } else {
        //     if(cnt[MEX+1] != 0)
        //     {
        //         cout << "No\n";
        //     }else cout << "Yes\n";
        // }
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
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}