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

    struct TM {
    string name;
    int rank,pant;
    int ttl = 1;
    TM(){}
    TM(string _name,int _rank,int _pant) {
        name = _name;
        rank = _rank;
        pant = _pant;
    }
};

    bool comp(TM a,TM b){
    if(a.rank != b.rank) return a.rank > b.rank;
    else return a.pant < b.pant;
}

class solution
{
private:

public:

    void solve()
    {
        int n;
        cin >> n;
        vector<TM> TA(n);
        set<string> fA,fB;

        for(int i = 0;i < n;i ++) {
            cin >> TA[i].name >> TA[i].rank >> TA[i].pant;
            fA.insert(TA[i].name);
        }
        int m;
        cin >> m;
        vector<TM> TB(m);
        for(int i = 0;i < m;i ++) {
            cin >> TB[i].name >> TB[i].rank >> TB[i].pant;
            fB.insert(TB[i].name);
        }
        sort(TA.begin(),TA.end(),comp);
        sort(TB.begin(),TB.end(),comp);
        // for(auto x:TA) cout << x.name << " " << x.rank << " " << x.pant << "\n";
        int MEXA = 1;
        for(auto x:TA) {
            if(x.name != "lzr010506") {
                if(fB.find(x.name) != fB.end()) continue;
                else MEXA ++;
            } else break;
        }
        int MEXB = 1;
        for(auto x:TB) {
            if(x.name != "lzr010506") {
                if(fA.find(x.name) != fA.end()) continue;
                else MEXB ++;
            } else break;
        }
        cout << min(MEXB,MEXA) << "\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}