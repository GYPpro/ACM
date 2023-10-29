#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    for(;;)
    {
        int A[100] = {0};
        int n;
        cin >> n;
        if(n == 0)
        {
            for(int i = 0;i < 25;i ++)
            {
                printf("%3d ",i);
            }
            cout << endl;
            continue;
        }
        for(int i = 0;i < 25;i ++)
        {
            printf("%3d ",(n^i) -i);
        }
        // for(int i = 0;i < n;i ++)
        //     cin >> A[i];
        // int T = 0;
        // cin >> T;
        // for(int i = 0;i < T;i ++)
        // {
        //     int a1;
        //     cin >> a1;
        //     for(int j = 0;j < n;j ++)
        //     {
        //         cout << (A[j] ^ a1) << " ";
        //     }
        //     cout << endl;
        // }
        cout << endl;
    }
    system("pause");
    return 0;
}
