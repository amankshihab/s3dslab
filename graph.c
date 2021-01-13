#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{

    int data;
    struct node *link;
} *graph[10];

struct node *start;

void print_links(int size){
    
    for(int i = 0; i < size; i++){

        struct node *temp = graph[i] -> link;
        //printf("%d", temp -> data);

        printf("\nLinks of node %d: ", graph[i] -> data);
        
        while(temp != NULL){

            printf("%d ", temp -> data);
            temp = temp -> link;
        }
    }
}

void links(int sz){

    //*start = graph[0];
    
    for(int i = 0; i < sz; i++){

        printf("Enter the no. of links for the node %d:", graph[i] -> data);
        int nlinks;
        scanf("%d", &nlinks);

        struct node * temp = graph[i];

        for(int j = 0; j < nlinks; j++){

            printf("Enter link %d of %d:", j+1, graph[i] -> data);
            struct node *newnode = (struct node*)malloc(sizeof(struct node));
            int link;
            scanf("%d", &newnode -> data);
            
            temp -> link = newnode;
            newnode -> link = NULL;
            temp = newnode;
        }
    }
}

/*void links(struct node *temp, int sz){

    //*start = graph[0];
    
    for(int i = 0; i < sz; i++){

        printf("Enter the no. of links for the node %d:", graph[i] -> data);
        int nlinks;
        scanf("%d", &nlinks);

        temp = graph[i];

        for(int j = 0; j < nlinks; j++){

            printf("Enter link %d of %d:", j+1, graph[i] -> data);
            int link;
            scanf("%d", &link);
            //temp -> link = newnode;
            //newnode -> link = NULL;
            //temp = newnode;


        }
    }
}*/

int main(){

    printf("Enter the no. of nodes in the graph(MAX:10):");
    int size;
    scanf("%d", &size);

    for(int i = 0; i < size; i++){

        printf("\nEnter the value of the node:");
        graph[i] = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &graph[i] -> data); 
    }

    links(size);
    print_links(size);

    return 0;
}