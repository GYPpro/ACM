#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
#define ll long long
#define int long long
const int N =1e5+100;
map<string,string> mp;

// void dfs(string s,string a){
//     if(s.size()<4){
//         mp[a]=s;
//         return;
//     }
//     mp[a]=s;
//     if(s[0]=='p'&&s[1]=='a'&&s[2]=='i'&&s[3]=='r'){
//         string s1;
//         int cnt=0,i;
//         for(i=5;;i++){
//             if(s[i]=='<')cnt++;
//             else if(s[i]=='>') cnt--;
//             if(s[i]==','&&cnt==0) break;
//             s1+=s[i];
//         }
//         string b=a;
//         b+=".first";
//         dfs(s1,b);
//         s1="";b=a+".second";
//         for(i+=1;;i++){
//             if(s[i]=='<')cnt++;
//             else if(s[i]=='>'){
//                 if(cnt==0) break;
//                 cnt--;
//             }
//             s1+=s[i];
//         }
//         dfs(s1,b);
//     }
// // }
// string dfs(string &s,string &a){
//     int sz=a.size();
//     for(int i=0;i<sz;i++){
//         if(a[i]=='.'){
//             if(a[i+1]=='f'){
//                 string s1;
//                 for(int j=i+6;j<sz;j++) s1+=a[j];
//                 string s2;
//                 int cnt=0,i;
//                 for(i=5;;i++){
//                     if(s[i]=='<')cnt++;
//                     else if(s[i]=='>') cnt--;
//                     if(s[i]==','&&cnt==0) break;
//                     s2+=s[i];
//                 }
//                 if(s1.empty()) return s2;
//                 else return dfs(s2,s1);
//             }
//             else{
//                 string s1="",s2="";
//                 for(int j=i+7;j<sz;j++) s1+=a[j];
//                 int cnt=0,i;
//                 for(i=5;;i++){
//                     if(s[i]=='<') cnt++;
//                     else if(s[i]=='>') cnt--;
//                     if(s[i]==','&&cnt==0) break;
//                 }
//                 for(i+=1;;i++){
//                     if(s[i]=='<')cnt++;
//                     else if(s[i]=='>'){
//                         if(cnt==0) break;
//                         cnt--;
//                     }
//                     s2+=s[i];
//                 }
//                 if(s1.empty()) return s2;
//                 else return dfs(s2,s1);
//             }
//         }
//     }
//     return s;
// }
void solve(){
	int n,q;cin>>n>>q;
    
    for(int i=0;i<n;i++){
        string s,a;
        cin>>s>>a;
//         int m=a.size();
        a.pop_back();
//         cout<<b<<" "<<a<<"\n";
        
        mp[a]=s;
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        string s1;
        int sz=s.size();
        for(int i=0;i<sz;i++){
            if(s[i]=='.') break;
            s1+=s[i];
        }
        // cout<<dfs(mp[s1],s)<<"\n";
        string LOCATE;
        int ti = 0;
        while(s[ti] != '.' && ti < s.size()) ti ++;
        while(ti < s.size()) LOCATE.push_back(s[++ti]);
        // cout << mp[s1] << " " << LOCATE << "\n";
        string ORI = mp[s1];
        string rt;

        function<void(int,int,int)> dfs = [&](int l,int r,int opl) -> void {
            // cout << l << " " << r << " " << opl << "\n"; 
            function<bool()> OP = [&]() -> bool {
                while(LOCATE[opl] == '.') opl ++;
                bool flag = LOCATE[opl] == 's';
                while(LOCATE[opl] != '.' && opl < s.size()) opl ++;
                return flag;
            }; //first:0 second:1;
            if(opl >= LOCATE.size()) {
                for(int i = l;i <= r;i ++) rt.push_back(ORI[i]);
                return;
            }

            if(ORI[l] == 'p') l += 5;
            else l += 1;
            r -= 1;
            int DEP = 0;
            if(OP()){
                for(;l < ORI.size();l ++)
                {
                    if(ORI[l] == ',' && DEP == 0) break;
                    if(ORI[l] == '<') DEP ++;
                    if(ORI[l] == '>') DEP --;
                }
                dfs(l+1,r,opl);
            } else {
                for(;r >= 0;r --)
                {
                    if(ORI[r] == ',' && DEP == 0) break;
                    if(ORI[r] == '<') DEP ++;
                    if(ORI[r] == '>') DEP --;
                }
                dfs(l,r-1,opl);
            }
        };

        dfs(0,ORI.size()-1,0);
        cout << rt << "\n";

    }
	return;
}
signed main(){
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;
	while(t--) solve();
	return 0;
}