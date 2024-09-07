// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}

class DynamicMedim
{
    public:
        // multiset<int> a,b;
        ordered_multiset c;
        int sa,sb,mid;
    public:
        inline void init(void)
        {
            // a.clear(); b.clear(); sa=sb=0;
            sa = sb = mid = 0;c.clear();
        }
        inline void insert(int x)
        {
            if(c.empty()) {
                c.insert(x);
                sb += x;
                mid = x;
                return;
            }
            mid = *c.find_by_order((c.size()-1)/2);
            if(x >= mid)  sb += x; 
            else sa += x;
            c.insert(x);
            if(*c.find_by_order((c.size()-1)/2) > mid) sb -= mid,sa += mid;
            else if(*c.find_by_order((c.size()-1)/2) < mid) sb += mid,sa -= mid;
            // if (b.empty())
            // {
            //     b.insert(x); sb+=x; return;
            // }
            // int mid=*b.begin();
            // if (x>=mid)
            // {
            //     b.insert(x); sb+=x;
            //     if (a.size()<b.size()-1)
            //     {
            //         auto it=b.begin(); sb-=*it; sa+=*it;
            //         a.insert(*it); b.erase(it);
            //     }
            // } else
            // {
            //     a.insert(x); sa+=x;
            //     if (a.size()>b.size())
            //     {
            //         auto it=(--a.end()); sa-=*it; sb+=*it;
            //         b.insert(*it); a.erase(it);
            //     }
            // }
        }
        void remove(int x)
        {
            mid = *c.find_by_order((c.size()-1)/2);
            // if(c.find(x) == c.end()) cout << x << "BRK\n";
            c.erase(c.find_by_order(c.order_of_key(x)));
            if(x >= mid) sb -= x;
            else sa -= x;
            // mid = *c.find_by_order((c.size()-1)/2);
            // if(*c.find_by_order((c.size()-1)/2) > mid) sb -= mid,sa += mid;
            // else if(*c.find_by_order((c.size()-1)/2) < mid) sb += mid,sa -= mid;
            // int mid=*b.begin();
            // if (x>=mid)
            // {
            //     b.erase(b.find(x)); sb-=x;
            //     if (a.size()>b.size())
            //     {
            //         auto it=(--a.end()); sa-=*it; sb+=*it;
            //         b.insert(*it); a.erase(it);
            //     }
            // } else
            // {
            //     a.erase(a.find(x)); sa-=x;
            //     if (a.size()<b.size()-1)
            //     {
            //         auto it=b.begin(); sb-=*it; sa+=*it;
            //         a.insert(*it); b.erase(it);
            //     }
            // }
        }
        inline int get()
        {
            return mid = *c.find_by_order((c.size()-1)/2);
        }
        inline int calcSum()
        {
            mid = *c.find_by_order((c.size()-1)/2);
            return (mid*(c.size()/2)-sa)+(sb-mid*((c.size()+1)/2));
        }
}S;

void check()
{
    int q;
    cin >> q;
        multiset<int> list;
    while(q--)
    {
        char op;
        cin >> op;
        switch (op)
        {
        case 'i':{
            int t;
            cin >> t;
            S.insert(t);
            list.insert(t);
        }
           goto CASEP;
        case 'e':{
            int t;
            cin >> t;
            if(list.find(t) != list.end())
                S.remove(t),list.erase(t);
            else cout << "Illigal op\n";
        }
           goto CASEP;
        CASEP:
        case 'p':{
            cout << "ANS:" << S.calcSum() << " sa:" << S.sa << " sb:" << S.sb << " mid:" << S.get() << "\nat:\n";
            for(auto x:list) cout << x << " ";
            // for(auto x:S.c) cout << x << " ";
            cout << "\n";
        }
            break;
        
        default:
            break;
        }
    }
}

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    // for(auto &x:arr) cin >> x;
    lop(i,0,n) cin >> arr[i];
    lop(i,0,n) arr[i] -= i;
    // cout << "?\n";
    int l = 0,r = 0;
    S.init();
    // S.insert(arr[r]);
    int maxlen = 0;
    for(;l < n;l ++)
    { 
        while(r < n) {
            // cout << l << " " << r << "\n";
            S.insert(arr[r]);
            r ++;
            if(S.calcSum() > k ) {
                r --;
                S.remove(arr[r]);
                break;
            }
        }
        // r --;
        // cout << "--";
        // S.remove(arr[r]);
        // cout << "--";
        maxlen = max(maxlen,r-l);
        // cout << "--";
        S.remove(arr[l]);
        // cout << "--";
    }
    cout << maxlen << "\n";
    
}

signed main()
{
#ifndef D
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif

    check();

    int T = 1;
    cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
