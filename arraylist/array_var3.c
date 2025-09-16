#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main(){
    List L = initialize(L);
    
    L = insertPos(L, 20, 0);
    L = insertPos(L, 30, 1);
    L = insertSorted(L, 25);
    
    display(L);
    
    return 0;
    
}

List initialize(List L){
    L.elemPtr =(int *)malloc(LENGTH * sizeof(int));
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position < 0 || position > L.count){
        printf("Invalid Position");
        exit(1);
    }
    if(L.count >= L.max){
        printf("Array is full!");
        L = resize(L);
    }
    
    for(int i = L.count - 1; i >= position; i--){
        L.elemPtr[i + 1] = L.elemPtr[i];
    }
    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(position < 0 || position >= L.count){
        printf("Invalid Position");
        exit(1);
    }
    for(int i = position; i < L.count - 1; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    if(L.count >= L.max){
        printf("Array is full");
        L = resize(L);
    }
    int i;
    for(i = L.count - 1;(i >= 0 && L.elemPtr[i] > data);i--){
        L.elemPtr[i + 1] = L.elemPtr[i];
    }
    L.elemPtr[i + 1] = data;
    L.count++;
    return L;
}

List resize(List L){
    L.max = L.max * 2;
    L.elemPtr = (int *)realloc(L.elemPtr, L.max * sizeof(int));
    if(L.elemPtr == NULL){
        printf("Memory allocation failed!");
        exit(1);
    }
    return L;
}

void display(List L){
    printf("Elements: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
}
