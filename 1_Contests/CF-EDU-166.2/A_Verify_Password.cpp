#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define map unordered_map
#define set unordered_set

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
        string s;
        cin >> s;
        string digit;
        // bool f = 0;
        bool endf = 0;
        bool com = 1;
        for(int i = 0;i < s.size();i ++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                // f = 1;
                if(endf){com = 0;break;}
                digit += s[i];
            } else{
                endf = 1;
            }
        }
        string letter;
        for(int i = 0;i < s.size();i ++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                letter += s[i];
            }
        }
        
        bool flag = 1;
        for(int i = 1;i < digit.size();i ++)
        {
            if(digit[i] < digit[i-1]) {flag = 0;break;}
        }

        for(int i = 1;i < letter.size();i ++)
        {
            if(letter[i] < letter[i-1]) {flag = 0;break;}
        }

        // int a = digit[0];
        // int b = digit[0];
        // bool flag = 1;
        // for(int i = 1;i < digit.size();i ++)
        // {
        //     a ++,b --;
        //     if(digit[i] != a && digit[i] != b)
        //     {
        //         flag = 0;
        //         break;
        //     }
        // }
        // if(!digit.size()) flag = 0;
        // cout << digit << "\n";
        // cout << flag << "\n";
        // cout << com << "\n";
        if((flag) && (com)) cout << "Yes\n";
        else cout << "No\n";
        // // if(com) cout << digit << "\n";
        // // else cout << "No\n";
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