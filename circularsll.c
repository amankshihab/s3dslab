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

void insert_beg(){

    struct node *p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element to enter:");
    int ele;
    scanf("%d", &ele);

    p -> data = ele;
    //start = p;
    //p -> link = start;
    
    if(start == NULL){
        start = p;
        p -> link = start;
    }
    else{

        //p -> link = start -> link;
        temp = start;

        while(temp -> link != start)
            temp = temp -> link;

        p -> link = start;
        temp -> link = p;
        start = p; 
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
            case 8 : display();
                        break;
            case 9 : exit(1);
                        break;
            default : printf("\nWrong Option!\n");
        }
    }
}