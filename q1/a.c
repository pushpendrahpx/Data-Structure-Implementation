#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int data){
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main(){
    struct Node *head = NULL;
    struct Node *temp = head;
    
    temp = createNode(5);
    head = temp;

    temp->next = createNode(3);
    temp = temp->next;
    temp->next = createNode(2);
    temp = temp->next;
    temp->next = createNode(5);
    temp = temp->next;
    temp->next = createNode(4);
    temp = temp->next;
    temp->next = createNode(7);
    temp = temp->next;
    temp->next = createNode(4);
    temp = temp->next;
    temp->next = createNode(2);
    temp = temp->next;


    temp = head;
    printf(" HEAD ");
    while(temp){
        printf(" => %d ",temp->data);
        temp = temp->next;
    }
    printf(" => NULL ");
}