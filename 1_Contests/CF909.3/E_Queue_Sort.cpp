#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    int m = a[0];
    int ni = 0;
    for(int i = 0;i < n;i ++)
    {
        if(a[i] < m){
            m = a[i];
            ni = i;
        }
    }
    bool c = 1;
    for(int i = ni;i < n-1;i ++)
    {
        if(a[i+1] < a[i]){
            c = 0;
            break;
        }
    } 
    if(c)
    {
        cout << ni << "\n";
    } else cout << "-1\n";
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