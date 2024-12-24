#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<(1<<n);i++){
        for(int j=n-1;j>=0;j--){
            a[j]=(i>>j&1);
            // cout<<a[j];
        }
        // cout<<" ";
        int cur=0;
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                int cnt=0;
                for(int l=j;l<=k;l++){
                    cnt+=a[l];
                }
                cur+=(cnt&1);
            }
        }
        if(cur==6){
            cout<<i<<" : ";
            for(int i=n-1;i>=0;i--) cout<<a[i];
            // cout<<" ";
            // cout<<cur<<"\n";
            cout<<"\n";
        }
        // cout<<"\n";
    }
}
/*
6
bbrb
brbb
brbr
brrr
rbbr
rbrb
rbrr
rrbr
rrrb
rrrr

*/