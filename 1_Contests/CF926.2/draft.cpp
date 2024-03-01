#include<iostream>
#include <map>
#include <vector>

using namespace std;

class tmp{
    public:int a = 0;
};

int main()
{
    vector<vector<int>> arr(2,vector<int>(2));
    vector<int> arr1(2,2);
    vector<tmp> arr2(2);
    for(auto x:arr) x.clear();
    system("pause");
    for(auto x:arr) for(auto y:x) y = 1134;
    system("pause");
    for(auto x:arr1) x = 1124;
    system("pause");
    for(auto x:arr2) x.a = 143245;
    system("pause");
}