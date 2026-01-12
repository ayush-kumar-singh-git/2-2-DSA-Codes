#include <stdio.h>
#include <stdlib.h>

int isVowel(char ch){
    if(ch>='A' && ch <= 'Z'){
        ch = (ch - 'A' + 'a');
    }
    return ((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'));
}

int main()
{
    char line[1000];
    scanf("%[^\n]%*c", line);
    int len = 0;
    int vowels = 0;
    int words =1;
    while(line[len]!='\0'){
        char ch = line[len];
        if(ch==' '){
            words++;
        }
        else if(isVowel(ch)){
            vowels++;
        }
        len++;
    }
    for(int i=0;i<len/2;i++){
        char ch = line[i];
        line[i]=line[len-i-1];
        line[len-i-1] = ch;
    }
    printf("Words: %d\n", words);
    printf("Vowels: %d\n", vowels);
    printf("Reversed: %s\n", line);
    return 0;
}
