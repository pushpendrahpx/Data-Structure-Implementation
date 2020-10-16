#include <stdio.h>
#include <stdlib.h>
struct Object{
    char *country;
};
struct Node{
    struct Object data;
    struct Node *next;
};

struct Node* createNode(struct Object data){
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main(){
    struct Node *head = NULL;
    struct Node *temp = head;
    
    struct Object obj = {"India"};
    temp = createNode(obj);
    head = temp;
    
    obj.country = "Russia";
    temp->next = createNode(obj);
    temp = temp->next;
    
    obj.country = "Canada";
    temp->next = createNode(obj);
    temp = temp->next;

    obj.country = "China";
    temp->next = createNode(obj);
    temp = temp->next;

    obj.country = "United States";
    temp->next = createNode(obj);
    temp = temp->next;
    
    obj.country = "Australia";
    temp->next = createNode(obj);
    temp = temp->next;



    temp = head;
    printf(" HEAD ");
    while(temp){
        printf(" => %s ",temp->data.country);
        temp = temp->next;
    }
    printf(" =>NULL");
    

    printf("\n Deleting All Heap Memory :- ");
    temp = head;
    while(temp){
        head = temp;
        temp = temp->next;
        free(head);
    }

    printf(" DELETED ALL ");
}