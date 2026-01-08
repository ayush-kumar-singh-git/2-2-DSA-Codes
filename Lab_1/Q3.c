#include <stdio.h>
#include <stdlib.h>

int isVowel(char ch){
    if(ch>='A' && ch <= 'Z'){
        ch = ch - 32;
    }
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

void swap(char* c1, char* c2){
    char c = *c1;
    *c1 = *c2;
    *c2 = c;
    return;
}

int main()
{
    char str[1000];
    scanf("%[^\n]%*c", str);
    int vowels = 0, words = 1;
    int len = 0;
    char ch;
    while(1){
        ch = str[len];
        if(ch=='\0') break;
        len++;
        if(ch==' '){
            words++;
            continue;
        }
        if(isVowel(ch)){
            vowels++;
        }
    }
    for(int i=0;i<len/2;i++){
        swap(&str[i], &str[len-i-1]);
    }
    printf("Words: %d\nVowels: %d\nReversed: %s", words,vowels,str);
    return 0;
}
