#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
using pii = pair<int,int>;
#define pb push_back
const int INF = 1e15;
void solve()
{
	int n, m, k, d;
	cin >> n >> m >> k >> d;
	vector<vector<pii>> cnj(n+1);
	for(int i = 0;i < m;i ++)
	{
		int u,v;
		cin >> u >> v;
		cnj[u].pb({v,1});
		cnj[v].pb({u,1});
	}
	using itf = function<vector<int>(vector<pii>)>;
	itf dij = [&](vector<pii> tmp) -> vector<int> {
		vector<int> dis(n+1,INF);
		priority_queue<pii,vector<pii>,greater<pii>> q;
		for(auto x:tmp) q.push(x);
		for(auto [w,u]:tmp) dis[u] = w;
		vector<int> LOCK(n+1);
		while(q.size()) {
			auto [_,u] = q.top();
			q.pop();
			if(LOCK[u]) continue;
			else LOCK[u] = 1;
			for(auto [v,w]:cnj[u]){
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					q.push({dis[v],v});
				}
			}
		}
		return dis;
	};
	auto dis = dij({{0,k}});
	
	vector<int> prfx(d+1);
	iota(prfx.begin(),prfx.end(),0);
	reverse(prfx.begin(),prfx.end());
	for(int i = 1;i < prfx.size();i ++)prfx[i] += prfx[i-1];

	// for(auto x:prfx) cout << x << " ";cout << "\n";

	auto sef = [&](int x) -> int {
		int res,cmt;
		cmt = x/d;
		res = cmt * prfx[d-1];
		x -= cmt * d;
		// cout<< "|" << x << "|";
		return res + (x == 0 ? 0 : prfx[x - 1]);
	};

	if(dis[1] > d) {
		dis = dij({{0,n}});
		// cout << dis[1] << "\n";
		cout << sef(dis[1]) << "\n";
		return;
	}

	for(int i = 1;i <= n;i ++)
		for(auto &[v,w]:cnj[i]){
			w = dis[v] >= d ? INF : d - dis[v];
		}
	// for(auto x:dis) cout << x << " ";cout << "\n";
	
	auto dis2 = dij({{0,1}});
	// for(auto x:dis2) cout << x << " ";cout << "\n";

	// vector<pii> ender;
	// for(int i = 1;i <= n;i ++){
	// 	if(dis[i] == 1) ender.push_back({i,dis2[i]});
	// }

	for(int i = 1;i <= n;i ++)
		for(auto &[v,w]:cnj[i]){
			w = dis[i] < d ? INF : 1;
		}
	auto dis3 = dij({{0,n}});

	// for(auto x:dis3) cout << x << " ";cout << "\n";

	int TMI = dis2[n];

	for(int i = 1;i <= n;i ++){
		if(dis[i] == d-1){
			TMI = min(TMI,dis2[i] + sef(dis3[i]));
			// cout << dis2[i] << " " << dis3[i] << " " << dis3[i] << "\n";
		}
	}
	cout << TMI << "\n";
	
}
/*
5 7 2 2
1 2
1 3
2 4
2 3
3 4
3 5
4 5

5 7 2 3
1 2
1 3
2 4
2 3
3 4
3 5
4 5
*/

void check(){
	int d,x;
	cin >> d >> x;
	vector<int> prfx(d+1);
	iota(prfx.begin(),prfx.end(),0);
	reverse(prfx.begin(),prfx.end());
	for(int i = 1;i < prfx.size();i ++)prfx[i] += prfx[i-1];
	// for(auto x:prfx) cout << x << " ";cout << "\n";
	auto sef = [&](int x) -> int {
		int res,cmt;
		cmt = x/d;
		res = cmt * prfx[d-1];
		x -= cmt * d;
		// cout<< "|" << x << "|";
		return res + (x == 0 ? 0 : prfx[x - 1]);
	};
	cout << sef(x) << "\n";
}

signed main()
{
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 cout.tie(0);
	int t = 1;
	// cin >> t;
	// while(t--) check();
	// while (t--)
		solve();
	return 0;
}
