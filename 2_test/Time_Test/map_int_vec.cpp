#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("D:\\Desktop\\Document\\Coding\\C++\\ACM\\2_test\\Time_Test\\in.md","r",stdin);
    map<int,int> emp;
    int pv = 0;
    vector<vector<int>> cnt;
    for(int i = 0;i < 1e6;i ++)
    {
        int tmp;
        cin >> tmp;
        if(emp.find(tmp) != emp.end()) cnt[emp[tmp]].push_back(i);
        else {
            emp[tmp] = pv;
            cnt.push_back(vector<int>());
            cnt[emp[tmp]].push_back(i);
        }
    }
}