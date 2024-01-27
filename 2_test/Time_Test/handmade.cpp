#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    freopen("D:\\Desktop\\Document\\Coding\\C++\\ACM\\2_test\\Time_Test\\in.md","r",stdin);
    vector<pair<int,int>> arr;
    for(int i = 0;i < 1e6;i ++) {
        int tmp;
        cin >> tmp;
        arr.push_back(pair<int,int>(tmp,i));
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>> cnt;
    int pv = arr[0].first;
    vector<int> emp;
    emp.push_back(arr[0].second);
    for(int i = 1;i < arr.size();i ++)
    {
        if(arr[i].first != pv){
            cnt.push_back(emp);
            emp.clear();
            pv = arr[i].first;
            emp.push_back(arr[i].second);
        }
    }
}