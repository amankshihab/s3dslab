#include<stdio.h>
#include<stdlib.h>

int tree[30], nodes, last, count = 10;

void display(int root, int space){

    if(tree[root] == '\0')
        return;
    
    space += count;

    display(2*root+1, space);

    printf("\n");

    for(int i = count; i < space; i++)
        printf(" ");
    printf("%d\n", tree[root]);

    display(2*root, space);
}

int search(int index, int key){

    int i = index, x;
    
    if(tree[i] == key)
        return i;
    if(2*i <= last)
        x = search(2*i, key);
    else
        return 0;

    if((x == 0) && (2*i+1 <= last))
        x = search(2*i+1, key);

    return x;
}

void insertion(int key, int item){

    int l;
    char b;
    l = search(1, key);

    if(l == 0)
        printf("Search Unsuccessful!");
    else if(tree[2*l] == '\0' || tree[2*l+1] == '\0'){

        printf("Enter to left or right (l or r):");
        scanf("%c%c", &b, &b);

        if(b == 'l' || b == 'L'){

            if(tree[2*l] == '\0'){

                tree[2*l] = item;
                printf("Inserted as node %d.", 2*l);
                last = 2 * l + 1;
            }
            else{

                printf("Insertion to node %d not possible!", l);
            }
        }
        else if(b == 'r' || b == 'R'){

            if(tree[2*l+1] == '\0'){

                tree[2*l+1] = item;
                printf("Inserted as node %d.", 2*l+1);
                last = 2 * l + 1;
            }
            else{

                printf("Insertion to node %d not possible!", l);
            }
        }
    }
    else{

        printf("Insertion not possible!");
    }
}

void deletion(int key){

    int flag = 0;

    int l = search(1, key);

    if(l != 0){

        if(tree[2*l] == '\0' && tree[2*l+1] == '\0'){

            printf("\nNode %d deleted!\n", l);
            flag = 1;
            tree[l] = '\0';
        }
        else{

            printf("\nCannot delete non leaf nodes!\n");
        }
    }
    else{

        printf("\nNode does not exist!\n");
    }
}

void build_tree(int i, int item){

    if(i != 0){

        last = i;

        tree[i] = item;
        printf("Node %d has left subtree(y/n):", i);
        char ch;
        scanf("%c%c",&ch,&ch);
        if(ch == 'y'){
            
            printf("Enter the data to insert:");
            int dt;
            scanf("%d", &dt);
            build_tree(2*i, dt);
        }
        else{

            build_tree(0, '\0');
        }

        printf("Node %d has right subtree(y/n):",i);
        char c;
        scanf("%c%c",&c,&c);
        if(c == 'y'){

            printf("Enter the data to insert:");
            int g;
            scanf("%d", &g);
            build_tree(2*i+1, g);
        }
        else{

            build_tree(0, '\0');
        }

    }
}
void inorder(int i){

    if(tree[i] != '\0'){

        inorder(2*i);
        printf("%d  ", tree[i]);
        inorder(2*i+1);
    } 
}

void postorder(int i){

    if(tree[i] != '\0'){

        postorder(2*i);
        postorder(2*i+1);
        printf("%d  ", tree[i]);
    }
}

void preorder(int i){

    if(tree[i] != '\0'){

        printf("%d  ", tree[i]);
        preorder(2*i);
        preorder(2*i+1);
    }
}

void main(){

    int ch, root, key, item, del;

    printf("\nEnter the root element:");
    scanf("%d", &root);
    
    build_tree(root, 1);
    
    while(1){

        printf("\n\nBinary Tree (Array) Operations:\n\n1.Inorder Traversal\n2.Postorder Traversal\n3.Preorder Traversal\n4.Insertion\n5.Deletion\n6.Exit\n\nEnter your choice:");
        scanf("%d", &ch);

        switch(ch){

            case 1 : printf("\nInorder: ");
                     inorder(1);
                        break;
            case 2 : printf("\nPostorder: ");
                     postorder(1);
                        break;
            case 3 : printf("\nPreorder: ");
                     preorder(1);
                        break;
            case 4 : printf("\nEnter the position and item:");
                     scanf("%d%d", &key, &item);
                     insertion(key, item);
                        break;
            case 5 : printf("\nEnter the node to delete:");
                     scanf("%d", &del);
                     deletion(del);
                        break;
            case 6 : exit(1);
                        break;
            case 8 : display(1, 1);
                        break;
            default : printf("\n!!WRONG OPTIONS!!\n");
        }
    }
}