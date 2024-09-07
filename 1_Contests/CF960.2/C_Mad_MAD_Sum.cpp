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
        int  n;
        cin >> n;
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        int sum = 0;
        for(auto x:arr) sum += x;
        int ans = 0;
        ans += sum;
        // cout  << ans << "\n";
        vector<int> LopN(n);
        int MAD = 0;
        map<int,int> cnt;
        lop(i,0,n)
        {
            cnt[arr[i]] ++;
            if(cnt[arr[i]] >= 2 && arr[i] > MAD) MAD = arr[i];
            LopN[i] = MAD;
        }
        // for(auto x:LopN) cout << x << " ";cout << "\n";
        sum = 0;
        for(auto x:LopN) sum += x;
        ans += sum;
        cnt.clear(),MAD = 0;
        lop(i,0,n)
        {
            cnt[LopN[i]] ++;
            if(cnt[LopN[i]] >= 2 && LopN[i] > MAD) MAD = LopN[i];
            LopN[i] = MAD;
        }
        // for(auto x:LopN) cout << x << " ";cout << "\n";
        sum = 0;
        for(auto x:LopN) sum += x;
        ans += sum;
        while(sum)
        {
        // cout  << ans << "\n";
            sum -= LopN[LopN.size()-1];
            LopN.pop_back();
            ans += sum;
        }
        cout << ans << "\n";

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