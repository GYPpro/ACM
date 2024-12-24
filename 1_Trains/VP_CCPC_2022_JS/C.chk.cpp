#include <bits/stdc++.h>
using namespace std;

const string QUES_NAME = "C";

int system(string s) {
    return system(s.c_str());
}

using namespace std;
int main()
{
    cout << "compiling...\n";
    system("g++ " + QUES_NAME + ".ptc.cpp -o " + QUES_NAME + ".ptc.exe -std=c++2a -DFC");
    system("g++ " + QUES_NAME + ".std.cpp -o " + QUES_NAME + ".std.exe -std=c++2a -DFC");
    system("g++ " + QUES_NAME + ".gnc.cpp -o " + QUES_NAME + ".gnc.exe -std=c++2a -DFC");
    cout << "compile complete\n";
    int t = 1;
    while(++t){
        system(".\\" + QUES_NAME + ".gnc.exe");
        system(".\\" + QUES_NAME + ".ptc.exe");
        system(".\\" + QUES_NAME + ".std.exe");
        system("cls");
        if (system("fc " + QUES_NAME + ".A.std " + QUES_NAME + ".A.ptc")) {
            cout << "WA\n";
            system("pause");
            return 0;
        } else cout << "AC at test:" << t-1 << "\n";
    }
}

