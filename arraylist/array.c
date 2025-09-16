#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);


int main(){
    List L;
    L = initialize(L);
    
    L = insertPos(L, 10, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 30, 1);

    display(L);
    return 0;
}

List initialize(List L){
    L.count = 0;
    for(int i = 0; i < MAX; i++){
        L.elem[i] = -1;
    }
    return L;
}

List insertPos(List L, int data, int position){
    
    if(position < 0 || position >= MAX){
        printf("Invalid Position!\n");
        return L;
    }
    
    if(L.count >= MAX){
        printf("Array is full!");
        return L;
    }
    
    for(int i = L.count - 1; i >= position; i--){
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(position < 0 || position >= L.count){
        printf("Invalid Position");
        return L;
    }
    for(int i = position; i < L.count - 1; i++){
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    if(L.count >= MAX){
        return L;
    }
    int i;
    for(i = L.count - 1; (i >= 0 && L.elem[i] > data); i--){
        L.elem[i + 1] = L.elem[i];
    }
    
    L.elem[i + 1] = data;
    L.count++;
    return L;
}

void display(List L){
    printf("List of elems: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}


