#include <bits/stdc++.h>
using namespace std;
const string QUES_NAME = "C";

int system(string s) {
    return system(s.c_str());
}

using namespace std;
int main()
{
    system("g++ " + QUES_NAME + ".ptc.cpp -o " + QUES_NAME + ".ptc.exe -DFC -std=c++2a");
    system("g++ " + QUES_NAME + ".std.cpp -o " + QUES_NAME + ".std.exe -DFC -std=c++2a");
    system("g++ " + QUES_NAME + ".gnc.cpp -o " + QUES_NAME + ".gnc.exe -DFC -std=c++2a");
    cout << "compile complete\n";
    while(1){
        system(".\\" + QUES_NAME + ".gnc.exe");
        system(".\\" + QUES_NAME + ".ptc.exe");
        system(".\\" + QUES_NAME + ".std.exe");
        if (system("fc " + QUES_NAME + ".A.std " + QUES_NAME + ".A.ptc")) {
            cout << "WA\n";
            system("pause");
            return 0;
        } else cout << "AC\n";
    }
}