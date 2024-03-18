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
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        int maxn = arr[n-1];
        for(int i = n-2;i >= 0;i --)
        {
            if(arr[i] > maxn){
                vector<int> div;
                int tmp = arr[i];
                while(tmp)
                {
                    div.pb(tmp%10);
                    tmp /= 10;
                }
                int minD = 10;
                int maxD = 0;
                for(int i = 0;i < div.size()-1;i ++)
                {
                    if(div[i+1] > div[i])
                    {
                        cout << "NO\n";
                        return;
                    }
                }
                for(auto x:div)
                {
                    minD = min(minD,x);
                    maxD = max(maxD,x);
                }
                if(maxD > maxn){
                    cout << "NO\n";
                    return;
                }
                maxn = min(maxn,minD);
            }
            else 
                maxn = min(maxn,arr[i]);
        }
        cout << "YES\n";
        return;
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