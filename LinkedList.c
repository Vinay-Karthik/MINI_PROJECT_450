#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtFirst(struct Node** head, int data);
void insertAtLast(struct Node** head, int data);
void insertAtRandom(struct Node** head, int data, int position);
void deleteAtFirst(struct Node** head);
void deleteAtLast(struct Node** head);
void deleteAtRandom(struct Node** head, int position);
void searchElement(struct Node* head, int key);
void updateElementAtIndex(struct Node* head, int index, int newData);
int getSize(struct Node* head);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position, index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Insert at random position\n");
        printf("4. Delete at first\n");
        printf("5. Delete at last\n");
        printf("6. Delete at random position\n");
        printf("7. Search for an element\n");
        printf("8. Update element at index\n");
        printf("9. Get size of the list\n");
        printf("10. Display list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                insertAtFirst(&head, data);
                break;
            case 2:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtRandom(&head, data, position);
                break;
            case 4:
                deleteAtFirst(&head);
                break;
            case 5:
                deleteAtLast(&head);
                break;
            case 6:
                printf("Enter position to delete at: ");
                scanf("%d", &position);
                deleteAtRandom(&head, position);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElement(head, data);
                break;
            case 8:
                printf("Enter index to update: ");
                scanf("%d", &index);
                printf("Enter new data: ");
                scanf("%d", &data);
                updateElementAtIndex(head, index, data);
                break;
            case 9:
                printf("Size of the list: %d\n", getSize(head));
                break;
            case 10:
                displayList(head);
                break;
            case 11:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to insert node at the beginning of the list
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert node at the end of the list
void insertAtLast(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert node at a given position
void insertAtRandom(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete node at the beginning of the list
void deleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Function to delete node at the end of the list
void deleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if ((*head)->next == NULL) {
        printf("Deleted element: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Function to delete node at a given position
void deleteAtRandom(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 0) {
        *head = (*head)->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    printf("Deleted element: %d\n", nodeToDelete->data);
    free(nodeToDelete);
}

// Function to search for an element in the list
void searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at index %d.\n", key, index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("Element %d not found in the list.\n", key);
}

// Function to update element at a given index
void updateElementAtIndex(struct Node* head, int index, int newData) {
    struct Node* temp = head;
    int count = 0;
    
    while (temp != NULL) {
        if (count == index) {
            temp->data = newData;
            printf("Element at index %d updated to %d.\n", index, newData);
            return;
        }
        temp = temp->next;
        count++;
    }

    printf("Index out of bounds!\n");
}

// Function to return the size of the list
int getSize(struct Node* head) {
    struct Node* temp = head;
    int size = 0;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
