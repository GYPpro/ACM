#define D

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
#pragma GCC optimize(2)

// #define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>

using namespace std;

class solution
{
private:

public:
    void solve()
    {
        map<char,map<char,char>> nxt;{//要往哪个方向走
        nxt['-']['u'] = 'u';
        nxt['-']['d'] = 'd';
        nxt['-']['l'] = 'r';
        nxt['-']['r'] = 'l';
        nxt['|']['u'] = 'd';
        nxt['|']['d'] = 'u';
        nxt['|']['l'] = 'l';
        nxt['|']['r'] = 'r';
        nxt['/']['u'] = 'l';
        nxt['/']['d'] = 'r';
        nxt['/']['l'] = 'u';
        nxt['/']['r'] = 'd';
        nxt['\\']['u'] = 'r';
        nxt['\\']['d'] = 'l';
        nxt['\\']['l'] = 'd';
        nxt['\\']['r'] = 'u';}

        map<char,map<char,char>> rnxt;{//往这个方向走，需要从哪来
        rnxt['-' ]['u'] = 'u';
        rnxt['-' ]['d'] = 'd';
        rnxt['-' ]['l'] = 'r';
        rnxt['-' ]['r'] = 'l';
        rnxt['|' ]['d'] = 'u';
        rnxt['|' ]['u'] = 'd';
        rnxt['|' ]['r'] = 'r';
        rnxt['|' ]['l'] = 'l';
        rnxt['/' ]['l'] = 'u';
        rnxt['/' ]['r'] = 'd';
        rnxt['/' ]['u'] = 'l';
        rnxt['/' ]['d'] = 'r';
        rnxt['\\']['r'] = 'u';
        rnxt['\\']['l'] = 'd';
        rnxt['\\']['d'] = 'l';
        rnxt['\\']['u'] = 'r';}

        map<char,map<char,int>> rf;{  //有没有产生折射
        rf['-']['u'] = 1;
        rf['-']['d'] = 1;
        rf['-']['l'] = 0;
        rf['-']['r'] = 0;
        rf['|']['u'] = 0;
        rf['|']['d'] = 0;
        rf['|']['l'] = 1;
        rf['|']['r'] = 1;
        rf['/']['u'] = 1;
        rf['/']['d'] = 1;
        rf['/']['l'] = 1;
        rf['/']['r'] = 1;
        rf['\\']['u']= 1;
        rf['\\']['d']= 1;
        rf['\\']['l']= 1;
        rf['\\']['r']= 1;}
        
        map<char,char> rev;{  //从这里出去，下一个从哪来
            rev['u'] = 'd';
            rev['d'] = 'u';
            rev['l'] = 'r';
            rev['r'] = 'l';
        }

        int n,m;
        cin >> n >> m;
      

        vector<vector<char>> s(n,vector<char>(m));
        map<char,vector<vector<int>>> cnt;
        cnt['u'] = vector<vector<int>>(n,vector<int>(m));
        cnt['d'] = vector<vector<int>>(n,vector<int>(m));
        cnt['l'] = vector<vector<int>>(n,vector<int>(m));
        cnt['r'] = vector<vector<int>>(n,vector<int>(m));

        auto ovf = [&](pii c) -> bool {
            if(c.first < 0 || c.first >= n) return true;
            if(c.second < 0 || c.second >= m) return true;
            return false;
        };

        for(auto &x:s)
            for(auto &y:x)
                cin >> y;

        for(int i = 0,j = 0;j < m;j ++)
            {
                set<pii> vst;
                // cout << i << " " << j << "\n";
                auto dfs = [&](auto self,pii p,char indir,pii r,char inidir,bool stt) -> pii {
                    //{ring? , length }
    #ifdef D
                    cout << "DFS enter:" << p.fi << " " << p.se;
    #endif
                    char thm = s[p.first][p.second];
                    char outv = nxt[thm][indir];

    #ifdef D
                    cout << " with thm:" << thm << " outv:" << outv << "\n";
    #endif
    
                    if(outv == inidir && p == r && stt) return {1,0};
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    if(ovf(np)) return {0,0};
                    // int addornot = (
                    //     (rf[s[p.fi][p.se]][indir] && 
                    //     vst.find(p) == vst.end())
                    // );
                    // if(cnt[outv][p.fi][p.se]) return {0,cnt[outv][p.fi][p.se] + addornot - 1};
                    auto rt = self(self,np,rev[outv],r,inidir,stt);
                    int addornot = (
                        (rf[s[np.fi][np.se]][rev[outv]] && 
                        vst.find(np) == vst.end())
                    );
                    if(addornot)vst.insert(np);
    #ifdef D
                    cout << "ADDON " << np.fi << " " << np.se << " :" << addornot << " with " << s[np.fi][np.se] << " " << rev[outv] << "\n";
    #endif
                    
                    // if(!rt.first) {
    #ifdef D
                    cout << outv << " " << p.fi << " " << p.se << " -> "  << rt.se + addornot << "\n";
    #endif
                    cnt[outv][p.fi][p.se] = rt.se + addornot;
                    return {rt.fi,rt.se + addornot};
                    // } else 
                };

                auto derain = [&](auto self,pii p,char indir,pii r,char inidir,int edv,bool stt) -> void {
                    char thm = s[p.fi][p.se];
                    char outv = nxt[thm][indir];
                    if(outv == inidir && p == r && stt) return;
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    cnt[outv][p.fi][p.se] = edv;
                    self(self,np,rev[outv],r,inidir,edv,stt);
                    return;
                };

                pii rt;
                if(cnt['d'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',rt.se,0);
                vst.clear();
                }
                if(cnt['u'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',rt.se,0);
                vst.clear();
                }
                if(cnt['l'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',rt.se,0);
                vst.clear();
                }
                if(cnt['r'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',rt.se,0);
                vst.clear();
                }
#ifdef D
                cout << "UPDATED " << i << " " << j << "\n";
                cout << "-u-\n";
                for(auto x:cnt['u'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-d-\n";
                for(auto x:cnt['d'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-l-\n";
                for(auto x:cnt['l'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-r-\n";
                for(auto x:cnt['r'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
#endif
            }
        for(int i = n-1,j = 0;j < m;j ++)
            {
                set<pii> vst;
                // cout << i << " " << j << "\n";
                auto dfs = [&](auto self,pii p,char indir,pii r,char inidir,bool stt) -> pii {
                    //{ring? , length }
    #ifdef D
                    cout << "DFS enter:" << p.fi << " " << p.se;
    #endif
                    char thm = s[p.first][p.second];
                    char outv = nxt[thm][indir];

    #ifdef D
                    cout << " with thm:" << thm << " outv:" << outv << "\n";
    #endif
    
                    if(outv == inidir && p == r && stt) return {1,0};
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    if(ovf(np)) return {0,0};
                    // int addornot = (
                    //     (rf[s[p.fi][p.se]][indir] && 
                    //     vst.find(p) == vst.end())
                    // );
                    // if(cnt[outv][p.fi][p.se]) return {0,cnt[outv][p.fi][p.se] + addornot - 1};
                    auto rt = self(self,np,rev[outv],r,inidir,stt);
                    int addornot = (
                        (rf[s[np.fi][np.se]][rev[outv]] && 
                        vst.find(np) == vst.end())
                    );
                    if(addornot)vst.insert(np);
    #ifdef D
                    cout << "ADDON " << np.fi << " " << np.se << " :" << addornot << " with " << s[np.fi][np.se] << " " << rev[outv] << "\n";
    #endif
                    
                    // if(!rt.first) {
    #ifdef D
                    cout << outv << " " << p.fi << " " << p.se << " -> "  << rt.se + addornot << "\n";
    #endif
                    cnt[outv][p.fi][p.se] = rt.se + addornot;
                    return {rt.fi,rt.se + addornot};
                    // } else 
                };

                auto derain = [&](auto self,pii p,char indir,pii r,char inidir,int edv,bool stt) -> void {
                    char thm = s[p.fi][p.se];
                    char outv = nxt[thm][indir];
                    if(outv == inidir && p == r && stt) return;
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    cnt[outv][p.fi][p.se] = edv;
                    self(self,np,rev[outv],r,inidir,edv,stt);
                    return;
                };

                pii rt;
                
                if(cnt['d'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',rt.se,0);
                vst.clear();
                }
                if(cnt['u'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',rt.se,0);
                vst.clear();
                }
                if(cnt['l'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',rt.se,0);
                vst.clear();
                }
                if(cnt['r'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',rt.se,0);
                vst.clear();
                }
#ifdef D
                cout << "UPDATED " << i << " " << j << "\n";
                cout << "-u-\n";
                for(auto x:cnt['u'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-d-\n";
                for(auto x:cnt['d'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-l-\n";
                for(auto x:cnt['l'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-r-\n";
                for(auto x:cnt['r'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
#endif
            }
        for(int i = 0,j = 0;i < n;i ++)
            {
                set<pii> vst;
                // cout << i << " " << j << "\n";
                auto dfs = [&](auto self,pii p,char indir,pii r,char inidir,bool stt) -> pii {
                    //{ring? , length }
    #ifdef D
                    cout << "DFS enter:" << p.fi << " " << p.se;
    #endif
                    char thm = s[p.first][p.second];
                    char outv = nxt[thm][indir];

    #ifdef D
                    cout << " with thm:" << thm << " outv:" << outv << "\n";
    #endif
    
                    if(outv == inidir && p == r && stt) return {1,0};
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    if(ovf(np)) return {0,0};
                    // int addornot = (
                    //     (rf[s[p.fi][p.se]][indir] && 
                    //     vst.find(p) == vst.end())
                    // );
                    // if(cnt[outv][p.fi][p.se]) return {0,cnt[outv][p.fi][p.se] + addornot - 1};
                    auto rt = self(self,np,rev[outv],r,inidir,stt);
                    int addornot = (
                        (rf[s[np.fi][np.se]][rev[outv]] && 
                        vst.find(np) == vst.end())
                    );
                    if(addornot)vst.insert(np);
    #ifdef D
                    cout << "ADDON " << np.fi << " " << np.se << " :" << addornot << " with " << s[np.fi][np.se] << " " << rev[outv] << "\n";
    #endif
                    
                    // if(!rt.first) {
    #ifdef D
                    cout << outv << " " << p.fi << " " << p.se << " -> "  << rt.se + addornot << "\n";
    #endif
                    cnt[outv][p.fi][p.se] = rt.se + addornot;
                    return {rt.fi,rt.se + addornot};
                    // } else 
                };

                auto derain = [&](auto self,pii p,char indir,pii r,char inidir,int edv,bool stt) -> void {
                    char thm = s[p.fi][p.se];
                    char outv = nxt[thm][indir];
                    if(outv == inidir && p == r && stt) return;
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    cnt[outv][p.fi][p.se] = edv;
                    self(self,np,rev[outv],r,inidir,edv,stt);
                    return;
                };

                pii rt;
                
                if(cnt['d'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',rt.se,0);
                vst.clear();
                }
                if(cnt['u'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',rt.se,0);
                vst.clear();
                }
                if(cnt['l'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',rt.se,0);
                vst.clear();
                }
                if(cnt['r'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',rt.se,0);
                vst.clear();
                }
#ifdef D
                cout << "UPDATED " << i << " " << j << "\n";
                cout << "-u-\n";
                for(auto x:cnt['u'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-d-\n";
                for(auto x:cnt['d'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-l-\n";
                for(auto x:cnt['l'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-r-\n";
                for(auto x:cnt['r'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
#endif
            }
        for(int i = 0,j = m-1;i < n;i ++)
            {
                set<pii> vst;
                // cout << i << " " << j << "\n";
                auto dfs = [&](auto self,pii p,char indir,pii r,char inidir,bool stt) -> pii {
                    //{ring? , length }
    #ifdef D
                    cout << "DFS enter:" << p.fi << " " << p.se;
    #endif
                    char thm = s[p.first][p.second];
                    char outv = nxt[thm][indir];

    #ifdef D
                    cout << " with thm:" << thm << " outv:" << outv << "\n";
    #endif
    
                    if(outv == inidir && p == r && stt) return {1,0};
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    if(ovf(np)) return {0,0};
                    // int addornot = (
                    //     (rf[s[p.fi][p.se]][indir] && 
                    //     vst.find(p) == vst.end())
                    // );
                    // if(cnt[outv][p.fi][p.se]) return {0,cnt[outv][p.fi][p.se] + addornot - 1};
                    auto rt = self(self,np,rev[outv],r,inidir,stt);
                    int addornot = (
                        (rf[s[np.fi][np.se]][rev[outv]] && 
                        vst.find(np) == vst.end())
                    );
                    if(addornot)vst.insert(np);
    #ifdef D
                    cout << "ADDON " << np.fi << " " << np.se << " :" << addornot << " with " << s[np.fi][np.se] << " " << rev[outv] << "\n";
    #endif
                    
                    // if(!rt.first) {
    #ifdef D
                    cout << outv << " " << p.fi << " " << p.se << " -> "  << rt.se + addornot << "\n";
    #endif
                    cnt[outv][p.fi][p.se] = rt.se + addornot;
                    return {rt.fi,rt.se + addornot};
                    // } else 
                };

                auto derain = [&](auto self,pii p,char indir,pii r,char inidir,int edv,bool stt) -> void {
                    char thm = s[p.fi][p.se];
                    char outv = nxt[thm][indir];
                    if(outv == inidir && p == r && stt) return;
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    cnt[outv][p.fi][p.se] = edv;
                    self(self,np,rev[outv],r,inidir,edv,stt);
                    return;
                };

                pii rt;
                if(cnt['d'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',rt.se,0);
                vst.clear();
                }
                if(cnt['u'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',rt.se,0);
                vst.clear();
                }
                if(cnt['l'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',rt.se,0);
                vst.clear();
                }
                if(cnt['r'][i][j] == 0){
                    rt = dfs(dfs,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',0);
                    if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',rt.se,0);
                vst.clear();
                }
#ifdef D
                cout << "UPDATED " << i << " " << j << "\n";
                cout << "-u-\n";
                for(auto x:cnt['u'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-d-\n";
                for(auto x:cnt['d'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-l-\n";
                for(auto x:cnt['l'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-r-\n";
                for(auto x:cnt['r'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
#endif
            }



        for(int ss = 0,i = 0;ss < n;ss ++,i = (n-ss)%n) 
            for(int tt = 0,j = 0;tt < m;tt ++,j = (m-tt)%m) 
            {
                set<pii> vst;
                // cout << i << " " << j << "\n";
                auto dfs = [&](auto self,pii p,char indir,pii r,char inidir,bool stt) -> pii {
                    //{ring? , length }
    #ifdef D
                    cout << "DFS enter:" << p.fi << " " << p.se;
    #endif
                    char thm = s[p.first][p.second];
                    char outv = nxt[thm][indir];

    #ifdef D
                    cout << " with thm:" << thm << " outv:" << outv << "\n";
    #endif
    
                    if(outv == inidir && p == r && stt) return {1,0};
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    if(ovf(np)) return {0,0};
                    // int addornot = (
                    //     (rf[s[p.fi][p.se]][indir] && 
                    //     vst.find(p) == vst.end())
                    // );
                    // if(cnt[outv][p.fi][p.se]) return {0,cnt[outv][p.fi][p.se] + addornot - 1};
                    auto rt = self(self,np,rev[outv],r,inidir,stt);
                    int addornot = (
                        (rf[s[np.fi][np.se]][rev[outv]] && 
                        vst.find(np) == vst.end())
                    );
                    if(addornot)vst.insert(np);
    #ifdef D
                    cout << "ADDON " << np.fi << " " << np.se << " :" << addornot << " with " << s[np.fi][np.se] << " " << rev[outv] << "\n";
    #endif
                    
                    // if(!rt.first) {
    #ifdef D
                    cout << outv << " " << p.fi << " " << p.se << " -> "  << rt.se + addornot << "\n";
    #endif
                    cnt[outv][p.fi][p.se] = rt.se + addornot;
                    return {rt.fi,rt.se + addornot};
                    // } else 
                };

                auto derain = [&](auto self,pii p,char indir,pii r,char inidir,int edv,bool stt) -> void {
                    char thm = s[p.fi][p.se];
                    char outv = nxt[thm][indir];
                    if(outv == inidir && p == r && stt) return;
                    stt = 1;

                    pii np = p;
                    switch (outv)
                    {
                    case 'u':
                        np.first -= 1;
                        break;
                    case 'd':
                        np.first += 1;
                        break;
                    case 'l':
                        np.second -= 1;
                        break;
                    case 'r':
                        np.second += 1;
                        break;
                    
                    default:
                        break;
                    }
                    
                    cnt[outv][p.fi][p.se] = edv;
                    self(self,np,rev[outv],r,inidir,edv,stt);
                    return;
                };

                pii rt;
                
                if(cnt['u'][i][j] != 0) goto nxtu;
                rt = dfs(dfs,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',0);
                if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['u'],{i,j},'u',rt.se,0);
                nxtu:
                vst.clear();

                if(cnt['d'][i][j] != 0) goto nxtd;
                rt = dfs(dfs,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',0);
                if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['d'],{i,j},'d',rt.se,0);
                nxtd:
                vst.clear();

                if(cnt['l'][i][j] != 0) goto nxtl;
                rt = dfs(dfs,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',0);
                if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['l'],{i,j},'l',rt.se,0);
                nxtl:
                vst.clear();

                if(cnt['r'][i][j] != 0) goto nxtr;
                rt = dfs(dfs,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',0);
                if(rt.first) derain(derain,{i,j},rnxt[s[i][j]]['r'],{i,j},'r',rt.se,0);
                nxtr:
                vst.clear();
#ifdef D
                cout << "UPDATED " << i << " " << j << "\n";
                cout << "-u-\n";
                for(auto x:cnt['u'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-d-\n";
                for(auto x:cnt['d'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-l-\n";
                for(auto x:cnt['l'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
                cout << "-r-\n";
                for(auto x:cnt['r'])
                {for(auto y:x) cout << y << " ";cout << "\n";}
#endif
            }



        int q;
        cin >> q;

        while(q--)
        {
#ifdef D
            cout << ">>>  QES " << q << " <<<\n";
#endif
            int a,b;
            cin >> a >> b;
            a --,b --;
            string res;
            cin >> res;

            if(res == "above") {

                // if(cnt['u'][a][b] != 0) {cout << cnt['u'][a][b] << "\n";continue;}

                // auto rt = dfs(dfs,{a,b},rnxt[s[a][b]]['u'],{a,b},'u',0);
                // if(rt.first) derain(derain,{a,b},rnxt[s[a][b]]['u'],{a,b},'u',rt.se,0);

                cout << cnt['u'][a][b] << "\n";

            } else if(res == "below") {

                // if(cnt['d'][a][b] != 0) {cout << cnt['d'][a][b] << "\n";continue;}

                // auto rt = dfs(dfs,{a,b},rnxt[s[a][b]]['d'],{a,b},'d',0);
                // if(rt.first) derain(derain,{a,b},rnxt[s[a][b]]['d'],{a,b},'d',rt.se,0);

                cout << cnt['d'][a][b] << "\n";

            } else if(res == "left") {

                // if(cnt['l'][a][b] != 0) {cout << cnt['l'][a][b] << "\n";continue;}

                // auto rt = dfs(dfs,{a,b},rnxt[s[a][b]]['l'],{a,b},'l',0);
                // if(rt.first) derain(derain,{a,b},rnxt[s[a][b]]['l'],{a,b},'l',rt.se,0);
                cout << cnt['l'][a][b] << "\n";

            } else if(res == "right") {

                // if(cnt['r'][a][b] != 0) {cout << cnt['r'][a][b] << "\n";continue;}

                // auto rt = dfs(dfs,{a,b},rnxt[s[a][b]]['r'],{a,b},'r',0);
                // if(rt.first) derain(derain,{a,b},rnxt[s[a][b]]['r'],{a,b},'r',rt.se,0);

                cout << cnt['r'][a][b] << "\n";

            }

#ifdef D
            cout << "-u-\n";
            for(auto x:cnt['u'])
            {for(auto y:x) cout << y << " ";cout << "\n";}
            cout << "-d-\n";
            for(auto x:cnt['d'])
            {for(auto y:x) cout << y << " ";cout << "\n";}
            cout << "-l-\n";
            for(auto x:cnt['l'])
            {for(auto y:x) cout << y << " ";cout << "\n";}
            cout << "-r-\n";
            for(auto x:cnt['r'])
            {for(auto y:x) cout << y << " ";cout << "\n";}
#endif

        }
    }
};

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
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