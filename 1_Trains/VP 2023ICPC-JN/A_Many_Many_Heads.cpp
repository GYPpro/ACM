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
    string s;cin>>s;
    int n=s.size();
    deque<int> q;
    bool f=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        // cout<<i<<" "<<cnt<<"\n";
        if(s[i]=='['||s[i]==']'){
            if(!q.empty()&&cnt%2==0){
                cnt=q.back();
                q.pop_back();
                f=0;
                
            }else{
                q.push_back(cnt);cnt=0;f=1;
            }
        }else cnt++;
        if(cnt>=4){
            cout<<"No\n";return;
        }
    }
    cnt=0;f=1;
    while(!q.empty()) q.pop_back();
    q.push_back(0);
    for(int i=0;i<n;i++){
        // cout<<i<<" "<<cnt<<"\n";
        if(s[i]=='['||s[i]==']'){
            if(!q.empty()&&cnt%2==0){
                cnt=q.back();
                q.pop_back();
                f=0;
                
            }else{
                q.push_back(cnt);cnt=0;f=1;
            }
        }else cnt++;
        if(cnt>=4){
            cout<<"No\n";return;
        }
    }
    cnt=0;f=0;
    while(!q.empty()) q.pop_back();
    for(int i=0;i<n;i++){
        // cout << i << " " << cnt << "\n";
        if(s[i]=='('||s[i]==')'){
            if(!q.empty()&&cnt%2==0){
                cnt=q.back();
                q.pop_back();
                f=0;
                
            }else{
                q.push_back(cnt);cnt=0;f=1;
            }
        }else cnt++;
        if(cnt>=4){
            cout<<"No\n";return;
        }
    }
    cnt=0;f=1;
    while(!q.empty()) q.pop_back();
    q.push_back(0);
    for(int i=0;i<n;i++){
        // cout << i << " " << cnt << "\n";
        if(s[i]=='('||s[i]==')'){
            if(!q.empty()&&cnt%2==0){
                cnt=q.back();
                q.pop_back();
                f=0;
                
            }else{
                q.push_back(cnt);cnt=0;f=1;
            }
        }else cnt++;
        if(cnt>=4){
            cout<<"No\n";return;
        }
    }
    cout<<"Yes\n";
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
