#include <bits/stdc++.h>
using namespace std;
const int N = 50005;

int n, top;
int s[N], ans[N];
struct node
{
    int x, y, id;
}; 

int rd() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') 
    	{if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9')
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}

bool cmp(node a, node b)
{
    if (a.x != b.x) //第一关键字为斜率
    {
        return a.x > b.x;
    }
    else //第二关键字为截距
        return a.y > b.y;
}

using ld = long double;
using pis = array<int,3>;
pis p[N];

bool comp(pis a,pis b) {
    if(a[0] == b[0]) return a[1] > b[1];
    else return a[0] > b[0];
};

ld getCovex(pis a,pis b) {
    return (1.0L * (a[1] -b[1]) / (b[0] - a[0]));
};

double jiaodot(int a, int b) //计算交点
{
    return getCovex(p[a],p[b]);
    // return ((1.0 * (p[a][1] - p[b][1])) / (p[b][0] - p[a][0]));
}

int main()
{
    // n=rd();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // p[i].x=rd();
        // p[i].y=rd();
        cin >> p[i][0] >> p[i][1];
        p[i][2] = i + 1;
    }
    using pis = array<int,3>;
    vector<int> st;
    vector<int> ans;
    sort(p, p + n, comp);
    for (int i = 0; i < n; i++)
    {
        if (p[i][0] == p[i - 1][0] && i > 0)
            continue;
        while (st.size() > 1 && jiaodot(st[st.size()-1], i) >= jiaodot(st[st.size()-1], st[st.size()-2]))
            // top--;
            st.pop_back(),ans.pop_back();
        // s[++top] = i;//当前直线入栈。
        st.push_back(i);
        ans.push_back(p[i][2]); //记录答案。
    }
    // sort(ans, ans + top);//将ans从小到大排一下序
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}