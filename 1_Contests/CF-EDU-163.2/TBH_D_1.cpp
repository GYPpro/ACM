#define _NRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[5005] = {};

int equal(char a, char b) {
    if (a == b || a == '?' || b == '?') return 1;
    else return 0;
}

int main(){
    int t, result = 0;
    scanf("%d", &t); getchar();
    for (int _ = 0; _ < t; _++) {
        gets(s);
        result = 0;
        int len = strlen(s);
        for (int i = len>>1; i > 0; i--) {
            int f = 0;
            for (int l = 0; l < len - i - i + 1; l++) {
                int flag = 1;
                int p = l;
                for (int j = l + i; j < l + i + i; j++) {
                    if (equal(s[p], s[j])) p++;
                    else {flag = 0; break;}
                }
                if (flag) {
                    result = i;
                    f = 1;
                    break;
                }
            }
            if (f) break; 
        }
        printf("%d\n", result * 2);
    }

    return 0;
}