#include <iostream>
#include <stack>

using namespace std;

stack<int> mys;

struct AdjacencyNode{
    int addr;
    struct AdjacencyNode *next;
};

struct Node{
  int data;
  bool visited;
  struct AdjacencyNode *head;
};
void printAdjacencyList(struct Node graph){
    struct AdjacencyNode *tmp = graph.head;

    while(tmp){

        cout<<"-->>,"<<tmp->addr;

        tmp = tmp->next;
    }
    cout<<" => NULL ";
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

int getIndex(struct Node graph[],int val){
    for(int i = 0; i < 10; i++){
        if(val == graph[i].data){
            return i;
        }
    }
    return -1;
}

struct Node graph[10];


void traverse(int nodeIndex){

  if(nodeIndex >= 0){
    mys.push(graph[nodeIndex].data);
    cout<<graph[nodeIndex].data<<", ";
    graph[nodeIndex].visited = true;

    struct AdjacencyNode *tmp = ::graph[nodeIndex].head;

    while(tmp){

        // Got First Adjacency Node

        if(graph[getIndex(graph,tmp->addr)].visited == false){
            traverse(getIndex(graph,tmp->addr));
        }

        tmp = tmp->next;
    }



  }


}
int main(){
    int arr[10] = {9,4,2,6,3,5,1,8,7,0};
    for(int i = 0; i < 10; i++){
        graph[i].data = arr[i];
        graph[i].head = NULL;
        graph[i].visited = false;
    } // to initialize grap   h

    int t[] = {0,8,0,1,1,3,3,4,4,2,2,6,6,9,4,5,5,7,4,7};
    int f[] = {8,0,1,0,3,1,4,3,2,4,6,2,9,6,5,4,7,5,7,4};

    for(int i = 0; i < 18; i++){
        makeEdge(graph,t[i],f[i]);
    }
    // cout<<myq.front();

    traverse(getIndex(graph,0));

    // for(int i = 0; i < 10; i++){
    //     cout<<graph[i].data<<",("<<i<<")";
    //     printAdjacencyList(graph[i]);
    //     // printf("\n");
    //     cout<<"\n";
    // }



    cout<<"\n";
    return 0;
}