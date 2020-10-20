#include <stdio.h>
#include <stdlib.h>
struct Object{
    char *name;
    int id;
    int semester;
    double CGPA;
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
    
    struct Object obj = {"Jay", 1, 3, 7};
    temp = createNode(obj);
    head = temp;
    
    obj.name = "Shubham";
    obj.id = 2;
    obj.semester = 3;
    obj.CGPA = 7;
    temp->next = createNode(obj);
    temp = temp->next;

    obj.name = "Pushpendra";
    obj.id = 3;
    obj.semester = 3;
    obj.CGPA = 7;
    temp->next = createNode(obj);
    temp = temp->next;

    obj.name = "Nirav";
    obj.id = 4;
    obj.semester = 3;
    obj.CGPA = 7;
    temp->next = createNode(obj);
    temp = temp->next;



    temp = head;
    printf(" HEAD ");
    while(temp){
        printf("Name => %s \n",temp->data.name);
        printf("ID => %d \n", temp->data.id);
        printf("Semester => %d \n", temp->data.semester);
        printf("CGPA => %lf \n", temp->data.CGPA);
        printf("\n\n");
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