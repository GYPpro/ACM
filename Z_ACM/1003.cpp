
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>

using namespace std;

#define maxn 1000100
#define ll long long

ll int tree_maxn[4*maxn];
ll int tree_maxn_idx[4*maxn];
ll int tree_minn[4*maxn];
ll int tree_minn_idx[4*maxn];
ll int ln_maxn[4*maxn];
ll int ln_minn[4*maxn];
ll int **S = new ll int*[maxn];
ll int siA[maxn] = {0};
ll int siN[maxn] = {0};

ll int d[4*maxn];
ll int a[maxn];

void build(int s,int t,int p)
{
    if(s == t) {
        d[p] = a[s];
        tree_maxn[p] = a[s];
        tree_maxn_idx[p] = s;
        tree_minn[p] = a[s];
        tree_minn_idx[p] = s;
        return;
    }
    int mid = (s+t)/2;
    build(s,mid,p*2);
    build(mid+1,t,p*2+1);
    if(tree_maxn[p*2] >= tree_maxn[p*2+1]) {
        tree_maxn[p] = tree_maxn[p*2];
        tree_maxn_idx[p] = tree_maxn_idx[p*2];
    } else {
        tree_maxn[p] = tree_maxn[p*2+1];
        tree_maxn_idx[p] = tree_maxn_idx[p*2+1];
    }
    if(tree_minn[p*2] <= tree_minn[p*2+1]) {
        tree_minn[p] = tree_minn[p*2];
        tree_minn_idx[p] = tree_minn_idx[p*2];
    } else {
        tree_minn[p] = tree_minn[p*2+1];
        tree_minn_idx[p] = tree_minn_idx[p*2+1];
    }
    d[p] = d[p*2] + d[p*2+1];
    return;
}

int getmaxn()
{
    return tree_maxn[1];
}

int getmaxn_idx()
{
    return tree_maxn_idx[1];
}

int getminn()
{
    return tree_minn[1];
}

int getminn_idx()
{
    return tree_minn_idx[1];
}

void resetNode(int s,int t,int p,int l,int n)
{
    if((l == s) && (l == t)) {
        d[p] = n;
        a[l] = n;
        tree_maxn[p] = n;
        tree_minn[p] = n;
        return;
    }
    int mid = (s+t)/2;
    if(l <= mid) {
        resetNode(s,mid,p*2,l,n);
    } else {
        resetNode(mid+1,t,p*2+1,l,n);
    }
    if(tree_maxn[p*2] >= tree_maxn[p*2+1]) {
        tree_maxn[p] = tree_maxn[p*2];
        tree_maxn_idx[p] = tree_maxn_idx[p*2];
    } else {
        tree_maxn[p] = tree_maxn[p*2+1];
        tree_maxn_idx[p] = tree_maxn_idx[p*2+1];
    }
    if(tree_minn[p*2] <= tree_minn[p*2+1]) {
        tree_minn[p] = tree_minn[p*2];
        tree_minn_idx[p] = tree_minn_idx[p*2];
    } else {
        tree_minn[p] = tree_minn[p*2+1];
        tree_minn_idx[p] = tree_minn_idx[p*2+1];
    }
    d[p] = d[p*2] + d[p*2+1];
    return;
}

void solve()
{
    memset(tree_maxn, 0, sizeof(tree_maxn));
    memset(tree_minn, 0, sizeof(tree_minn));
    memset(ln_maxn, 0, sizeof(ln_maxn));
    memset(ln_minn, 0, sizeof(ln_minn));
    memset(d, 0, sizeof(d));
    memset(a, 0, sizeof(a));
    memset(tree_maxn_idx, 0, sizeof(tree_maxn_idx));
    memset(tree_minn_idx, 0, sizeof(tree_minn_idx));
    memset(siA, 0, sizeof(siA));
    memset(siN, 0, sizeof(siN));
    ll int n;
    cin >> n;
    for(int i = 0;i < n;i ++){
        ll int si;
        cin >> si;
        siN[i] = si;
        S[i] = new ll int[(int)si]();
        // vector<ll int> tmp;
        // for(int j = 0;j < si;j ++) {
        //     ll int tmpn;
        //     cin >> tmpn;
        //     tmp.push_back(tmpn);
        // }
        // S.push_back(tmp);
        // sort(S[i].begin(),S[i].end());
        for(int j = 0;j < si;j ++) {
            cin >> S[i][j];
        }   
        sort(S[i],S[i]+si);
    }
    vector<int> ans;
    for(int i = 0;i < n;i ++) a[i] = S[i][0];
    build(0, n - 1, 1);
    ans.push_back(getmaxn() - getminn());
    for(;;)
    {
        int tmpMinnIdx = getminn_idx();
        siA[tmpMinnIdx] ++;
        if(siA[tmpMinnIdx] >= siN[tmpMinnIdx]) break;
        resetNode(0,n-1,1,tmpMinnIdx,S[tmpMinnIdx][siA[tmpMinnIdx]]);
        ans.push_back(getmaxn() - getminn());
    }
    ll int minnans = INT_MAX;
    for(int i = 0;i < ans.size();i ++)
        if(ans[i] < minnans) minnans = ans[i];
    cout << minnans << endl;
}

int main()
{
    memset(tree_maxn, 0, sizeof(tree_maxn));
    memset(tree_minn, 0, sizeof(tree_minn));
    memset(ln_maxn, 0, sizeof(ln_maxn));
    memset(ln_minn, 0, sizeof(ln_minn));
    memset(d, 0, sizeof(d));
    int T;
    std::ios::sync_with_stdio(false);
    // cin >> T;
    // for (int i = 0; i < T; i++)
    //     cin >> a[i];

    // build(0, T - 1, 1);
    // cout << getmaxn() << endl;
    // cout << getminn() << endl;
    // for(;;)
    // {
    //     int n,l;
    //     cin >> l >> n;
    //     resetNode(0, T - 1, 1, l, n);
    //     cout << "set a[" << l << "] to " << n << endl;
    //     cout << "find maxn value:" << getmaxn() << " in " << getmaxn_idx()<< endl;
    //     cout << "find minn value:" << getminn() << " in " << getminn_idx()<< endl;
    //     cout << "reseted array:" << endl;
    //     for(int i = 0;i < T;i ++)
    //         cout << a[i] << " ";
    // }

    // int T;
    cin >> T;
    for(int i = 0;i < T;i ++)
        solve();


    //system("pause");
    return 0;
}