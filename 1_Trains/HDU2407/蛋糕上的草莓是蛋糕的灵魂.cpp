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
    __int128 x,y;
        auto print = [&](__int128 n)
    {
        vector<char> c;
        while(n)
        {
            c.pb('0' + n%10);
            // cout << (int)(n%10);
            n /= 10;
        }
        if(c.size() == 0) cout << 0 << " ";
        for(int i = c.size()-1;i >= 0;i -- ) cout << c[i];
        cout << " ";
    };
    int x1,y1;
    cin >> x1 >> y1;
    x = x1,y = y1;
    __int128 t = __gcd(x1,y1);
    // int sx = x/t,sy = y/t;
    // if(t%2) t *= 2;
    __int128 lcm = x * y /t;
    if((lcm/x) %2 && (lcm/x) != 1) lcm *= 2;
    // print(lcm),cout << "\n";
    // if((lcm/y) %2 && (lcm/y) != 1) lcm *= 2;
    __int128 subc = (lcm/x)/2;



    print(y1),print(lcm/y1),cout << "\n";

    // cout << (int)lcm << " " << (int)lcm/y1 << "\n";
    // if((x/t)%2) t *= 2;
    // if((y/t)%2) t *= 2;
    
    // cout << 

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
