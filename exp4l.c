#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// a) Insert at beginning
void insertBegin(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// b) Insert at end
void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// c) Insert at position
void insertPos(int data, int pos) {
    if (pos == 1) {
        insertBegin(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// d) Delete from beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// e) Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// f) Delete from position
void deletePos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deleteBegin();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

// g) Search element
void search(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found\n");
}

// h) Reverse list
void reverse() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// i) Merge two lists
struct Node* merge(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = list2;
    return list1;
}

// j) Display
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// k) Detect loop (Floyd’s Cycle Detection)
void detectLoop() {
    struct Node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop detected\n");
            return;
        }
    }
    printf("No loop detected\n");
}

// Main menu
int main() {
    int choice, data, pos;
    struct Node* list2 = NULL;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1.Insert Begin\n2.Insert End\n3.Insert Position\n");
        printf("4.Delete Begin\n5.Delete End\n6.Delete Position\n");
        printf("7.Search\n8.Reverse\n9.Merge (with new list)\n");
        printf("10.Display\n11.Detect Loop\n12.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBegin(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d%d", &data, &pos);
                insertPos(data, pos);
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;

            case 8:
                reverse();
                break;

            case 9: {
                printf("Enter number of elements in second list: ");
                int n, val;
                scanf("%d", &n);

                for (int i = 0; i < n; i++) {
                    printf("Enter data: ");
                    scanf("%d", &val);
                    struct Node* newNode = createNode(val);
                    if (list2 == NULL)
                        list2 = newNode;
                    else {
                        struct Node* temp = list2;
                        while (temp->next != NULL)
                            temp = temp->next;
                        temp->next = newNode;
                    }
                }
                head = merge(head, list2);
                break;
            }

            case 10:
                display();
                break;

            case 11:
                detectLoop();
                break;

            case 12:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
