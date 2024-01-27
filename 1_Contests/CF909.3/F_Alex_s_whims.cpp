#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
        cout << i << " " << i + 1 << "\n";
    int p = n,u = n,v1 = n - 1,v2 = 0;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == v1)
            cout << "-1 -1 -1\n";
        else
        {
            v2 = t;
            cout << u << " " << v1 << " " << v2 << "\n";
            v1 = v2;
        }
    }
}

int main()
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