#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *link;
};

struct node *start = NULL, *temp, *loc;     //loc for getting location of element

void display(){

    if(start == NULL){
    
        printf("\nLinked list is empty!\n");
    }
    else{

        printf("\nThe linked list now is:\n");
        
        temp = start;
        
        if(temp -> link == NULL){
            
            printf("%d  ", temp -> data);
        }
        else{
        
            do{

                printf("%d  ", temp -> data);
                temp = temp -> link;

                if(temp -> link == NULL){
            
                    printf("%d  ", temp -> data);
                }
            }while(temp -> link != NULL);
        }
    }
}

void insert_beg(){

    int el, pos;
    
    printf("\nEnter the element to insert:");
    scanf("%d", &el);

    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));

    
    p -> data = el;
    
    if(start == NULL)
    p -> link = NULL;
    else
    p -> link = start;
    
    start = p;

    display();
}

void insert_at_pos(){

    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the position to enter:");
    int ele, pos;
    scanf("%d", &pos);

    if(pos == 1)
    insert_beg();
    else{

        printf("Enter the element to be inserted:");
        scanf("%d", &ele);

        p -> data = ele;

        temp = start;

        for(int i = 1; i < (pos - 1); i++){

            temp = temp -> link;
        }
        p -> link = temp -> link;
        temp -> link = p;
        display();
    }
}

void insert_end(){

    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element to insert:");
    int item;
    scanf("%d", &item);

    p -> data = item;
    if(start == NULL){

        p -> link = NULL;
        start = p;
    }
    else{

        temp = start;
        while(temp -> link != NULL){

            temp = temp -> link;
        }
        temp -> link = p;
        p -> link = p;
        p -> link = NULL;
    }

    display();
}

void main(){

    int ans = 0;
    
    while(1){

        printf("\n\nLinked List Operations:\n\n1.Insert beginning\n2.Insert at end\n3.Insert in the middle\n4.Delete beginning\n5.Delete end\n6.Delete in the middle\n7.Display\n8.Exit\n\nEnter your option:");
        scanf("%d", &ans);

        switch(ans){

            case 1 : insert_beg();
                    break;
            case 2 : insert_end();
                    break;
            case 3 : insert_at_pos();
                    break;
            case 4 : exit(0);
                    break;
            case 8 : exit(0);
                    break;
            default : printf("\n!Wrong option!\n");
        }
    }
}