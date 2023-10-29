#include <iostream>
main()
{
    int a,b;
    std::cin>>a >> b;
    std::cout << (a*6+b*21+16)%24;
}