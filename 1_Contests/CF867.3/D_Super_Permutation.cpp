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


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

class solution
{
private:

public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> b;
        vector<int> a(n);
        if(n == 1){cout << "1\n";return;}
        if(n%2) {cout << "-1\n";return;}
        bool q = 0;
        for(int i = 0;b.size() < n;i ++) b.pb(i),b.pb(n-1-i);
        // FI cout << b[i] << " ";
        a[0] = n;
        for(int i = 1;i < n;i ++) a[i] =(b[i] + n - b[i-1])%n;
        FI cout << a[i] << " ";
        cout << "\n";
    }
};

signed main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

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