#include<stdio.h>
#include<stdlib.h>

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

void addEdge(int n,int adj[n][n],int a,int b){
    adj[a][b]=adj[b][a]=1;
}

void disp(int n,int adj[n][n]){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(adj[i][j]==1){
                printf("%d--%d;",i,j);
            }
        }
    }
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
            if(adj[x][i]==1 && visited[i]!=1){
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
            if(adj[k][i]==1 && visited[i]!=1){
                printf("%d ",i);
                visited[i]=1;
                enqueue(&q,i);
            }
        }
    }
}

int main(){
    
    int n=4;
    int adj[n][n],start,start2;
    adj [0][1] = adj [1][0] = 1;
	adj [0][2] = adj [2][0] = 1;
	adj [2][1] = adj [1][2] = 1;
	adj [3][2] = adj [2][3] = 1;
	adj [0][3] = adj [3][0] = 1;

    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         int c;
    //         printf("relation between %d and %d:",i,j);
    //         scanf("%d",&c);
    //         if(c==1){
    //             adj[i][j]=adj[j][i]=1;
    //         }
    //         else{
    //             adj[i][j]=adj[j][i]=0;
    //         }
    //     }
    // }

    printf("the graph is:\n");
    disp(n,adj);

    printf("the starting node for bfs\n");
    scanf("%d",&start);
    BFS(start,n,adj);

    printf("the starting node for dfs\n");
    scanf("%d",&start2);       
    printf("\nDFS is:\n");
    DFS(start2,n,adj);

    
return 0;
}