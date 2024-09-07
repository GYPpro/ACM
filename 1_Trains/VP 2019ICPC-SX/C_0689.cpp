#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>


#include <map>
#include <set>
#pragma GCC optimize(2)

#define int long long
#define FI for (int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second

using namespace std;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

        int t;
        cin >> t;
        vector<int> l9,l8,l6,l0;
        while (t--)
        {
            string s;
            cin >> s;
            int n = s.size();
            l8.resize(n+1);
            l8[n] = 0;
            l6.resize(n+1);
            l6[n] = 0;
            l9.resize(n+1);
            l9[n] = 0;
            l0.resize(n+1);
            l0[n] = 0;
            
            for (int i = n - 1; i >= 0; i--)
            {
                l9[i] = l9[i+1];
                l8[i] = l8[i+1];
                l0[i] = l0[i+1];
                l6[i] = l6[i+1];
                switch (s[i])
                {
                case '0':
                    l0[i] = l0[i+1]+1;
                    break;
                case '9':
                    l9[i] = l9[i+1]+1;
                    break;
                case '6':
                    l6[i] = l6[i+1]+1;
                    break;
                case '8':
                    l8[i] = l8[i+1]+1;
                    break;
                default:
                    break;
                }
            }
            int dict = 0;
            for (int i = 0; i < n; i++)
            {
                switch (s[i])
                {
                case '0':
                    dict += l0[i];
                    break;
                case '8':
                    dict += l8[i];
                    break;
                case '9':
                    dict += l6[i];
                    break;
                case '6':
                    dict += l9[i];
                    break;
                default:
                    break;
                }
            }
            map<char,int> rt;
            for(auto x:s)rt[x] ++;

            cout << n * (n + 1LL) / 2LL - dict + !(rt.size() == 1 && (s[0] == '6' || s[0] == '9'))<< "\n";
        }
    return 0;
}