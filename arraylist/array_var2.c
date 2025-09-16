#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *Eptr;

void initialize(Eptr L);
void insertPos(Eptr L, int data, int position);
void deletePos(Eptr L, int position);
int locate(Eptr L, int data);
int retrieve(Eptr L, int position);
void insertSorted(Eptr L, int data);
void display(Eptr L);
void makeNULL(Eptr L);

int main(){
    Eptr L; 
    initialize(L);
    insertPos(L, 10, 0);
    insertPos(L, 20, 1);
    insertPos(L, 30, 1);
    display(L);
    return 0;
    
}

void initialize(Eptr L){
    L = (Eptr)malloc(sizeof(Etype));
    L->count = 0;

    for(int i = 0; i< MAX; i++){
        L->elem[i] = -1;
    }

}

void insertPos(Eptr L, int data, int position){
    if(L->count >= MAX){
        printf("The list is full!\n");
        return;
    }
    if(position < 0 || position > L->count){
        printf("Invalid Position!\n");
        return;
    }

    
    for(int i = L->count; i > position; i--){
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position] = data;
    L->count++;
}

void deletePos(Eptr L, int position){
    if(L->count == 0){
        printf("The list is empty!\n");
        return;
    }

    if(position < 0 || position >= L->count){
        printf("Invalid Position!\n");
        return;
    }

    for(int i = position; i < L->count - 1; i++){
        L->elem[i] = L->elem[i + 1];
    }

    L->elem[L->count - 1] = -1;
    L->count--;
}

int locate(Eptr L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data){
            return i;
        }
    }
    return -1;
}

int retrieve(Eptr L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid Position!\n");
        return -1;
    }
    return L->elem[position];
}

void insertSorted(Eptr L, int data){
    if(L->count >= MAX){
        printf("The list is full!\n");
        return; 
    }

    int i;
    for(i = L->count -1;(i >= 0 && L->elem[i] > data); i--){
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[i + 1] = data;
    L->count++;
}

void display(Eptr L){
    if(L->count == 0){
        printf("The list is empty!\n");
        return;
    }
    printf("List elements: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(Eptr L){
    free(L);
    L->count = 0;
    for(int i = 0; i < MAX; i++){
        L->elem[i] = -1;
    }
}
