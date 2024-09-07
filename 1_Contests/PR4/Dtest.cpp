#include <bits/stdc++.h>
using namespace std;

#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
int main(){
    std::ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n <= 5)
        {
            int cnt = 1;
            int tmp = 1;
            cout << (n)/2+1 << "\n";
            lop(i,1,n+1) {
                cout << tmp << " ";
                cnt++;
                if(cnt == 2) {
                    tmp ++;
                    cnt = 0;
                }
            }
            cout << "\n";
            continue;;
        } else {
            cout << 4 << "\n";
            lop(i,1,n+1) cout << i%4+1 << " ";cout << "\n";
        }
    }
    return 0;
}