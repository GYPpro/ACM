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
        vector<int> req(n);
        for(int i = 0;i < n;i ++)
        {
            for(int j = i;j >= 0;j --)
            {
                req[i] = 1145141919810LL;
                if(arr[i] % (j+2) != 0){req[i] = i-j;break;}
            }
        }
        int lvt = 0;
        for(int i = 0;i < n;i ++)
        {
            if(lvt >= req[i]) lvt ++;
            else {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n"; 
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