#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define ll long long
#define mod1 998244353
#define maxn 1001000



#define ull unsigned long long
using namespace std;

struct person{
    ll int idx;
    ll int val;
};

bool comp(person a,person b)
{
    return a.val < b.val;
};

person A[maxn] = {0};

ll int subscearch(ll int t,ll int l,ll int r)
{
    if(l == r) return l;
    ll int mid = (l+r)/2;
    if(A[mid].val == t) return mid;
    if(A[mid].val > t) return subscearch(t,l,mid);
    if(A[mid].val < t) return subscearch(t,mid+1,r);
}

void test()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        int val;
        cin >> val;
        A[i].idx = i +1;
        A[i].val = val;
    }
    sort(A,A+n,comp);
    for(;;)
    {
        int t,l,r;
        cin >> t >> l >> r;
        cout << subscearch(t,l,r) << endl;
    }
}

void slove()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++) 
    {
        int val;
        cin >> val;
        A[i].idx = i +1;
        A[i].val = val; 
    }
    sort(A,A+n,comp);
    ll int nl = 0,nr = n-1;
    for(int i = 0;i < n-1;i ++)
    {
        if(nr - nl == 1) break;
        ll int mid = (A[nl].val + A[nr].val)/2;
        int midIdx = subscearch(mid,nl,nr);
        if(A[midIdx].val > mid) midIdx --;
        int divl = midIdx - nl;
        int divr = nr - midIdx;
        divl ++;
        if(divl >= divr) nr --;
        else nl ++;
    }
    cout << A[nl].idx << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
   // test();
    slove();
   // system("pause");
    return 0;
}