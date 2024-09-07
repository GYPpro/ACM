// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;


class KMP
{
private:
    string s;
    string inis;
public:
    vector<int> pi;
    KMP(string _s)
    {
        s = _s;
        inis = s;
    }
    void prefix_function()
    {
        pi.clear();
        int n = (int)s.length();
        pi.resize(n);
        for (int i = 1; i < n; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j] && (s[i] != '?' && s[j] != '?'))
                j = pi[j - 1];
            if (s[i] == s[j] || s[j] == '?' || s[i] == '?')
                j++;
            pi[i] = j;
        }
        return;
    }
    vector<int> find_occr(string p)
    {
        s = inis;
        s = p + "#" + s;
        prefix_function();
        vector<int> v;
        for (int i = p.size() + 1; i < s.size(); i++)
            if (pi[i] == p.size())
                v.push_back(i - 2 * p.size());
        return v;
    }
};
bool a = true;
void solve()
{
    string s1,s2;
    cin  >> s1 >> s2;
    int p1  =  0,p2= 0;
    // vector<int> ans;
    while(p1 < s1.size() && p2 < s2.size())
    {
        if(s1[p1] == '?'  || s1[p1] == s2[p2]) {
            s1[p1] = s2[p2];
            p1 ++,p2 ++;
        } else p1++;
    }
    // cout  << p1 <<  " " << p2 << "\n";
    if(p2 != s2.size()) {cout << "NO\n";}
    else {
        cout << "YES\n";
        for(auto &x:s1) x = (x=='?' ? 'a' : x);
        cout << s1 << "\n";
    }
    // KMP kmp(s1);
    // auto rt = kmp.find_occr(s2);
    // if(rt.size() ==  0) cout << "NO\n";
    // else {
    //     cout << "YES\n";
    //     int a = rt[0];
    //     string ans;
    //     // cout << rt[0] << " "  <<  s2.size() << "\n";
    //     for(int i = 0;i < s1.size();i ++)
    //     {
    //         if(i >= a && i < a + s2.size()) ans.pb(s2[i-a]);
    //         else ans.pb(s1[i] == '?' ? 'a' : s1[i]);
    //     }
    //     cout  << ans <<  "\n";
    // }
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
