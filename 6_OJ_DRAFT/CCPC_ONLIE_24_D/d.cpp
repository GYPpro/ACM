#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ord_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
using ord_mset = tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>;
#define int long long 
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define map unordered_map
#define all(x) x.begin(),x.end()
#pragma GCC optimize(2)
const int N= 1e3+100;
vector<int> fac(N),inv(N);
const int mod=998244353;

/*
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
abcderasogihoauisovjudjamoicoadsmchomasodhgauiahiujlkskcjinjxkiruhromgraiadjifasxuifhmasindlkfhlakgh
*/
static const int mod1 = 1e9+7,base1 = 114;
static const int mod2 = 1e9+9,base2 = 514;



const pii INV = {-1,-1};

vector<int> val1,val2;
using puv = pair<int,int>;
void init(int n = N){
	val1.resize(n+1),val2.resize(n+1);
	val1[0] = 1,val2[0] =1;
	for(int i = 1;i <= n;i ++)
	{
		val1[i] = val1[i-1] * base1 % mod1;
		val2[i] = val2[i-1] * base2 % mod2;
	}
}

class hstring
{
public:
	vector<int> h1,h2;
	string s;
	hstring(string _s) : s(_s),h1{0},h2{0} { build();}
    hstring() { };
	
	void build()
	{
		for(auto it:s)
		{
			h1.pb((h1.back() * base1 % mod1 + it) % mod1);
			h2.pb((h2.back() * base2 % mod2 + it) % mod2);
		}
	}
	
	puv get(){
		if(h1.size() == 0) return INV;
		return {h1.back(),h2.back()};
	}
	
	puv substring(int l,int r) {
		if(h1.size() == 0) return INV;
		if(l > r) return INV;
		int ans1 = (mod1 + h1[r+1] - h1[l] * val1[r-l +1] % mod1) % mod1;
		int ans2 = (mod2 + h2[r+1] - h2[l] * val2[r-l +1] % mod2) % mod2;
		return {ans1,ans2};
	}
};

struct puvHash {
    std::size_t operator()(const puv& m) const {
        return std::hash<int>()((m.fi * 1000000000LL + m.se));
    }
};

void solve(){
	int n,m;
	string a,t;
	cin >> a >> t;
	hstring ha(a),ht(t);
	n = a.size(),m = t.size();
	map<puv,int,puvHash> sscnt; // n 
	map<puv,hstring,puvHash> rev;
	for(int i = 0;i < m;i ++)
		for(int j = i;j < m;j ++)
		{
			string tmp;
			for(int ii = i;ii <= j;ii ++) tmp.pb(t[ii]);
			hstring htmp(tmp);
			rev[htmp.get()] = htmp;
			sscnt[htmp.get()] = 0;
		}
	sscnt[INV] = 1;
	sscnt[ht.get()] = 0;
	map<puv,int,puvHash> newcnt;
	set<char> occr;
	auto addto = [&](char c) -> void { // n^2
		newcnt = sscnt;
		// for(auto x:sscnt) // iter prf and sef for each n -> n^2
		// {
		// 	// hstring substr(rev[x.fi]);
        //     auto & substr = rev[x.fi];
            auto & substr = ht;
			int rg = substr.s.size();
//			if(rg > )
			int curcnt = 0;
			if(substr.s.size() == 1) {
				curcnt = sscnt[substr.get()] * 2;
				if(substr.s[0] == c) curcnt ++;
				curcnt%=mod;
				newcnt[substr.get()] = curcnt;
				// continue;
			} else if(substr.s.size() != 0) {
                for(int i = 0;i <= rg;i ++)
                {
                    puv prfx = substr.substring(0,i-1);
                    puv	sefx = substr.substring(i,rg-1);
                    curcnt += sscnt[sefx] * sscnt[prfx] % mod;
                    if(curcnt>=mod) curcnt-=mod;
                }
                for(int i = 0;i < rg;i ++)
                {
                    if(substr.s[i] != c) continue;
                    puv prfx = substr.substring(0,i-1);
                    puv	sefx = substr.substring(i+1,rg-1);
                    curcnt += sscnt[sefx] * sscnt[prfx] % mod;
                    if(curcnt>=mod) curcnt-=mod;
                }
                newcnt[substr.get()] = curcnt%mod;
            }
		// }
		sscnt = newcnt;
		if(occr.find(c) == occr.end()) {
			occr.insert(c);
			string tc;
			tc.pb(c);
			if(sscnt[hstring(tc).get()] == 0) sscnt[hstring(tc).get()] ++;
		}
//		string tc;
//		tc.pb(c);
//		if(sscnt[hstring(tc).get()] == 0) sscnt[hstring(tc).get()] ++;
	};
	for(auto x:a) addto(x);
	cout << sscnt[ht.get()] % mod << "\n";
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}
