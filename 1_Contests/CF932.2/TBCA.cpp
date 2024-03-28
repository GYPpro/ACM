#include <iostream>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

#define ll long long

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll k = 0;
    while (s[k] == s[s.size() - k - 1])
        k++;
    if (s[k] <= s[s.size() - k - 1])
    {
        cout << s << "\n";
        return;
    }
    else
    {
        string s1;
        for (ll i = s.size() - 1; i >= 0; i--)
        {
            s1 += s[i];
        }
        s1 += s;
        cout << s1 << "\n";
        return;
    }
}

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
    ll t;
    t = 1;
    cin >> t;
    while (t--)
        solve();
    system("pause");
}