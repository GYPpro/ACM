
#include <iostream>

using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        
    int a;
    cin >> a;
    cout << ((a%3 != 0)?"First":"Second") << "\n";
    }

    // system("pause");

    return 0;
}