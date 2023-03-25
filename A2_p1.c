#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int *arr;
}queue;

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack overflow!Cannot push %d in stack!\n",val);
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top]=val;
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow!Cannot pop!\n");
        return -1;
    }
    int val=ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

void enqueue(queue* q,int val){
    
    if(q->r==q->size-1){
        printf("\nThe queue is full\n");
        return;
    }
    
    q->r++;
    q->arr[q->r]=val;
}

int dequeue(queue* q){
    if(q->f==q->r){
        printf("\nThe queue is empty\n");    
    }
    q->f++;
    return q->arr[q->f];

}

void addEdge(int n,int adj[n][n],int a,int b,int w){
    adj[a][b]=adj[b][a]=w;
}

void disp(int n,int adj[n][n]){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(adj[i][j]!=0){
                printf("%d--(%d)--%d;",i,adj[i][j],j);
            }
        }
    }
    printf("\n");

}

// void DFS(int node,int n,int adj[n][n],int visited[n]){
//     printf("%d ",node);
//     visited[node]=1;
//     for(int i=0;i<n;i++){
//         if(adj[node][i]==1 && visited[i]!=1){
//             DFS(i,n,adj,visited);
//         }
//     }
// }

void DFS(int start,int n,int adj[n][n]){
    int visited[n];
    struct stack *stack=(struct stack*)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=400;
    stack->arr=(int*)malloc(stack->size*sizeof(int));
    push(stack,start);
    while(!isEmpty(stack)){
        int x=pop(stack);
        if(visited[x]!=1){
            printf("%d ",x);
            visited[x]=1;            
        }
        for(int i=0;i<n;i++){
            if(adj[x][i]!=0 && visited[i]!=1){
                push(stack,i);
            }
        }
    }
}

void BFS(int node,int n,int adj[n][n]){
    int visited[n];
    queue q;
    q.size=400;
    q.f=q.r=0;
    q.arr=(int*)malloc(sizeof(int));
    visited[node]=1;
    enqueue(&q,node);
    printf("\nBFS is:\n");
    printf("%d ",node);
    while(q.f!=q.r){
        int k=dequeue(&q);
        for(int i=0;i<n;i++){
            if(adj[k][i]!=0 && visited[i]!=1){
                printf("%d ",i);
                visited[i]=1;
                enqueue(&q,i);
            }
        }
    }
}

/////Prim's Algorithm//////

int minKey(int n,int key[],int mstSet[]){
    int min=INT_MAX,index;
    for(int i=0;i<n;i++){
        if(mstSet[i]==0 && key[i]<min){
            min=key[i];
            index=i;
        }
    }
    return index;
}

void primMST(int n,int adj[n][n]){
    int mst[n],key[n],mstSet[n];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        mstSet[i]=0;
    }
    key[0]=0;
    mst[0]=-1;

    for(int i=0;i<n-1;i++){
        int u=minKey(n,key,mstSet);
        mstSet[u]=1;
        for(int v=0;v<n;v++){
            if(adj[u][v]!=0 && mstSet[v]==0 && adj[u][v]<key[v]){
                mst[v]=u;
                key[v]=adj[u][v];
            }
        }
    }
    
    printf("MST in Prim's Algorithm:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", mst[i], i,
               adj[i][mst[i]]);
}

//////Kruskal Algorithm///////

int find(int n,int parent[],int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void uni(int n,int a,int b,int parent[]){
    int i=find(n,parent,a);
    int j=find(n,parent,b);
    parent[i]=j;
}

void kruskalMST(int n,int adj[n][n]){
    int minCost=0;
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    printf("MST in Kruskal's Algorithm:\n");
    printf("Edge \tWeight\n");
    int edge=0;
    while (edge<n-1)
    {
        int min=INT_MAX,a=-1,b=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(find(n,parent,i)!=find(n,parent,j) && adj[i][j]!=0 && adj[i][j]<min){
                    a=i;
                    b=j;
                    min=adj[i][j];
                }
            }
        }
        uni(n,a,b,parent);
        printf("%d - %d \t%d \n", a, b, min);
		minCost += min;
	}
	printf("\n Minimum cost= %d \n", minCost);
    
}

int main(){
    int n=5;
    // printf("enter the no of vertices:");
    // scanf("%d",&n);
    //int adj[n][n],start,start2,k,ch,a,b,w;
    // int adj[n][n];
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         adj[i][j]=adj[j][i]=0;
    //     }
    // }
    int adj[5][5] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};


    primMST(5,adj);
    kruskalMST(5,adj);


    // while(1){
    //     printf("\nEnter 1 for creating edge between two vertices,2 to display the graph,3 for BFS,4 for DFS,5 for exit:");
    //     scanf("%d",&ch);
    //     switch (ch)
    //     {
    //     case 1:
    //         printf("enter the vertices:");
    //         scanf("%d%d",&a,&b); 
    //         printf("\nenter the weight:") ;
    //         scanf("%d",&w);
    //         addEdge(n,adj,a,b,w);   
    //         break;
    //     case 2:
    //         disp(n,adj); 
    //         break;
    //     case 3:
    //         printf("enter the the starting vertex:");
    //         scanf("%d",&start);
    //         BFS(start,n,adj);
    //         break;
    //     case 4:
    //         printf("enter the the starting vertex:");
    //         scanf("%d",&start2); 
    //         DFS(start2,n,adj);
    //         break;
    //     case 5:
    //         exit(0);
    //         break;       
    //     default:
    //         break;
    //     }
    // }
return 0;
}