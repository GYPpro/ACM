#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    freopen("D:\\Desktop\\Document\\Coding\\C++\\ACM\\2_test\\Time_Test\\in.md","w",stdout);
    srand(114514);
    for(int i = 0;i <= 5e5;i ++) cout << rand()%100 << "\n";
    for(int i = 0;i < 5e5;i ++) cout << rand() << "\n";
    return 0;
}