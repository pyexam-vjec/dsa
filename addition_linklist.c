#include <stdio.h>
#include <stdlib.h>

struct node {
    int c;
    int e;
    struct node* link;
};

struct node* readpoly(struct node* head, int n) {
    struct node* ptr = head;
    for (int i = 0; i < n; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the coefficient: ");
        scanf("%d", &newNode->c);
        printf("Enter the exponent: ");
        scanf("%d", &newNode->e);
        newNode->link = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            ptr = head;
            while (ptr->link != NULL) {
                ptr = ptr->link;
            }
            ptr->link = newNode;
        }
    }
    return head;
}

struct node* addpoly(struct node* phead, struct node* qhead) {
    struct node* rhead = NULL;
    struct node* rptr = NULL;
    struct node* pptr = phead;
    struct node* qptr = qhead;
    
    while (pptr != NULL && qptr != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->link = NULL;
        
        if (pptr->e > qptr->e) {
            newNode->c = pptr->c;
            newNode->e = pptr->e;
            pptr = pptr->link;
        } else if (pptr->e < qptr->e) {
            newNode->c = qptr->c;
            newNode->e = qptr->e;
            qptr = qptr->link;
        } else {
            newNode->c = pptr->c + qptr->c;
            newNode->e = pptr->e;
            pptr = pptr->link;
            qptr = qptr->link;
        }
        
        if (rhead == NULL) {
            rhead = newNode;
            rptr = newNode;
        } else {
            rptr->link = newNode;
            rptr = newNode;
        }
    }
    
    while (pptr != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->c = pptr->c;
        newNode->e = pptr->e;
        newNode->link = NULL;
        if (rhead == NULL) {
            rhead = newNode;
            rptr = newNode;
        } else {
            rptr->link = newNode;
            rptr = newNode;
        }
        pptr = pptr->link;
    }
    
    while (qptr != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->c = qptr->c;
        newNode->e = qptr->e;
        newNode->link = NULL;
        if (rhead == NULL) {
            rhead = newNode;
            rptr = newNode;
        } else {
            rptr->link = newNode;
            rptr = newNode;
        }
        qptr = qptr->link;
    }
    
    return rhead;
}

void printpoly(struct node* head) {
    struct node* ptr = head;
    if (ptr == NULL) {
        printf("0\n");
        return;
    }
    
    printf("%dx^%d", ptr->c, ptr->e);
    ptr = ptr->link;
    
    while (ptr != NULL) {
        if (ptr->c > 0) {
            printf("+%dx^%d", ptr->c, ptr->e);
        } else if (ptr->c < 0) {
            printf("%dx^%d", ptr->c, ptr->e);
        }
        ptr = ptr->link;
    }
    printf("\n");
}

int main() {
    struct node* phead = NULL;
    struct node* qhead = NULL;
    int n1, n2;
    
    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &n1);
    phead = readpoly(phead, n1);
    
    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &n2);
    qhead = readpoly(qhead, n2);
    
    struct node* rhead = addpoly(phead, qhead);
    
    printf("First Polynomial: ");
    printpoly(phead);
    printf("Second Polynomial: ");
    printpoly(qhead);
    printf("Resultant Polynomial: ");
    printpoly(rhead);
    
    return 0;
}
