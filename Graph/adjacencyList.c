#include<stdio.h>
#include<stdlib.h>

struct Node{
    int vertex;
    struct Node * next;

};

struct List{
    struct Node* head;
};

struct Graph{
    int V;
    struct List * array;
};

struct Node * createNode(int v){
    struct Node * q = (struct Node*)malloc(sizeof(struct Node));
    q->vertex = v;
    q->next = NULL;
    return q;
}

void addEdge(struct Graph * g, int src,int des){
    struct Node * temp = createNode(des);
    temp->next = g->array[src].head;
    g->array[src].head = temp;
}

struct Graph * createGraph(int v){
    struct Graph * g = (struct Graph*)malloc(sizeof(struct Graph));
    g->V = v;
    g->array = (struct List *)malloc(v*sizeof(struct List));
    for(int i=0 ; i<v ; i++){
        g->array[i].head=NULL;
    }
    return g;
}

void printGraph(struct Graph * g){
    int v;
    for(int v=0 ; v<g->V ; v++){
        struct Node * trav=g->array[v].head;
        while(trav!=NULL){
            printf("->%d",trav->vertex);
            trav = trav->next;
        }
        printf("\n");
    }
}

int main(){
    struct Graph * graph = createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,1,2);
    addEdge(graph,2,0);
    addEdge(graph,2,3);
    




    printGraph(graph);
    return 0;
}

