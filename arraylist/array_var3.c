#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, int position, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);


int main(){

}

List initialize(List L){
    L.elemPtr = (int *)malloc(LENGTH * sizeof(int));
    L.count = 0;
    L.max = LENGTH;

    for(int i = 0; i < L.max; i++){
        L.elemPtr[i] = -1;
    }

    return L;
}

List insertPos(List L, int position, int data){
    if(L.count >= L.max){
        L = resize(L);
        if(L.max == -1){
            printf("Memory allocation failed!\n");
            return L;
        }
    }

    if(position < 0 || position >= L.count){
        printf("Invalid Position!\n");
        return L;
    }

    for(int i = L.count; i > position; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }
    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(L.count == 0){
        printf("The list is empty!\n");
        return L;
    }

    if(position < 0 || position >= L.count){
        printf("Invalid Position!\n");
        return L;
    }

    for(int i = position; i < L.count -1; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }

    L.elemPtr[L.count - 1] = -1;
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
        L = resize(L);
        if(L.max == -1){
            printf("Memory allocation failed!\n");
            return L;
        }
    }

    int i;
    for(i = L.count -1;(i >= 0 && L.elemPtr[i] > data); i--){
        L.elemPtr[i + 1] = L.elemPtr[i];
    }

    L.elemPtr[i + 1] = data;
    L.count++;
    return L;
}

void display(List L){
    if(L.count == 0){
        printf("The list is empty!\n");
        return;
    }

    printf("List elements: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}

List resize(List L){
    int newMax = L.max * 2;
    int *newArray = (int *)malloc(newMax * sizeof(int));
    return L;
}
