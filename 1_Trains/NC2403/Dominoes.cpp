//#define debug
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#define inf 1e9
#define F(i, a, b) for(int i = a; i <= b ; i++) 
#define mem(a,b) memset(a,b,sizeof(a))
#define open(x) freopen(x ".in", "r", stdin);

#ifndef debug
const int N=2 * 1e5 + 10;
#else
const int N=101;
#endif

using namespace std;

struct interval {
	int l, r, fre;
	interval() {l=r=fre=0;}
	interval(int l, int r) {this->l = l;this->r = r;}
	interval(int l, int r, int fre) {this->l = l;this->r = r;this->fre = fre;}
	bool operator<(const interval& other) const {
		return fre < other.fre;
	}
}s[N], ans[N];

inline interval T(const interval& a) {
	return interval(a.r, a.l, a.fre);
} 

int n;
unordered_map<int, int> count_num;

bool check() {
	
	priority_queue<interval> pq;
	F(i, 1, n) pq.push(s[i]);
	
	ans[1] = pq.top();
	pq.pop();
	
	F(i, 2, n) {
		priority_queue<interval> temp_pq;
		bool found = false;
		
		while (!pq.empty()) {
			interval current = pq.top();
			pq.pop();
			
			if (current.l != ans[i - 1].r) {
				ans[i] = current;
				found = true;
				break;
			} else 
			if(T(current).l != ans[i - 1].r) {
				ans[i] = T(current);
				found = true;
				break;
			}
			else 
			{
				temp_pq.push(current);
			}
		}
		
		// restore back
		while (!temp_pq.empty()) {
			pq.push(temp_pq.top());
			temp_pq.pop();
		}
		
		if (!found) return false;
	}
	
	
	return true;
}

signed main() {
	#ifdef debug
	open("D");
	#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    
    cin >> n;
    F(i, 1, n) cin >> s[i].l >> s[i].r;
    
    F(i, 1, n) count_num[s[i].l]++, count_num[s[i].r]++;
	F(i, 1, n) s[i].fre = count_num[s[i].l] + count_num[s[i].r];
	if(check()) {
		cout << "Yes" << "\n";
		#ifndef debug
		F(i,1,n) cout << ans[i].l << " " << ans[i].r << "\n";
		#endif
		return 0;
	} 
	
	s[1] = T(s[1]);
	
	if(check()) {
		
		cout << "Yes" << "\n";
		#ifndef debug
		F(i,1,n) cout << ans[i].l << " " << ans[i].r << "\n";
		#endif
		return 0;
	}  

	cout << "No" << "\n";
		
	
	return 0;
} 
