#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate (EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);


int main(){
    EPtr L = (EPtr)malloc(sizeof(Etype));
    initialize(L);
    
    insertPos(L,10, 0);
    insertPos(L,20, 1);
    display(L);
    printf("\nRetrieved: %d", retrieve(L,1));
    
    
}

void initialize(EPtr L){
    for(int i = 0; i < MAX;i++){
        L->elem[i] = -1;
    }
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(position < 0 || position > L->count){
        printf("Invalid Position");
        return;
    }
    if(L->count >= MAX){
        printf("Array is full!");
        return;
    }
    for(int i = L->count - 1; i >= position; i--){
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid Position");
        return;
    }
    for(int i = position; i < L->count - 1; i++){
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data){
            return i;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid Position!");
        return -1;
    }
    return L->elem[position];
}
void insertSorted(EPtr L, int data){
    if(L->count >= MAX){
        printf("Array is full!");
        return;
    }
    int i;
    
    for(i = L->count - 1;(i > 0 && L->elem[i] > data); i++){
        L->elem[i + 1 ] = L->elem[i]; 
    }
    L->elem[i + 1 ] = data;
    L->count++;
}

void display(EPtr L){
    printf("List of Elements: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
}

void makeNULL(EPtr L){
    free(L);
}
