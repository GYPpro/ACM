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


bool sg[50][50][50];
bool vis[50][50][50];
bool dfs(int a,int b,int c){
	if(vis[a][b][c]) return sg[a][b][c];
	bool f=0;
	//  分 a 
	for(int i=1;i<a;i++){
		if(dfs(i,a-i,c)==0) f=1;
		if(dfs(i,b,a-i)==0) f=1;
	}
	//  分 b 
	for(int i=1;i<b;i++){
		if(f==1) break;
		if(dfs(i,b-i,c)==0) f=1;
		if(dfs(a,i,b-i)==0) f=1;
	}
	//  分 a 
	for(int i=1;i<c;i++){
		if(f==1) break;
		if(dfs(i,c-i,a)==0) f=1;
		if(dfs(i,b,c-i)==0) f=1;
	}
	vis[a][b][c]=1;
	sg[a][b][c]=f;
	return f;
}
bool check(int a,int b,int c)
{
    vector<int> t = {a,b,c};
    sort(all(t));
    if(t[0] == t[1] && t[1] == 1) return !(t[2]%2);
    // t[0]uto gh = [&](int _t[0],int _t[1]) -> t[1]ool{
    //     if(_t[0] > _t[1]) swt[0]p(_t[0],_t[1]);
    //     if(_t[1]/_t[0] == 2 && _t[1]%_t[0] == 0) 
    // };
    if(t[1] == 2*t[0] || t[2] == 2*t[0] || t[2] == 2*t[1]) return 1;
    int f = (t[0]&-t[0]);

    if(f!= 1) if((t[1]&-t[1]) == f && (t[2]&-t[2]) == f) return 0;
    // if(((t[2]-t[1])%4) == 0 && ((t[1]-t[0])%4) == 0) return 0;
    if((t[0]%2) && (t[1]%2) && (t[2]%2)) return 0;
    return 1;
    // else return 0;
    // if(a==b&&a==c) return 0;
	// else if(a<=1&&b<=1&&c<=1){
	// 	if(dfs(a,b,c)==1) return 1;
	// 	else return 0;
	// }
	// else{
	// 	int cnt=(a&1)+(b&1)+(c&1);
	// 	if(cnt<3) return 1;
	// 	else return 0;
	// }
}


void solve(){
	int a,b,c;
	cin>>a>>b>>c;
    cout << (check(a,b,c)) ?"Yes\n":"No\n";
	// cout << dfs(a,b,c) << "\n";
    // lop(a,1,50)
    //     lop(b,a,50)
    //         lop(c,b,50)
    //         {
    //             if(dfs(a,b,c) != check(a,b,c))
    // //             {
    //                 cout << "WA at:";
    //                 cout << a << " " << b << " " << c << "\n";
    //                 cout << "dfs:" << dfs(a,b,c) << " check:" << check(a,b,c) << "\n";
    //                 system("pause");
    //             } else cout << "ac\n";
                // if(!dfs(a,b,c))
                // {
                //     cout << a << " " << b << " " << c << "\n";
                //     cout << bitset<8>(a) << " " << bitset<8>(b) << " " << bitset<8>(c) << "\n";
                // }
            // }
    
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

    for (int i = 0; i < T; i++) solve();

    system("pause");

    return 0;
}
