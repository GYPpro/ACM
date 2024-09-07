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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    // lop()
    int al = 0,ar = n-1,bl = 0,br = n-1;
    lop(i,0,n)
    {
        // cout << a[i] << " " << b[bl] << " " << b[br] << "\n";
        if(a[i] == b[bl]) bl ++;
        else if(a[i] == b[br]) br --;
        else {
            cout << "Alice\n";
            return;
        }
    }
    al = 0,ar = n-1,bl = 0,br = n-1;
    for(int i = n-1;i >= 0;i --)
    {
        // cout << a[i] << " " << b[bl] << " " << b[br] << "\n";
        if(a[i] == b[bl]) bl ++;
        else if(a[i] == b[br]) br --;
        else {
            cout << "Alice\n";
            return;
        }
    }

    // while(al <= ar)
    // {
    //     if((a[al] != b[bl] && a[al] != b[br]) || (a[ar] != b[bl] && a[ar] != b[br])) {
    //         // cout << al << " " << ar << "\n";
    //         cout << "Alice\n";
    //         return;
    //     }
    //     al ++,ar --,bl ++,br --;
    // }
    cout << "Bob\n";
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
