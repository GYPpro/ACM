#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#define ll long long
#define maxn 100100
const ll int mod = (ll int)(1e9 + 7);

using namespace std;

struct plate //记录每个商品目前的状态
{
    ll int a;
    ll int b;
    bool used;//是否被使用
};

struct queA //优先队列
{
    ll int val; //a的值
    ll int idx; //对应在主数组s的位置
};

bool compshop(plate a, plate b)
{
    if (a.b == b.b)
        return a.a > b.a;
    return a.b > b.b;
}

bool compque(queA a, queA b)
{
    return a.val > b.val;
}

void solve()
{
    int n;
    cin >> n;
    vector<plate> s;
    for (int i = 0; i < n; i++)
    {
        ll int tmpa, tmpb;
        cin >> tmpa >> tmpb;
        plate tmps;
        tmps.used = false;
        tmps.a = tmpa;
        tmps.b = tmpb;
        s.push_back(tmps);
    }
    vector<queA> qa; //A的处理队列
    sort(s.begin(), s.end(), compshop); //优先b次优先a降序排列主数组s

    // for (int i = 0; i < s.size(); i++)
    //     cout << "i:" << i << " a:" << s[i].a << " b:" << s[i].b << " used:" << s[i].used << endl;

    //完成qa初始化并排序
    for (int i = 0; i < n; i++)
    {
        queA tmpq;
        tmpq.val = s[i].a;
        tmpq.idx = i;
        qa.push_back(tmpq);
    }
    sort(qa.begin(), qa.end(), compque);

    //计算选取全部k个时的答案
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += s[i].a;
    ans += s[0].b;

    //记录答案列表并插入一个答案
    vector<ll int> anslis;
    anslis.push_back(ans);


    int tarb = 0,  //以b排序的列表s目前的焦点
        tarmb = 1, //列表中下一个可用b的位置
        tarma = 0; //以a排序的列表qa中目前的焦点

    for (; anslis.size() < n;)
    {//由于s中b降序，从k=n -> k = n-1转移时，只需使用tarb tarmb计算出收益c1，与移除qa中最大a的收益，即a，比较。
        ll int c1 = s[tarb].a + s[tarb].b - s[tarmb].b;
        //计算c1
        if (c1 >= qa[tarma].val)
        {
            ans -= c1; //计算ans

            //若此时已将所有答案计算出来，插入走人
            if (anslis.size() == n - 1)
            {
                anslis.push_back(ans);
                break;
            }

            //记录此节点已被删除
            s[tarb].used = 1;

            for (;;)
            { //先将焦点后移，若后面第一个用过，继续移，直到找到能用的
                tarb++;
                if (s[tarb].used)
                    continue;
                else
                    break;
            }

            for (;;)
            { //此处出错，即若tarb tarmb所在和他们后面2个以上都是用过的，此循环会得出与上一循环相同的解  修改后：tarb与tarmb相同时循环不会结束，会继续找下一个可用的b
                tarmb++;
                if (s[tarmb].used)
                    continue;
                else
                    if(tarmb != tarb) break;
            }

            for (;;)
            { //如果这次刚好选到了最大a，那么要把a的焦点往后移
                if (s[qa[tarma].idx].used)
                    tarma++;
                else
                    break;
            }
            // cout << "after drop: tara:" << tara << " tarb:" << tarb << " tarmb" << tarmb << " tarma:" << tarma << endl;
        }
        else
        {
            ans -= qa[tarma].val;
            // cout << "ues ak = " << qa[tarma].val << " with ans = " << ans << endl;
            // cout << "before drop: tara:" << tara << " tarb:" << tarb << " tarmb" << tarmb << " tarma:" << tarma << endl;
            if (anslis.size() == n - 1)
            {
                anslis.push_back(ans);
                break;
            }
            s[qa[tarma].idx].used = true;
            for (;;)
            {
                if (s[tarmb].used)
                    tarmb++;
                else
                    break;
            }
            for (;;)
            {
                tarma++;
                if (s[qa[tarma].idx].used)
                    continue;
                else
                    break;
            }
            // cout << "after drop: tara:" << tara << " tarb:" << tarb << " tarmb" << tarmb << " tarma:" << tarma << endl;
        }
        anslis.push_back(ans);
    }
    for (int i = anslis.size() - 1; i >= 0; i--)
        cout << anslis[i] << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;

    cin >> t;

    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
