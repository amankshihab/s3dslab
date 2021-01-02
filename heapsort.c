#include<stdio.h>
#include<stdlib.h>
#define count 10

int heap[50], size;

void display(int root, int space){

    if(heap[root] == '\0')
        return;
    
    space += count;

    display(2*root+1, space);

    printf("\n");

    for(int i = count; i < space; i++)
        printf(" ");
    printf("%d\n", heap[root]);

    display(2*root, space);
}

//root is the index of root of the particular subtree, same with lchild and rchild
int greatest(int root, int lchild, int rchild){

    if(heap[root] >= heap[lchild] && heap[root] >= heap[rchild])
        return root;
    
    if(heap[lchild] >= heap[root] && heap[lchild] >= heap[rchild])
        return lchild;
    
    if(heap[rchild] >= heap[root] && heap[rchild] >= heap[lchild])
        return rchild;
}

//a and b are the 2 nos to swap
void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxheap(int index, int sz){

    if(index <= sz){
        
        maxheap(2*index, sz);
        
        int great = greatest(index, 2*index, 2*index+1);

        //checking if right subree is greatest
        if(heap[great] == heap[2*index])
            swap(&heap[index], &heap[2*index]);
        //checking if left subtree is greatest
        if(heap[great] == heap[2*index+1])
            swap(&heap[index], &heap[2*index+1]);

        maxheap(2*index+1, sz);
    }
}

//root and last are indices
void heapsort(int root, int last){

    printf("\n%d", last);
    
    if(last > 1){
        
        if(heap[root] > heap[last]){
            
            swap(&heap[root], &heap[last]);
            last = last - 1;
        }
        for(int i = 0; i < last; i++)
            maxheap(1, last);
        printf("\nAfter maxheap");
        display(1,1);
        heapsort(root, last);
    }
}

int main(){

    printf("\nEnter the size of the array:");
    scanf("%d", &size);

    printf("\nEnter the array:");
    for(int i = 1; i <= size; i++)
        scanf("%d", &heap[i]);

    printf("\nThe entered heap tree is :\n");
    display(1, 1);

    printf("\nThe maxheap is:\n");
    for(int i = 0; i < size; i++)
        maxheap(1, size);
    display(1,1);

    printf("\nAfter heapsort");
    //for(int i = 0; i < size; i++)
        heapsort(1, size);
    printf("Main after heapsort");
    display(1,1);

    return 0;
}