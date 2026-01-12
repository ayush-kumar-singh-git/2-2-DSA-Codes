#include <stdio.h>
#include <stdlib.h>

char* toString(int n){
    char* res = (char*)calloc(1000, sizeof(char));
    int k=0;
    while(n>0){
        res[k++]=(n%10)+'0';
        n/=10;
    }
    res[k]='\0';
    for(int i=0;i<k/2;i++){
        char ch = res[i];
        res[i]=res[k-i-1];
        res[k-i-1]=ch;
    }
    return res;
}

int main()
{
    char in[1000];
    scanf("%s", in);
    char out[1000];
    int i=0, k=0;
    while(in[i]!='\0'){
        int j=i+1;
        while(in[j]!='\0' && in[j]==in[i]) j++;
        char* s = toString(j-i);
        out[k++] = in[i];
        int x = 0;
        while(s[x]!='\0'){
            out[k++]=s[x++];
        }
        free(s);
        i=j;
    }
    out[k]='\0';
    if(k<=i){
        printf("%s\n", out);
    }else{
        printf("%s\n", in);
    }
    return 0;
}
