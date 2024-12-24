#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update>;
using ord_mset = tree<int,null_type,less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update>;
// #pragma GCC optimize(2)
#define int long long
#define pii pair<int,int>
#define se second
#define fi first

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
	map<int,int> ord;
	int prv = 0;
	
	auto pw = [&](int t) -> int {return t * t;};
	
	auto add = [&](pii t) -> int {
		if(ord.size() == 0) {
			ord.insert(t);
			return 0;
		}
		if(ord.size() == 1) {
			ord.insert(t);
			prv = pw(ord.begin()->se-ord.rbegin()->se);
			ord.insert({0,0});
			ord.insert({100004,100004});
			return prv;
		}
		auto tr = ord.upper_bound(t.fi);
		int sr = (tr)->se;
		int fr = (--tr)->se;
		ord.insert(t);

		if(fr == 0){
			prv += pw(t.se-sr);
			return prv;
		}
		if(sr == 100004)
		{
			prv += pw(t.se - fr);
			return prv;
		}
//		cout << "\n";
		prv -= pw(fr-sr);
		prv += pw(t.se - fr) + pw(t.se - sr);
		return prv;
	};
	
	int n,q;
	cin >> n >> q;
	vector<pii> stu(n+1); //[p,h]
	vector<pii> tmp(n+1);
	for(int i = 0;i < n;i ++)
	{
		cin >> stu[i].se;
	}
	for(int i = 0;i < n;i ++)
	{
		cin >> stu[i].fi;
	}
	
	auto push = [&](int k) -> void {
		k %= n;
		tmp = stu;
		for(int i = 0;i < n;i ++) stu[(i - k + n) % (n)] = tmp[i];
	};
	int k = 0;
	int prvans = 0;
	for(int i = 0;i <= q;i ++)
	{
		if(i != 0) cin >> k;
		// cout << "tar: " << k << " " << prvans << "\n";
		push(k+prvans);
		// for(auto x:stu) cout << x.fi << "," << x.se << " | ";
		prvans = 0;
		ord.clear();
		prv = 0;
		for(int j = 0;j < n;j ++) prvans += add(stu[j]);
//	,	cout << "\n===prv:" << prv << "===\n";
		cout << prvans << "\n";
	}
	return 0;
}