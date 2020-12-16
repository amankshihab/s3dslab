#include<stdio.h>
#include<stdlib.h>

struct tree{

    int data;
    struct tree *lchild;
    struct tree *rchild;
};

struct tree *root = NULL;
int count = 10;

struct tree *succ(struct tree *ptr){

    struct tree *ptr1 = ptr -> rchild;

    if(ptr1 != NULL){

        while(ptr1 -> lchild != NULL){

            ptr1 = ptr1 -> lchild;
        }
    }

    return ptr1;

}

void search(int item){

    struct tree *ptr = root;
    int flag = 0;

    while(ptr != NULL && flag == 0){

        if(item < ptr -> data)
            ptr = ptr -> lchild;
        if(ptr -> data == item)
            flag = 1;
        if(item < ptr -> data)
            ptr = ptr -> rchild;
    }

    if(flag == 1)
        printf("\nItem found!");
    else
        printf("\nItem not found!");
}

void insert(){

    struct tree *p = (struct tree*)malloc(sizeof(struct tree));

    printf("\nEnter the item:");
    int item;
    scanf("%d", &item);

    p -> data = item;
    p -> lchild = NULL;
    p -> rchild = NULL;

    struct tree *ptr = root;
    struct tree *parent;

    while(ptr != NULL){

        parent = ptr;

        if(item < ptr -> data)
            ptr = ptr -> lchild;
        else
            ptr = ptr -> lchild;
    }

    if(item < parent -> data)
        parent -> lchild = p;
    else
        parent -> rchild = p;

    if(root == NULL)
        root = p;
}

struct tree *delete_bst(int item){

    struct tree *ptr = root, *parent;
    int flag = 0;

    while(ptr != NULL && flag == 0){

        if(item < ptr -> data){

            parent = ptr;
            ptr = ptr -> lchild;
        }
        else if(ptr -> data == item)
            flag = 1;
        else if(item > ptr -> data){

            parent = ptr;
            ptr = ptr -> lchild;
        }
    }

    if(flag == 0){
        printf("Item not found!");
        //break;
    }

    if(ptr -> lchild == NULL && ptr -> rchild == NULL){

        if(parent -> lchild == ptr)
            parent -> lchild = NULL;
        else
            parent -> lchild = NULL;

        return ptr;
    }
    else if(ptr -> lchild != NULL && ptr -> rchild != NULL){

        struct tree *ptr1 = succ(ptr);
        item = ptr1 -> data;
        delete_bst(ptr1 -> data);
        ptr -> data = item;
    }
    else{

        struct tree *ptr1 = succ(ptr);
        item = ptr -> data;
        delete_bst(ptr1 -> data);
        ptr -> data = item;
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

    int data, key, ch;
    
    while(1){

        printf("\n\nBinary Search Tree Operations:\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n\nEnter your choice:");
        scanf("%d", &ch);

        switch(ch){

            case 1 :    insert();
                            break;
            case 2 :    printf("\nEnter the data to be deleted:");
                        scanf("%d", &key);
                        delete_bst(key);
                            break;
            case 3 :    display(root, 1);
                            break;
            case 4 :    exit(0);
                            break;
            default :   printf("\n!!WRONG OPTION!!");
        }
    }

    return 0;
}