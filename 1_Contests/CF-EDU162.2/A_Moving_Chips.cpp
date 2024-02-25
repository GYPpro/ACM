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
        int cnt1 = 0;
        for(auto x:arr) if(x == 1) cnt1++;
        int cnt = 0;
        for(int i = n-1;i > 0;i --)
        {
            if(arr[i] == 1){
                int r = n-1;
                for(int j = n-1;j >= 0;j --)
                {
                    if(arr[j] == 1){ r = j;break;}
                }
                int f = r+1;
                for(int j = r;j >= 0;j --)
                {
                    if(arr[j] == 0){
                        f = r-j;
                        break;
                    }
                }
                if(f >= cnt1) break;
                cnt ++;
                arr[i] = 0;
                for(int j = i-1;j >= 0;j --)
                {
                    if(arr[j] == 0){
                        arr[j] = 1;
                        break;
                    }
                }

            }
        }
        cout << cnt << "\n";
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