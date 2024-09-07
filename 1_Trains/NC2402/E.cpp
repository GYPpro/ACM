#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>

// #define map unordered_map
// #define set unordered_set
// #define pq priority_queue
#include <map>
#include <set>

#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int INF = 1145141919810LL;
void sort(auto &x){sort(x.begin(),x.end());}
using namespace std;

void solve(){
	int x;
    cin >> x;
    if(x == 1) {cout << "-1\n";return;}
    if(x % 2) {cout << x-1 << "\n";return;}
    int cnt=__builtin_popcountll(x);
    if(cnt == 1) {cout <<"-1\n";return;}
    cout <<(1 <<  __builtin_ctz(x)) << "\n";
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}