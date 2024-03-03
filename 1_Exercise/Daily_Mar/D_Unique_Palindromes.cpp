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

const char _OVERFLOW_CHAR_ = 'z';

class solution{
    private:

    class IVC{
        char token = 'z';
        char usdToken = 'a';
        char maxn = 0;
        bool ifOV = 0;
        public:
        char next()
        {
            if(token == 'x') return token = 'y';
            if(token == 'y') return token = 'z';
            if(token == 'z') return token = 'x';
            return token;
        }
        // char next()
        // {
        //     if(token > _OVERFLOW_CHAR_) (token = 'a',ifOV = 1);
        //     maxn = max(maxn,token);
        //     char rt = token;
        //     token ++;
        //     return rt;
        // }
        char usd()
        {
            if(usdToken > min(_OVERFLOW_CHAR_,maxn)) usdToken = 'a';
            char rt = usdToken;
            usdToken ++;
            return rt;
        }
        char usd(char c)
        {
            usdToken = c+1;
            if(usdToken > min(_OVERFLOW_CHAR_,maxn)) usdToken = 'a';
            char rt = usdToken;
            usdToken ++;
            return rt;
        }
        bool ovf()
        {
            return ifOV;
        }
    };

    public:
    void solve()
    {
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> tk(k);
        for(auto &x:tk) cin >> x.first;
        for(auto &x:tk) cin >> x.second;
        sort(tk.begin(),tk.end());

        

        IVC ivc;
        string ans;
        int prnNum = 0;
        char thc = 'a'-1;
        for(auto x:tk)
        {
            thc ++;
            int dif = x.second - prnNum;
            int subl = x.first - ans.size();
            if(dif > subl){
                cout << "NO\n";
                return;
            }
            for(int i = ans.size();i < x.first;i ++)
            {
                if(i < 3) {
                    ans.pb(ivc.next());
                    prnNum += 1;
                    if(prnNum > x.second)
                    {
                        cout << "NO\n";
                        return;
                    }
                    continue;
                }
                if(prnNum < x.second)
                {
                    prnNum += 1;
                    ans.pb(thc);
                } else ans.pb(ivc.next());
            }
        }
        for(int i = ans.size();i < n;i ++) ans.pb('a');
        cout << "YES\n" << ans << "\n";
    }
    //     vector<int> sumf;
    //     for(auto x:tk)
    //     {
    //         for(int i = sumf.size();i < x.first;i ++)
    //         {
    //             if(prnNum < x.second){
    //                 sumf.pb(1);
    //                 prnNum ++;
    //             } else sumf.pb(0);
    //         }
    //         if(prnNum != x.second)
    //         {
    //             cout << "NO\n";
    //             return;
    //         }
    //     }
    //     for(int i = 0;i < min(3LL,n);i ++) 
    //         if(sumf[i] != 1)
    //         {
    //             cout << "NO\n";
    //             return;
    //         }
    //     // for(auto x:tk)
    //     // {
    //     //     int dif = x.second - prnNum;
    //     //     int subl = x.first - ans.size();
    //     //     if(dif > subl){
    //     //         cout << "NO\n";
    //     //         return;
    //     //     }
    //     //     for(int i = ans.size();i < x.first;i ++)
    //     //     {
    //     //         if(prnNum < x.second)
    //     //     }
    //     // }
    //     int flag = 0;
    //     int rvidx = 0;
    //     bool ctu1 = 0;
    //     for(auto x:sumf)
    //     {
    //         if(ivc.ovf())
    //         {
    //             if(ctu1)
    //             {
    //                 ans.pb(ans[rvidx]);
    //             }
    //         } else if(x) ans.pb(ivc.next());
    //         else ans.pb(ivc.usd());
    //     }
    // }
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