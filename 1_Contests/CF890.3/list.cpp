#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

struct vertex
{
    ll int num;
    ll int idx;
};

bool comp(vertex a, vertex b)
{
    return a.num < b.num;
}


int main()
{
    for(;;)
    {
        int n;
        cin >> n;
        vertex a[100] = {0};
        for(int i = 0;i < n;i ++)
        {
            cin >> a[i].num;
            a[i].idx = i;
        }
        sort(a,a+n,comp);
        for(int i = 0;i < n;i ++) cout << a[i].num << " ";
        cout << endl;
        for(int i = 0;i < n;i ++) cout << a[i].idx << " ";
        cout << endl;

    }
    system("pause");
    return 0;
}