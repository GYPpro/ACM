#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
    freopen("t.txt","w",stdout);
    cout << "1\n";
    // string oct = "aa";
    string oct;
    // int f = 1;
    // char c = 'a';
    string sed = "defghijklmnpoqrstuvw";
    char c = 'a';
    

    for(;oct.size() <= 3320;) oct+="a";
    for(;oct.size() < 4999;)
    {
        if(c > 'z'){
            c = 'a';
            // f ++;
        }
        // // for(int i = 0;i < f;i ++) 
        //     oct.push_back(c);
        // c += f;
        oct.push_back(c);
        oct += sed;
        sed = sed + c + sed;
        c ++;
    }
    for(int i = 0;i < 4999;i ++) cout << oct[i];
    // cout << "aa";
}