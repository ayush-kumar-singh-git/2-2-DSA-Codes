#include <stdio.h>

int digitsCount(int n){
    if(n==0) return 1;
    int count = 0;
    while(n>0){
        count++;
        n/=10;
    }
    return count;
}

int IntegerMultiplication(int a, int b){
    int n = digitsCount(a);
    if(n == 1){
        return a*b;
    }
    int exp = 1;
    for(int i = 0; i<n/2; i++){
        exp *= 10;
    }
    int A1 = a/exp;
    int A2 = a%exp;
    int B1 = b/exp;
    int B2 = b%exp;
    int alpha = IntegerMultiplication(A1, B1);
    int beta = IntegerMultiplication(A2, B2);
    int gamma = IntegerMultiplication(A1+A2, B1+B2);
    int ans = alpha * exp * exp + (gamma - alpha - beta) * exp + beta;
    return ans;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", IntegerMultiplication(a,b));
    return 0;
}