#include <stdio.h>
#include <stdlib.h>
#define count 10

struct node{
	int data;
	struct node *lchild, *rchild;
};

struct node *root = NULL, *temp;

void insert();
void inorder(struct node *r);
void postorder(struct node *r);
void preorder(struct node *r);
void display(struct node *temp,int space);
void search();
void del(int item);

int main()
{
	while(1){
		printf("\n\nBinary Search Tree Operations");
		printf("\n\n1.Insert\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n5.Delete\n6.Display\n7.Exit");
		int ch;
		printf("\n\nEnter Choice:");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert(); 
						break;
			case 2:	printf("\nTraversing 'INORDER'\n");
					inorder(root);
						break;
			case 3 :printf("\nTraversing 'PREORDER'\n"); 
					preorder(root);
						break;
			case 4 :printf("\nTraversing 'POSTORDER'\n"); 
					postorder(root);
						break;
			
			case 5:	
					if(root == NULL){
						printf("\nEmpty Binary Search Tree");
						break;
					}
					else{
						int item;
						printf("\nEnter item to delete : ");
						scanf("%d", &item);
						del(item);
					} 
					break;
			case 6 :  display(root, 10);
						break;
			case 7 : exit(0);
						break; 
			default: return 0;
		}
	}
}

void insert(){
	struct node *x = malloc(sizeof(struct node));
	printf("\nEnter data to insert: ");
	scanf("%d", &(x->data));
	x->lchild = NULL;
	x->rchild = NULL;
	if(root == NULL){
		root = x;
		printf("\nSuccessfully Inserted.");
		return;
	}
	struct node *ptr, *parent;
	ptr = root;
	while(ptr != NULL){
		parent = ptr;
		if(x->data > ptr->data){
			ptr = ptr->rchild;
		}
		else if(x->data < ptr->data){
			ptr = ptr->lchild;
		}
		else{
			printf("Duplicate Element. Could Not Insert.");
			free(x);
			return;
		}
	}
	if(x->data > parent->data){
		parent->rchild = x;
	}
	else{
		parent->lchild = x;
	}
	printf("\nSuccessfully Inserted.");
}

void display(struct node *temp,int space){
    
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

void inorder(struct node *r){
	struct node *ptr = r;
	if(ptr != NULL){
		inorder(ptr->lchild);
		printf("%d  ", ptr->data);
		inorder(ptr->rchild);
	}
}
void preorder(struct node *r){
	struct node *ptr = r;
	if(ptr != NULL){
		printf("%d  ", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
void postorder(struct node *r){
	struct node *ptr = r;
	if(ptr != NULL){
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ", ptr->data);
	}
}

struct node *succ(struct node *ptr){
	ptr = ptr->rchild; 
	while(ptr->lchild != NULL){
		ptr = ptr->lchild;
	}
	return ptr;
}
void del(int item){
	int flag = 0;
	struct node *ptr = root, *parent = root;
	while(ptr != NULL){
		if(item == ptr->data){
			flag = 1;
			break;
		}
		
		parent = ptr;
		if(item > ptr -> data){
			ptr = ptr->rchild;
		}
		else{
			ptr = ptr->lchild;
		}
	}
	if(flag == 0){
		printf("%d could not be found.", item);
		return;
	}
	int ch;
	if(ptr->lchild == NULL && ptr->rchild == NULL){
		ch = 1;
	}
	else if(ptr->lchild != NULL && ptr->rchild != NULL){
		ch = 3;
	}
	else{
		ch = 2;
	}
	switch(ch){
		case 1:{
			if(ptr == root){ 
				root = NULL; 
			}
			else if(parent->lchild == ptr){
				parent->lchild = NULL;
			}
			else{
				parent->rchild = NULL;
			}
			free(ptr);
			break;
		}
		case 2:{
			if(ptr == root){ 
				if(ptr->lchild == NULL){
					root = ptr->rchild;
				}
				else{
					root = ptr->lchild;
				}
			}
			else if(parent->lchild == ptr){
				if(ptr->lchild == NULL){
					parent->lchild = ptr->rchild;
				}
				else{
					parent->lchild = ptr->lchild;
				}
			}
			else{
				if(ptr->lchild == NULL){
					parent->rchild = ptr->rchild;
				}
				else{
					parent->rchild = ptr->lchild;
				}
			}
			free(ptr);
			break;
		}
		case 3:{
			struct node *sp = succ(ptr);
			int sd = sp->data;
			del(sd);
			ptr->data = sd;
			return; 
		}
	}
	printf("Successfully deleted.");
}