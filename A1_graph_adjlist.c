#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int vertex;
    struct node *next;
}node;

typedef struct graph
{   
    int vertices;
    node **adjlist;
    int *visited;
}graph;

typedef struct queue{
    int size;
    int f;
    int r;
    int arr[];
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
    if(q->r!=q->f){
        printf("\nThe queue is empty\n");    
    }
    q->f++;
    return q->arr[q->f];

}

// void dispQ(queue* q){
//     if(q->f==q->r){
//         printf("\nThe queue is empty\n");
//         return;
//     }
//     printf("the queue is:\n");
//     for(int i=q->f+1;i<=q->r;i++){
//         printf("%d ",q->arr[i]);
//     }
// }

node *createNode(int v){
    node *new=(node*)malloc(sizeof(node));
    new->vertex=v;
    new->next=NULL;
    return new;
}

graph *createGraph(int n){
    graph *g=(graph*)malloc(sizeof(graph));
    g->vertices=n;
    g->adjlist=malloc(n*sizeof(node*));
    g->visited=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        g->adjlist[i]=NULL;
        g->visited[i]=0;
    }
    return g;
}

void addEdge(graph *g,int a,int b){
    node *new=createNode(a);
    new->next=g->adjlist[b];
    g->adjlist[b]=new;

    new=createNode(b);
    new->next=g->adjlist[a];
    g->adjlist[a]=new;
}

void dispG(graph *g){
    for(int i=0;i<g->vertices;i++){
        node *temp=g->adjlist[i];
        printf("\nVertex %d:",i);
        while(temp){
            printf("%d->",temp->vertex);
            temp=temp->next;
        }
    }
}
void BFS(graph* g,int start){
    queue *q=malloc(sizeof(queue));
    q->f=0;
    q->r=0;
    q->size=400;
    g->visited[start]=1;
    enqueue(q,start);
    while(q->r!=q->f){
        //dispQ(q);
        int k=dequeue(q);
        printf("%d ",k);
        node *temp=g->adjlist[k];
        while(temp){
            int adjVertex=temp->vertex;
            if(g->visited[adjVertex]==0){
                g->visited[adjVertex]=1;
                enqueue(q,adjVertex);
            }
            temp=temp->next;
        }

    }
}

// void DFS(graph *g,int start){
//     node *temp=g->adjlist[start];
//     
//     g->visited[start]=1;
//     printf("%d ",start);
//     while(temp){
//         int k=temp->vertex;
//         if(g->visited[k]==0){
//             DFS(g,k);
//         }
//         temp=temp->next;
//     }
// }

void DFS(graph *g,int start){
    struct stack *stack=(struct stack*)malloc(sizeof(struct stack));
    node *temp=g->adjlist[start];
    stack->top=-1;
    stack->size=400;
    stack->arr=(int*)malloc(stack->size*sizeof(int));
    push(stack,start);
    while(!isEmpty(stack)){
        int x=pop(stack);
        if(g->visited[x]!=1){
            printf("%d ",x);
            g->visited[x]=1;            
        }
        while(temp){
        int k=temp->vertex;
        if(g->visited[k]==0){
            push(stack,k);
        }
        temp=temp->next;
    }
    }
}

int main(){
    int v,ch,i,j,start,start2;
    printf("enter the no of vertices:");
    scanf("%d",&v);
    graph *g=createGraph(4);
    // addEdge(g,0,1);
    // addEdge(g,0,2);
    // addEdge(g,0,3);
    // addEdge(g,1,2);
    // addEdge(g,2,3);
    // dispG(g);
    // printf("\n");
    // BFS(g,0);
    while(1){
        printf("\nEnter 1 for creating edge between two vertices,2 to display the graph,3 for BFS,4 for DFS,5 for exit:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the vertices:");
            scanf("%d%d",&i,&j);  
            addEdge(g,i,j);   
            break;
        case 2:
            dispG(g); 
            break;
        case 3:
            printf("enter the the starting vertex:");
            scanf("%d",&start);    
            BFS(g,start);
            break;
        case 4:
            printf("enter the the starting vertex:");
            scanf("%d",&start2);        
            DFS(g,start2);
            break;
        case 5:
            exit(0);
            break;       
        default:
            break;
        }
    }
    return 0;
}