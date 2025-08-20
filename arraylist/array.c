#include <stdio.h>
#define MAX 10
 

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int position, int data);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);


int main(){
    List L;
    L.count = 0; 
    int num, pos;

    L = insertPos(L, 0, 10);
    L = insertPos(L, 1, 20);
    L = insertPos(L, 1, 30);

    display(L);
    return 0;
}

List initialize(List L){
    L.count = 0;

    for(int i = 0; i < MAX; i++){
        L.elem[i] = -1;
    }

}
List insertPos(List L, int position, int data) {
    if (L.count >= MAX) {
        printf("The list is full!\n");
        return L;
    }

    if (position < 0 || position >= MAX) {
        printf("Invalid Position!\n");
        return L;
    }

    L.elem[position] = data;

    if (position >= L.count) {
        L.count = position + 1;
    }

    return L;
}

List deletePos(List L, int position){

    if(position < 0 || position >= L.count){
        printf("Invalid position!");
        return L;
    }
    for(int i = position; i < L.count - 1; i++){
        L.elem[i] = L.elem[i + 1];
    }

    L.count--;
    return L;

}


int locate(List L, int data){

    for(int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) {
            return i; 
        }
    }
    return -1; 

}


List insertSorted(List L, int data){

    if (L.count >= MAX) {
        printf("The list is full!\n");
        return L;
    }

    int i;
    for (i = L.count - 1; (i >= 0 && L.elem[i] > data); i--) {
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[i + 1] = data;
    L.count++;
    
    return L;

}


void display(List L){

    if (L.count == 0) {
        printf("The list is empty!\n");
        return;
    }

    printf("List elements: ");
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}