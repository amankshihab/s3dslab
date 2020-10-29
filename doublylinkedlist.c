#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL, *tail = NULL;
struct node * temp, *loc;

void traverse_back(){


}

void display(int x){
    
    if(start == NULL)
    printf("\nThe doubly linked list is empty!\n");
    else{

        if(x == 0)
        printf("\n\nThe linked list now is:\n");
        else
        printf("\n\nTraversing forwards:\n");
        
        temp = start;
        
        if(temp -> next == NULL){
            
            printf("%d  ", temp -> data);
        }

        while(temp -> next != NULL){

            printf("%d  ", temp -> data);
            temp = temp -> next;

            if(temp -> next == NULL){
            
                printf("%d  ", temp -> data);
            }
        }
    }
}

void insert_end(){

    struct node *p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element you wish to add at the end:");
    int ele;
    scanf("%d", &ele);

    p -> data = ele;

    if(start == NULL){

        p -> next = NULL;
        p -> prev = NULL;
        start = p;
        tail = p;
    }
    else{

        //temp = start;
        
        //while(temp -> next != NULL){

          //  temp = temp -> next;
        //}

        tail -> next = p;
        p -> prev = tail;
        tail = p;
        p -> next = NULL;

        //p -> prev = temp;
        //temp -> next = p;
        //p -> next = NULL;
        //tail = p;
    }

    display(0);
}

void insert_beg(){

    struct node *p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element you wish to add at the beginning:");
    int ele;
    scanf("%d", &ele);

    p -> data = ele;

    if(start == NULL){

        p -> next = NULL;
        p -> prev = NULL;
        start = p;
        tail = p;
    }
    else{

        p -> next = start;
        p -> prev = NULL;
        start -> prev = p;
        start = p;
    }

    display(0);
}

void inser_at_pos(){

    printf("Enter the position at which you wish to insert:");
    int ele, pos;
    scanf("%d", &pos);

    if(pos == 1)
    insert_beg();
    else{

        struct node *p = (struct node*)malloc(sizeof(struct node));

        temp = start;
    
        printf("Enter the element you wish to add at %d : ", pos);
        scanf("%d", &ele);

        p -> data = ele;

        for(int i = 1; i < (pos - 1); i++){

            temp = temp -> next;
            //loc = temp -> next;
        }

        if(temp == tail)
        insert_end();
        else{
            p -> next = temp -> next;
            temp -> next = p;
            p -> prev = temp;
            //p -> next = loc;
            //loc -> prev = p;
        }
    }

    display(0);
}

void delete_beg(){
    
    if(start == NULL)
    printf("\nNothing to delete! Doubly linked list is empty!\n");
    else if(start -> next == NULL){

        printf("\n%d is deleted.\n", start -> data);
        start = NULL;
        tail = NULL;
        free(start);
        free(tail);
        
        printf("\nDoubly linked list has been emptied!");
    }
    else{

        temp = start;
        
        printf("\n%d is deleted.\n", temp -> data);

        start = temp -> next;
        start -> prev = NULL;
        free(temp);

        display(0);
    }
}

void delete_end(){

    if(start == NULL)
    printf("\nNothing to delete! Doubly linked list is empty!\n");
    else if(start == tail){

        printf("\n%d is deleted.\n", start -> data);
        start = NULL;
        tail = NULL;
        free(start);
        free(tail);
        
        printf("\nDoubly linked list has been emptied!");
    }
    else{

        /*temp = start;
        loc = temp -> next;

        while(loc -> next != NULL){

            temp = temp -> next;
            loc = loc -> next;
        }

        printf("\n%d is deleted!\n", loc -> data);

        temp -> next = NULL;
        free(loc);*/

        loc = tail;
        loc = loc -> prev;
        loc -> next = NULL;
        free(loc);

        display(0);
    }
}

void delete_pos(){

    printf("Enter the position from which you want to delete:");
    int pos;
    scanf("%d", &pos);

    if(pos == 1)
    delete_beg();
    else{

        temp = start;
        loc = temp -> next;

        for(int i = 1; i <(pos - 1); i++){

            temp = temp -> next;
            loc = temp -> next;
        }

        printf("\n%d is deleted!\n", loc -> data);

        temp -> next = loc -> next;
        free(loc);

        display(0);
    }
}

void main(){

    int ans = 0;

    while(1){

        printf("\n\nDoubly linked list:\n\n1.Insert beginning\n2.Insert middle\n3.Insert end\n4.Delete beginning\n5.Delete middle\n6.Delete end\n7.Traverse forwards\n8.Traverse backwards\n9.Exit\n\nEnter your choice:");
        scanf("%d", &ans);

        switch(ans){

            case 1: insert_beg();
                     break;
            case 2 : inser_at_pos();
                     break;
            case 3 : insert_end();
                     break;
            case 4 : delete_beg();
                     break;
            case 5 : delete_pos();
                     break;
            case 6 : delete_end();
                     break;
            case 7 : display(1);
                     break;
            case 8 : traverse_back();
                     break;
            case 9 : exit(1);
                     break;
            default : printf("Wrong option!");
        }
    }
}