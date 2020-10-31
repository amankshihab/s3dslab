#include<stdio.h>
#include<stdlib.h>

int i = -1, size = 0;

struct node{

    int data;
    struct node *link;
};

struct node *top = NULL, *temp;

void display(){
    
    if(top == NULL)
    printf("\nLinked stack is empty! Stack underflow!\n");
    else{
    
        printf("\nThe stack now is:\n");
        
        temp = top;

        if(temp -> link == NULL)
        printf("%d  ", temp -> data);
        else if(top == NULL)
        printf("\n!!EMPTY!!\n");
        else{

            while(temp -> link != NULL){

                printf("%d  ", temp -> data);
                temp = temp -> link;

                if(temp -> link == NULL)
                printf("%d  ", temp -> data);
            }
        }
    }
}

void push(){

    if(i < size - 1){

        struct node *p = (struct node*)malloc(sizeof(struct node));

        int item;

        printf("\nEnter the element to add:");
        scanf("%d", &item);
        
        p -> data = item;

        if(top == NULL){

            p -> link = NULL;
            top = p;
        }
        else{

            p -> link = top;
            top = p;
        }

        display();

        ++i;
    }
    else
    printf("\nCan't add more elements! Stack Overflow!\n");
}

void pop(){

    if(i != -1){

        temp = top;
        printf("\n%d is popped.\n", temp -> data);

        if(temp -> link == NULL)
        top = NULL;
        else
        top = temp -> link;
        
        free(temp);

        i -= 1;

        if(i == -1)
        printf("\nLinked stack has been emptied!\n");
        else
        display();
    }
    else
    printf("\nNothing to delete! Stack Underflow!\n");
}

void main(){

    int ans = 0;

    printf("\nEnter the size of the stack:");
    scanf("%d", &size);

    while(1){
        
        printf("\n\nStack operations:\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n\nEnter you choice:");
        scanf("%d", &ans);

        switch(ans){

            case 1 : push();
                      break;
            case 2 : pop();
                      break;
            case 3 : display();
                      break;
            case 4 : exit(1);
                      break;
            default : printf("\nWrong Option!\n");
        }
    }
}