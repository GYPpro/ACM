#include <iostream>
using namespace std;
int main()
{
    freopen("1.md","w",stdout);
    // ios::sync_with_stdio(0);
    cout << "1\n10000\n10000\n";
    for(int i = 0;i < 10000;i ++)
    {
        cout << "100000000 ";
    }
    cout << "\n";
    for(int i = 0;i < 10000;i ++)
    {
        cout << i << " 0\n";
    }
    long long int sum = 0;
    for(int i = 0;i < 10000;i ++)
        cout << (long long)100000000*(long long)(i+1) << " ";
    cout << "\n";
}