#include <stdio.h>
#include <stdlib.h>

typedef struct Student_t{
    int ID;
    char name[1000];
    float marks[3];
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
            scanf("%f", &students[i].marks[j] );
            tot += students[i].marks[j];
        }
        tot/=3;
        if(maxAv<tot){
            maxAv = tot;
        }
    }
    printf("Merit List:\n");
    for(int i=0;i<N;i++){
        float avg = 0;
        for(int j=0;j<3;j++){
            avg += students[i].marks[j];
        }
        avg /= 3;
        if(avg>=75){
            printf("%d %s\n", students[i].ID, students[i].name);
        }
    }
    printf("Topper: ");
    for(int i=0;i<N;i++){
        float avg = 0;
        for(int j=0;j<3;j++){
            avg += students[i].marks[j];
        }
        avg /= 3;
        if(avg==maxAv){
            printf("%s ", students[i].name);
        }
    }
    printf("\n");
    return 0;
}
