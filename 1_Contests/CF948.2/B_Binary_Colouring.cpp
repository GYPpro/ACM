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
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fi first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

class solution
{
private:

public:
    void solve()
    {
        int x;
        vector<int> bin(32);
        cin >> x;
        for(int i = 0;i < 32;i ++)
        {
            bin[i] = x%2;
            x /= 2;
        }
        vector<int> ans;
        bool pushf = 1;
        for(int i = 0;i < 31;i ++)
        {
            // if(bin[i] == 1 && bin[i+1] == 1)
            // {
            //     if(pushf) {bin[i] = -1;pushf = 0;}
            //     else bin[i] = 0;
            // } else if(bin[i] == 1 && bin[i+1] == 0)
            // {
            //     pushf = 1;
            //     bin[i+1] = 1;
            //     bin[i] = 0;
            // }
            if(bin[i] == 1){
                if(bin[i+1] == 1) if(pushf) {
                        bin[i] = -1;
                        pushf = 0;
                    } else bin[i] = 0,bin[i+1] = 1;
                else if(pushf) continue;
                    else {
                        bin[i] = 0;
                        bin[i+1] = 1;
                        pushf = 1;
                    }
            }
        }
        int top = 32;
        while(top --) if(bin[top] != 0) break;
        cout << top +1 << "\n";
        for(int i = 0;i <= top;i ++)
        {
            cout << bin[i] << " ";
        }
        cout << endl;
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

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