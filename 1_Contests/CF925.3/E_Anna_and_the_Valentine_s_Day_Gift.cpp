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
        int n = 1,m;
        cin >> n >> m;
        m ++;
        int cntd = 0;
        vector<int> arr(n);
        for(int i = 0;i < n;i ++)
        {
            int t;
            cin  >> t;
            int rt = t;
            int ctz = 0;
            while(rt)
            {
                if(rt%10 == 0) ctz ++;
                else break;
                rt /= 10;
            }
            int ctc = 0;
            rt = t;
            while(rt)
            {
                ctc ++;
                rt /= 10;
            }
            arr[i] = ctz;
            cntd += ctc;
        }
        sort(arr.begin(),arr.end());
        bool flag = 0;
        for(int i = n-1;i >= 0;i --) cntd -= arr[i]*(flag = !flag);
        if(cntd >= m) cout << "Sasha\n";
        else cout << "Anna\n";
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