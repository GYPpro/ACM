#define _USE_IOSTREAM_
// #define _PRIV_TEST_

#ifndef _USE_IOSTREAM_
#define _USE_STDIO_
#endif

#ifdef _USE_IOSTREAM_
#include <iostream>
#endif
#ifdef _USE_STDIO_
#include <stdio.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

#define ll long long
#define mod1 998244353

using namespace std;

class Trie
{
public:
    vector<map<int, int>> t;
    int root = 0;
    Trie()
    {
        t.resize(1);
    }
    void addedge(const vector<int> &_s)
    {
        int pvidx = root;
        for (int i = 0; i < _s.size(); i++)
        {
            if (t[pvidx].find(_s[i]) != t[pvidx].end())
            {
                pvidx = t[pvidx][_s[i]];
            }
            else
            {
                t[pvidx][_s[i]] = t.size();
                t.push_back(map<int, int>());
                pvidx = t[pvidx][_s[i]];
            }
        }
    }
};

void rev(vector<int> &s)
{
    for(int i = 0;i < s.size()/2;i ++) swap(s[i],s[s.size()-1-i]);
}

void solve()
{
    int n;
    cin >> n;
    n -= 1;
    vector<int> arr(n);
    int mxBin = 22;
    
    #ifdef _PRIV_TEST_
    mxBin = 4;
    #endif
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    n += 1;
    vector<int> cnt(n);
    for (int i = 1; i < n; i++)
        cnt[i] = cnt[i - 1] ^ arr[i - 1];
    Trie trie = Trie();
    for(int i = 0;i < cnt.size();i ++)
    {
        vector<int> tar;
        int tmp = cnt[i];
        while(tmp){
            tar.push_back(tmp%2);
            tmp >>= 1;
        }
        for(int i = tar.size();i <= mxBin;i ++) tar.push_back(0);
        rev(tar);
        trie.addedge(tar);
    }
    int ans = 0;
    for(ans = 0;ans <= n;ans ++)
    {
        vector<int> tar;
        int tmp = ans;
        while(tmp){
            tar.push_back(tmp%2);
            tmp >>= 1;
        }
        for(int i = tar.size();i <= mxBin;i ++) tar.push_back(0);
        rev(tar);
        int pv = trie.root;
        vector<int> max;
        for(int i = 0;i < tar.size();i ++){
            if(trie.t[pv].find(!tar[i]) != trie.t[pv].end()){
                pv = trie.t[pv][!tar[i]];
                max.push_back(1);
            } else {
                pv = (*trie.t[pv].begin()).second;
                max.push_back(0);
            }
        }
        int maxi = 0;
        int pow = 1;
        for(int i = max.size()-1;i >= 0;i --)
        {
            maxi += max[i]*pow;
            pow <<= 1;
        }
        if(maxi < n) break;
    }
    for(int i = 0;i < cnt.size();i ++) cout << (ans ^ cnt[i]) << " ";
    cout << "\n";
}

// #define _WITH_T_

int main()
{
#ifndef _PRIV_TEST_
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;

#ifdef _WITH_T_
#ifdef _USE_IOSTREAM_
    cin >> T;
#endif
#ifdef _USE_STDIO_
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}