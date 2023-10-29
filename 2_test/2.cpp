#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>

#define ll long long
#define N 100005
#define YES 1
#define NO 0
#define OK 1

using namespace std;

stack<char> dele;
vector<char> st;
stack<vector<ll>> note;

void append()
{
    string s;
    cin>>s;
    for(ll i=0;i<s.size();i++)
    {
        st.push_back(s[i]);
    }
    vector<ll> add;
    //记录操作编号和插入字符串的长度
    add.push_back(1);
    add.push_back(s.size());
    note.push(add);
    return ;
}

void Delete()
{
    ll k;
    cin>>k;
    vector<ll> del;
    //记录操作编号和删除的长度
    del.push_back(2);
    del.push_back(k);
    note.push(del);
    //执行删除操作，并将删除的部分记录在栈dele中
    for(ll i=0;i<k;i++)
    {
        dele.push(st.back());
        st.pop_back();
    }
    return;
}

void print()
{
    ll k;
    cin>>k;
    cout<<st[k-1]<<endl;
    return;
}

void undo()
{
    if(note.top()[0]==1)
    {
        for(ll i=0;i<note.top()[1];i++)
        {
            st.pop_back();
        }
    }
    else
    {
        for(ll i=0;i<note.top()[1];i++)
        {
            st.push_back(dele.top());
            dele.pop();
        }
    }
    note.pop();
    return;
}

void solve()
{
    ll q;
    cin>>q;
    while(q--)
    {
        ll t;
        cin>>t;
        switch(t)
        {
            case 1:append();break;
            case 2:Delete();break;
            case 3:print();break;
            case 4:undo();break;
        }
        for(int i = 0;i < st.size(); i ++) cout << st[i];
        cout << endl;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    ll t;
//     cin >> t;
    t = 1;
    while (t--)
        solve();
    // system("pause");
}