#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define inf 1e18
#define ll long long
#define F(i, a, b) for(int i = a; i <= b ; i++) 
#define sf scanf
#define pf printf 
#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define open(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout)
//#define M 1000010
#define M 101
using namespace std;

class SL1{
public:
int T = 1, n,m, len = 0, d[M];
vector<int> a;

int check(int def) {

	int remain = m;
	F(now, 1, n) {
		// walk a step to now point
		remain--;
		d[now] += a[now];
		if(d[now] < def) {
			
			int cnt = (def - d[now]) % a[now] == 0? (def-d[now])/a[now] : (def-d[now])/a[now] +1;
			
			remain -= cnt * 2;
			if(remain < 0) return 0;
			d[now + 1] += a[now + 1] * (cnt);
			if(now + 1 == n && d[now + 1] >= def) return 1; 
		}
	}
	
	return remain >= 0;
}

signed solve(int _n,int _m,vector<int> _a) {
    for(int i = 0;i < M;i ++) d[i] = 0;
	//open("E");
    a = _a;
    n = _n;
    m = _m;
	// cin >> T;
    T = 1;
	while(T--) {
		// cin >> n >> m;
		int tmp = 0, ans = 0;
		// F(i,1, n) cin >> a[i];
		F(i, 1, n)tmp = max(tmp, a[i]);
		
		int l = 0, r = tmp * m, mid = (l + r) >> 1;
		while(l<r){
			mid = (l+r)>>1;
			F(i,1,n)d[i]=0;
			if(check(mid)){
				ans = mid;
				l = mid+1;
			}
				 else r = mid-1;
		}
		F(i,1,n)d[i]=0;
		if(check(l)) ans = max(ans, l);
		return ans;
	}
    
} 
}
;

int solve(int n,int m,vector<int> a)
{
    // int n, m;
    // cin >> n >> m;
    // // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    auto check = [&](int k) -> bool
    {
        int sp = 0;
        vector<int> sum(n, 0);
        for (int i = 0; i < n; i++)
        {
            int cnt = (k - sum[i] + a[i] - 1) / a[i];
            sp += cnt;
            if (cnt > 0)
            {
                if (i + 1 < n)
                    sum[i + 1] += (cnt - 1) * a[i + 1];
                sp += (cnt - 1);
            }
            else
            { // cnt=0;
                if (i != n - 1)
                    sp++;
            }
        }
        return sp <= m;
    };
    //	cout<<n*(n+1)/2<<"\n";
    int l = 0, r = 1e18;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
        //		cout<<l<<" "<<r<<"\n";
    }

return l;
    // return;
}

signed main(){
    srand(114514);
    for(;;){
        int n = rand()%10;
        int m = rand()%20;
        vector<int> a(n);
        for(auto &x:a) x = rand()%10;
        SL1 sl1;
        int s1 = sl1.solve(n,m,a);
        int s2 = solve(n,m,a);
        if(s1 != s2) {
            cout << n << " " <<  m << "\n";
            for(auto x:a) cout << x << " ";
            cout << "\n";
            cout << s1 << " " << s2 << "\n";
            system("pause");
        } else cout << "ct..\n";
    }
}