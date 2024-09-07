// #define D

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

// #define set unordered_set
// #define map unordered_map

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()

using namespace std;

bool comp(int a,int b) {return a < b;}

// // string solve2(int n,int l,int r,vector<int> arr) {
//     vector<int> sl,sr,sb;
//     for(auto x:arr) sl.pb(x);
//     auto dfs = [&](auto self,vector<int> curl,vector<int> curr,bool bt) -> bool {
//         // cout << "ET:" << bt << "\n-l : ";
//         // for(auto x:curl) cout << x << " " ;cout << " \n-r : "; 
//         // for(auto x:curr) cout << x << " " ;cout << " \n"; 
//         // system("pause");
//         // bt = 1 : r  
//         vector<int> tmpl,tmpr;
//         for(auto x:curl) if(x!= 0) tmpl.pb(x);
//         for(auto x:curr) if(x!= 0) tmpr.pb(x);
//         curl  = tmpl,curr = tmpr;
//         bool cmp = 0;
//         if(curl.size() == 0 && bt){ return 1;}
//         if(bt){
//             // map<int,int> cnt;
//             // for(auto x:curr) cnt[x] ++;
//             if(curr.size() < l) {return 0;}
//             else {
//                 int tt = 1;
//                 for(int t = 0;t < tt;t ++)
//                 {
//                     int tmp = tt;
//                     int i = 0;
//                     vector<vector<int>> TTLC;
//                     vector<int> TTLCtmp;
//                     auto getttlc = [&](auto prfs,int i,int m) -> void{
//                         // cout << "ETgettlc:" << i << " " << m << "\n";
//                         // for(auto x:TTLCtmp) cout << x << " ";cout << "\n----\n";
//                         if(i == curr.size()-1 || m == 0) {
//                             TTLCtmp.push_back(curr[i]);
//                             TTLC.pb(TTLCtmp);
//                             TTLCtmp.pop_back();
//                         } else {
//                             for(int j = i;j < curl.size()-m;j ++)
//                             {
//                                 TTLCtmp.pb(curr[j]);
//                                 prfs(prfs,j+1,m-1);
//                                 TTLCtmp.pop_back();
//                             }
//                         }
//                     }; getttlc(getttlc,0,l-1);
//                     // for(auto x:TTLC)
//                     // {
//                     //     for(auto y:x) cout << y << " ";cout << ":\n";
//                     // }
//                     for(auto x:TTLC)
//                     {
//                         // for(auto y:x) cout << y << " ";cout << ":\n";
//                         vector<int> tmpr;
//                         vector<int> tmpl;
//                         multiset<int> setr;
//                         for(auto x:curl) tmpl.pb(x);
//                         for(auto x:curr) setr.insert(x);
//                             for(auto y:x)
//                             {
//                                 tmpl.pb(y);
//                                 setr.erase(setr.find(y));
//                             }
//                         for(auto x:setr) tmpr.pb(x);
//                         if(self(self,tmpl,tmpr,!bt)) {return 1;}
//                     }
//                 }
//             } 
//         } else {
//             // map<int,int> cnt;
//             // for(auto x:curl) cnt[x] ++;
//             // if(curl.size() < r) return 0;
//             if(curl.size() == 0) {return 1;}
//             else {
//                 int tt = curl.size();
//                 // for(int t = 0;t < tt;t ++)
//                 // {
//                     int tmp = tt;
//                     int i = 0;
//                     vector<vector<int>> TTLC;
//                     vector<int> TTLCtmp;
//                     auto getttlc = [&](auto prfs,int i,int m) -> void{
//                         // cout << "ETgettlc:" << i << " " << m << "\n";
//                         // for(auto x:TTLCtmp) cout << x << " ";cout << "\n----\n";
//                         if(i == curl.size()-1 || m == 0) {
//                             TTLCtmp.push_back(curl[i]);
//                             TTLC.pb(TTLCtmp);
//                             TTLCtmp.pop_back();
//                         } else {
//                             for(int j = i;j < curl.size()-m;j ++)
//                             {
//                                 TTLCtmp.pb(curl[j]);
//                                 prfs(prfs,j+1,m-1);
//                                 TTLCtmp.pop_back();
//                             }
//                         }
//                     }; getttlc(getttlc,0,r-1);
//                     // for(auto x:TTLC)
//                     // {
//                     //     for(auto y:x) cout << y << " ";cout << ":\n";
//                     // }
//                     // // cout << "ET:" << bt << "\n-l : ";
//                     // for(auto x:curl) cout << x << " " ;cout << " \n-r : "; 
//                     // for(auto x:curr) cout << x << " " ;cout << " \n"; 
//                     for(auto x:TTLC)
//                     {
//                         // for(auto y:x) cout << y << " ";cout << ":\n";
//                         vector<int> tmpr;
//                         vector<int> tmpl;
//                         multiset<int> setl;
//                         for(auto x:curr) tmpr.pb(x);
//                         for(auto x:curl) setl.insert(x);
//                             // for(auto x:setl) cout << x << " ";
//                         for(auto y:x)
//                         {
//                             tmpr.pb(y-1);
//                             setl.erase(setl.find(y));
//                             // cout << "stler:" << y << "\n";
//                             // for(auto xx:setl) cout << xx << " ";
//                         }
//                         for(auto x:setl) tmpl.pb(x);
//                         if(self(self,tmpl,tmpr,!bt)) {return 1;}
//                     }
//                     // while(tmp)
//                     // {
//                     //     if(i >= r) break;
//                     //     if(tmp % 2) {
//                     //         tmpl.pb(curr[i]-1);
//                     //         setr.erase(curr[i]);
//                     //     }
//                     //     tmp /= 2;
//                     //     i ++;
//                     // }
//                 // }
//             } 
//         }
//         {return 0;}
//     };

//     if(dfs(dfs,sl,sr,0)) return "Yes";
//     else return "No";
// }

string solve2(int n,int L,int R,vector<int> ar) {
    //     cin >> n >> L >> R;
    // for(int i=1;i<=n;i++){
    //     cin >> h[i];
    // }
    vector<int> h(1);
    for(auto x:ar) h.pb(x);
    long long times = 1LL * (n-L-1) / (R-L);
    long long need = times * L;
    long long cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += min(times, 1LL * (h[i] - 1) / 2);
    }
    // cout << (cnt >= need ? "Yes" : "No") << endl;
    if(cnt >= need) return "Yes";
    else return "No";
}

string solve1(int n,int l,int r,vector<int>arr){
	// int n,l,r;
    // cin>>n>>l>>r;
    priority_queue<int> q1,q3;
    priority_queue<int,vector<int>,greater<int>> q2;
    for(int i=0;i<n;i++){
        // int x;
        // cin>>x;
        q1.push(arr[i]);
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
        q3.push(cur-1);
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
                // cout<<"No\n";
                return "No";
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
    // cout<<"Yes\n";
	return "Yes";
}


signed main()
{
// #ifndef D
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0);
//     std::cout.tie(0);
// #endif
//     int T = 1;
//     cin >> T;

//     for (int i = 0; i < T; i++)
//     {
//         solution sl;
//         sl.solve();
//     }

// 2 2 | 1 4 0 | 2 3 4 7

// 2 | 1 0 1 | 4 1 2 5
// | 1 0 1 | 3 2 0  1 4

    srand(114514);

    while(1)
    {
        int n = rand()%10+3,l=rand()%(n-1)+1,r = rand()%(n-l)+l+1;
        // int n = 4,l=2,r =3;
        // cout << n << " " << l << " " << r << "\n";
        // vector<int> ll = {1,1,1,6};
        vector<int> ll(n);

        for(auto &x:ll) x = rand()%10+1;
        if(solve1(n,l,r,ll) != solve2(n,l,r,ll))
        {
            cout << solve1(n,l,r,ll) << " " << solve2(n,l,r,ll) << "\n";
            cout << n << " " << l << " " << r << "\n";
            for(auto x:ll) cout << x << " ";cout << "\n";
            system("pause");
        } else {cout << "ACCEPTED\n";}
    }

    // system("pause");

    return 0;
}