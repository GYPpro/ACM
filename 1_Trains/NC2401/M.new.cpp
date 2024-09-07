// #define D

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
        cnt['u'] = vector<vector<int>>(n,vector<int>(m,-1));
        cnt['d'] = vector<vector<int>>(n,vector<int>(m,-1));
        cnt['l'] = vector<vector<int>>(n,vector<int>(m,-1));
        cnt['r'] = vector<vector<int>>(n,vector<int>(m,-1));

        auto ovf = [&](pii c) -> bool {
            if(c.first < 0 || c.first >= n) return true;
            if(c.second < 0 || c.second >= m) return true;
            return false;
        };

        for(auto &x:s)
            for(auto &y:x)
                cin >> y;
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

            set<pii> vst;
            bool thisrev = 0;
            pii ed;
            char ev;
            auto dfs = [&](auto self,pii p,char indir,pii r,char inidir,bool stt) -> pii {
                //{ring? , length }
                
                ed = p;
                ev = indir;
#ifdef D
                cout << "DFS enter:" << p.fi << " " << p.se;
#endif
                char thm = s[p.first][p.second];
                char outv = nxt[thm][indir];
                if(outv == inidir && p == r && stt) {
                cnt[outv][p.fi][p.se] = 0;return {1,0};}
                stt = 1;
                if(cnt[outv][p.fi][p.se] != -1 && thisrev ){ return {0,cnt[outv][p.fi][p.se]};}
#ifdef D
                cout << " with thm:" << thm << " outv:" << outv << "\n";
#endif

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
                
                if(ovf(np)) { cnt[outv][p.fi][p.se] = 0;return {0,0};}
                pii rt;
                rt = self(self,np,rev[outv],r,inidir,stt);
                // cnt[outv][p.fi][p.se] = 0;
                // else rt = {0,cnt[outv][np.fi][np.se]};
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
                cnt[indir][p.fi][p.se] = edv;
                self(self,np,rev[outv],r,inidir,edv,stt);
                return;
            };

            auto find = [&](pii p,char outdir) -> void{
                thisrev = 0;
                auto rt = dfs(dfs,p,rnxt[s[p.fi][p.se]][outdir],p,outdir,0);
                if(rt.first) derain(derain,p,rnxt[s[p.fi][p.se]][outdir],p,outdir,rt.se,0);
                else {
                    // auto vstn = vst;
                    thisrev = 1;
                    // vst.clear();
#ifdef D
                    cout << "entREV:" <<  ed.fi <<  " " << ed.se <<  " " <<  ev <<  "\n";
#endif
                    if(cnt[ev][ed.fi][ed.se] == -1) dfs(dfs,ed,rnxt[s[ed.fi][ed.se]][ev],ed,ev,0);
                    // vst.clear();
                    // vst = vstn;
#ifdef D
                    cout << "entREV:" <<  ed.fi <<  " " << ed.se <<  " " <<  ev <<  "\n";
#endif
                    if(cnt[ev][ed.fi][ed.se] == -1) dfs(dfs,ed,rnxt[s[ed.fi][ed.se]][ev],ed,ev,0);
                }
            };

            if(res == "above") {

                if(cnt['u'][a][b] != -1) {cout << cnt['u'][a][b] << "\n";continue;}

                // auto rt = dfs(dfs,{a,b},rnxt[s[a][b]]['u'],{a,b},'u',0);
                // if(rt.first) derain(derain,{a,b},rnxt[s[a][b]]['u'],{a,b},'u',rt.se,0);
                find({a,b},'u');
                cout << cnt['u'][a][b] << "\n";

            } else if(res == "below") {

                if(cnt['d'][a][b] != -1) {cout << cnt['d'][a][b] << "\n";continue;}

                // auto rt = dfs(dfs,{a,b},rnxt[s[a][b]]['d'],{a,b},'d',0);
                // if(rt.first) derain(derain,{a,b},rnxt[s[a][b]]['d'],{a,b},'d',rt.se,0);

                find({a,b},'d');
                cout << cnt['d'][a][b] << "\n";

            } else if(res == "left") {

                if(cnt['l'][a][b] != -1) {cout << cnt['l'][a][b] << "\n";continue;}

                // auto rt = dfs(dfs,{a,b},rnxt[s[a][b]]['l'],{a,b},'l',0);
                // if(rt.first) derain(derain,{a,b},rnxt[s[a][b]]['l'],{a,b},'l',rt.se,0);
                
                find({a,b},'l');
                cout << cnt['l'][a][b] << "\n";

            } else if(res == "right") {

                if(cnt['r'][a][b] != -1) {cout << cnt['r'][a][b] << "\n";continue;}

                // auto rt = dfs(dfs,{a,b},rnxt[s[a][b]]['r'],{a,b},'r',0);
                // if(rt.first) derain(derain,{a,b},rnxt[s[a][b]]['r'],{a,b},'r',rt.se,0);

                find({a,b},'r');
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