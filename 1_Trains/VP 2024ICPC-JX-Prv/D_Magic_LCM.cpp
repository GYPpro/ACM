#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N =2e5+100;
int m =998244353;
#pragma GCC optimize(3)
#define pii pair<int,int>
#define fi first
#define se second
#define lop(i,a,b) for(int i = a;i < b;i ++)
#define all(x) x.begin(),x.end()
#define ord(a,b) pii(min(a,b),max(a,b))
#define pb push_back
const int INF = 11451419198LL;
//const int N=2e5+100;

class Pollard_Rho
{
private:

    vector<int> B;

    int mul(int a, int b, int m)
    {
        int r = a * b - m * (int)(1.L / m * a * b);
        return r - m * (r >= m) + m * (r < 0);
    }

    int mypow(int a, int b, int m)
    {
        int res = 1 % m;
        for (; b; b >>= 1, a = mul(a, a, m))
        {
            if (b & 1)
            {
                res = mul(res, a, m);
            }
        }
        return res;
    }

    bool MR(int n)
    {
        if (n <= 1)
            return 0;
        for (int p : B)
        {
            if (n == p)
                return 1;
            if (n % p == 0)
                return 0;
        }
        int m = (n - 1) >> __builtin_ctz(n - 1);
        for (int p : B)
        {
            int t = m, a = mypow(p, m, n);
            while (t != n - 1 && a != 1 && a != n - 1)
            {
                a = mul(a, a, n);
                t *= 2;
            }
            if (a != n - 1 && t % 2 == 0)
                return 0;
        }
        return 1;
    }

    inline const int getfecsum(int _n)
    {
        int sum = 0;
        while (_n)
        {
            sum += _n % 10;
            _n /= 10;
        }
        return sum;
    };

    int PR(int n)
    {
        for (int p : B)
        {
            if (n % p == 0)
                return p;
        }
        auto f = [&](int x) -> int
        {
            x = mul(x, x, n) + 1;
            return x >= n ? x - n : x;
        };
        int x = 0, y = 0, tot = 0, p = 1, q, g;
        for (int i = 0; (i & 255) || (g = __gcd(p, n)) == 1; i++, x = f(x), y = f(f(y)))
        {
            if (x == y)
            {
                x = tot++;
                y = f(x);
            }
            q = mul(p, abs(x - y), n);
            if (q)
                p = q;
        }
        return g;
    }

    vector<int> fac(int n)
    {
        // if(n == 0)
        // #define pb emplace_back
        if (n <= 1)
            return {};
        if (MR(n))
            return {n};
        int d = PR(n);
        auto v1 = fac(d), v2 = fac(n / d);
        auto i1 = v1.begin(), i2 = v2.begin();
        vector<int> ans;
        while (i1 != v1.end() || i2 != v2.end())
        {
            if (i1 == v1.end())
            {
                ans.pb(*i2++);
            }
            else if (i2 == v2.end())
            {
                ans.pb(*i1++);
            }
            else
            {
                if (*i1 < *i2)
                {
                    ans.pb(*i1++);
                }
                else
                {
                    ans.pb(*i2++);
                }
            }
        }
        return ans;
    }

public:

    Pollard_Rho(){
        B = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    }

    vector<pii> fac_Comp(int n)
    {
        auto srt = fac(n);
        unordered_map<int, int> cnt;
        for (auto x : srt)
            cnt[x]++;
        vector<pii> rt;
        for (auto x : cnt)
            rt.push_back(x);
        return rt;
    }

    vector<int> fac_pri(int n)
    {
        return fac(n);
    }
    
    vector<int> fac_all(int n)
    {
        vector<pii> rt = fac_Comp(n);
        vector<int> v;
        function<void(int, int)> dfs = [&](int id, int x)
        {
            if (id == rt.size())
            {
                v.push_back(x);
                return;
            }
            for(int i = 0;i <= rt[id].se;i ++)
            {
                dfs(id + 1, x * (mypow(rt[id].fi, i, INF)));
            }
        };
        dfs(0, 1);
        return v;
    }
};
long long binpow(long long a, long long b) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
Pollard_Rho pr;
vector<int> arr;
unordered_map<int,vector<int>> cnt;
vector<int> rec;
map<int,int> tcnt;

auto cmp = [](int a,int b) {
		return a > b;
	};

void solve(){
	int n;
	cin >> n;
	arr.clear();
	arr.resize(n);
	cnt.clear();
	rec.clear();
	for(auto &x:arr) cin >> x;
	sort(all(arr));
	lop(i,0,n)
	{
		int t = arr[i];
		rec = pr.fac_pri(t);
        tcnt.clear();
        for(auto x:rec) tcnt[x] ++;
		for(auto x:tcnt) cnt[x.fi].pb(x.se);
	}
	for(auto &x:cnt) sort(all(x.se),cmp);
	int sum = 0;
	
	vector<vector<pii>> cnj(n+1);
	for(auto x:cnt) // [prinum,sums]
	{
//		cout << x.fi << ":";
		int t = 0;
		for(auto y:x.se) // (sum)
		{
//			cout << y << " ";
			cnj[t].pb({x.fi,y});
			t ++;
		}
//		cout << "\n";
	}
	
	lop(i,0,n){
		int t = 1;
		for(auto x:cnj[i])
		{
			t *= binpow(x.fi,x.se);
			t %= m;
		}
//		cout << t << " ";
		sum += t;
		sum %= m;
	}
	
	cout << sum << "\n";
}

signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int test=1;
	cin>>test;
	while(test--){
		
//		cout << "------\n";
		
		solve();
	}
	return 0;
} 
/*


*/
