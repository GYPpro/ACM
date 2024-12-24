#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    srand(114514);while(1){
    a = rand()%10+1,b = rand()%10+1,c = rand()%10+1;
        // if(((a%b) % (c%b)) == ((a%c)%b)) cout << "AC\n";
        if(a%b%c == a%c%b) cout << "AC\n";
        else {
            cout << "WA at" << a << " " << b << " " << c << "\n";
            system("pause");
        }
    }
}