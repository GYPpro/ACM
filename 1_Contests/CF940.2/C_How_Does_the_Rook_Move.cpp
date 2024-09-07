#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fr first
#define se second

int N = 300010;;//

const int m = 1e9+7;

void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

    vector<int> arr;
class solution
{
private:
    void init()
    {
        arr.resize(N);
        arr[0] = 1;
        arr[1] = 3;
        int n = N-2;
        for(int i = 2;i < n;i ++)
        {
            arr[i] = 2LL * (i) * arr[i-2] % m;
            arr[i] += arr[i-1];
            arr[i] %= m;
        }
    }

public:
    void solve()
    {
        init();
        int t;
        cin >> t;
        while(t--){
            int n,k;
            cin >> n >> k;
            int thn = n;
            while(k --)
            {
                int u,v;
                cin >> u >> v;
                if(u != v) n -= 2;
                else n -= 1;
            }
            // cout << arr[thn] - arr[thn - n + 1] + 1 << "\n";
            if(n-1 <= 0) cout << 1 << "\n";
            else cout << arr[n-1] << "\n";
        }
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}