#define _USE_IOSTREAM_
// #define _USE_STDIO_

#ifdef _USE_IOSTREAM_
#include <iostream>
#endif
#ifdef _USE_STDIO_
#include <stdio.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define ll long long
#define mod1 998244353
#define maxn 1000100
#define ull unsigned long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    vector<int> cntn(n);
    vector<int> cntm(m);

    vector<int> pwn(n);
    vector<int> pbn(n);

    for (int i = 0; i < n; i++)
    {
        int tmpsum = 0;
        int pbsum = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != '.')
                tmpsum++;
            if ((arr[i][j] != '.') && (arr[i][j] != 'L') && (arr[i][j] != 'R'))
                pbsum++;
        }
        if (tmpsum % 2 == 1)
        {
            cout << -1 << endl;
            return;
        }
        cntn[i] = tmpsum;
        pwn[i] = pbsum/2;
        pbn[i] = pbsum/2;
    }
    for (int i = 0; i < m; i++)
    {
        int tmpsum = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] != '.')
                tmpsum++;
        }
        if (tmpsum % 2 == 1)
        {
            cout << -1 << endl;
            return;
        }
        cntm[i] = tmpsum;
    }

    vector<int> swn(n);
    vector<int> sbn(n);
    vector<int> swm(m);
    vector<int> sbm(m);

    for (int i = 0; i < n; i++)
    {
        swn[i] = cntn[i] / 2;
        sbn[i] = cntn[i] / 2;
    }
    for (int i = 0; i < m; i++)
    {
        swm[i] = cntm[i] / 2;
        sbm[i] = cntm[i] / 2;
    }
    // for(int j = 0;j < m;i ++)
    // {
    //     int tmpsum = 0;
    //     for(int j = 0;j < m;j ++)
    //     {
    //         if(arr[i][j] != '.') tmpsum ++;
    //     }
    //     if(tmpsum %2 == 1) {
    //         cout << -1 << endl;
    //         return;
    //     }
    //     cnti[i] = tmpsum;
    // }
    // for(int i = 0;i < n;i ++)
    // {
    //     int tmpsum = 0;
    //     for(int j = 0;j < n;j ++)
    //     {
    //         if(arr[j][i] != '.') tmpsum ++;
    //     }
    //     if(tmpsum %2 == 1) {
    //         cout << -1 << endl;
    //         return;
    //     }
    //     cntj[i] = tmpsum;
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
                continue;
            else if ((arr[i][j] == 'W') || (arr[i][j] == 'B'))
                continue;
            else
            {
                if ((pwn[i] > 0) && (swm[j] > 0))
                {
                    switch (arr[i][j])
                    {
                    case 'L':
                    {
                        arr[i][j] = 'W';
                        swn[i]--;
                       // pwn[i]--;
                        swm[j]--;
                        arr[i][j + 1] = 'B';
                        sbn[i]--;
                        sbm[j + 1]--;
                        break;
                    };
                    case 'R':
                    {
                        arr[i][j] = 'W';
                        swn[i]--;
                       // pwn[i]--;
                        swm[j]--;
                        arr[i][j - 1] = 'B';
                        sbn[i]--;
                        sbm[j - 1]--;
                        break;
                    };
                    case 'U':
                    {
                        arr[i][j] = 'W';
                        swn[i]--;
                        pwn[i]--;
                        swm[j]--;
                        arr[i + 1][j] = 'B';
                        sbn[i + 1]--;
                        pbn[i+1]--;
                        sbm[j]--;
                        break;
                    };
                    case 'D':
                    {
                        arr[i][j] = 'W';
                        swn[i]--;
                        pwn[i]--;
                        swm[j]--;
                        arr[i - 1][j] = 'B';
                        sbn[i - 1]--;
                        pbn[i+1]--;
                        sbm[j]--;
                        break;
                    };
                    }
                }
                else if ((pbn[i] > 0) && (sbm[j] > 0))
                {
                    switch (arr[i][j])
                    {
                    case 'L':
                    {
                        arr[i][j] = 'B';
                        sbn[i]--;
                       // pbn[i]--;
                        sbm[j]--;
                        arr[i][j + 1] = 'W';
                        swn[i]--;
                        swm[j + 1]--;
                        break;
                    };
                    case 'R':
                    {
                        arr[i][j] = 'B';
                        sbn[i]--;
                       // pbn[i]--;
                        sbm[j]--;
                        arr[i][j - 1] = 'W';
                        swn[i]--;
                        swm[j - 1]--;
                        break;
                    };
                    case 'U':
                    {
                        arr[i][j] = 'B';
                        sbn[i]--;
                        pbn[i]--;
                        sbm[j]--;
                        arr[i + 1][j] = 'W';
                        swn[i + 1]--;
                        pwn[i+1]--;
                        swm[j]--;
                        break;
                    };
                    case 'D':
                    {
                        arr[i][j] = 'B';
                        sbn[i]--;
                        pbn[i]--;
                        sbm[j]--;
                        arr[i - 1][j] = 'W';
                        swn[i - 1]--;
                        pwn[i+1]--;
                        swm[j]--;
                        break;
                    };
                    }
                }
                else
                {
                    if ((arr[i][j] == 'L') || (arr[i][j] == 'R'))
                    {
                        if ((swm[j] > 0))
                        {
                            switch (arr[i][j])
                            {
                            case 'L':
                            {
                                arr[i][j] = 'W';
                                swn[i]--;
                                swm[j]--;
                                arr[i][j + 1] = 'B';
                                sbn[i]--;
                                sbm[j + 1]--;
                                break;
                            };
                            case 'R':
                            {
                                arr[i][j] = 'W';
                                swn[i]--;
                                swm[j]--;
                                arr[i][j - 1] = 'B';
                                sbn[i]--;
                                sbm[j - 1]--;
                                break;
                            };
                            case 'U':
                            {
                                arr[i][j] = 'W';
                                swn[i]--;
                                swm[j]--;
                                arr[i + 1][j] = 'B';
                                sbn[i + 1]--;
                                sbm[j]--;
                                break;
                            };
                            case 'D':
                            {
                                arr[i][j] = 'W';
                                swn[i]--;
                                swm[j]--;
                                arr[i - 1][j] = 'B';
                                sbn[i - 1]--;
                                sbm[j]--;
                                break;
                            };
                            }
                        }
                        else if ((sbm[j] > 0))
                        {
                            switch (arr[i][j])
                            {
                            case 'L':
                            {
                                arr[i][j] = 'B';
                                sbn[i]--;
                                sbm[j]--;
                                arr[i][j + 1] = 'W';
                                swn[i]--;
                                swm[j + 1]--;
                                break;
                            };
                            case 'R':
                            {
                                arr[i][j] = 'B';
                                sbn[i]--;
                                sbm[j]--;
                                arr[i][j - 1] = 'W';
                                swn[i]--;
                                swm[j - 1]--;
                                break;
                            };
                            case 'U':
                            {
                                arr[i][j] = 'B';
                                sbn[i]--;
                                sbm[j]--;
                                arr[i + 1][j] = 'W';
                                swn[i + 1]--;
                                swm[j]--;
                                break;
                            };
                            case 'D':
                            {
                                arr[i][j] = 'B';
                                sbn[i]--;
                                sbm[j]--;
                                arr[i - 1][j] = 'W';
                                swn[i - 1]--;
                                swm[j]--;
                                break;
                            };
                            }
                        } else {
                            cout << -1 << endl;
                            return;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j];
        cout << endl;
    }
}

#define _WITH_T_

int main()
{
    std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);
    int T = 1;

#ifdef _WITH_T_
#ifdef _USE_IOSTREAM_
    cin >> T;
#endif
#ifdef _USE_STDIO_
    scanf("%d", &T);
#endif
#endif

    // for(;;) test();
    for (int i = 0; i < T; i++)
        solve();

    // system("pause");

    return 0;
}