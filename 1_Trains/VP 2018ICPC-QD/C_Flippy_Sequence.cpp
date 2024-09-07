// #include <bits/stdc++.h>
// #define inf 1e9
// #define ll long long
// #define F(i, a, b) for(int i = a; i <= b ; i++) 
// #define sf scanf
// #define pf printf 
// #define int long long
// #define mem(a,b) memset(a,b,sizeof(a))
// #define open(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout)
// //#define M 1000010
// #define M 101
// using namespace std;


// int T, n,len, l, r;

// string s1, s2;

//     string s;

// int get_interval() {
//     for(int i = 0;i < n;i ++) s.push_back(s1[i] != s2[i]);
//     s.clear();
//     // for(auto x:s)cout << (x?1:0);
//     // cout << "\n";
//     bool f = 0;
//     int cnt = 0;
//     for(auto x:s) {
//         if(x) if(!f) {cnt ++;f = 1;}
//             else continue;
//         else f = 0;  
//     }
//     return cnt;
// 	// l = r = 0;
// 	// int ret = 0;
// 	// if(s1[0] != s2[0]) {
// 	// 	++ret;
// 	// 	l=0;
// 	// }
// 	// F(i, 1, n - 1) {
// 	// 	if(s1[i - 1] == s2[i - 1] && s1[i] != s2[i]) {
// 	// 		++ret;
// 	// 		l = i;
// 	// 	} 
// 	// 	if(s1[i - 1] != s2[i - 1] && s1[i] == s2[i]) r = i - 1;
// 	// }
// 	// if(s1[n - 1] != s2[n - 1]) r = n - 1;
// 	// return ret;
// }

// signed main() {
// 	//open("C");
// 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

// 	cin >> T;
// 	while(T--) {
// 		cin >> n;
// 		cin >> s1 >> s2;
// 		int cnt = get_interval();
// 		if(cnt > 2) {
// 			cout << 0 << "\n";
// 		}else
// 		if(cnt == 2) {
// 			cout << 6 << "\n";
// 		}
// 		else
// 		if(cnt == 1) {
//             l = -1,r = -1;
//             for(int i = 0;i < n;i ++){
//                 if(l == -1 && s[i] == 1) l = i;
//                 if(l != -1 && s[i] == 0 && r == -1) r = i-1;
//             }
//             cout << (r - l) * 2 << "\n";

// 		}
// 		else 
// 			cout << n * (n + 1)/2 << "\n";
//         // cout << cnt << "\n";
// 	}
// 	return 0;
// } 
#include <bits/stdc++.h>
#define inf 1e9
#define ll long long
#define F(i, a, b) for(int i = a; i <= b ; i++) 
#define sf scanf
#define pf printf 
#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define open(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout)
//#define M 1000010
#define M 101
using namespace std;


int T, n,len, l, r;

string s1, s2;


int get_interval() {
	l = r = 0;
	int ret = 0;
	if(s1[0] != s2[0]) {
		++ret;
		l=0;
	}
	F(i, 1, n - 1) {
		if(s1[i - 1] == s2[i - 1] && s1[i] != s2[i]) {
			++ret;
			l = i;
		} 
		if(s1[i - 1] != s2[i - 1] && s1[i] == s2[i]) r = i - 1;
	}
	if(s1[n - 1] != s2[n - 1]) r = n - 1;
	return ret;
}

signed main() {
	//open("C");
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

	cin >> T;
	while(T--) {
		cin >> n;
		cin >> s1 >> s2;
		int cnt = get_interval();
if(cnt > 2) {
			cout << 0 << "\n";
		}else
		if(cnt == 2) {
			cout << 6 << "\n";
		}
		else
		if(cnt == 1) {
			cout << 2 * (n - 1) << "\n"; 
		}
		else cout << n * (n - 1) / 2 + n<< "\n";
	}
	return 0;
} 