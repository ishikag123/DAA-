#include<stdio.h>
#include<stdlib.h>

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

void push(struct stack *ptr){
    int val;
    printf("\nenter the value to be pushed:");
    scanf("%d",&val);
    if(isFull(ptr)){
        printf("Stack overflow!Cannot push %d in stack!\n",val);
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top]=val;
}

void pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow!Cannot pop!\n");
        return;
    }
    int val=ptr->arr[ptr->top];
    ptr->top--;
    printf("%d popped from the stack\n",val);
}

void disp(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty\n");
    }
    else{
        printf("The stack is:\n");
        for(int i=0;i<=ptr->top;i++){
            printf("%d ",ptr->arr[i]);
        }
    }

}

int main(){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    printf("enter the size of the stack:\n");
    scanf("%d",&s->size);
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("Press 1 to push a value in stack\nPress 2 to pop a value from the stack\nPress 3 to display the stack\nPress 4 to exit\n");
    int choice;
    while(1){
    printf("\nenter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        push(s);
        break;
        case 2:
        pop(s);
        break;
        case 3:
        disp(s);
        break;
        case 4:
        printf("Program ended\n");
        exit(0);
        break;
        default:
        printf("invalid choice\n");
        break;
    }
    }
}