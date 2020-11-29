#include <iostream>
#include <queue>

using namespace std;

queue<int> myq;

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
void traverse(struct Node graph[],int nodeIndex){

  if(nodeIndex >= 0){
        myq.push(graph[nodeIndex].data);
        // added initial Vertex


    graph[nodeIndex].visited = true;

    int index = getIndex(graph,myq.front());
    // int index = 0;
    while(!myq.empty()){


        index = getIndex(graph,myq.front());
        struct AdjacencyNode *tmp = graph[index].head;

        while(tmp){

            if(graph[getIndex(graph,tmp->addr)].visited == false){
                myq.push(tmp->addr);
                graph[getIndex(graph,tmp->addr)].visited = true;
            }

            tmp = tmp->next;
        }

        cout<<myq.front()<<", ";


        myq.pop();

    }






    /////////////////////////////////////////////////////



    // cout<<graph[nodeIndex].data <<" - ";

  }


}
int main(){
    struct Node graph[10];
    int arr[10] = {9,4,2,6,3,5,1,8,7,0};
    for(int i = 0; i < 10; i++){
        graph[i].data = arr[i];
        graph[i].head = NULL;
        graph[i].visited = false;
    } // to initialize grap   h

    int t[] = {0,8,3,0,3,1,3,2,3,4,3,7,3,5,6,4,4,9};
    int f[] = {8,0,0,3,1,3,2,3,4,3,7,3,5,3,4,6,9,4};

    for(int i = 0; i < 18; i++){
        makeEdge(graph,t[i],f[i]);
    }
    // cout<<myq.front();

    traverse(graph,getIndex(graph,0));


    // for(int i = 0; i < 10; i++){
    //     cout<<graph[i].data<<", ("<<i<<")";
    //     printAdjacencyList(graph[i]);
    //     // printf("\n");
    //     cout<<"\n";
    // }



    cout<<"\n";
    return 0;
}