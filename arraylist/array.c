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
void displayMenu();

int main(){
    List L;
    L = initialize(L);
    int choice, data, position;

    while(1){
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                L = insertPos(L, data, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                L = deletePos(L, position);
                break;
            case 3:
                printf("Enter data to locate: ");
                scanf("%d", &data);
                position = locate(L, data);
                if(position != -1){
                    printf("Element found at position %d\n", position);        
                }else{
                    printf("Element not found!\n");
                }
                break;
            case 4:
                printf("Enter data to insert in sorted order: ");
                scanf("%d", &data);
                L = insertSorted(L, data);
                break;
            case 5:
                display(L);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again. \n\n");
                break;
        }
    }
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
        printf("Invalid Position!\n\n");
        return L;
    }
    
    if(L.count >= MAX){
        printf("Array is full!\n\n");
        return L;
    }
    
    for(int i = L.count - 1; i >= position; i--){
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[position] = data;
    L.count++;
    printf("Element inserted successfully!\n\n");
    return L;
}

List deletePos(List L, int position){
    if(position < 0 || position >= L.count){
        printf("Invalid Position\n");
        return L;
    }
    for(int i = position; i < L.count - 1; i++){
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;
    printf("Element deleted successfully!\n\n");
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
    printf("Element inserted successfully in sorted order!\n\n");
    return L;
}

void display(List L){
    printf("List of elems: \n");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

void displayMenu(){
    printf("1. Insert at Position\n");
    printf("2. Delete at Position\n");
    printf("3. Locate Element\n");
    printf("4. Insert in Sorted Order\n");
    printf("5. Display Elements\n");
    printf("6. Exit\n");
}

