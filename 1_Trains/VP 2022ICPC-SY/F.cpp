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
int a,b;
string s[60];
// vector<vector<int>> v(10,vector<int>(10));
void check(int x,int y,int q,int w){
    bool f=0;
    char tmp=s[x][y];
    for(int i=x;i<=q;i++){
        for(int j=y;j<=w;j++){
            if(s[i][j]!=tmp) f=1;
        }
    }
    if(f==0) a++;
    else b++;
}
void solve()
{
    int n,m;
    cin >> n;
    if(n > 1e3) {cout << "ILLIG\n";return;}
    cin >> m;
    if(m > 1e3) {cout << "ILLIG\n";return;}
    int tmp=n*m;
    lop(i,0,n) cin >> s[i];
    // for(int i=0;i<(1<<tmp);i++){
    //     for(int j=0;j<n;j++){
    //         for(int k=0;k<m;k++){
    //             if((i>>(j*m+k)&1)) v[j][k]=1;
    //             else v[j][k]=0;
    //         }
    //     }
    //     // for(int j=0;j<n;j++){
    //     //     for(int k=0;k<m;k++){
    //     //         cout<<v[j][k]<<" \n"[k==m-1];
    //     //     }
    //     // }
        a=0,b=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=i;k<n;k++){
                    for(int l=j;l<m;l++){
                        check(i,j,k,l);
                    }
                }
                ans+=(n-i)*(m-j);
            }
        }
        cout<<a<<" "<<b<<" "<<ans<<"\n";
    //     if(a==b){
    //         for(int j=0;j<n;j++){
    //             for(int k=0;k<m;k++){
    //                 cout<<v[j][k]<<" \n"[k==m-1];
    //             }
    //         }
    //         cout<<"\n";
    //     }
    //     // cout<<" "<<a<<" "<<b<<"\n";
    // }
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         // for(int k=i;k<n;k++){
    //         //     for(int l=j;l<m;l++){
    //         //         check(i,j,k,l);
    //         //     }
    //         // }
    //         ans+=(n-i)*(m-j);
    //     }
    // }
    // cout << ans << "\n";
    // int q;cin>>q;
    // while(q--){
    // for(int i=0;i<n;i++) cin>>s[i];
        
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
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}


