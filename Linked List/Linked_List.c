#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List *initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main(){
    List *l = initialize();
    if(l == NULL) return 1;

    insertFirst(l, 10);
    insertLast(1, 20);
    display(l);

    empty(l);
    free(l);
    return 0;
}

List *initialize(){
    List *list = (List *)malloc(sizeof(List));
    if(list == NULL){
        printf("Memory allocation failed");
        return NULL;
    }
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list){
    Node *current = list->head;
    Node *nNode;
    while(current != NULL){
        nNode = current->next;
        free(current);
        current = nNode;
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!");
        return;
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!");
        return;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    

    if(list->head == NULL){
        list->head = newNode;
    }else{
        Node *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
    current->next = newNode;
    list->count++;
    }
}

void insertPos(List *list, int data, int index){
    if(index < 0 || index > list->count){
        printf("Invalid Position!");
        return;
    }

    if(index == 0){
        insertFirst(list, data);
        return;
    }else if(index == list->count){
        insertLast(list, data);
        return;
    }else{
        Node *newNode = (Node *)malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Memory allocation failed!");
            return;
        }
        newNode->data = data;
        Node *current = list->head;
        for(int i = 0; i < index - 1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    }
}

void deleteStart(List *list){
    Node *current = list->head;
    if(list->head == NULL){
        printf("List is empty");
        return;    
    }
    list->head = current->next;
    free(current);
    list->count--;
}

void deleteLast(List *list){
    if(list->head != NULL && list->head->next == NULL){
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }

    Node *current = list->head;
    for(int i = 0; i < list->count - 2; i++){
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    list->count--;

}

void deletePos(List *list, int index){
    if(index == 0){
        deleteStart(list);
        return;
    }

    Node *current = list->head;

    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index){
    if(index < 0 || index >= list->count){
        printf("Invalid position!\n");
        return -1;
    }

    Node *current = list->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }

    return current->data;
}

int locate(List *list, int data){
    if(list->head == NULL){
        return -1;
    }

    Node *current = list->head;
    int index = 0;
    
    while(current != NULL){
        if(current->data == data){
            return index;
        }
        current = current->next;
        index++;

        
    }
    return -1;
}

void display(List *list){
    Node *current = list->head;
    if(list->head == NULL){
        printf("List is empty!\n");
        return;
    }


    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}