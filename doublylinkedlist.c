#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;
struct node * temp;

void display(){

    printf("\nThe doubly linked list now is:\n");
    
    if(start == NULL)
    printf("\nThe doubly linked list is empty!");
    else{
        
        temp = start;
        
        do{
            printf("%d  ", temp ->data);
            temp = temp -> next;
        }while(temp -> next != NULL);
    }
}

void insert_beg(){

    struct node *p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element you wish to enter:");
    int ele;
    scanf("%d", &ele);

    p -> data = ele;

    if(start == NULL){

        printf("%d", 1);
        p -> next = NULL;
        p -> prev = NULL;
        start = p;
    }
    else{

        printf("%d", 1);
        p -> next = start -> prev;
        p -> prev = NULL;
        start = p;
    }

    display();
}

void main(){

    int ans = 0;

    while(1){

        printf("\nDoubly linked list:\n\n1.Insert beginning\n2.Insert middle\n3.Insert end\n4.Delete beginning\n5.Delete middle\n6.Delete end\n7.Display\n8.Exit\n\nEnter your choice:");
        scanf("%d", &ans);

        switch(ans){

            case 1: insert_beg();
                     break;
            case 8 : exit(1);
            default : printf("Wrong option!");
        }
    }
}