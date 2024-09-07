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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    lop(i,0,n)
        lop(j,0,n)
        {
            if(i == j) continue;
            if(arr[i] > arr[j]) swap(arr[i],arr[j]);
            if(arr[i] == 0) continue;
            if(arr[j]%arr[i] == 0) {arr[j] = 0;}
        }
    vector<int> N;
    for(auto x:arr) if(x) N.pb(x);
    sort(all(N));
    int ans = -N.size()+arr.size();
    if(N.size() <= 1) {cout << ans << "\n";return;}

	vector<int> v;
	for(int i=0;i<n;i++) if(arr[i]!=0) v.push_back(arr[i]);
	n=v.size();
	for(int i=0;i<n;i++){
		int g=0;
		for(int j=0;j<n;j++){
			if(i==j) continue;
			g=gcd(v[j],g);
		}
		if(g>=vi]){
			cout<<ans+n<<"\n";
			return;
		}
	}

    // int tgcd = N[1];
    // lop(i,1,N.size()) tgcd = __gcd(N[i],tgcd);
    // bool findGCD = 0;
    // for(auto x:N) if(x <= tgcd) {findGCD = 1;break;}
    // if(findGCD) {cout << ans+N.size() << "\n";return;}


    // auto v = N;
    n = N.size();
    int m = arr.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(i==j) continue;
			if(v[j]>v[i]){
				int c=v[j]%v[i];
				bool f=1;
				for(int k=0;k<n;k++){
					if(k==j) continue;
					if(v[k]%c!=0){
						f=0;
						break;
					}
				}
				if(f==1){
					cout<<ans+n<<"\n";
					return;
				}
			}
			else{
				int c=v[i]%v[j];
				bool f=1;
				for(int k=0;k<n;k++){
					if(k==i) continue;
					if(v[k]%c!=0){
						f=0;
						break;
					}
				}
				if(f==1){
					cout<<ans+n<<"\n";
					return;
				}
			}
		}
	}
	// if(n!=m)
    cout<<ans+n+1<<"\n";
	// else cout<<ans+n+1<<"\n";

    // cout << ans+N.size()+1 << "\n";

}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
