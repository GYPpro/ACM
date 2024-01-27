#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("D:\\Desktop\\Document\\Coding\\C++\\ACM\\2_test\\Time_Test\\in.md","r",stdin);
    map<int,vector<int>> cnt;
    for(int i = 0;i < 1e6;i ++)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp].push_back(i);
    }
}