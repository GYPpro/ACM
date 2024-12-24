#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lop(i,a,b) for(int i = a,i < b;i ++)

map<string,int> tr = {
    {"C",1},
    {"C#",2},
    {"D",3},
    {"D#",4},
    {"E",5},
    {"F",6},
    {"F#",7},
    {"G",8},
    {"G#",9},
    {"A",10},
    {"A#",11},
    {"B",12}
};

void solve()
{
    string A,B,C;
    cin >> A >> B >> C;
    int a = tr[A],b = tr[B],c = tr[C];
    auto dis = [&](int x,int y) -> int {
        if(x > y) return 12-x+y;
        else return y-x;
    };
    // cout << dis(a,b) << " " << dis(b,c) << "\n";
    if((dis(a,b) == 4 && dis(b,c) == 3)) cout << "Major triad\n";
    else if( (dis(a,b)== 3 && dis(b,c) == 4) ) cout << "Minor triad\n";
    else cout << "Dissonance\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}