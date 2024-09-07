#include <iostream>
using namespace std;
int main()
{
    int t = 100;
    int n = 2000/100;
    cout << t << "\n";
    while (t--)
    {
        cout << n << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << 67108864 << " ";
        }
        cout << "\n";
    }
}