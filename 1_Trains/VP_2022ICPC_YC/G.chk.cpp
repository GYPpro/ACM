#include <bits/stdc++.h>

const string QUES_NAME = "G";

int system(string s) {
    return system(s.c_str());
}

using namespace std;
int main()
{
    while(1){
        system("g++ " + QUES_NAME + ".ptc.cpp -o " + QUES_NAME + ".ptc.exe -std=c++2a -FC");
        system("g++ " + QUES_NAME + ".std.cpp -o " + QUES_NAME + ".std.exe -std=c++2a -FC");
        system("g++ " + QUES_NAME + ".gnc.cpp -o " + QUES_NAME + ".gnc.exe -std=c++2a -FC");
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