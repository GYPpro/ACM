
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
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            sum += c[2] * 2;
        sum += c[a[i]] - 1;
    }
    sum /= 2;
    cout << sum << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T = 1;

    cin >> T;

    for (int i = 0; i < T; i++)
        solve();
    return 0;
}