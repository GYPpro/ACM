#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;

int n ;
int a[100005];
map<int,int> mp[300005];
int pile_to_mp[300005];
int mid , pid;
string msg;
int k;
bool broken[100005];
int Merge(int x,int y) {
    if(mp[x].size() < mp[y].size()) swap(x , y) ;
    for(auto &[u,v] : mp[y]) {
        mp[x][u] += v;
    }
    return x;
}
inline int readAndCheckAnswer(InStream &in) {
    int L = in.readInt(-1, n);
    if (L == -1)
        return L;
    for(int i = 1;i <= n * 3;i++) mp[i].clear() ;
    for(int i = 1;i <= n;i++) {
        mp[i][a[i]]++ ;
        pile_to_mp[i] = i;
    }
    for(int i = 2;i <= k;i++) broken[i] = 0;
    mid = pid = n;
    int sum_m = 0;
    for(int i = 1;i <= L;i++) {
        int m = in.readInt(2 , k) ;
        sum_m += m;
        if(sum_m > n * 3) {
            msg = "Sum m exceed 3n" ;
            return 0;
        }
        if(broken[m]) {
            msg = "The machine is broken\n" ; 
            return 0;
        }
        vector<int> v(m) ;
        int new_pile_mp = 0;
        for(int j = 0;j < m;j++) {
            v[j] = in.readInt(1 , pid) ;
            if(pile_to_mp[v[j]] == 0) {
                msg = "Wrong answer, choose an empty pile" ;
                return 0;
            }
            new_pile_mp = Merge(new_pile_mp , pile_to_mp[v[j]]) ;
            pile_to_mp[v[j]] = 0;
        }
        if(mp[new_pile_mp].size() == 1 && mp[new_pile_mp].begin()->first == m) {
            pile_to_mp[pid + 1] = new_pile_mp ;
            pile_to_mp[pid + 2] = 0;
            pid += 2;
            broken[m] = 1;
        }
        else if(mp[new_pile_mp].count(m) == 0) {
            pile_to_mp[pid + 2] = new_pile_mp ;
            pile_to_mp[pid + 1] = 0;
            pid += 2;
        }
        else {
            mid++ ;
            mp[mid][m] = mp[new_pile_mp][m] ;
            mp[new_pile_mp].erase(m) ;
            pile_to_mp[pid + 1] = mid ;
            pile_to_mp[pid + 2] = new_pile_mp;
            pid += 2;
            broken[m] = 1;
        }
    }
    int nid = 0;
    for(int i = 1;i <= pid;i++) {
        if(pile_to_mp[i]) {
            if(nid == 0) nid = pile_to_mp[i];
            else {
                msg = "There are more than one piles" ;
                return 0;
            }
        }
    }
    return 1;
}
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
 
    int t = inf.readInt() ;
    for(int i = 1;i <= t;i++) {
        n = inf.readInt() ; k = inf.readInt() ;
        for(int j = 1;j <= n;j++) a[j] = inf.readInt() ;
        int ja = readAndCheckAnswer(ans) ;
        int pa = readAndCheckAnswer(ouf) ;
        if(ja == 0) {
            quitf(_fail , msg.c_str()) ;
        }
        if(pa == 0) {
            quitf(_wa , msg.c_str()) ;
        }
        if (ja != -1 && pa == -1)
            quitf(_wa, "Jury has the answer but participant has not");
        if (ja == -1 && pa != -1)
            quitf(_fail, "Participant has the answer but jury has not");
 
    }
    quitf(_ok , "ok") ;
    return 0;
}
