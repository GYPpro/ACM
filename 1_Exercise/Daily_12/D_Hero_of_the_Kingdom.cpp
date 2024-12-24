#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mod = 998244353;
mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};
void solve()
{
	ll p, a, b, q, c, d, m, t;
	cin >> p >> a >> b >> q >> c >> d >> m >> t;
	if (m < p)
	{
		cout << m << '\n';
		return;
	}

	ll curl = m/p;
    int inintm = m;

	ll total = 0;

	while(1){
		ll needM = (curl+1) * p - m;
		// ll rotdm = 
		// ll needM = (q-p) * curl;
		ll rotdm = (needM + ((q-p) * curl) - 1) / ((q-p) * curl);
        // rotdm = (rotdm + curl - 1)/curl;
		ll costTperR = (a+c) * curl + b + d;
		// cout << curl << " " << needM << " " << rotdm << " " << costTperR << " " << m << " " << t << "\n";
		if(costTperR * rotdm > t) {
			total += (t / costTperR) * curl;
			t -= costTperR * (t / costTperR);
			break;
		} else {
			m += rotdm * (q-p) * curl;
			total += rotdm * curl;
			// cout << total << "\n";
			t -= costTperR * rotdm;
			curl = m/p;
		}
	}

	ll final = max(0LL,min(m / p, (t - b - d) / (a + c)));

    // cout << total  << " " << final << "\n";

	cout << (total + final) * (q-p) + inintm << "\n";


	// int curt = min(m / p, (t - b - d) / (a + c));

	// while(1) {
	// 	int dm = (q - p) * curt;
	// 	int need = (p+dm)/dm;
	// 	if(t >= need * (curt * (a+c) + b + d)) {

	// 	} else {
	// 		t -= 
	// 	}

	// }

	// ll l = min(m / p, (t - b - d) / (a + c));
	// t -= (a + c) * l + b + d;
	// m += (q - p) * l;

	// cout << m << '\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}