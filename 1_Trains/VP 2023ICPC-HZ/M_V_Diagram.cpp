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
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int tmp=0;
    double ans=0;
    for(int i=1;i<n-1;i++){
        if(a[i]<a[i-1]&&a[i]<a[i+1]){
            int sum=a[i];
            int cnt=1;
            int cnt1=1,cnt2=1;
            int sum1=a[i],sum2=a[i];
            for(int j=i-1;j>=0;j--){
                if(a[j]>a[j+1]){
                    sum1+=a[j];
                    sum+=a[j];
                    cnt1++;
                    cnt++;
                }
                else break;
            }
            for(int j=i+1;j<n;j++){
                if(a[j]>a[j-1]){
                    sum+=a[j];
                    cnt++;
                    sum2+=a[j];
                    cnt2++;
                }
                else break;
            }
            sum1+=a[i+1];
            cnt1++;
            sum2+=a[i-1];
            cnt2++;
            double cur=(double)sum/cnt;
            if((double)sum1/cnt1 > cur) cur=(double)sum1/cnt1;
            if((double)sum2/cnt2 > cur) cur=(double)sum2/cnt2;
            ans=max(ans,cur);
        }
    }
    cout<<setprecision(15)<<ans<<"\n";
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
