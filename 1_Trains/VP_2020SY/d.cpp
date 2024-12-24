#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        if(i==(n/2)+1) s+='1';
        else s+='0';
    }
    int ans=0;
    int y=n;
    while(y>0){
        ans+=y;
        y-=2;
    }
    cout<<ans<<"\n";
    int cnt=1;
    for(int i=0;i<n;i++) {if(s[i]=='0') cout<<"b"; else cout<<"r";}
    cout<<"\n";
    // cout<<s<<"\n";
    int c[3];
    c[0]=c[1]=c[2]=0;
    bool f1=1;
    while(cnt<100){
        
        bool f=0;
        if(f1==1){
            for(int i=n-1;i>=0;i--){
                if(f==0){
                    if(s[i]=='0') continue;
                    f=1;
                    s[i]='0';
                }
                else{
                    if(s[i]=='1') s[i]='0';
                    else{
                        s[i]='1';
                        f=0;
                        break;
                    }
                }
            }
            if(f==1) break;
        }
        
        c[0]=c[1]=c[2]=0;
        f=0;
        int t=0;
        for(int i=n-1;i>=0;i--){
            if(f==0){
                if(s[i]=='0') c[2]++;
                else f=1;
            }
            if(f==1){
                if(s[i]=='1') t^=1;
                c[t]++;
            }
        }
        int tmp=-1,mx=c[2]*c[1];
        if(f1==0) mx=0;
        
        // cout<<mx<<" ";
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1') break;
            c[2]--;
            int cur=(c[0]+c[2]+1)*(n-i)+c[1]*c[2];
            if(cur>mx) tmp=i,mx=cur;
            // cout<<mx<<" ";
        }
        // cout<<"\n";
        if(tmp!=-1) s[tmp]='1';
        if(tmp==-1) f1=0;
        else f1=1;
        for(int i=0;i<n;i++) {if(s[i]=='0') cout<<"b"; else cout<<"r";}
        cout<<"\n";
        // cout<<s<<"\n"; 
        cnt++;
    }
}