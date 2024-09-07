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
        map<string,string> cnj = {
            {"imasu","tte"},
            {"chimasu","tte"},
            {"rimasu","tte"},
            {"mimasu","nde"},
            {"bimasu","nde"},
            {"nimasu","nde"},
            {"kimasu","ite"},
            {"gimasu","ide"},   
            {"shimasu","shite"}
        };
        string s;
        cin >> s;
        if(s == "ikimasu"){ cout << "itte\n";return;}
        string s7,s6;
        if(s.size() >= 7) {
            for(int i = s.size()-7;i < s.size();i ++) s7.push_back(s[i]);
        }
        for(int i = s.size()-6;i < s.size();i ++) s6.push_back(s[i]);
        if(cnj.find(s7) != cnj.end()){
            for(int i = 0;i < s.size()-7;i ++) cout << s[i];
            cout << cnj[s7];
            cout << "\n";
            return;
        } else if(cnj.find(s6) != cnj.end()){
            for(int i = 0;i < s.size()-6;i ++) cout << s[i];
            cout << cnj[s6];
            cout << "\n";
            return;
        }
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