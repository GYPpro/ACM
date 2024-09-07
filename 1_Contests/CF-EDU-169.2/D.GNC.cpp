// #define D

// #define set unordered_set

#pragma GCC optimize(3)

#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb emplace_back
#define fi first
#define se second
const int INF = 11451810;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define a(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

signed main()
{
    freopen("1.in","w",stdout);
    vector<string> a = {"BG","BR","BY","GR","GY","RY"};
    int t = 1145;
    cout << t << "\n";
    srand(114514);
    while(t--)
    {
        int n = rand()%10+2;
        int q = rand()%10+2;
        cout << n << " " << q << "\n";
        lop(i,0,n) cout << a[rand()%6] << " ";
        cout << "\n";
        while(q--)
        {
            cout << rand()%n+1 << " " << rand()%n+1 << "\n";
        }
    }
    return 0;
}
