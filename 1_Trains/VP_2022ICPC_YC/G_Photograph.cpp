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
    int n,q;
	cin >> n >> q;
	vector<int> h(n+2),p(n);
	lop(i,1,n+1) cin >> h[i];
	lop(i,0,n) cin >> p[i];
	vector<int> lb(n+2),rb(n+2);

	auto pw = [](int x) -> int {return x * x;};

	auto get = [&]() -> int {
		lop(i,1,n+1) lb[i] = i-1;
		lop(i,1,n+1) rb[i] = i+1;

		int cur = 0,ans = 0;
		lop(i,2,n+1) cur += pw(h[i]-h[i-1]);
		for(int i = n-1;i >= 0;i --) {
			// cout << cur << "\n";

			// for(auto x:lb) cout << x << " ";cout << "\n";
			// for(auto x:rb) cout << x << " ";cout << "\n";

			ans += cur;
			int it = p[i];
			// cout << "del:" << it << "\n";
			// 0 | [lb] --- [it] --- [rb] | n+1
			if(lb[it] == 0) {
				cur -= pw(h[it]-h[rb[it]]);
			} else if(rb[it] == n+1) {
				cur -= pw(h[it]-h[lb[it]]);
			} else {
				cur += pw(h[rb[it]]-h[lb[it]]);
				cur -= pw(h[it]-h[rb[it]]);
				cur -= pw(h[it]-h[lb[it]]);
			}
			rb[lb[it]] = rb[it];
			lb[rb[it]] = lb[it];
		}
		// cout << cur << "\n";
		return ans;
	};

	auto push = [&](int c) -> void {
		auto tp = p;
		c %= n;
		lop(i,0,n) p[(i+n-c )% n] = tp[i];
	};

	int prvans = get();
	cout << prvans << "\n";
	while(q--)
	{
		int k;
		cin >> k;
		push(k+prvans);
		prvans = get();
		cout << prvans << "\n";
	}
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
