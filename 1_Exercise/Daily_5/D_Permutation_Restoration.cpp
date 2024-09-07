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
#define fi first
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
        vector<int> arr(n);
        for (auto &x:arr) cin >> x;
        vector<pair<int,int>> arg(n);
        FI{
            if(arr[i] == 0) arg[i] = {(i+1)/(arr[i]+1)+1,n};
            else arg[i] = {(i+1)/(arr[i]+1)+1,(i+1)/arr[i]};
        }
        vector<pair<pair<int,int>,int>> srt(n);
        FI{
            // srt[i].fi = {arg[i].se-arg[i].fi,arg[i].fi};
            srt[i].fi = arg[i];
            srt[i].se = i;
        }
        sort(srt);
        vector<int> ans(n);
        int MEX = 0;
        bool prm = 1;
        set<pair<int,int>> minr2idx;
        FI{
            while(MEX < n && srt[MEX].fi.fi == i+1){
                minr2idx.insert({srt[MEX].fi.se,srt[MEX].second});
                MEX ++;
            }
            if(!minr2idx.size()){prm = 0;break;}
            auto t = *(minr2idx.begin());
            ans[t.second] = i+1;
            minr2idx.erase(minr2idx.begin());
            // if(srt[i].fi.fi < MEX || srt[i].fi.se > MEX){prm = 0;break;}
            // ans[srt[i].se] = MEX;
            // MEX ++;
        }
        if(prm) for(auto x:ans) cout << x << " ";
        else cout << "-1";
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