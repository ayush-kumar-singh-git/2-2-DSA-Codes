#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int intTop = -1;
int strTop = -1;

int main()
{
    int n;
    scanf("%d", &n);

    char in[MAX];
    scanf("%s", in);

    int length = strlen(in);

    char charStk[MAX][MAX];
    int intStk[MAX];

    char curr[MAX];
    char temp[MAX];
    char prev[MAX];

    curr[0] = '\0';

    int total = 0;

    for(int i = 0; i < length; i++)
    {
        char c = in[i];

        if(c >= '0' && c <= '9')
        {
            total = total * 10 + (c - '0');
        }

        else if(c == '[')
        {
            intStk[++intTop] = total;
            strcpy(charStk[++strTop], curr);
            total = 0;
            curr[0] = '\0';
        }

        else if(c == ']')
        {
            int repeat = intStk[intTop--];

            strcpy(temp, curr);
            strcpy(prev, charStk[strTop--]);

            strcpy(curr, prev);

            for(int j = 0; j < repeat; j++)
            {
                strcat(curr, temp);
            }
        }

        else
        {
            int len = strlen(curr);
            curr[len] = c;
            curr[len+1] = '\0';
        }
    }

    printf("%s\n", curr);
    return 0;
}
