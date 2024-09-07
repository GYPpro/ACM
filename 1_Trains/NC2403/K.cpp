#include <iostream>
#include <vector>

using namespace std;
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> mtx(n,vector<int>(m));
    while(k--)
    {
        int u,v;
        cin >> u >> v;
        u --,v --;
        mtx[u][v] = 1;
    }

    auto dfs = [&](auto self,vector<vector<int>> s) -> int {
        int ans = INT_MAX;
        for(int i = 0;i < s.size();i ++)
            for(int j = 0;j < s[i].size();j ++)
                {
                    if(!s[i][j]) continue;
                    auto t = s;
                    if(i < (int)s.size()-2) {
                        if(t[i+1][j] == 1 && t[i+2][j] == 0)
                        {
                            t[i+1][j] = 0,t[i][j] = 0,t[i+2][j] = 1;
                            ans = min(ans,self(self,t));
                        }
                    }t = s;
                    if(i >= 2) {
                        if(t[i-1][j] == 1 && t[i-2][j] == 0)
                        {
                            t[i-1][j] = 0,t[i][j] = 0,t[i-2][j] = 1;
                            ans = min(ans,self(self,t));
                        }
                    }t = s;
                    if(j < (int)s[i].size()-2) {
                        if(t[i][j+1] == 1 && t[i][j+2] == 0)
                        {
                            t[i][j+1] = 0,t[i][j] = 0,t[i][j+2] = 1;
                            ans = min(ans,self(self,t));
                        }
                    }t = s;
                    if(j >= 2) {
                        if(t[i][j-1] == 1 && t[i][j-2] == 0)
                        {
                            t[i][j-1] = 0,t[i][j] = 0,t[i][j-2] = 1;
                            ans = min(ans,self(self,t));
                        }
                    }
                }
        if(ans == INT_MAX) {
            int cnt = 0;
            for(auto x:s)
                for(auto y:x) if(y) cnt ++;
            ans = cnt;
        }return ans;
        
    };
    cout << dfs(dfs,mtx) << "\n";
    // return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}