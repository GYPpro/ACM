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

int que(int i){
    cout << "? " << i << "\n";
    int t;
    cin >> t;
    return t;
}


void solve()
{
    int n,k;
    cin >> n >> k;
    int ans = 0;
    int l = n;
    while(l >= 2 * k){
        ans ^= que(l-k+1);
        l -= k;
    }
    if(l == k) ans ^= que(1);
    else {
        int t = l-k >> 1;
        ans ^= que(1) ^ que(t+1) ^ que(t*2+1);
    }
    cout << "! " << ans << "\n"; 
}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
/*



/*
 7 - 5 + 1

 | 1   2   3   4   5 | 6   7   -> 12345
   5 | 4   3   2   1   6 | 7   -> 12346
   5   6 | 1   2   3   4   7 | -> 12347  -> 1234567  l-k
   5   4   7   6   1   2   3   

 | 1   2   3   4   5   6 | 7   8   9   10    -> 1 2 3 4 5 6
   6   5   4   3 | 2   1   7   8   9   10 |  -> 1 2 7 8 9 10 -> 3-10
 | 6   5   4   3   10  9 | 8   7   1   2     -> 3 4 5 6 9 10 -> 7-8  -> 1 2 9 10 -> SUM^9,10
   9   10| 3   4   5   6   8   7 | 1   2     -> 3 4 5 6 7 8  -> 3-6


 | 1   2   3   4   5 | 6   7   -> 1 2 3 4 5 
   5   4 | 3   2   1   6   7 | -> 1 2 3 6 7 -> 4-7 
 | 5   4   7   6   1 | 2   3   -> 1 4 5 6 7 -> 1   -> 2-5 -> 2,3,6,7 
   1 | 6   7   4   5   2 | 3   -> 2 4 5 6 7 -> 2   -> 3-5 -> 3,6,7 

10->6
 | 1   2   3   4   5   6 | 7   8   9   10   -> 1,2,3,4,5,6
   6   5 | 4   3   2   1   7   8 | 9   10   -> 1,2,3,4,7,8  
   1   2   8   7 | 1   2   3   4   9   10 | -> 1,2,3,4,9,10  
   1   2   3   4   5   6   7   8   9   10   
   
12 -> 6

R1.1 >> | 1   2   3   4   5   6 | 7   8   9   10   11   -> 1, 2, 3, 4, 5, 6
R1.2 >>   6   5 | 4   3   2   1   7   8 | 9   10   11   -> 1, 2, 3, 4, 7, 8
R1.3 >>   6   5   8   7   1 | 2   3   4   9   10   11 | -> 2, 3, 4, 9, 10,11


R2.2 >>   6   5   4 | 3   2   1   7   8   9 | 10   11   -> 1, 2, 3, 7, 8, 9
R2.3 >>   6   5   4   9   8 | 7   1   2   3   10   11 | -> 1, 2, 3, 7, 10,11


*/