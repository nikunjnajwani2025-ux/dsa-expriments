#include <stdio.h>

struct employee {
    char name[50];
    char address[100];
    int age;
    float salary;
};

int main() {
    int n, i;
    float s=0, avg;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct employee e[n];

    
    for(i = 0; i < n; i=i+1) {
        printf("\nEmployee %d\n", i+1);

        printf("Name: ");
        scanf(" %[^\n]", e[i].name);

        printf("Address: ");
        scanf(" %[^\n]", e[i].address);

        printf("Age: ");
        scanf("%d", &e[i].age);

        printf("Salary: ");
        scanf("%f", &e[i].salary);

        s=s+e[i].salary;
    }

    
    avg=s/n;

  
    printf("\nAverage Salary = %.2f\n", avg);

    return 0;
}
