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
#define FI for (int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second

using namespace std;
void sort(auto &x)
{
    sort(x.begin(), x.end());
};

class s1
{
private:
public:
    int solve(string s)
    {
        int n = s.size();
        vector<int> l9, l8, l6, l0;
        l8.resize(n + 1);
        l8[n] = 0;
        l6.resize(n + 1);
        l6[n] = 0;
        l9.resize(n + 1);
        l9[n] = 0;
        l0.resize(n + 1);
        l0[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            l9[i] = l9[i + 1];
            l8[i] = l8[i + 1];
            l0[i] = l0[i + 1];
            l6[i] = l6[i + 1];
            switch (s[i])
            {
            case '0':
                l0[i] = l0[i + 1] + 1;
                break;
            case '9':
                l9[i] = l9[i + 1] + 1;
                break;
            case '6':
                l6[i] = l6[i + 1] + 1;
                break;
            case '8':
                l8[i] = l8[i + 1] + 1;
                break;
            default:
                break;
            }
        }
        int dict = 0;
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case '0':
                dict += l0[i];
                break;
            case '8':
                dict += l8[i];
                break;
            case '9':
                dict += l6[i];
                break;
            case '6':
                dict += l9[i];
                break;
            default:
                break;
            }
        }
        return n * (n + 1LL) / 2LL - dict + 1LL;
        // return ans;
    }
};
class so
{
private:
public:
    int solve(string s)
    {
        auto rev = [&](int l, int r) -> void
        {
            while (r >= l)
            {
                if (s[l] == s[r] && s[r] == '9')
                {
                    s[l] = s[r] = '6';
                    l++, r--;
                } else if (s[l] == s[r] && s[r] == '6')
                {
                    s[l] = s[r] = '9';
                    l++, r--;
                } else {
                    if(s[l] == s[r] || (s[r] == '9' && s[l] == '6') || (s[r] == '6' && s[l] == '9')) {
                        l ++,r --;
                    } else {
                        swap(s[l],s[r]);
                        l ++,r --;
                    }
                }
            }
        };
        string s0 = s;
        int cnt = 0;
        set<string> vst;
        for(int i = 0;i < s.size();i ++)
            for(int j = i;j < s.size();j ++)
                {
                    rev(i,j);
                    if(s != s0) {if(vst.find(s) == vst.end()){
                        // cout << s << "\n";
                        vst.insert(s);
                        cnt ++;
                    } }
                    s = s0;
                }
        return cnt+1;
    }
};

signed main()
{
    srand(114514);
    for (;;)
    {
        int n = 10;
        // vector<pair<int, int>> itv;
        string s;
        int r = 0;
        string t = "9680";
        for (int i = 0; i < 4; i++)
            s.pb(t[rand() % 4]);
        s1 a;
        int t1 = a.solve(s);
        so b;
        int t2 = b.solve(s);
        if (t1 != t2)
        {
            cout << "EX\n";
            cout << s << "\n";
            cout << t1 << " " << t2 << "\n";
            system("pause");
        }
        else
            cout << "ct..";
    }
}