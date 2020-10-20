#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
}*head;

struct Node* createNewNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void seeList(){
    struct Node* temp = head;
    while(temp){
        printf(" %d ",temp->data);
        if(!(temp->next==NULL)) printf("-->");
        temp = temp->next;
    }
}

void insertNode(){
    int num;
    printf("\n Enter a Number to add in Node :- "); scanf("%d",&num);
    if(head == NULL){
        head = createNewNode(num);
    }else{
        struct Node *temp = head;
        while(temp){
            if(temp->next == NULL){
                temp->next = createNewNode(num);
                printf("\n Element Added \n");
                break;
            }
            temp = temp->next;
        }
    }
}

void reverseList(){
    if(!head) printf("Can't reverse an empty list");
    else{
     struct Node* current = head;
     struct Node* prev = NULL;
     struct Node* next = NULL;
     current = head;
     while(current != NULL){
         next = current->next;
         current->next = prev;
         prev = current;
         current = next;
    }
    head = prev;   
    }
}
void _DELETE_BY_DEFAULT_(){
    printf("\n DELETING ALL NODES \n");
    struct Node* temp = head;
    while(temp){
        head = temp;
        printf("\n Deleted Node having value %d",temp->data);
        temp = temp->next;
        free(head);
    }
    printf("\n Deleted All Nodes in Linked List \n");
}

void end_now(){
    _DELETE_BY_DEFAULT_();
    printf("\n ============== Bye Bye ============== \n");
    exit(0);
}

int main(){
      head = NULL;
    int choice = 0;

    start : 
    printf("=============================================================================\n");
    printf("[ Linked List ] - *head =>"); seeList(); printf(" => NULL ");
    printf("\n\t---- Main Menu ----\n\t1. Insert an Element \t[ Press 1 ]\n\t2. Seethelist \t[ Press 2 ]\n\t3. Reverse List \t[ Press 3 ]\n\t4. Exit \t\t[ Press 4 ]\n============================\nEnter Your Choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1: insertNode() ; goto start;
        case 2: seeList(); goto start;
        case 3: reverseList(); goto start;
        case 4: end_now(); goto start;
        default: printf("\n Entered Wrong Key \n"); goto start;
    }
}