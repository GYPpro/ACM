#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fr first
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
        // int n,q;
        // cin >> n >> q;
        // string s;
        // cin >> s;
        // vector<int> sum(n+1);
        // bool t = 0;
        // FI
        // {
        //     int tmp;
        //     if(s[i] == '+') tmp = 1;
        //     else tmp = -1;
        //     if(t == 1) tmp *= -1;
        //     sum[i] = sum[i-1] + tmp;
        //     t = !t;
        // }
        // while(q --)
        // {
        //     int l,r;
        //     cin >> l >> r;
        //     set<int> pbd;
        //     if(l-r +1 %2 == 0) {
        //         pbd.insert(r);
        //         r --;
        //     }
            
        // }
        // D2
    // cin.tie(nullptr)->sync_with_stdio(false);
    // int _; for (cin >> _; _--;) {
        int n, q;
        cin >> n >> q;
        string _s;
        cin >> _s;
        vector<int> which(n);
        for (int i = 0; i < n; i++) {
            which[i] = (_s[i] == '-') != (i & 1);
        }
        vector<int> psum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + (which[i] ? -1 : 1);
        }
        while (q--) {
            int l, r;
            cin >> l >> r; l--; r--;
            if (psum[r + 1] == psum[l])  cout << "0\n\n";
            else {
                if ((r + 1 - l) & 1) cout << "1\n";
                else {
                    cout << "2\n";
                    cout << (r + 1) << ' ';
                    r--;
                }
                int d = min(psum[l], psum[r + 1]) + abs(psum[l] - psum[r + 1]) / 2;
                // d -> d+1
                int s = l;
                int e = r + 1;
                while (s + 1 < e) {
                    int m = (s + e) / 2;
                    if ((psum[m] <= d) == (psum[s] <= d)) s = m;
                    else e = m;
                }
                cout << s + 1 << "\n";
            }
        }
    // }


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
// #include <bits/stdc++.h>

// using i64 = long long;

// void solve() {
//     int n, q;
//     std::cin >> n >> q;
    
//     std::string s;
//     std::cin >> s;
    
//     int sum[n + 1];
//     sum[0] = 0;
//     for (int i = 0; i < n; i++) {
//         sum[i + 1] = sum[i] + (s[i] == '+' ? 1 : -1) * (i % 2 == 0 ? 1 : -1);
//     }
    
//     std::vector<int> p[4 * n + 1];
//     for (int i = 0; i < n; i++) {
//         p[sum[i] + sum[i + 1] + 2 * n].push_back(i);
//     }
    
//     auto get = [&](int l, int r) {
//         int x = sum[l] + sum[r] + 2 * n;
//         auto it = std::lower_bound(p[x].begin(), p[x].end(), l);
//         // assert(it != p[x].end() && *it < r);
//         return *it;
//     };
    
//     for (int i = 0; i < q; i++) {
//         int l, r;
//         std::cin >> l >> r;
//         l--;
//         if ((r - l) % 2 == 1) {
//             std::cout << "1\n";
//             std::cout << get(l, r) + 1 << "\n";
//         } else if (sum[l] == sum[r]) {
//             std::cout << "0\n";
//         } else {
//             std::cout << "2\n";
//             std::cout << l + 1 << " " << get(l + 1, r) + 1 << "\n";
//         }
//     }
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
    
//     int t;
//     std::cin >> t;
    
//     while (t--) {
//         solve();
//     }
    
//     return 0;
// }
