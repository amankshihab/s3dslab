#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct node{

    int data;
    struct node *link;
};

struct node *start = NULL, *temp, *loc;     

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

void insert(int pos, int x){

    count += 1;
    
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the element to be entered:");
    int el;
    scanf("%d", &el);
    
    p -> data = el;

    if(pos == 1 && x == 0){
    
        if(start == NULL)
        p -> link = NULL;
        else
        p -> link = start;
    
        start = p;
    }
    else if(x == 1){

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
    }
    else{

        temp = start;

        for(int i = 1; i < (pos - 1); i++){

            temp = temp -> link;
        }
        p -> link = temp -> link;
        temp -> link = p;
    }
    display();
}

void delete(int pos, int x){

    temp = start;
    
    if(start == NULL)
    printf("\nNothing to delete! Linked list is empty!\n");
    else if(pos == 1 && x == 0){
        
        start = start -> link;

        printf("\n%d is deleted!\n", temp -> data);
    }
    else if(pos != 1 && x == 0){

        //temp = start;
        loc = temp -> link;

        for(int i = 1; i < (pos - 1); i++){

            temp = temp -> link;
            loc = loc -> link;
        }

        printf("\n%d is deleted!\n", loc -> data);
        temp -> link = loc -> link;
            
        free(loc);
    }
    else{

        loc = temp -> link;

        while(loc -> link != NULL){

            temp = temp -> link;
            loc = loc -> link;
        }
        temp -> link = NULL;

        printf("\n%d is deleted!\n", loc -> data);
        
        free(loc);
    }

    display();
}

void main(){

    int ans = 0, ind = 0, posi;
    
    while(1){

        printf("\n\nLinked List Operations:\n\n1.Insert beginning\n2.Insert at end\n3.Insert in the middle\n4.Delete beginning\n5.Delete end\n6.Delete in the middle\n7.Display\n8.Exit\n\nEnter your option:");
        scanf("%d", &ans);

        switch(ans){

            case 1 : insert(1, 0);
                    break;
            case 2 : insert(0, 1);
                    break;
            case 3 : printf("Enter the position at which you want to insert:");
                     scanf("%d", &posi);
                     insert(posi, 0);
                    break;
            case 4 : delete(1, 0);
                    break;
            case 5 : delete(0,1);
                    break;
            case 6 : printf("Enter the position from which you want to delete:");
                     scanf("%d", &posi);
                     delete(posi, 0);
                    break;
            case 7 : display();
                    break;
            case 8 : exit(0);
                    break;
            default : printf("\n!Wrong option!\n");
        }
    }
}