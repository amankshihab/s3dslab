#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
};

struct node *head = NULL;

void main(){

    struct node *newnode;
    
    printf("Enter the value to be entered:");
    int e;
    scanf("%d", &e);

    newnode = (struct node *)malloc(sizeof(struct node));

    if(head = NULL){

        newnode -> next = NULL;
        head = newnode;
    }
    else{

        newnode -> next = head;
        head = newnode; 
    }

    struct node *temp = head;

    while(temp -> next != NULL){
        printf("\n%d", temp -> data);
        temp = temp -> next;
    }

    //printf("\n%d --->NULL",temp->data);
}