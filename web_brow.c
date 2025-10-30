#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* current = NULL;

struct Node* createNode(const char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void visit(const char* url) {
    struct Node* newPage = createNode(url);
    if (current == NULL) {
        head = newPage;
        current = newPage;
    } else {
        struct Node* temp = current->next;
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        current->next = newPage;
        newPage->prev = current;
        current = newPage;
    }
    printf("Visited: %s\n", current->url);
}

void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Back to: %s\n", current->url);
    } else {
        printf("No previous page.\n");
    }
}

void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Forward to: %s\n", current->url);
    } else {
        printf("No forward page.\n");
    }
}

void showCurrent() {
    if (current != NULL) {
        printf("Current page: %s\n", current->url);
    } else {
        printf("No page visited yet.\n");
    }
}

void clearHistory() {
    struct Node* temp = head;
    while (temp) {
        struct Node* toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    head = NULL;
    current = NULL;
}

int main() {
    int choice;
    char url[100];
    do {
        printf("\n--- Browser Navigation ---\n");
        printf("1. Visit New Page\n2. Back\n3. Forward\n4. Show Current Page\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = '\0';
                visit(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                showCurrent();
                break;
            case 5:
                clearHistory();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
