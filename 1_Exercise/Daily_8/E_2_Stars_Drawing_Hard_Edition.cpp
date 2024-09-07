// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mtx(n+1,vector<int>(m+1));
    lop(i,1,n+1)
        lop(j,1,m+1)
        {
            char c;
            cin >> c;
            mtx[i][j] = c == '*';
        }
    vector<vector<int>> colfoc(n+1,vector<int>(m+1)); // [i] -> j
    vector<vector<int>> rowfoc(n+1,vector<int>(m+1)); // [j] -> i
    vector<vector<int>> colboc(n+1,vector<int>(m+1)); // [i] -> j
    vector<vector<int>> rowboc(n+1,vector<int>(m+1)); // [j] -> i
    lop(i,1,n+1)
    {
        int k = 0;
        bool f = 1;
        lop(j,1,m+1)
            if(mtx[i][j] && f) colfoc[i][j] = k = j-1,f = 0;
            else if(mtx[i][j]) colfoc[i][j] = k;
            else f = 1;
    }
    lop(j,1,m+1)
    {
        int k = 0;
        bool f = 1;
        lop(i,1,n+1)
            if(mtx[i][j] && f) rowfoc[i][j] = k = i-1,f = 0;
            else if(mtx[i][j]) rowfoc[i][j] = k;
            else f = 1;
    }
    lop(i,1,n+1)
    {
        int k = 0;
        bool f = 1;
        // lop(j,1,m+1)
        for(int j = m;j > 0;j --)
            if(mtx[i][j] && f) colboc[i][j] = k = j+1,f = 0;
            else if(mtx[i][j]) colboc[i][j] = k;
            else f = 1;
    }
    lop(j,1,m+1)
    {
        int k = 0;
        bool f = 1;
        // lop(i,1,n+1)
        for(int i = n;i > 0;i --)
            if(mtx[i][j] && f) rowboc[i][j] = k = i+1,f = 0;
            else if(mtx[i][j]) rowboc[i][j] = k;
            else f = 1;
    }
    vector<array<int,3>> STAS;

    lop(i,1,n+1)
        lop(j,1,m+1)
        {
            int l = min( min(j - colfoc[i][j], colboc[i][j] - j)   ,
                         min(i - rowfoc[i][j], rowboc[i][j] - i) ) - 1;
            if(mtx[i][j] && l >= 1) STAS.pb({ i,j,l});
        }
    
    vector<vector<int>> colSum(n+2,vector<int>(m+2));
    vector<vector<int>> rowSum(n+2,vector<int>(m+2));

    for(auto [i,j,d]:STAS)
    {
        colSum[i][j-d] ++,colSum[i][j+d+1] --;
        rowSum[i-d][j] ++,rowSum[i+d+1][j] --;
    }

    // return;


    bool ck = 1;
    lop(i,1,n+1)
        lop(j,1,m+1)
            colSum[i][j] += colSum[i][j-1];
    lop(j,1,m+1)
        lop(i,1,n+1)
            rowSum[i][j] += rowSum[i-1][j];

    lop(i,1,n+1)
        lop(j,1,m+1)
            if(mtx[i][j] && (colSum[i][j] == 0 && rowSum[i][j] == 0)) {
                ck = 0;
                break;
            }

    // for(auto x:colSum)
    // {
    //     for(auto y:x) cout << y << " ";
    //     cout << "\n";
    // }
    // cout << "-\n";
    // for(auto x:rowSum)
    // {
    //     for(auto y:x) cout << y << " ";
    //     cout << "\n";
    // }
    if(!ck) cout << "-1\n";
    else {
        cout << STAS.size() << "\n";
        for(auto x:STAS)
        {
            for(auto t:x) cout << t << " ";
            cout << "\n";
        }
    }

    return;


}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");
    // cout << "cp\n";
    return 0;
}
