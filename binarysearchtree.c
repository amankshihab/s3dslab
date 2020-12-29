#include<stdio.h>
#include<stdlib.h>
#define count 10

struct tree{

    int data;
    struct tree *lchild;
    struct tree *rchild;
};

struct tree *start = NULL, *ptr = NULL;


struct tree *newnode(int data){     //to create a new node

    struct tree *p = (struct tree*)malloc(sizeof(struct tree));

    p -> data = data;
    p -> lchild = NULL;
    p -> rchild =  NULL;

    return p;
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

struct tree *insucc(struct tree *start){

    struct tree *start1 = start -> rchild;

    if(start1 != NULL)
        while(start1 -> lchild != NULL)
            start1 = start1 -> lchild;
        
    return start1;
}

struct tree *search(struct tree *start, int key){

    if(start != NULL){
        
        if(start -> data == key)
            return start;
        else if(start -> data < key){
            
            ptr = start;
            search(start -> rchild, key);
        }
        else if(start -> data > key){
            
            ptr = start;
            search(start -> lchild, key);
        }
    }
    else
        return NULL;
}

void deletion(struct tree *start, int key){

    struct tree *l = search(start, key);
    
    if(l != NULL){
        
        if(l -> lchild == NULL && l -> rchild == NULL){ //normal    case 1

            printf("\n%d deleted!", l -> data); //l is the element to be deleted
            
            if(ptr -> lchild == l)
                ptr -> lchild = NULL;
            else if(ptr -> rchild == l)
                ptr -> rchild = NULL;

            free(l);
        }
        else if(l -> lchild == NULL && l -> rchild != NULL){//rchild occupied   case 2a
        
            struct tree *f = l -> rchild;   //l is the element to be deleted

            printf("\n%d deleted!", l -> data);
            ptr -> rchild = NULL;
            insertion(start, f -> data);
            free(l);
            /*int item = f -> data;
            l -> data = item;
            f -> lchild = NULL;
            f -> rchild = NULL;
            l -> rchild = NULL;
            free(f);*/
        }
        else if(l -> rchild ==  NULL && l -> lchild != NULL){//lchild occupied  case 2b

            struct tree *f = l -> lchild;

            printf("\n%d deleted!", l -> data);
            int item = f -> data;
            l -> data = item;
            f -> lchild = NULL;
            f -> rchild = NULL;
            l -> rchild = NULL;
            free(f);
        }
        else if(l -> lchild != NULL && l -> rchild != NULL){//both occupied case 3

            struct tree *g = insucc(l);

            printf("\n%d deleted!", l -> data);
            int item = g -> data;
            //l -> data = item;

            deletion(start ,g -> data);
            l -> data = item;
        
            free(g);
        }
    }
    else
        printf("\nNode not found!");
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


int main(){

    int data;
    
    printf("Enter the root element:");  //to initialize tree
    int root, ch, key;
    scanf("%d", &root);
    start = insertion(start, root);
    
    while(1){

        printf("\n\nBinary Search Tree Operations:\n\n1.Insertion\n2.Deletion\n3.Display\n4.Inorder Traversal\n5.Postorder traversal\n6.Preorder traversal\n7.Exit\n\nEnter your choice:");
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

            case 4 :    printf("\nTraversing 'INORDER':\n");
                        inorder(start);
                            break;

            case 5 :    printf("\nTraversing 'POSTORDER':\n");
                        postorder(start);
                            break;

            case 6 :    printf("\nTraversing 'PREORDER':\n");
                        preorder(start);
                            break;

            case 7:    exit(0);
                            break;

            default :   printf("\n!!WRONG OPTION!!");
        }
    }

    return 0;
}