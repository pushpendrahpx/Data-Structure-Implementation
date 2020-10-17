/*
    U19EE003 - Pushpendra Vishwakarma
    Electrical Engineering Department, SVNIT  

    My Experience with Sentinel Node was that, it really Helped and Simplified my Side Constraints, I dont have to think about the edge cases like about NULL Pointer, at the end will point NULL.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}*head;


struct Node* createNewNode(int data,struct Node* previous_Node){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = previous_Node;
    temp->next = head;
    return temp;
}
void seeList(){

    printf("\033[0;31m"); //Set the text to the color red
    struct Node *temp = head->next;
    while(temp != head){
        printf("\n Value=%d, This address = %p, Prev Address = %p, Next Address = %p => ", temp->data, temp, temp->prev, temp->next);
        temp = temp->next;
    }

    printf("\033[0m"); //Resets the text to default color
}
void search(){
    int num;
    printf("\n Enter a Number to Search :- "); scanf("%d",&num);
    int count = 0;
    
        struct Node *temp = head->next;
        do{
            count++;
            if(temp->data == num){
                printf("\nElement Found at Node No. %d, having data %d\n",count,num);
                getchar();
                getchar();
                return;
            }
            temp = temp->next;
        }while(temp != head);
        printf("\n Element Not Found \n");

                getchar();
                getchar();
    
}
void insert(){
    int num;
    printf("\n Enter a Number to add in Node :- "); scanf("%d",&num);
   
        struct Node *temp = head->next;
        while(temp){
            if(temp->next == head){
                
                temp->next = createNewNode(num,temp);
                (temp->next)->prev = temp;

                printf("\n Element Added \n");
                getchar();
                getchar();
                break;
            }
            temp = temp->next;
        }
}
void delete(){
    
        struct Node* temp = head->next;
        head->next = temp->next;
        if(head->next != head){
            free(temp);

            getchar();
            getchar();
            printf("\n Deleted Head \n");
            return;
        }
        printf("\n Linked List Already Empty\n");
        
    
}
void _DELETE_BY_DEFAULT_(){
    printf("\n DELETING ALL NODES \n");
    struct Node* temp = head->next;
    while(temp != head){
        head->next = temp->next;
        printf("\n Deleted Node having value %d",temp->data);
        
        free(temp);
        temp = head->next;
    }
    printf("\n Deleted All Nodes in Linked List \n");
}
void end_now(){
    _DELETE_BY_DEFAULT_();
    printf("\n ============== Bye Bye ============== \n");
    exit(0);
}
int main(){
    struct Node *abcd = (struct Node*) malloc(sizeof(struct Node));
    abcd->data = 12;
    abcd->next = abcd;
    // As Circular so Initial Sentinal Declarations
    head = abcd;
    int choice = 0;

    start : 
    printf("=============================================================================\n");
    printf("[ Circular Doubly Linked List ] - *head =>"); seeList(); printf(" => head ");
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