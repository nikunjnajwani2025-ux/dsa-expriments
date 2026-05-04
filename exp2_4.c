#include <stdio.h>
#include <string.h>

struct employee {
    char name[30];
    char address[100];
    int salary;    
};

int main() {
    struct employee e[5], temp;
    int i, j;

    printf("Enter details of 5 employee:\n");

    for(i = 0; i < 5; i=i+1) {
        printf("\nEmployee %d\n", i+1);

        printf("Name : ");
        scanf(" %[^\n]", e[i].name);

        printf("Address : ");
        scanf(" %[^\n]", e[i].address);

        printf("Salary : ");
        scanf("%d", &e[i].salary);   
        
    }
    for(i = 0; i < 4; i=i+1) {
        for(j = i+1; j < 5; j=j+1) {
            if(strcmp(e[i].name, e[j].name) > 0) {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    printf("\nEmployees in Alphabetical Order\n");
    for(i = 0; i < 5; i=i+1) {
        printf("%s  %s  %d\n",
               e[i].name,
               e[i].address,
               e[i].salary);
    }

    return 0;
}
