#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int MAXN = 100005;
bool vis[MAXN];
int stk[MAXN], top;
unsigned long sd;

bool check(const vector<vector<pair<int, int>>> &op)
{
    memset(stk, 0, sizeof(stk));
    top = 0;
    for (auto &it: op)
    {
        for (auto &p: it)
        {
            if (p.first == p.second || vis[p.first] || vis[p.second])
            {
                return false;
            }
            vis[p.first] = vis[p.second] = true;
            stk[++top] = p.first;
            stk[++top] = p.second;
        }
        while (top)
        {
            vis[stk[top--]] = false;
        }
    }
    return true;
}

bool check_ans(vector<int> &data)
{
    for (int i = 1; i < data.size(); ++i)
    {
        if (data[i - 1] > data[i])return false;
    }
    return true;
}

void Sort(vector<int> &data, const vector<vector<pair<int, int>>> &op)
{
    for (auto &it: op)
    {
        for (auto &p: it)
        {
            if (data[p.first] > data[p.second])
            {
                swap(data[p.first], data[p.second]);
            }
        }
    }
}

bool test_case_1(int n, const vector<vector<pair<int, int>>> &op)
{
    vector<int> data;
    for (int i = 1; i <= n; ++i)
    {
        data.push_back(n + 1 - i);
    }
    Sort(data, op);
    return check_ans(data);
}

bool test_case_2(int n, const vector<vector<pair<int, int>>> &op)
{
    vector<int> data;
    for (int i = 1; i <= n; ++i)
    {
        data.push_back(i);
    }
    swap(data[0], data[n - 1]);
    Sort(data, op);
    return check_ans(data);
}


bool test_case_3(int n, const vector<vector<pair<int, int>>> &op)
{
    rnd.setSeed(sd);
    vector<int> data;
    for (int i = 1; i <= n; ++i)
    {
        data.push_back(rnd.next(1000000000));
    }
    Sort(data, op);
    return check_ans(data);
}

bool test_case_4(int n,int k, const vector<vector<pair<int, int>>> &op)
{
    rnd.setSeed(sd);
    vector<int> data;
    for (int i = 1; i <= n; ++i)
    {
        data.push_back(i);
    }
    for(int i=1;i<=k;++i)
    {
        int u=rnd.next(data.size());
        int v=rnd.next(data.size());
        swap(data[u], data[v]);
    }
    Sort(data, op);
    return check_ans(data);
}

bool test_case_5(int n, const vector<vector<pair<int, int>>> &op)
{
    rnd.setSeed(sd);
    vector<int> data;
    int b=rnd.next(1000000000);
    for (int i = 1; i <= n; ++i)
    {
        data.push_back(b%n);
    }
    Sort(data, op);
    return check_ans(data);
}

bool test_case_permutation(int n, const vector<vector<pair<int, int>>> &op)
{
    if (n > 10)return true;
    vector<int> data;
    vector<int> temp;
    for (int i = 1; i <= n; ++i)
    {
        temp.push_back(i);
    }

    for (int i = 1; i <= 3000 && next_permutation(temp.begin(), temp.end()); ++i)
    {
        data = temp;
        Sort(data, op);
        if (!check_ans(data))
        {
            return false;
        }
    }
    temp.clear();
    for (int i = 1; i <= n; ++i)
    {
        temp.push_back(n - i + 1);
    }
    for (int i = 1; i <= 3000 && prev_permutation(temp.begin(), temp.end()); ++i)
    {
        data = temp;
        Sort(data, op);
        if (!check_ans(data))
        {
            return false;
        }
    }

    return true;
}


int main(int argc, char *argv[])
{

    registerTestlibCmd(argc, argv);
    vector<vector<pair<int, int>>> op;
    int n = inf.readInt();
    int m = ouf.readInt(0, 200, "m");
    sd=n*10000+114514;
    for (int i = 0; i < m; ++i)
    {
        int k = ouf.readInt(1, n / 2, "k");
        vector<pair<int, int>> temp;
        for (int j = 0; j < k; ++j)
        {
            int x = ouf.readInt(0, n - 1, "x");
            int y = ouf.readInt(0, n - 1, "y");
            if (x == y)
            {
                quitf(_wa, "same index in a pair");
            }
            temp.emplace_back(x, y);
        }
        op.push_back(temp);
    }
    if (!check(op))
    {
        quitf(_wa, "invalid input operator list");
    }
    if (!test_case_1(n, op))
    {
        quitf(_wa, "wa on test_case_1");
    }
    if (!test_case_2(n, op))
    {
        quitf(_wa, "wa on test_case_2");
    }
    if (!test_case_3(n, op))
    {
        quitf(_wa, "wa on test_case_3");
    }
    if (!test_case_4(n, 1, op))
    {
        quitf(_wa, "wa on test_case_4_1");
    }
    if (!test_case_4(n, 5, op))
    {
        quitf(_wa, "wa on test_case_4_5");
    }
    if (!test_case_4(n, 10, op))
    {
        quitf(_wa, "wa on test_case_4_10");
    }
    if (!test_case_4(n, 50, op))
    {
        quitf(_wa, "wa on test_case_4_50");
    }
    if (!test_case_4(n, 100, op))
    {
        quitf(_wa, "wa on test_case_4_100");
    }
    if (!test_case_4(n, 1000, op))
    {
        quitf(_wa, "wa on test_case_4_1000");
    }
    if (!test_case_4(n, 10000, op))
    {
        quitf(_wa, "wa on test_case_4_10000");
    }
    if (!test_case_5(n, op))
    {
        quitf(_wa, "wa on test_case_5");
    }
    if (!test_case_permutation(n, op))
    {
        quitf(_wa, "wa on test_case_permutation");
    }
    quitf(_ok, "all ok!");
    return 0;
}