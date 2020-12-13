#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define count 10

struct tree{

    struct tree *lchild;
    int data;
    struct tree *rchild;
};

struct tree *temp = NULL, *start = NULL, *ptr = NULL;

struct tree *build_tree(int i){

    struct tree *p = (struct tree*)malloc(sizeof(struct tree));
    
    printf("Enter the data to be inserted at node %d:", i);
    scanf("%d", &p -> data);

    printf("Does node %d have left subtree (y/n):", i);
    char opt;
    scanf("%c%c", &opt, &opt);
    
    if(opt == 'y' || opt == 'Y'){

        p -> lchild = build_tree(2*i);
    }
    else
        p -> lchild = NULL;

    printf("Does node %d have right subtree (y/n):", i);
    scanf("%c%c", &opt, &opt);

    if(opt == 'y' || opt == 'Y'){

        p -> rchild = build_tree(2*i+1);
    }
    else
        p -> rchild = NULL;

    return p;
}

void display(struct tree *temp, int space){
    
    if(temp == NULL)
        return;
    else{

        space += count;

        display(temp -> rchild, space);

        printf("\n");

        for(int i = count; i < space; i++)
            printf(" ");
        printf("%d\n", temp -> data);

        display(temp -> lchild, space);
    }
}

void inorder(struct tree *temp){

    if(temp != NULL){

        inorder(temp -> lchild);
        printf("%d ", temp -> data);
        inorder(temp -> rchild);
    }
}

void postorder(struct tree *temp){

    if(temp != NULL){

        postorder(temp -> lchild);
        postorder(temp -> rchild);
        printf("%d ", temp -> data);
    }
}

void preorder(struct tree *temp){

    if(temp != NULL){

        printf("%d ", temp -> data);
        preorder(temp -> lchild);
        preorder(temp -> rchild);
    }
}

struct tree *search(struct tree *temp, int key){

    struct tree *y;
    
    if(temp != NULL){
        
        if(temp -> data == key)
            return temp;
        else{
            
            ptr = temp;    
            y = search(temp -> lchild, key);
            
            if(y == NULL){
                
                ptr = temp;
                y = search(temp -> rchild, key);
            }
            return y;
        }
    }
    else
        return NULL;
}

void insertion(struct tree *temp, int key){

    struct tree *l = search(temp, key);
    //printf("%d", l -> data);

    if(l != NULL){
        
        printf("\nInsert as left or right child(l / r):");
        char opt;
        scanf("%c%c", &opt, &opt);

        int ele;
        
        if(opt == 'l' || opt == 'L'){

            if(l -> lchild == NULL){
                
                struct tree *ll = (struct tree*)malloc(sizeof(struct tree));

                printf("Enter the element to insert:");
                scanf("%d", &ele);
                
                l -> lchild = ll;
                ll -> data = ele;

                ll -> lchild = NULL;
                ll -> rchild = NULL;

                printf("\n%d inserted successfully!", ll -> data);
            }
            else
                printf("\nInsertion is not possible!");
        }
        else if(opt == 'r' || opt == 'R'){

            if(l -> rchild == NULL){
                
                struct tree *lll = (struct tree*)malloc(sizeof(struct tree));

                printf("Enter the element to insert:");
                scanf("%d", &ele);
                
                l -> rchild = lll;
                lll -> data = ele;

                lll -> rchild = NULL;
                lll -> lchild = NULL;

                printf("\n%d inserted successfully!", lll -> data);
            }
            else
                printf("\nInsertion is not possible!");
        }
    }
    else
        printf("\nElement not found!");
}

void deletion(struct tree *temp, int key){

    struct tree *s = search(temp, key);

    if(s != NULL){

        if(s -> lchild == NULL && s -> rchild == NULL){

            printf("\nNode %d deleted!", s -> data);
            
            if(ptr -> lchild == s)
                ptr -> lchild = NULL;
            else
                ptr -> rchild = NULL;

            free(s);
        }
        else
            printf("\nCannot delete non leaf nodes!");
    }
    else
        printf("\nNode not found!");
}

void main(){

    start = build_tree(1);
    printf("%d", start -> data);
    
    int ch, n, del;
    
    while(1){

        printf("\n\nBinary Tree (Linked List) Operations:\n\n1.Insertion\n2.Deletion\n3.Inorder traversal\n4.Preorder traversal\n5.Postorder traversal\n6.Display\n7.Exit\n\nEnter your choice:");
        scanf("%d", &ch);

        switch(ch){

            case 1 :    printf("Enter the node to which you want to insert:");
                        scanf("%d", &n);
                        insertion(start, n);
                        break;
            case 2 :    printf("Enter the node you want to delete:");
                        scanf("%d", &del);
                        deletion(start, del);
                        break;
            case 3 :    printf("\nTraversing 'INORDER': ");
                        inorder(start);
                        break;
            case 4 :    printf("\nTraversing 'PREORDER' : ");
                        preorder(start);
                        break;
            case 5 :    printf("\nTraversing 'POSTORDER' : ");
                        postorder(start);
                        break;
            case 6 :    display(start, 1);
                        break;
            case 7 :    exit(0);
                        break;
            default :   printf("!!WRONG OPTION!!");
        }
    }
}