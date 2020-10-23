#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *link;
};

struct node *start = NULL, *temp;

void display(){

    if(start == NULL){
    
        printf("\nLinked list is empty!\n");
    }
    else{

        printf("\nThe linked list now is:\n");
        
        temp = start;
        
        while(temp != NULL){

            printf("%d  ", temp -> data);
            temp = temp -> link;
        }
    }
}

void insert(){

    int el, pos;
    
    printf("\nEnter the element to insert:");
    scanf("%d", &el);

    struct node *p;
    p = malloc(sizeof(struct node));

    //printf("%d", 1);
    
    if(start == NULL){

        p -> data = el;
        p -> link = NULL;
        start = p;

        display();
    }
    else{

        printf("\nEnter position:");
        scanf("%d", &pos);

        temp = start;

        for(int i = 0; i < (pos - 1); i++){

            temp = temp -> link;
        }

        p -> link = temp -> link;
        temp -> link = p;

        display();
    }
}

void main(){

    int ans = 0;
    
    while(1){

        printf("\n\nLinked List Operations:\n\n1.Insert beginning\n2.Delete\n3.Display\n4.Exit\n\nEnter your option:");
        scanf("%d", &ans);

        switch(ans){

            case 1 : insert();
                    break;
            //case 2 : delete();
                    //break;
            case 3 : display();
                    break;
            case 4 : exit(0);
                    break;
            default : printf("\n!Wrong option!\n");
        }
    }
}