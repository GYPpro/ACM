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

int check(int n,vector<int> arr)
{
    auto dfs = [&](auto self,vector<int> cur,bool added) -> int{
        // for(auto x:cur) cout << x << " ";
        // system("pause");
        int cnt = 0;
        for(auto x:cur) if(x) cnt++;
        if(cnt <= 1) return 0;
        int minn = INT_MAX;
        lop(i,0,cur.size())
            lop(j,0,cur.size())
            {
                if(i == j) continue;
                if(!(cur[i] && cur[j])) continue;
                if(cur[i] > cur[j]) continue;
                auto tmp = cur;
                tmp[j] %= tmp[i];
                minn = min(self(self,tmp,added)+1,minn);
            }
        int maxn = 0;
        if(added) return minn;
        for(auto x:cur) maxn = max(maxn,x);
        lop(i,0,cur.size())
            lop(j,0,maxn)
            {
                if(!cur[i]) continue; 
                auto tmp = cur;
                tmp[i] += j;
                minn = min(self(self,tmp,1)+1,minn);
            }
        return minn;
    };
    return dfs(dfs,arr,0);
}

int solve(int n,vector<int> arr)
{
    // int n = rand()%4+1; 
    // // cin >> n;
    // vector<int> arr(n);
    
    // for(auto &x:arr) x = rand()%10+1;
    //  return n ;
    // for(auto x:arr)  return x ;
    //  return "---\n";
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
    if(N.size() <= 1) { return ans ; }
    int tgcd = N[1];
    lop(i,1,N.size()) tgcd = __gcd(N[i],tgcd);
    // for(auto x:N) tgcd = __gcd(x,tgcd);
    bool findGCD = 0;
    // for(auto x:N) if(x == tgcd) {findGCD = 1;break;}
    // if(findGCD) { return ans+N.size()-1 ; }
    //  return tgcd ;
    findGCD = 0;
    for(auto x:N) if(x <= tgcd) {findGCD = 1;break;}
    if(findGCD) { return ans+N.size() ; }


    auto v = N;
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
					 return ans+n;
					 
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
					 return ans+n;
					 
				}
			}
		}
	}
	if(n!=m)  return ans+n;
	else  return ans+n+1;

    //  return ans+N.size()+1 ;

}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while(T++)
    {
        // int n = rand()%4+1; 
        int n = 5;
        // // cin >> n;
            vector<int> arr(n);
        
        for(auto &x:arr) x = rand()%20+1;
    //  return n ;
    // for(auto x:arr)  return x ;
            cout << n << "\n";
            for(auto x:arr) cout << x << " ";cout << "\n";
        // int r1 = check(n,arr);
        cout << solve(n,arr) << "\n";
        system("pause");
        // if(r1 != r2)
        // {
        //     cout << "WA\n";
        //     cout << "check:" << r1 << " " << "solve:" << r2 << "\n";
        //     system("pause");
        // } else cout << "Ac:"<< T << "\n";
    }

    // for (int i = 0; i < T; i++) {solve();
    // system("pause");}

    // system("pause");

    return 0;
}
