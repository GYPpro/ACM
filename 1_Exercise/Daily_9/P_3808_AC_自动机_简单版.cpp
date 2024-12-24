// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define ord(u, v) {min(u, v), max(u, v)}
using namespace std;

class AC_automaton
{   
private:
    vector<array<int,26>> trie;
    vector<int> fail;
    vector<int> endtags;
    vector<vector<int>> cnj;
    bool ifBuilt = 0;
    static const int IGNORETAG = -1;
#ifndef pii
    using pii = pair<int,int>;
#endif
public:
    AC_automaton() {
        trie.resize(1);
        endtags.resize(1);
        fail.resize(1);  
    }

    void insert(const string &s) {
        ifBuilt = 0; 
        int u = 0;
        for(auto ch:s){
            int c = ch-'a';
            if((trie.size() <= u+1) || (!trie[u][c]))
                trie.push_back(array<int,26>()),trie[u][c] = trie.size()-1;
            u = trie[u][c];
        }
        endtags.push_back(u);
    }

    void build()
    {
        ifBuilt = 1;
        queue<int> q;
        for(int c = 0;c < 26;c ++)
            if(trie[0][c]) q.push(trie[0][c]);
        fail.resize(trie.size(),0);    
        cnj.resize(fail.size()+1,vector<int>());
        // vector<int> LOCK(trie.size()+1,0);
        while(q.size())
        {
            // cout << q.size() << " ";
            auto u = q.front();
            q.pop();
            // if(LOCK[u]) continue;
            // else LOCK[u] = 1;
            for(int c = 0;c < 26;c ++)
                if(trie[u][c]) {
                    fail[trie[u][c]] = trie[fail[u]][c];
                    q.push(trie[u][c]);
                } else trie[u][c] = trie[fail[u]][c];
        }
        for(int i = 1;i < trie.size();i ++) cnj[fail[i]].push_back(i);
    }

    vector<int> que(string &t) {
        using itf = function<void(int)>;
        if(!ifBuilt) build();
        // cout << "build finished\n";
        vector<int> sum = vector<int>(trie.size());
        int u = 0;
        for(auto ch:t){
            int c = ch-'a';
            u = trie[u][c];
            sum[u] ++;
        }
        vector<int> vst(trie.size()+1);
        itf dfs = [&](int u) -> void {
            vst[u] = 1;
            for(auto v:cnj[u]){
                // if(vst[v]) continue;
                dfs(v);
                sum[u] += sum[v];
            }
        };
        dfs(0);
        vector<int> rt;
        // for(auto x:fail) cout << x << " ";cout << "\n";
        // for(auto x:sum) cout << x << " ";cout << "\n";
        for(int i = 1;i < endtags.size();i ++) rt.push_back(sum[endtags[i]]);
        return rt;
    };


};

void solve()
{
    int n;
    cin >> n;
    AC_automaton ac;
    vector<string> ris;
    lop(i,0,n)
    {
        string s;
        cin >> s;
        ac.insert(s);   
        ris.pb(s); 
    }
    string t;
    cin >> t;
    // for(auto x:ac.que(t)) cout << x << "\n";
    auto rt = ac.que(t);
    // multiset<string> cnt;
    map<int,vector<string>> cnt;
    lop(i,0,n)
    {
        if(rt[i] != 0) cnt[rt[i]].pb(ris[i]);
    }
    sort(all(cnt));
    // cout << cnt.size();
    for(auto x:cnt.back()) cout << x << " ";cout << "\n";
    // cout << "\n";
}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}
