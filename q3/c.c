/*
[ Final Correct ]
    U19EE003 - Pushpendra Vishwakarma
    Electrical Engineering Department, SVNIT  
*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}*head;

struct Node* createNewNode(int data, struct Node* previous_address){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = previous_address;
    temp->next = NULL;
    return temp;
}

void seeList(){
    struct Node* temp = head;
    while(temp){
        printf("\n ( %d ",temp->data);
        if(!(temp->next == NULL)) printf(" <=> ");
        printf(" This Address %p,  Prev %p, Next %p ) > ",temp,temp->prev,temp->next);
        temp = temp->next;
    }
}
void search(){
    int num;
    printf("\n Enter a Number to Search :- "); scanf("%d",&num);
    int count = 0;
    if(head == NULL){
        printf("\n Linked List is Already Empty \n");
        getchar();
        getchar();
    }else{
        struct Node *temp = head;
        while(temp){
            count++;
            if(temp->data == num){
                printf("\nElement Found at Node No. %d, having data %d\n",count,num);
                getchar();
                getchar();
                return;
            }
            temp = temp->next;
        }
        printf("\n Element Not Found \n");

                getchar();
                getchar();
    }
}
void insert(){
    int num;
    printf("\n Enter a Number to add in Node :- "); scanf("%d",&num);
    if(head == NULL){
        head = createNewNode(num,NULL);
    }else{
        struct Node *temp = head;
        while(temp){
            if(temp->next == NULL){
                temp->next = createNewNode(num,temp);
                printf("\n Element Added \n");
                getchar();
                getchar();
                break;
            }
            temp = temp->next;
        }
    }
}
void delete(){

    printf("\033[0;31m"); //Set the text to the color red
    if(head==NULL){
        printf("\n Linked List Already Empty \n");
        getchar();
        getchar();
    }else{
        struct Node* temp = head;
        head = head->next;
        if(head){
            head->prev = NULL;
        }
        if(temp){
            free(temp);
        }
        printf("\n Deleted Head \n");
        getchar();
        getchar();
    }

    printf("\033[0m"); //Resets the text to default color
}
void _DELETE_BY_DEFAULT_(){
    printf("\033[0;31m"); //Set the text to the color red
    printf("\n DELETING ALL NODES \n");
    struct Node* temp = head;
    while(temp){
        head = temp;
        printf("\n Deleted Node having value %d",temp->data);
        temp = temp->next;
        free(head);
    }
    printf("\n Deleted All Nodes in Linked List \n");

    printf("\033[0m"); //Resets the text to default color
}
void end_now(){
    _DELETE_BY_DEFAULT_();
    printf("\n ============== Bye Bye ============== \n");
    exit(0);
}
void reverse(){
    struct Node *current = head,*prev=NULL,*next;
    while(current!=NULL){
        
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int main(){
    
    
    head = NULL;
    int choice = 0;

    start : 
    printf("=============================================================================\n");
    printf("[ Doubly Linked List ] - NULL <=> [ *head ]"); seeList(); printf(" => NULL ");
    printf("\n\t---- Main Menu ----\n\t1. Search an Element \t[ Press 1 ]\n\t2. Insert an Element \t[ Press 2 ]\n\t3. Delete an Element \t[ Press 3 ]\n\t4. Exit \t\t[ Press 4 ]\n\t5. Reverse \t\t[ Press 5 ]\n============================\nEnter Your Choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1: search(); goto start;
        case 2: insert(); goto start;
        case 3: delete(); goto start;
        case 4: end_now(); goto start;
        case 5: reverse(); goto start;
        default: printf("\n Entered Wrong Key \n"); goto start;
    }
}