#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
    for(int ii = 0;ii < 1000;ii ++)
    {
        ll int n = 8*ii+6 ;
        int anskey = 3;
        for(ll int i = 0;i < n*n*n;i ++)
        {
            ll tmp = i*i;
            ll tmpdiv = abs(n-i*i);
            ll tmpsqrt = (ll)sqrt(tmpdiv);
            if(tmp == n){
                anskey = 1;
                break;
            } else if(tmpsqrt*tmpsqrt == (n-i*i))
            {
                anskey = 2;
                if(n == 42){
                     cout <<"42-" <<  i << endl;}
                break;
            }
        }
        if(anskey == 2)
            cout << n << endl;
        if(ii % 100 == 0)
            cout <<"- "<< ii << endl;
    }
    system("pause");
    return 0;
}