/*
    U19EE003 - Pushpendra Vishwakarma
    Electrical Engineering Department, SVNIT  
*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*head;


struct Node* createNewNode(int data){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void seeList(){
    struct Node* temp = head;
    while(temp){
        printf(" %d ",temp->data);
        if(!(temp->next == NULL)) printf(" => ");
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
/* ------------------------------ Main Part of Questions is Insertion -------------------------------------- */
void insert(){
    int num;
    printf("\n Enter a Number to add in Node :- "); scanf("%d",&num);
    if(head == NULL){
        head = createNewNode(num);
        head->next = NULL;
    }else{
        struct Node* temp2 = head;
        struct Node* temp = head;
        if(head->data > num){
            temp = createNewNode(num);
            temp->next = head;
            head = temp;
            return;
        }
        while(temp && temp->data < num){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = createNewNode(num);
        (temp2->next)->next = temp;



    }
}
/* ------------------------------ Main Part of Questions is Insertion -------------------------------------- */
void delete(){
    if(head==NULL){
        printf("\n Linked List Already Empty \n");
        getchar();
        getchar();
    }else{
        struct Node* temp = head;
        head = head->next;
        free(temp);
        getchar();
        getchar();
        printf("\n Deleted Head \n");
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
    printf("\n\t---- Main Menu ----\n\t1. Search an Element \t[ Press 1 ]\n\t2. Insert an Element \t[ Press 2 ]\n\t3. Delete an Element \t[ Press 3 ]\n\t4. Exit \t\t[ Press 4 ]\n============================\nEnter Your Choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1: search(); goto start;
        case 2: insert(); goto start;
        case 3: delete(); goto start;
        case 4: end_now(); goto start;
        default: printf("\n Entered Wrong Key \n"); goto start;
    }
}