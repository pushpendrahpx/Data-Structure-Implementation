#include <iostream>
#include <queue>

#define MAX 100

struct AdjacencyNode{
    int addr;
    struct AdjacencyNode *next;
};

struct Node{
  int data;
  struct AdjacencyNode *head;
};
void printAdjacencyList(struct Node graph){
    struct AdjacencyNode *tmp = graph.head;

    while(tmp){

        printf(" -->> (%d),",tmp->addr);

        tmp = tmp->next;
    }
    printf(" => NULL ");
}
void makeEdge(struct Node graph[], int from, int to, int graphSize = 10){
    for(int i = 0; i < graphSize; i++){
        if(graph[i].data == from){

            if(graph[i].head == NULL){

                graph[i].head = new AdjacencyNode;
                (graph[i].head)->addr = to;
                (graph[i].head)->next = NULL;

            }else{
                struct AdjacencyNode *tmp = graph[i].head, *tmp2 = graph[i].head;
                while(tmp){
                    tmp2 = tmp;
                    tmp = tmp->next;
                }

                tmp2->next = new AdjacencyNode;
                (tmp2->next)->addr = to;
                (tmp2->next)->next = NULL;
            }



            break;
        }
    }
}
using namespace std;
int main(){
    struct Node graph[10];
    int arr[10] = {9,4,2,6,3,5,1,8,7,0};
    for(int i = 0; i < 10; i++){
        graph[i].data = arr[i];
        graph[i].head = NULL;
    } // to initialize graph

    int t[] = {0,8,3,0,3,1,3,2,3,4,3,7,3,5,6,4,4,9};
    int f[] = {8,0,0,3,1,3,2,3,4,3,7,3,5,3,4,6,9,4};

    for(int i = 0; i < 18; i++){
        makeEdge(graph,t[i],f[i]);
    }



    for(int i = 0; i < 10; i++){
        printf(" %d(%d) ",graph[i].data,i);
        printAdjacencyList(graph[i]);
        printf("\n");
    }



    printf("\n");
    return 0;
}