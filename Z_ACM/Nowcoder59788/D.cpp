#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <numeric>

#define ull unsigned long long
#define ld long double
#define maxn 3000010
#define testmax 100
#define modq 1000000007
#define ll long long

using namespace std;

    int Stu_Are[maxn] = {0};
    int AreNum[200010] = {0};
void solve()
{
    int cacustu = 0;
    int m,n;
    cin >> n >> m;
    n *= 3;
    memset(Stu_Are,0,maxn-1);
    memset(AreNum,0,200009);
    int idxThisAr = 1;
    for(int i = 0;i < m;i ++)
    {
        int tmpa,tmpb;
        cin >> tmpa >> tmpb;
        if((Stu_Are[tmpa] == 0) && (Stu_Are[tmpb] == 0))
        {
            Stu_Are[tmpa] = idxThisAr;
            Stu_Are[tmpb] = idxThisAr;
            AreNum[idxThisAr] += 2;
            cacustu += 2;
            idxThisAr ++;
        } else if((Stu_Are[tmpa] == 0) && (Stu_Are[tmpb] != 0)){//tmpa = 0
            AreNum[Stu_Are[tmpb]] ++;
            cacustu ++;
            Stu_Are[tmpa] = Stu_Are[tmpb];
        } else if((Stu_Are[tmpb] == 0) && (Stu_Are[tmpa] != 0)){//tmpb = 0
            AreNum[Stu_Are[tmpa]] ++;
            cacustu ++;
            Stu_Are[tmpb] = Stu_Are[tmpa];
        } else continue;
    }
    int Num[3] = {0};
    Num[1] = n-cacustu;
    for(int i = 1;i <= idxThisAr;i ++) Num[AreNum[i]%3] ++;
    if(Num[1] < Num[2]){
        int div = Num[2]-Num[1];
        div /= 3;
        Num[1] += 2*div;
        Num[2] -= div;
    }
    ll int ANS = 4*Num[2] + 2*(Num[1]-Num[2]);
    cout << ANS;
    return;
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