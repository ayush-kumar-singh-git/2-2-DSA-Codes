#include <stdio.h>
#include <stdlib.h>

void swap(char* c1, char* c2){
    char c = *c1;
    *c1 = *c2;
    *c2 = c;
    return;
}

char* toString(int n){
    char* s = (char*) calloc(100, sizeof(char));
    int k = 0;
    while(n>0){
        s[k]=((n%10)+'0');
        k++;
        n/=10;
    }
    s[k]='\0'; // donot forget to null terminate the string
    for(int i=0;i<k/2;i++){
        swap(&s[i], &s[k-i-1]);
    }
    return s;
}

int main()
{
    char inp[1000];
    scanf("%s", inp);
    int len = 0;
    int i=0;
    char out[1000];
    int k =0;
    while(inp[i]!='\0'){
        out[k]=inp[i];
        k++;
        int j= i+1;
        while(inp[j]!='\0' && inp[j]==inp[i]) j++;
        char* c = toString(j-i);
        int x = 0;
        while(c[x]!='\0'){
            out[k]=c[x];
            x++;
            k++;
        }
        i=j;
        len = i+1;
    }
    out[k]='\0';
    if(k<=len){
        printf("%s\n",out);
    }else{
        printf("%s\n",inp);
    }
    return 0;
}
