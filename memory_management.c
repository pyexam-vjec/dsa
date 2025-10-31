#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Block {
    int id;
    bool allocated;
    struct Block* prev;
    struct Block* next;
} Block;

Block* head = NULL;
int blockCounter = 0;

Block* createBlock(bool allocated) {
    Block* newBlock = (Block*)malloc(sizeof(Block));
    newBlock->id = ++blockCounter;
    newBlock->allocated = allocated;
    newBlock->prev = NULL;
    newBlock->next = NULL;
    return newBlock;
}

void allocateMemory() {
    Block* newBlock = createBlock(true);
    if (head == NULL) {
        head = newBlock;
    } else {
        Block* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newBlock;
        newBlock->prev = temp;
    }
    printf("Memory Block %d allocated.\n", newBlock->id);
}

void deallocateMemory(int id) {
    Block* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            temp->allocated = false;
            printf("Memory Block %d marked as unused.\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("Block %d not found.\n", id);
}

void garbageCollector() {
    Block* temp = head;
    while (temp != NULL) {
        Block* next = temp->next;
        if (!temp->allocated) {
            printf("Garbage Collector: Cleaning Block %d\n", temp->id);
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                head = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            free(temp);
        }
        temp = next;
    }
}

void displayMemory() {
    Block* temp = head;
    printf("Memory Blocks:\n");
    while (temp != NULL) {
        printf("Block %d [%s]\n", temp->id, temp->allocated ? "Allocated" : "Free");
        temp = temp->next;
    }
}

int main() {
    int choice, id;
    while (1) {
        printf("\n--- Memory Management Menu ---\n");
        printf("1. Allocate Memory\n");
        printf("2. Mark Memory as Free\n");
        printf("3. Run Garbage Collector\n");
        printf("4. Display Memory Blocks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                allocateMemory();
                break;
            case 2:
                printf("Enter Block ID to mark as free: ");
                scanf("%d", &id);
                deallocateMemory(id);
                break;
            case 3:
                garbageCollector();
                break;
            case 4:
                displayMemory();
                break;
            case 5:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
