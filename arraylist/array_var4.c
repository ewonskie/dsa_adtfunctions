#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
}List;


void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main(){
    List L;
    initialize(&L);
    int choice, data, position;

    while(1) {
        printf("\n1. Insert at position\n2. Delete at position\n3. Locate\n4. Insert sorted\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPos(&L, data, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePos(&L, position);
                break;
            case 3:
                printf("Enter data to locate: ");
                scanf("%d", &data);
                position = locate(&L, data);
                if(position != -1) printf("Found at %d\n", position);
                else printf("Not found\n");
                break;
            case 4:
                printf("Enter data to insert sorted: ");
                scanf("%d", &data);
                insertSorted(&L, data);
                break;
            case 5:
                display(&L);
                break;
            case 6:
                makeNULL(&L);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


void initialize(List *L){
    L->elemPtr =(int *)malloc(LENGTH * sizeof(int));
    if(L->elemPtr == NULL){
        printf("Memory allocation failed!");
        exit(1);
    }
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L, int data, int position){
    if(position < 0 || position > L->count){
        printf("Invalid Position\n\n");
        return;
    }
    if(L->count >= L->max){
        resize(L);
    }
    for(int i = L->count - 1; i >= position; i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }
    
    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid Position\n\n");
        return;
    }
    for(int i = position; i < L->count - 1; i++){
        L->elemPtr[i] = L->elemPtr[i + 1];
    }
    
    L->count--;
}

int locate(List *L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

int retrieve(List *L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid Position");
        exit(1);
    }
    return L->elemPtr[position];
}

void insertSorted(List *L, int data){
    if(L->count >= L->max){
        printf("Array is full\n\n");
        return;
    }
    int i;
    for(i = L->count - 1;(i >= 0 && L->elemPtr[i] > data); i++){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }
    L->elemPtr[i + 1] = data;
    L->count++;
}

void display(List *L){
    printf("List of elements: ");
    for(int i = 0; i < L->count;i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void resize(List *L){
    L->max = L->max * 2;
    L->elemPtr = (int *)realloc(L->elemPtr, L->max * sizeof(int));
    if(L->elemPtr == NULL){
        printf("Memory allocation failed!\n\n");
        exit(1);
    }
}

void makeNULL(List *L){
    free(L->elemPtr);
    L->count = 0;
}