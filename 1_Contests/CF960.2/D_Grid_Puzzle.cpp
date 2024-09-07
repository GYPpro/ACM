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
        for(auto &x:arr)cin >> x;
        vector<vector<int>> FREC(n+1,vector<int>(4,-1));
        auto gtf = [&](auto f,int i,int f1,int f2) -> int { //[f1][f1][f2][f2]
        // cout << "et:" << i << " " << f1 << " " << f2 << "\n";
            if(FREC[i][f1*2+f2] != -1) return FREC[i][f1*2+f2];
            if(i == 0) {
                if(arr[i] == 0) return FREC[i][f1*2+f2] = 0;
                if(arr[i] > 4) return FREC[i][f1*2+f2] = 1;
                if(arr[i] <= 2 && f1) return FREC[i][f1*2+f2] = 0;
                if(arr[i] <= 2 || f2) return FREC[i][f1*2+f2] = 1;
                // if(f1) return 1;
                return 1;
            }
            if(arr[i] == 0) return FREC[i][f1*2+f2] = f(f,i-1,0,0);
            if(arr[i]>4) return FREC[i][f1*2+f2] = f(f,i-1,0,0)+1;
            if(arr[i] <= 2 && f1) return FREC[i][f1*2+f2] = f(f,i-1,0,0);
            if(f1)  return FREC[i][f1*2+f2] = f(f,i-1,0,1) + 1;
            if(arr[i] <= 2 || f2) return FREC[i][f1*2+f2] = f(f,i-1,1,0) + 1;
            return FREC[i][f1*2+f2] = min(f(f,i-1,1,1)+2,f(f,i-1,0,0)+1);

        };
        cout << gtf(gtf,n-1,0,0) << "\n";
        // for(auto x:FREC){
        //     for(auto y:x) cout << y << " ";cout << "\n";}
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