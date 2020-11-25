#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *link;
};

struct node *start = NULL, *temp;;

void display(){

    printf("\nThe circular linked list now is:\n");

    temp = start;
    
    if(temp -> link == start)
    printf("%d  ", temp -> data);

    while(temp -> link != start){

        printf("%d  ", temp -> data);

        temp = temp -> link;

        if(temp -> link == start)
        printf("%d  ", temp -> data);
    }
}

void del_beg(){

    if(start == NULL)
    printf("\nCircular Linked List is empty!");
    else{

        temp = start;

        start = start -> link;
        free(temp);

        display();
    }
}

void insert_end(){

    struct node *p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element you want to insert at the end:");
    int ele;
    scanf("%d", &ele);

    p -> data = ele;

    if(start == NULL){

        start = p;
        p -> link = start;
    }
    else{

        temp = start;

        while(temp -> link != start)
            temp = temp -> link;

        temp -> link = p;
        p -> link = start;
    }

    display();
}

void insert_beg(){

    struct node *p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element to enter at the beginning:");
    int ele;
    scanf("%d", &ele);

    p -> data = ele;
    
    if(start == NULL){
        start = p;
        p -> link = start;
    }
    else{

        temp = start;

        while(temp -> link != start)
            temp = temp -> link;

        p -> link = start;
        temp -> link = p;
        start = p; 
    }

    display();
}

void insert_atpos(){

    struct node *p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the position at which you want to enter the element in:");
    int pos, ele;
    scanf("%d", &pos);

    if(pos == 1)
    insert_beg();
    else if(start == NULL)
    printf("\nCircular linked list not initiated, please initiate it first");
    else{
        
        temp = start;

        for(int i = 1; i < (pos - 1); i++)
            temp = temp -> link;

        if(temp -> link == start)
            insert_end();
        else{
        
            printf("Enter the element to be entered:");
            scanf("%d", &ele);

            p -> data = ele;
            
            p -> link = temp -> link;
            temp -> link = p;
        
            display();
        }
    }
}

void main(){

    int ans = 0;
    
    while(1){

        printf("\n\nCircular Singly Linked List Operations:\n\n1.Insert in beginning\n2.Insert at position\n3.Insert at end\n4.Delete beginning\n5.Delete at pos\n6.Delete at end\n8.Display linked list\n9.Exit\n\nEnter your choice:");
        scanf("%d", &ans);

        switch(ans){

            case 1 : insert_beg();
                        break;
            case 2 : insert_atpos();
                        break;
            case 3 : insert_end();
                        break;
            case 4 : del_beg();
                        break;
            case 8 : display();
                        break;
            case 9 : exit(1);
                        break;
            default : printf("\nWrong Option!\n");
        }
    }
}