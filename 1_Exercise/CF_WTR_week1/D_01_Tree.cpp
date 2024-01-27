#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define int long long
#define mod1 998244353
#define NEL 1145141919810LL

// template<class T>
// class linkedList{
//     class LLnode{
//         public:
//         T data;
//         int r;
//         int l;

//         LLnode()
//         {
//             r = NEL;
//             l = NEL;
//         }
//         LLnode(T _data)
//         {
//             r = NEL;
//             l = NEL;
//             data = _data;
//         }
//     };

//     public:
//     vector<LLnode> dt;
//     void init(const vector<T> &indata)
//     {
//         dt.clear;
//         dt.resize(indata.size());
//         for(int i = 1;i < indata.size()-1;i ++)
//         {
//             dt[i-1].r = i;
//             dt[i+1].l = i;
//             dt[i].l = i-1;
//             dt[i].r = i+1;
//         }
//         for(int i = 0;i < indata.size()-1;i ++)
//             dt[i].data = indata[i];
//     }
//     linkedList(){;}
//     linkedList(const vector<T> &indata)
//     {
//         dt.clear;
//         dt.resize(indata.size());
//         for(int i = 1;i < indata.size()-1;i ++)
//         {
//             dt[i-1].r = i;
//             dt[i+1].l = i;
//             dt[i].l = i-1;
//             dt[i].r = i+1;
//         }
//         for(int i = 0;i < indata.size()-1;i ++)
//             dt[i].data = indata[i];
//     }

//     LLnode& operator[] (const int i)
//     {
//         return dt[i];
//     }

//     void erase(int i)
//     {
//         if(dt[i].r != NEL) dt[dt[i].r].l = dt[i].l;
//         if(dt[i].l != NEL) dt[dt[i].l].r = dt[i].r;
//     }
//     LLnode& r(int i)
//     {
//         if(dt[i].r != NEL) return dt[dt[i].r];
//         else return NEL;
//     }
//     LLnode& l(int i)
//     {
//         if(dt[i].l != NEL) return dt[dt[i].l];
//         else return NEL;
//     }
// };

// class solution{
//     private:
//         map<int,int> arr;

//     bool perm(int i)
//     {
//         bool comp = 0;
//         if(i > 0) comp = (arr[i] == arr[i-1] +1);
//         if(i < arr.size()-1) comp = (arr[i] == arr[i+1] +1);
//         return comp;
//     }
//     public:

//     void solve()
//     {
//         int n;
//         cin >> n;
//         for(int i = 0 ;i < n;i ++){
//             int tmp;
//             cin >> tmp;
//             arr[i] = tmp;
//         }
//         vector<int> arr(n,-1);
//         map<int,set<int>> cnt;
//         set<int> prq;
//         for(int i = 0;i < n;i ++)
//             cnt[arr[i]].insert(i);
//         for(int i = n;i >= 0;i --)
//         {
//             if(cnt.find(i) == cnt.end()) continue;
//         }
//         cout << "ac" << "\n";
//     }
// };

    class LLnode{
        public:
        int data;
        int r;
        int l;

        LLnode()
        {
            r = NEL;
            l = NEL;
        }
        LLnode(int _data)
        {
            r = NEL;
            l = NEL;
            data = _data;
        }
    };

class solution{
    public:
        vector<LLnode> lk;
        vector<int> arr;

    bool perm(int i)
    {
        bool comp = 0;
        // if(i > 0) comp = (lk[i].data == lk.l(i).data +1);
        if(lk[i].r != NEL) comp |= (lk[i].data == lk[lk[i].r].data +1);
        // if(i < arr.size()-1) comp = (lk[i].data == lk.r(i).data +1);
        if(lk[i].l != NEL) comp |= (lk[i].data == lk[lk[i].l].data +1);
        return comp;
    }

    void solve()
    {
        int n;
        cin >> n;
        arr.resize(n);
        for(auto &x:arr) cin >> x;
        
        lk.resize(n);
        if(n > 1)
        {
            lk[0].r = 1;
            lk[n-1].l = n-2;
        }
        for(int i = 1;i < arr.size()-1;i ++)
        {
            lk[i-1].r = i;
            lk[i+1].l = i;
            lk[i].l = i-1;
            lk[i].r = i+1;
        }
        for(int i = 0;i < arr.size();i ++)
            lk[i].data = arr[i];

        map<int,set<int>> cnt;
        for(int i = 0;i < n;i ++)
            cnt[arr[i]].insert(i);
        for(int i = n;i >= 0;i --)
        {
            if(cnt.find(i) == cnt.end()) continue;
            set<int> rmq;
            for(auto x:cnt[i])
            {
                if (perm(x)) rmq.insert(x);
            }
            set<int> atl = cnt[i];
            while(rmq.size())
            {
                int th = *rmq.begin();
                if(lk[th].r != NEL) lk[lk[th].r].l = lk[th].l;
                if(lk[th].l != NEL) lk[lk[th].l].r = lk[th].r;
                atl.erase(th);
                rmq.erase(th);
                // if(perm(lk[th].r) && (lk.r(th).data == i)) rmq.insert(lk[th].r);
                // if(perm(lk[th].l) && (lk.l(th).data == i)) rmq.insert(lk[th].l);
                if(lk[th].r != NEL) if(perm(lk[th].r)) if(lk[lk[th].r].data == i) rmq.insert(lk[th].r);
                if(lk[th].l != NEL) if(perm(lk[th].l)) if(lk[lk[th].l].data == i) rmq.insert(lk[th].l);
            }
            if(atl.size()) {
                if(atl.size() == 1 && i == 0) continue;
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    std::cin.tie(0);
    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solution sl;
        sl.solve();
    }

    // system("pause");

    return 0;
}