/*
 * Logic : Take input in a struct, define custom comparator, bubble sort
 * TC O(n^2)
 * SC O(1) other than the input list
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct Student_t{
    int marks;
    int delay;
}Student;

int cmp(Student s1, Student s2){
    // return 1 if s1 must come before s2
    if(s1.marks>s2.marks) return 1;
    if(s1.marks == s2.marks && s1.delay<s2.delay) return 1;
    return 0;
}

void sort(Student* s, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(cmp(s[j+1],s[j])){
                Student temp = s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    Student* list = (Student*)calloc(n, sizeof(Student));
    for(int i=0;i<n;i++){
        scanf("%d %d", &list[i].marks, &list[i].delay);
    }
    sort(list, n);
    for(int i=0;i<n;i++){
        printf("%d %d\n", list[i].marks, list[i].delay);
    }
    free(list);
    return 0;
}
