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

void ask(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
}
void is_chain(){
    cout<<"! 1"<<endl;
}
void is_ju(){
    cout<<"! 2"<<endl;
}
void solve()
{
    int n;
    cin>>n;
    int tmp=-1,tmp1=-1;
    for(int i=1;i<=n;i+=2){
        int u=i,v=i+1;
        if(i+1>n) v=1;
        ask(u,v);
        int x;cin>>x;
        if(x==1){
            tmp=u;tmp1=v;
            break;
        }
    } 
    if(tmp==-1){
        is_chain();
        return;
    }
    // cout<<tmp<<" "<<tmp1<<endl;
    int a1=-1,a2=-1;
    for(int i=1;i<=n;i++){
        if(i==tmp||i==tmp1) continue;
        if(a1==-1) a1=i;
        else{
            a2=i;
            break;
        }
    }
    ask(tmp,a1);
    int x;cin>>x;
    if(x==1){
        ask(tmp,a2);
        cin>>x;
        if(x==1) is_ju();
        else is_chain();
    }
    else{
        ask(tmp1,a1);
        cin>>x;
        if(x==1){
            ask(tmp1,a2);
            cin>>x;
            if(x==1) is_ju();
            else is_chain();
        }
        else{
            is_chain();
        }
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
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}