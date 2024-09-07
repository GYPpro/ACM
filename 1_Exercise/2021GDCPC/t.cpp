#include<bits/stdc++.h>
#define int long long
const int n=1000;
using namespace std;
void solve(){
    int x1,y1,z1,x2,y2,z2;
    cin>>x1>>y1>>z1>>x2>>y2>>z2;
//     if((x1>0&&x2<0)||(x1<0&&x2>0)||(y1>0&&y2<0)||(y1<0&&y2>0)||(z1>0&&z2<0)||(z1<0&&z2>0)){
//         cout<<"No\n";
//         return;
//     }
    // 1000x=y*y+z*z;
    int f1,f2;  // f=1 在里  f=0 在外  f=2 在边上
    if(y1*y1+z1*z1==n*(x1)) f1=2;
    else if(y1*y1+z1*z1>n*(x1)) f1=0;
    else f1=1;
    if(y2*y2+z2*z2==n*(x2)) f2=2;
    else if(y2*y2+z2*z2>n*(x2)) f2=0;
    else f2=1;
    if((f1==1&&f2==0)||(f1==0&&f2==1)){
        cout<<"No\n";
        return;
    }
    x1 = -x1,x2 = -x2;
    if(y1*y1+z1*z1==n*(x1)) f1=2;
    else if(y1*y1+z1*z1>n*(x1)) f1=0;
    else f1=1;
    if(y2*y2+z2*z2==n*(x2)) f2=2;
    else if(y2*y2+z2*z2>n*(x2)) f2=0;
    else f2=1;
    if((f1==1&&f2==0)||(f1==0&&f2==1)){
        cout<<"No\n";
        return;
    }
    if(x1*x1+z1*z1==n*(y1)) f1=2;
    else if(x1*x1+z1*z1>n*(y1)) f1=0;
    else f1=1;
    if(x2*x2+z2*z2==n*(y2)) f2=2;
    else if(x2*x2+z2*z2>n*(y2)) f2=0;
    else f2=1;
    if((f1==1&&f2==0)||(f1==0&&f2==1)){
        cout<<"No\n";
        return;
    }
    y1 = -y1,y2 = -y2;
    if(x1*x1+z1*z1==n*(y1)) f1=2;
    else if(x1*x1+z1*z1>n*(y1)) f1=0;
    else f1=1;
    if(x2*x2+z2*z2==n*(y2)) f2=2;
    else if(x2*x2+z2*z2>n*(y2)) f2=0;
    else f2=1;
    if((f1==1&&f2==0)||(f1==0&&f2==1)){
        cout<<"No\n";
        return;
    }
    if(x1*x1+y1*y1==n*(z1)) f1=2;
    else if(x1*x1+y1*y1>n*(z1)) f1=0;
    else f1=1;
    if(x2*x2+y2*y2==n*(z2)) f2=2;
    else if(x2*x2+y2*y2>n*(z2)) f2=0;
    else f2=1;
    if((f1==1&&f2==0)||(f1==0&&f2==1)){
        cout<<"No\n";
        return;
    }
    z1 = -z1,z2 = -z2;
    if(x1*x1+y1*y1==n*(z1)) f1=2;
    else if(x1*x1+y1*y1>n*(z1)) f1=0;
    else f1=1;
    if(x2*x2+y2*y2==n*(z2)) f2=2;
    else if(x2*x2+y2*y2>n*(z2)) f2=0;
    else f2=1;
    if((f1==1&&f2==0)||(f1==0&&f2==1)){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    return;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}