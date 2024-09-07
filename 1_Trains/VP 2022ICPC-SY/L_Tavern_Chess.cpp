// #define D

// #define set unordered_set
// #define map unordered_map

#pragma GCC optimize(2)

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

double ans[3];
// vector<int> ha(10),hb(10);
int n,m;
// void init(vector<int>&a,vector<int>&b,vector<int>&ha,vector<int>&hb,vector<int>&c,vector<int>&d){
//     bool f=0;
//     for(int i=n-1;i>=0;i--){
//         if(a[i]<=0){
//             if(f==1){
//                 for(int j=i;j<n-1;j++){
//                     swap(a[j],a[j+1]);
//                     swap(ha[j],ha[j+1]);
//                     swap(c[j],c[j+1]);
//                 }
//                 break;
//             }
//         }else f=1;
//     }
//     f=0;
//     for(int i=m-1;i>=0;i--){
//         if(b[i]<=0){
//             if(f==1){
//                 for(int j=i;j<m-1;j++){
//                     swap(b[j],b[j+1]);
//                     swap(hb[j],hb[j+1]);
//                     swap(d[j],d[j+1]);
//                 }
//                 break;
//             }
            
//         }else f=1;
//     }
// }
void dfs(vector<int> &a,vector<int> &b,vector<int> &ha,vector<int> &hb,vector<int> &c,vector<int> &d,int f,double tt){
    // init(a,b,ha,hb,c,d);
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            cnt1++;
        }
    }
    for(int i=0;i<m;i++){
        if(b[i]>0){
            cnt2++;
        }
    }
    if(cnt2==0&&cnt1==0){
        // cout<<"la==0&&lb==0:  "<<tt<<" "<<f<<"\n";
        ans[2]+=tt;
        return;
    }else if(cnt2==0){
        // cout<<"lb==0:  "<<tt<<"\n";
        ans[0]+=tt;
        return;
    }else if(cnt1==0){
        // cout<<"la==0:  "<<tt<<"\n";
        ans[1]+=tt;
        return;
    }
        if(f==1){
            int mi=1e9,tmp;
            for(int i=0;i<n;i++){
                if(a[i]<=0) continue;
                if(c[i]<mi){
                    mi=c[i];tmp=i;
                }
            }
            for(int i=0;i<m;i++){
                if(b[i]<=0) continue; 
                a[tmp]-=hb[i];
                c[tmp]++;
                b[i]-=ha[tmp];
                // cout<<f<<" "<<tt<<" "<<i<<"\n";
                dfs(a,b,ha,hb,c,d,f^1,(double)tt/cnt2);
                a[tmp]+=hb[i];
                b[i]+=ha[tmp];
                c[tmp]--;
            }
        }else{
            int mi=1e9,tmp;
            for(int i=0;i<m;i++){
                if(b[i]<=0) continue;
                if(d[i]<mi){
                    mi=d[i];tmp=i;
                }
            }
            for(int i=0;i<n;i++){
                if(a[i]<=0) continue;
                b[tmp]-=ha[i];
                d[tmp]++;
                a[i]-=hb[tmp];
                // cout<<f<<" "<<tt<<" "<<i<<"\n";
                dfs(a,b,ha,hb,c,d,f^1,(double)tt/cnt1);
                b[tmp]+=ha[i];
                d[tmp]--;
                a[i]+=hb[tmp];
            }
        }
    // }
    

}
void solve()
{
    // int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m),ha(n),hb(m),c(n),d(m);
    for(int i=0;i<n;i++){
        cin>>a[i];ha[i]=a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];hb[j]=b[j];
    }
    if(n==m){
        dfs(a,b,ha,hb,c,d,1,0.5);
        // for(int i=0;i<n;i++) cout<<a[i]<<" \n"[i==n-1];
        
        dfs(a,b,ha,hb,c,d,0,0.5);
    }
    else if(n>m){
        dfs(a,b,ha,hb,c,d,1,1.0);
    }else dfs(a,b,ha,hb,c,d,0,1.0);
        
    for(int i=0;i<3;i++){
        cout<<setprecision(15)<<ans[i]<<" ";
    }
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
