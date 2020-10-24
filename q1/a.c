#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int element;
    struct Node *next;
};

struct Node* addNode(int element){
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->element = element;
    temp->next = NULL;
    return temp;
}

int main()
{
    struct Node *head = NULL;
    struct Node *temp = head;

    int elements[8] = {3, 2, 5, 4, 7, 4, 2};

    temp = addNode(5);
    head = temp;

    for(int j=0; j<7; j++)
    {

        temp->next = addNode(elements[j]);
        temp = temp->next;
    }

    temp = head;
    printf(" HEAD ");
    while(temp){
        printf(" => %d ",temp->element);
        temp = temp->next;
    }
    printf(" => NULL ");
}
