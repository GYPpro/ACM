#include <bits/stdc++.h>
using namespace std; 
 
template <class X, class Y> bool mini(X &x, const Y &y){ if (x > y){ x = y; return true;} return false;}
template <class X, class Y> bool maxi(X &x, const Y &y){ if (x < y){ x = y; return true;} return false;}
 
typedef long long ll;
typedef pair <int, int> pii;
#define fi first
#define sc second
 
const int N = 2e5 + 1;
 
ll a[N], b[N];
ll prf[N], suf[N];
 
//1 2 4 6
//1 2 3 3 5 7
//6 3 2 5
 
void solve(){
    int n, m; cin >> n >> m;
 
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
 
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    memset(prf, 0, sizeof(prf));
    memset(suf, 0, sizeof(suf));
 
    for (int i = 1; i <= n; ++i){
        prf[i] = prf[i - 1] + abs(a[i] - b[m - i + 1]);
    }
 
    ll ans = prf[n];
 
    for (int i = n; i >= 1; --i){
        suf[i] = suf[i + 1] + abs(a[i] - b[n - i + 1]);
 
        //cout << suf[i] << ' ' << prf[i - 1] << '\n';
 
        maxi(ans, prf[i - 1] + suf[i]);
    }
 
    cout << ans << '\n';
 
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int T = 1; cin >> T;
    while (T--)
        solve();
    
    return 0;
}