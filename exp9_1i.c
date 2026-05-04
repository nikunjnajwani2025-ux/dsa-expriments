#include <stdio.h>

#define MAX 100

int tree[MAX];

// Initialize tree
void init() {
    for (int i = 0; i < MAX; i++)
        tree[i] = -1;
}

// Insert root
void insertRoot(int data) {
    if (tree[0] == -1)
        tree[0] = data;
    else
        printf("Root already exists\n");
}

// Insert left
void insertLeft(int parent, int data) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (tree[i] == parent) {
            if (tree[2*i + 1] == -1) {
                tree[2*i + 1] = data;
            } else {
                printf("Left child already exists\n");
            }
            return;
        }
    }
    printf("Parent not found\n");
}

// Insert right
void insertRight(int parent, int data) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (tree[i] == parent) {
            if (tree[2*i + 2] == -1) {
                tree[2*i + 2] = data;
            } else {
                printf("Right child already exists\n");
            }
            return;
        }
    }
    printf("Parent not found\n");
}

// Display tree
void display() {
    printf("Tree elements:\n");
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != -1)
            printf("%d ", tree[i]);
    }
    printf("\n");
}

// Main
int main() {
    init();

    insertRoot(1);
    insertLeft(1, 2);
    insertRight(1, 3);
    insertLeft(2, 4);
    insertRight(2, 5);

    display();

    return 0;
}
