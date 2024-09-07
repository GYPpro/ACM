// #include<bits/stdc++.h>
#include <iostream>
// #include <vectror>
#include <queue>
using namespace std;
const int N=1e5+100;
#define int long long
#define ll long long
int mod=998244353;

/*
1 | 0 1 0 3

1 2 3 | 3 | 3

1 2 2 | 2 | 1

1 2 | 2 | 1 0

1 0 | 1 | 0 1 0

 | 0 | 0 1 1 1

1 2 | 1 | 1 2  

1 2 | 2 | 1 1

1 1 3 | 2 | 2

| 0 | 0 0 0 0

2 3

2 | 1 3 | 1 3

1  | 2 2 | 0 0

2 3 4 3 2

2 | 1 0 | 1 2

1 1 | 2 | 1 0

*/


void solve(){
	int n,l,r;
    cin>>n>>l>>r;
    priority_queue<int> q1,q3;
    priority_queue<int,vector<int>,greater<int>> q2;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q1.push(x);
    }
    int tt=0;
    auto printpq = [&](auto q) -> void{
        cout << "curtt:" << tt << " - ";
        vector<int> pq;
        while(!q.empty()) pq.push_back(q.top()),q.pop();
        for(auto x:pq) cout << x - tt << " ";cout << " ED\n"; 
    };
    for(int i=0;i<l;i++){
        int cur=q1.top();
        q1.pop();
        q2.push(cur-1);
    }
            // printpq(q2);
    for(int i=0;i<r-l;i++){
        //
        int cur=q1.top();
        q1.pop();
        q3.push(cur);
    }
    while(!q1.empty()){
            // printpq(q2);
        while(q2.top() - tt < 2){
            // for(auto x:q2) cout << x -tt << " " ;cout << "\n";
            // cout<<q2.top()<<" "<<tt<<"\n";
            int cur=q2.top();
            q2.pop();
            q3.push(cur-tt);
            cur=q3.top();
            q3.pop();
            // cout << "ADD " << cur << "\n";
            if(cur<2){
                cout<<"No\n";
                return;
            }
            q2.push(cur+tt);
        }
        for(int i=0;i<r-l;i++){
            if(q1.empty()) break;
            int cur=q1.top();
            q1.pop();
            q3.push(cur-1);
        }
        tt+=2;
    }
    cout<<"Yes\n";
	return;
}


signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;
// 	cin>>t;
	while(t--) solve();
	return 0;
} 