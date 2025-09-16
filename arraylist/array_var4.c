#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
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
    insertPos(&L, 10, 0);
    insertPos(&L, 20, 1);
    insertPos(&L, 30, 1);
    display(&L);
    return 0;
    

}


void initialize(List *L){
    L->elemPtr = (int *)malloc(LENGTH * sizeof(int));
    L->count = 0;
    L->max = LENGTH;
}

void insertPos(List *L, int data, int position){
    if(position < 0 || position > L->count){
        printf("Invalid Position!\n");
        return;
    }

    if(L->count >= L->max){
        resize(L);
    }

    for(int i= L->count; i > position; i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L.elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid Position!\n");
        return;
    }

    for(int i = position; i < L->count -1; i++){
        L->elemPtr[i] = L->elemPtr[i + 1];
    }
    L->elemPtr[L->count - 1] = -1;
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
        printf("Invalid Position!\n");
        return -1;
    }

    return L-elemPtr[position];
}

void insertSorted(List *L, int data){
    if(L->count >= L->max){
        resize(L);
    }

    int i;
    for(int i = L.count - 1; (i >= 0 && L->elemPtr[i] > data); i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    })

    L->elemPtr[i + 1] = data;
    L->count++;
}

void display(List *L){
    printf("List elements: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void resize(List *L){
    int newMax = L->max * 2;
    int newArr = (int *)malloc(newMax * sizeof(int));
}

void makeNULL(List *L){
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}


