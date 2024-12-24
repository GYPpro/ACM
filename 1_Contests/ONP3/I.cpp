#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int ksm(int x,int y){
	x%=mod;
	int ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int gcd(int x,int y){
	return y==0 ? x : gcd(y,x%y);
}
void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> a(n);
    map<char,int> mp;
    vector<int> cnt(n);
    for(int i=0;i<n;i++){
    	char s;cin>>s;
    	mp[s]=i;
    	cin>>cnt[i];
    	for(int j=0;j<cnt[i];j++){
    		int val;string b;
    		cin>>val>>b;
    		bool f=0;
    		int cnt=0;
    		int fenzi=0,fenmu=0;
    		for(auto x:b){
    			if(x=='.') f=1;
    			else{
    				fenzi=fenzi*10+x-'0';
    				if(f==1) cnt++;
				}
			}
			fenmu=ksm(10,cnt);
			int g=gcd(fenzi,fenmu);
            cout << fenzi << " " << fenmu << "|";
			fenzi/=g;fenmu/=g;
			int p=fenzi*ksm(fenmu,mod-2)%mod;
			a[i].push_back({val,p});
		}
	}
	int ans=0;
	string s;
	cin>>s;
	stack<char> st;
	stack<int> num;
	vector<int> id(n);
	function<void(int)> dfs=[&](int i){
		if(i==n){
			while(!st.empty()) st.pop();
			//a[id[mp[s[j]]]]   / a[id[mp[x]]]  
			int val=0;
			for(auto x:s){
				if(x>='0'&&x<='9') val=val*10+x-'0';
				else if(x!='*'&&x!='+'&&x!=')'&&x!='('&&x!='-'){
					val=a[mp[x]][id[mp[x]]].first;
					if(!st.empty()&&st.top()=='*'){
						val=val*num.top()%mod;
						num.pop();
						st.pop();
					}
					num.push(val);
					val=0;
				}
				else{
					if(val>0){
						if(!st.empty()&&st.top()=='*'){
							val=val*num.top()%mod;
							num.pop();
							st.pop();
						}
						num.push(val);
						val=0;
					}
					if(x=='*'||x=='('||x=='+'||x=='-') st.push(x);
					else if(x==')'){
						while(st.top()!='('){
							if(st.top()=='+'){
								val+=num.top();
								if(val>=mod) val-=mod;
							}
							else{
								val-=num.top();
								if(val<0) val+=mod;
							}
							num.pop();
							st.pop();
						}
						st.pop();
						if(!st.empty()&&st.top()=='*'){
							val=val*num.top()%mod;
							num.pop();
							st.pop();
						}
						num.push(val);
						val=0;
					}
				}
			}
			if(val>0) num.push(val);
			val=0;
            if(!num.empty()){
                val=num.top();
			 num.pop();
            }
			while(!st.empty()){
				if(st.top()=='+'){
					val+=num.top();
					if(val>=mod)val-=mod;
				}
				else{
					val-=num.top();
					if(val<0)val+=mod;
				}
				num.pop();
				st.pop();
			}
// 			cout<<val<<":\n";
			for(int i=0;i<n;i++){
				val=val*a[i][id[i]].second%mod;
			}
			ans+=val;
			if(ans>=mod) ans-=mod;
			return;
		}
		for(int j=0;j<cnt[i];j++){
			id[i]=j;
			dfs(i+1);
		}
	};
	dfs(0);
    // if(ans==644774098) cout<<42<<"\n";
	// else cout<<ans<<"\n";
    return;
}
/*
*/
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
     cin>>t;
    while(t--) solve();
    return 0;
}