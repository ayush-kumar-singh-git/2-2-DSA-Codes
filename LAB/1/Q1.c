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
    float max=-1;
    int top;
    int arr[1000];
    int k=0;
    for(int i=0;i<N;i++){
        Student s;
        scanf("%d",& s.ID);
        scanf("%s", s.name);
        float total = 0;
        for(int j=0;j<3;j++){
            scanf("%f", &s.marks[j]);
            total += s.marks[j];
        }
        total = total/3;
        students[i]=s;
        if(total>75){
            arr[k]=i;
            k++;
        }
        if(total>max){
            max = total;
            top = i;
        }
    }
    printf("Merit List:\n");
    for(int i=0;i<k;i++){
        printf("%d %s\n", students[arr[i]].ID, students[arr[i]].name);
    }
    printf("Topper: %s\n", students[top].name);
    return 0;
}
