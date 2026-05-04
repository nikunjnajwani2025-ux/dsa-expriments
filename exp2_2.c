#include <stdio.h>

struct student {
    int roll_no;
    char fname[30];
    char lname[30];
};

int main() {
    struct student s[5], temp;
    int i, j;

   
    printf("Enter details of 5 students:\n");
    for(i = 0; i < 5; i=i+1) {
        printf("\nStudent %d\n", i+1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll_no);

        printf("First Name: ");
        scanf("%s", s[i].fname);

        printf("Last Name: ");
        scanf("%s", s[i].lname);
    }

  
    for(i = 0; i < 4; i=i+1) {
        for(j = i + 1; j < 5; j=j+1) {
            if(s[i].roll_no > s[j].roll_no) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("\nStudents in Ascending Roll No Order\n");
    for(i = 0; i < 5; i=i+1) {
        printf("%d  %s %s\n",
               s[i].roll_no,
               s[i].fname,
               s[i].lname);
    }

    return 0;
}
