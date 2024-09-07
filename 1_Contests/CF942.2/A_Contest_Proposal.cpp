#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for(int i = 0;i < n;i ++)
#define pb push_back
#define fr first
#define se second


void sort(auto &x)
{
    sort(x.begin(),x.end());
};

using namespace std;

class solution
{
private:
int subsearch_2(int tar, vector<int> &arr) // 第二类二分：取小于或等于tar的最大的元素
{
    int l = 0;
    int r = arr.size();
    int m = 0;
    while (r > l + 1)
    {
        int m =(l + r )/2;
        if (arr[m] > tar)
            r = m;
        else
            l = m;
    }
    return l;
}

public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> arr1(n);
        vector<int> arr2(n);
        FI cin >> arr1[i];

        FI cin >> arr2[i];

        int maxn = 0;
        int idx = 0;
        FI{
            if(arr2[i] < arr1[idx]) maxn ++;
            else idx ++;
        }
        cout << maxn <<  "\n";
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