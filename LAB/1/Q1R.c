#include <stdio.h>
#include <stdlib.h>

typedef struct Student_t{
    int ID;
    char name[1000];
    float avg;
}Student;

int main()
{
    int N;
    scanf("%d", &N);
    Student students[N];
    float maxAv = 0;
    for(int i=0;i<N;i++){
        scanf("%d", &students[i].ID);
        scanf("%s", students[i].name);
        float tot = 0;
        for(int j=0;j<3;j++){
            float temp;
            scanf("%f", &temp );
            tot += temp;
        }
        tot/=3;
        students[i].avg=tot;
        if(maxAv<tot){
            maxAv = tot;
        }
    }
    printf("Merit List:\n");
    for(int i=0;i<N;i++){
        if(students[i].avg>=75){
            printf("%d %s\n", students[i].ID, students[i].name);
        }
    }
    printf("Topper: ");
    for(int i=0;i<N;i++){
        if(students[i].avg==maxAv){
            printf("%s ", students[i].name);
        }
    }
    printf("\n");
    return 0;
}
