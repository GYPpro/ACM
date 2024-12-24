// // #pragma GCC optimize(2)

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update>;
// #define int long long
// #define pii pair<int,int>
// #define pb push_back
// #define fi first
// #define se second
// const int INF = 1145141919810LL;
// #define lop(i, a, b) for(int i = a; i < b ; i++) 
// #define all(x) x .begin(), x .end()
// #define ord(u, v) {min(u ,v ),max(u ,v )}
// // #define set unordered_set
// // #define map unordered_map
// char lst[] = {'U','L','R','D'};
// void solve()
// {
//     // int n,m;
//     // cin >> n >> m;
//     int n = rand()%10;
//     int m = rand()%10;
//     int ttl = rand()%20+2;
//     string f;
//     while(ttl--) f += lst[rand()%4];
//     // cin >> f;
//     map<int,int> cnt;
//     for(auto x:f) cnt[x] ++;
//     string l,s;
//     string l2,s2;
//     int t = 0;
//     if((n == 0 && m == 0) || (n == cnt['R']-cnt['L'] && m == cnt['U']-cnt['D'])) {
//         // cout << "Impossible\n";
//         return;
//     }
//     while(t < min(cnt['U'],cnt['D'])){
//         t ++;
//         l2 += 'U',l2 += 'D';
//         l += 'D',l += 'U';
//     } 
//     if(cnt['U'] > cnt['D']) while(t < cnt['U']) {
//         t ++,l += 'U',l2 += 'U';
//     }
//     if(cnt['U'] < cnt['D']) while(t < cnt['D']) {
//         t ++,l += 'D',l2 += 'D';
//     }
//     t = 0;
//     while(t < min(cnt['R'],cnt['L'])){
//         t ++;
//         s2 += 'R',s2 += 'L';
//         s += 'L',s += 'R';
//     } 
//     if(cnt['R'] > cnt['L']) while(t < cnt['R']) {
//         t ++,s += 'R',s2 += 'R';
//     }
//     if(cnt['R'] < cnt['L']) while(t < cnt['L']) {
//         t ++,s += 'L',s2 += 'L';
//     }
    

//     auto check = [&](string s) -> bool {
//         int cx = 0,cy = 0;
//         for(auto x:s){
//             if(cx == n && cy == m) return 0;
//             switch (x)
//             {
//             case 'U': cy ++;
//                 break;
//             case 'D': cy --;
//                 break;
//             case 'L': cx --;
//                 break;
//             case 'R': cx ++;
//                 break;
//             }
            
//         }
//         if(cx == n && cy == m) return 0;
//         return 1;
//     };

//     auto imps = [&]( ) {
//         // cout << "Impossible\n";
//         cout << "ASSERT WA\n";
//         cout << f << "\n";
//         cout << n << " " << m << "\n";
//         cout << "--------------\n";
//         system("pause");
//     };

//     //l:U,D s:L,R
//     if(n == 0 && cnt['R']-cnt['L'] == 0) {
//         string ans;
//         while(cnt['R'] --)ans += "R";
//         ans += l;
//         while(cnt['L'] --)ans += "L";
    
//         if(check(ans)) cout << ans << "\n";
//         else imps();
//         return;
//     }
//     if(m == 0 && cnt['U']-cnt['D'] == 0) {
//         string ans;
//         while(cnt['U'] --)ans += "U";
//         ans += s;
//         while(cnt['D'] --)ans += "D";
//         if(check(ans)) cout << ans << "\n";
//         else imps();
//         return;
//     }

//     map<int,int> cnt2,cnt3;
//     for(auto x:l) cnt2[x] ++;
//     for(auto x:l2) cnt3[x] ++;
//     for(auto x:s) cnt2[x] ++;
//     for(auto x:s2) cnt3[x] ++;
//     for(auto [u,v]:cnt) if(cnt2[u] != v || cnt3[u] != v){
//         cout << "ASSERT FALSE AT:" << f << "\n";
//         cout << l << " " << l2 << " " << s << " " << s2 << "\n";
//         system("pause");
//     }
    
//     cout << "ACCEPTED\n";
//     if(check(l+s)) cout << l+s << "\n";
//     else if(check(s+l)) cout << s+l << "\n";
//     else if(check(l2+s2)) cout << l2+s2 << "\n";
//     else if(check(s2+l2)) cout << s2+l2 << "\n";
//     else imps();
//     // cout << l << " " << s << "\n";
// }

// signed main()
// {
// #ifdef FC
//     freopen("G.A.in","r",stdin);
//     freopen("G.A.ptc","w",stdout);
// #endif
// #ifndef FC
//     // std::ios::sync_with_stdio(false);
//     // std::cin.tie(0);
//     // std::cout.tie(0);
// #endif
//     int T = 1;
//     cin >> T;
//     while(T--) solve();
//     return 0;
// }

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ord_set = tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
// #define set unordered_set
// #define map unordered_map
char lst[] = {'U','L','R','D'};
void solve()
{
    int n,m;
    cin >> n >> m;
    // int n = rand()%10;
    // int m = rand()%10;
    // int ttl = rand()%10+2;
    string f;
    // while(ttl--) f += lst[rand()%4];
    cin >> f;
    map<int,int> cnt;
    for(auto x:f) cnt[x] ++;
    string l,s;
    string l2,s2;
    int t = 0;
    if((n == 0 && m == 0) || (n == cnt['R']-cnt['L'] && m == cnt['U']-cnt['D'])) {
        cout << "Impossible\n";
        return;
    }
    while(t < min(cnt['U'],cnt['D'])){
        t ++;
        l2 += 'U',l2 += 'D';
        l += 'D',l += 'U';
    } 
    if(cnt['U'] > cnt['D']) while(t < cnt['U']) {
        t ++,l += 'U',l2 += 'U';
    }
    if(cnt['U'] < cnt['D']) while(t < cnt['D']) {
        t ++,l += 'D',l2 += 'D';
    }
    t = 0;
    while(t < min(cnt['R'],cnt['L'])){
        t ++;
        s2 += 'R',s2 += 'L';
        s += 'L',s += 'R';
    } 
    if(cnt['R'] > cnt['L']) while(t < cnt['R']) {
        t ++,s += 'R',s2 += 'R';
    }
    if(cnt['R'] < cnt['L']) while(t < cnt['L']) {
        t ++,s += 'L',s2 += 'L';
    }
    

    auto check = [&](string s) -> bool {
        int cx = 0,cy = 0;
        for(auto x:s){
            if(cx == n && cy == m) return 0;
            switch (x)
            {
            case 'U': cy ++;
                break;
            case 'D': cy --;
                break;
            case 'L': cx --;
                break;
            case 'R': cx ++;
                break;
            }
            
        }
        if(cx == n && cy == m) return 0;
        return 1;
    };



    //l:U,D s:L,R
    if(n == 0 && cnt['R']-cnt['L'] == 0) {
        string bf,sf;
        while(cnt['R'] --)bf += "R";
        while(cnt['L'] --)sf += "L";
        if(check(bf+l+sf)) cout << bf+l+sf << "\n";
        // else if(check(bf+l2+sf)) cout << bf+l2+sf << "\n";
        else cout << "Impossible\n";
        return;
    }
    if(m == 0 && cnt['U']-cnt['D'] == 0) {
        string bf,sf;
        while(cnt['U'] --)bf += "U";
        while(cnt['D'] --)sf += "D";
        if(check(bf+s+sf)) cout << bf+s+sf << "\n";
        // else if(check(bf+s2+sf)) cout << bf+s2+sf << "\n";
        else cout << "Impossible\n";
        return;
    }

    // map<int,int> cnt2,cnt3;
    // for(auto x:l) cnt2[x] ++;
    // for(auto x:l2) cnt3[x] ++;
    // for(auto x:s) cnt2[x] ++;
    // for(auto x:s2) cnt3[x] ++;
    // for(auto [u,v]:cnt) if(cnt2[u] != v || cnt3[u] != v){
    //     cout << "ASSERT FALSE AT:" << f << "\n";
        // cout << l << " " << l2 << " " << s << " " << s2 << "\n";
    //     system("pause");
    // }
    
    // cout << "ACCEPTED\n";
    if(check(l+s)) cout << l+s << "\n";
    else if(check(s+l)) cout << s+l << "\n";
    else if(check(l2+s2)) cout << l2+s2 << "\n";
    else if(check(s2+l2)) cout << s2+l2 << "\n";
    else{
        // cout << "-----------\n";
        // cout << "f:" << f << "\n";
        // cout << n << " " << m  << "\n";
        cout << "Impossible\n";
        // system("pause");
    }
    // cout << l << " " << s << "\n";
}

signed main()
{
#ifdef FC
    freopen("G.A.in","r",stdin);
    freopen("G.A.ptc","w",stdout);
#endif
#ifndef FC
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
