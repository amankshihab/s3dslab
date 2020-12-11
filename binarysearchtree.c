#include<stdio.h>
#include<stdlib.h>

struct tree{

    int data;
    struct tree *lchild;
    struct tree *rchild;
};

struct tree *start = NULL, *templ = NULL, *tempr = NULL;

struct tree *root(int data){

    struct tree *p = (struct tree*)malloc(sizeof(struct tree));

    p -> data = data;
    p -> lchild = NULL;
    p -> rchild = NULL;
}

struct tree *search(struct tree *start, int data){

    if(start -> lchild != NULL && start -> rchild != NULL){
    
        if(start -> data < data)
            return search(start -> lchild, data);
        else if(start -> data > data)
            return search(start -> rchild, data);
    }
    else if(start -> lchild == NULL && start -> rchild == NULL)
        return start;
    else
        return NULL;
}

void *insert(struct tree *start){

    struct tree *p = (struct tree*)malloc(sizeof(struct tree));
    
    printf("\nEnter the data to be inserted:");
    int data;
    scanf("%d", &p -> data);
    
    struct tree *l = search(start, data);
    printf("%d", l -> data);

    if(l != NULL){

        if(l -> data < data){

            l -> lchild = p;
            p -> rchild = NULL;
            p -> lchild = NULL;
            printf("\nNode with %d inserted successfully at left as a child to %d", p -> data, l -> data);
        }
        else if(l -> data > data){

            l -> rchild = p;
            p -> rchild = NULL;
            p -> lchild = NULL;

            printf("\nNode with %d inserted successfully at right as a child to %d", p -> data, l -> data);
        }
    }
    else
        printf("\nInsertion not possible!");
}

void main(){


    printf("\nEnter the root element:");
    int data;
    scanf("%d", &data);
    start = root(data);
    insert(start);
    printf("\nEnd of first insert!");
    
    /*while(1){

        printf("\n\nBinary Search Tree Operations:\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n\nEnter your choice:");
        scanf("%d", &ch);

        switch(ch){

            case 1 :    insertion;
                            break;
            case 2 :    deletion;
                            break;
            case 3 :    display;
                            break;
            case 4 :    exit(0);
                            break;
            default :   printf("\n!!WRONG OPTION!!");
        }
    }*/
}