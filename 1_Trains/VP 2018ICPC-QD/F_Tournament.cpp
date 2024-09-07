#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define map unordered_map
#define set unordered_set

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

class solution
{
private:

int cal(int x){
	for(int i=1;i<=10;i++){
		if((x>>i&1)==1) return i;
	}
}

int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=ans*x;
		x*=x;
		y>>=1;
	}
	return ans;
}
public:
    void solve()
    {
        int n,k;
        cin >> n >> k;
        vector<int> ans(n);
        auto drev = [&](int f,int g) -> void {
            // for(int i = f;i <= f+g/2;i ++) swap(ans[i],ans[f+g-1-i]);
            int l = f,r = f+g-1;
            while(r > l) {
                swap(ans[l],ans[r]);
                r --;
                l ++;
            }
        };
        auto rev = [&](int g) -> void {
            for(int i = 0;i < n;i += g)
                drev(i,g);
        };
        // int MEX = 1;
        // int t = n;
        // while(t) {
        //     if(t%2) break;
        //     t /= 2;
        //     MEX <<= 1;
        // }
        auto getMEX = [&](int rt) -> int {
            int t = rt;
            int tmpr = 1;
            while(t) {
                if(t%2) break;
                t /= 2;
                tmpr <<= 1;
            }
            return tmpr;
        };
        int MEX = getMEX(n) - 1;
        // cout << MEX-1 << "\n";
        if(k > MEX) {cout << "Impossible\n";return;}
        for(int i = 0;i < n;i ++) ans[i] = i+1;
        for(int i = 0;i < k;i ++) {
            rev(getMEX(i+1)*2);
            // cout << getMEX(i+1)*2 << "\n";
            for(auto x:ans) cout << x << " ";
            cout << "\n";
        }
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}