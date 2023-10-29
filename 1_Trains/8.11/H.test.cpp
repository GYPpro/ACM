#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int bt[39] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,167,173,179,181,191,193,197,199,11451};
bool cp(int x)
{
    x = abs(x);
    for(int i = 0;i < 38;i ++)
    {
        if(x == bt[i]) return true;
    }
    return false;
}

int main()
{
    int A[100];

    for(int i = 0;i < 100;i ++)
    {
        
        for(int k = 1;k <= i;k ++) A[k] = k;
        bool flag = 1;
        while(next_permutation(A+1, A + i))
        {
            for(int j = 1;j < i;j ++)
            {
                if(!(cp(A[j]+A[j+1]) || cp(A[j]-A[j+1])))
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag)
        {
            cout << i << endl;
            for(int j = 1;j < i+1;j ++)
            {
                cout << A[j] << " ";
            }
            cout << endl;
        } else cout << -1 << endl;
    }
    system("pause");
    return 0;
}