#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL, *temp, *loc, *pack;

void traverse(int x){

    if(head == NULL && tail == NULL)
    printf("\nThe doubly linked list is empty!\n");
    else{
    
        if(x == 1){

            printf("\nTraversing forwards:\n");
            
            temp = head;

            if(temp -> next == NULL)
            printf("%d ", temp -> data);
        
            while(temp -> next != NULL){

                printf("%d  ", temp -> data);

                temp = temp -> next;

                if(temp -> next == NULL)
                printf("%d", temp -> data);
            }
        }
        else{

            printf("\nTraversing backwards:\n");
            
            temp = tail;

            if(temp -> prev == NULL)
            printf("%d", temp -> data);

            while(temp -> prev != NULL){

                printf("%d  ", temp -> data);

                temp = temp -> prev;

                if(temp -> prev == NULL)
                printf("%d", temp -> data);
            }
        }

    }
}

void del_end(){

    if(head == NULL && tail == NULL)
    printf("\nNothing to delete! Doubly linked list is empty!\n");
    else{

        temp = tail;

        //printf("\n%d is deleted!\n", temp -> data);

        if(head != tail){

            /*head = NULL; tail = NULL;
            printf("%d", 1);*/

            tail = tail -> prev;
            tail -> next = NULL;
        }
        else{

            head = NULL; 
            tail = NULL;
            printf("%d", 1);
            
            /*printf("%d", 11);
            tail = tail -> prev;
            tail -> next = NULL;
            printf("%d", 11);*/
        }

        printf("\n%d is deleted!\n", temp -> data);

        free(temp);

        traverse(1);
    }
}

void del_beg(){

    if(head == NULL && tail == NULL)
    printf("\nNothing to delete! Doubly Linked List is empty!\n");
    else{
    
        temp = head;

        printf("\n%d is deleted!", temp -> data);
    
        if(temp -> next == NULL){

            head = NULL; tail = NULL;
        }
        else{

            head = temp -> next;
            head -> prev = NULL;

            free(temp);
        }

        traverse(1);
    }
}

void del_atpos(){

    printf("Enter the position at which you want to delete:");
    int pos;
    scanf("%d", &pos);

    if(pos == 1)
    del_beg();
    else{

        temp = head;
        loc = temp -> next;

        for(int i = 1; i < (pos - 1); i++){

            temp = temp -> next;
            loc = temp -> next;
        }

            if(loc == tail)
            del_end();
            else{

                pack = loc -> next;
                temp -> next = loc -> next;
                pack -> prev = temp;

                free(loc);
            }
        //}
    }

    traverse(1);
}

void insert_beg(){

    struct node *p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element to add at beginning :");
    int ele;
    scanf("%d", &ele);

    p -> data = ele;
    p -> next = head;

    if(head == NULL && tail == NULL){

        //head = p;
        tail = p;
        //p -> next = NULL;
        //p -> prev = NULL;
    }
    else{

        //p -> next = head;
        head -> prev = p;
        //p -> prev = NULL;
        //head = p;
    }

    head = p;

    p -> prev = NULL;

    traverse(1);
}

void insert_end(){

    struct node *p = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element to be inserted at the end:");
    int ele;
    scanf("%d", &ele);

    p -> data = ele;
    p -> prev = tail;

    if(head == NULL && tail == NULL){

        head = p;
        //tail = p;
        //p -> next = NULL;
        //p -> prev = NULL;
    }
    else{

        //p -> prev = tail;
        //p -> next = NULL;
        tail -> next = p;
    }

    tail = p;
    p -> next = NULL;

    traverse(1);
}

void insert_atpos(){

    printf("Enter the position at which to add element:");
    int pos;
    scanf("%d", &pos);

    if(pos == 1)
    insert_beg();
    else{

        struct node *p = (struct node*)malloc(sizeof(struct node));

        temp = head;
        loc = temp -> next;

        for(int i = 1; i < (pos - 1); i++){

            temp = temp -> next;
            loc = temp -> next;
        }

        if(loc == tail)
        insert_end();
        else{

        printf("Enter the element to enter at %d:", pos);
        int ele;
        scanf("%d", &ele);

        p -> data = ele;
            
            p -> prev = temp;
            p -> next = loc;
            temp -> next = p;
            loc -> prev = p;

            traverse(1);
        }
    }
}

void main(){

    int ans;
    
    while(1){

        printf("\n\nDoubly Linked List Operations:\n\n1.Insert beginning\n2.Insert at position\n3.Insert end\n4.Delete beginning\n5.Delete at pos\n6.Delete end\n7.Traverse forwards\n8.traverse backwards\n9.Exit\n\nEnter your choice:");
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
            case 5 : del_atpos();
                      break;
            case 6 : del_end();
                      break;
            case 7 : traverse(1);
                      break;
            case 8 : traverse(2);
                      break;
            case 9 : exit(1);
                      break;
            default : printf("\nWrong Option!\n");
        }
    }
}