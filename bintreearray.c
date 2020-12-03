#include<stdio.h>
#include<stdlib.h>

int tree[30], nodes;

void display(){

    if(tree[1] == '\0'){

        printf("Tree is empty!");
    }
    
    else{
        
        for(int i = 1; i <= nodes; i++){

            //printf("%d", tree[i]);

            if(tree[i] != '\0')
                printf("%d", tree[i]);
            else
                break;
        }
    }
}

void root(int r){

    tree[1] = r;
}

void lchild(){

    printf("\nEnter the parent nodes position:");
    int parent;
    scanf("%d", &parent);

    printf("Enter the data:");
    int data;
    scanf("%d", &data);

    tree[(2*parent)] = data;
}

void rchild(){

    printf("\nEnter the parent node:");
    int parent;
    scanf("%d", &parent);

    printf("Enter the data:");
    int data;
    scanf("%d", &data);

    tree[(2*parent + 1)] = data;
}

void main(){

    printf("Enter the no. of nodes in the tree:");
    scanf("%d", &nodes);
    
    printf("Insert root :");
    int r;
    scanf("%d", &r);
    root(r);
    
    while(1){

        printf("\nBinary tree using array:\n\n1.Insert left\n2.Insert right\n3.Display\n4.Delete left\n5.Delete right\n6.Exit\n\nEnter your choice:");
        int ch;
        scanf("%d", &ch);

        switch(ch){

            case 1 : lchild();
                        break;
            case 2 : rchild();
                        break;
            case 3 : display();
                        break;
            case 6 : exit(0);
                        break;
            default : printf("\n!!WRONG OPTION!!");
        }
    }
}