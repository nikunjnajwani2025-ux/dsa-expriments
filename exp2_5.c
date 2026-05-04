#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

struct employee {
    char name[50];
    int id;
    float salary;
    struct date dob;  
};

int main() {
    struct employee e;

    printf("Enter employee name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Date of Birth (day month year): ");
    scanf("%d %d %d", &e.dob.day, &e.dob.month, &e.dob.year);

    printf("Enter salary: ");
    scanf("%f", &e.salary);

   
    printf("\nEmployee Details\n");
    printf("Name   : %s\n", e.name);
    printf("ID     : %d\n", e.id);
    printf("DOB    : %02d-%02d-%04d\n",
           e.dob.day, e.dob.month, e.dob.year);
    printf("Salary : %.2f\n", e.salary);

    return 0;
}
