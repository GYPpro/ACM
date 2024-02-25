#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define int long long
#define mod1 998244353
#define pb push_back

using namespace std;

class solution{
    private:

    public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> arr(n),rmin(n,n+1);
        for(auto &x:arr) cin >> x;
        int l = 0;
        for(int i = 1;i < n;i ++)
        {
            if(arr[i] != arr[i-1])
            {
                for(;l < i;l ++) rmin[l] = i;
            }
        }
        int q;
        cin >> q;
        while(q--)
        {
            int ql,qr;
            cin >> ql >> qr;
            ql --,qr --;
            if(rmin[ql] <= qr) cout << ql+1 << " " << rmin[ql]+1 << "\n";
            else cout << "-1 -1\n";
        }
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