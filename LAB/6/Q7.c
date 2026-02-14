// I have to implement this on my own first :(
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void repeat(char *to, char *from, int n) {
    char temp[MAX] = "";
    for (int i = 0; i < n; i++) {
        strcat(temp, from);
    }
    strcpy(to, temp);
}

void decodeString(char* s) {
    int numStack[MAX];
    char strStack[MAX][MAX];

    int numTop = -1;
    int strTop = -1;

    int curNum = 0;
    char curString[MAX] = "";

    for (int i = 0; s[i] != '\0'; i++) {

        if (isdigit(s[i])) {
            curNum = curNum * 10 + (s[i] - '0');
        }

        else if (s[i] == '[') {
            // push current string
            strcpy(strStack[++strTop], curString);

            // push number
            numStack[++numTop] = curNum;

            // reset
            curNum = 0;
            curString[0] = '\0';
        }

        else if (s[i] == ']') {
            int num = numStack[numTop--];

            char prevString[MAX];
            strcpy(prevString, strStack[strTop--]);

            char repeated[MAX];
            repeat(repeated, curString, num);

            strcpy(curString, prevString);
            strcat(curString, repeated);
        }

        else {
            int len = strlen(curString);
            curString[len] = s[i];
            curString[len+1] = '\0';
        }
    }
    printf("%s\n", curString);
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    decodeString(s);
    return 0;
}

