#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int V;
    int E;
    int **Adj;
};

void adjMatrixOfGraph(struct Graph *G){
    int u,v,i,j,k;
    G->Adj = (int **)malloc(sizeof(int)*G->V);
    for(i=0 ; i<G->E ; i++){
        G->Adj[i] = (int *)malloc(sizeof(int)*G->V);
    }
    for(j=0 ; j<G->V ; j++){
        for(k=0 ; k<G->V ; k++){
            G->Adj[j][k]=0;
        }
    }
    printf("Enter the edges pairs\n");
    for(i=0 ; i<G->E ; i++){
        scanf("%d %d",&u,&v);
        G->Adj[u][v]=1;
        G->Adj[v][u]=1;
    }
}

int main(){
    struct Graph *G=(struct Graph*)malloc(sizeof(struct Graph));
    printf("Enter No. of vertices\n");
    scanf("%d",&G->V);
    printf("Enter No. of Edges\n");
    scanf("%d",&G->E); 
    adjMatrixOfGraph(G);
    for(int i=0; i<G->V; i++){
        for(int j=0; j<G->V; j++){
            printf("%d\t",G->Adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
