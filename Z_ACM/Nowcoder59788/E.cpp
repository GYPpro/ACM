#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>

#define ull unsigned long long
#define ld long double
#define maxn 200010
#define modq 1000000007
#define ll long long

using namespace std;

void solve()
{
    int N;
    int worker[maxn] = {0};
    int div[maxn] = {0};
    for(int i = 0;i < n;i ++) cin >> worker[i];
    sort(worker,worker+N);
    div[0] = worker[1]=worker[0];
    for(int i = 1;i < N;i ++){
        div[i] = min(worker[i-1]-worker[i])
    }
}

int main()
{
    int T = 1;
    std::ios::sync_with_stdio(false);
    cin >> T;
    for(int i = 0;i < T;i ++)
    {
        solve();
    }
    system("pause");
    return 0;
}