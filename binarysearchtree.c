#include<stdio.h>
#include<stdlib.h>
#define count 10

struct tree{

    int data;
    struct tree *lchild;
    struct tree *rchild;
};

struct tree *start = NULL, *ptr = NULL;

struct tree *search(struct tree *start, int key){

    if(start != NULL){
        if(start -> data == key)
            return start;
        else if(start -> data < key){
            
            ptr = start;
            search(start -> lchild, key);
        }
        else if(start -> data > key){
            
            ptr = start;
            search(start -> rchild, key);
        }
    }
    else
        return NULL;
}

struct tree *insucc(struct tree *start){

    struct tree *start1 = start -> rchild;

    if(start1 != NULL)
        while(start1 -> lchild != NULL)
            start1 = start1 -> lchild;
        
    return start1;
}

void deletion(struct tree *start, int key){

    struct tree *l = search(start, key);
    //printf("%d", l -> data);
    
    if(l != NULL){
        
        if(l -> lchild == NULL && l -> rchild == NULL){ //normal

            if(ptr -> lchild == l)
                ptr -> lchild = NULL;
            else if(ptr -> rchild == l)
                ptr -> lchild = NULL;

            free(l);
        }
        else if(l -> lchild == NULL && l -> rchild != NULL){//rchild occupied
        
            struct tree *f = l -> rchild;

            l -> data = f -> data;
            free(f);
        }
        else if(l -> rchild ==  NULL && l -> lchild != NULL){//lchild occupied

            struct tree *f = l -> lchild;

            l -> data = f -> data;
            free(f);
        }
        else if(l -> lchild != NULL && l -> rchild != NULL){//both occupied

            struct tree *h = search(start, key);
            struct tree *g = insucc(h);

            h -> data = g -> data;
            free(g);
        }
    }
    else
        printf("\nNode not found!");
}

struct tree *newnode(int data){     //to create a new node

    struct tree *p = (struct tree*)malloc(sizeof(struct tree));

    p -> data = data;
    p -> lchild = NULL;
    p -> rchild =  NULL;

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

struct tree *insertion(struct tree *start, int data){
    
    if(start == NULL)
        return newnode(data);
    if(data < start -> data)
        start -> lchild = insertion(start -> lchild, data);
    else if(data > start -> data)
        start -> rchild = insertion(start -> rchild, data);

    return start;
}

int main(){

    int data;
    
    printf("Enter the root element:");
    int root, ch, key;
    scanf("%d", &root);
    start = insertion(start, root);
    //printf("hh %d", start -> data);
    
    while(1){

        printf("\n\nBinary Search Tree Operations:\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n\nEnter your choice:");
        scanf("%d", &ch);

        switch(ch){

            case 1 :    printf("Enter the data to insert:");
                        scanf("%d", &data);
                        insertion(start, data);
                            break;
            case 2 :    printf("\nEnter the data to be deleted:");
                        scanf("%d", &key);
                        deletion(start, key);
                            break;
            case 3 :    display(start, 1);
                            break;
            case 4 :    exit(0);
                            break;
            default :   printf("\n!!WRONG OPTION!!");
        }
    }

    return 0;
}