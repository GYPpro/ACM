#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int sqr(int x) { return x*x; }
const int MAXN=100005;
int h[MAXN],p[MAXN];
ll solve(int n,int ptr)
{
    ll ans=0,now=0;
    set<int> st;
    st.insert(0);
    st.insert(n+1);
    for(int i=ptr,j=0;j<n;i=(i+1)%n,j++)
    {
        int idx=p[i];
        cout << "insert:"<< " " << h[idx] << "\n";
        auto itr=st.lower_bound(idx);
        int nxt=*itr,pre=*--itr;
        if(pre>=1 && nxt<=n)
            now-=sqr(h[pre]-h[nxt]);
        if(pre>=1)
            now+=sqr(h[pre]-h[idx]);
        if(nxt<=n)
            now+=sqr(h[idx]-h[nxt]);
        st.insert(idx);
        ans+=now;
        cout << "now:" << now << "\n";
    }
    return ans;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    int ptr=0;
    ll lastans=solve(n,ptr);
    printf("%lld\n",lastans);
    while(q--)
    {
        cout << "----------\n";
        int k;
        scanf("%d",&k);
        ptr=(ptr+k+lastans)%n;
        lastans=solve(n,ptr);
        printf("%lld\n",lastans);
    }
    return 0;
}
