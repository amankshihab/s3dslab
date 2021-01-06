#include<stdio.h>
#include<stdlib.h>
#define count 10

int heap[100], size;

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

//a and b are the 2 nos to swap
void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

//to find maxheap
void maxheap(int index, int sz){
    
    if(index <= sz){
        
        maxheap(2*index, sz);
        
        if(2*index <= sz && heap[index] < heap[2*index])
            swap(&heap[index], &heap[2*index]);

        if(2 * index + 1 <= sz && heap[index] < heap[2*index+1])
            swap(&heap[index], &heap[2*index+1]);

        maxheap(2*index+1, sz);
    }
}

//root and last are indices
void heapsort(int root, int last){

    
    if(last > 1){
        
        swap(&heap[root], &heap[last]);
        
        last = last - 1;
        
        for(int i = 0; i < last; i++)
            maxheap(1, last);
        
        heapsort(root, last);
    }
}

//to delete a node
void deletion(){

    if(size < 1)
        printf("\nHeap is empty, deletion not possible!");
    else{

        swap(&heap[1], &heap[size]);
        
        heap[size] = '\0';
        size -= 1;

        maxheap(1, size);
    }
}

//to insert a node towards the end
void insertion(){

    if(size > 100)
        printf("\nThe heap is full!");
    else{

        printf("\nEnter the element to be inserted:");
        int item;
        scanf("%d", &item);

        size += 1;

        heap[size] = item;

        maxheap(1, size);

        printf("\nThe heap after inserting %d is:", item);
        display(1,1);
    }
}

int main(){

    printf("\nEnter the size of the array:");
    scanf("%d", &size);

    printf("\nEnter the array:");
    for(int i = 1; i <= size; i++)
        scanf("%d", &heap[i]);

    maxheap(1, size);
    maxheap(1,size);

    printf("\nThe entered array in maxheap form:\n");
    display(1,1);

    while(1){

        printf("\nHeap Tree Operations:\n\n1.Insertion\n2.Deletion\n3.Heap Sort\n4.Display\n5.Exit\n\nEnter your choice:");
        int ch;
        scanf("%d", &ch);

        switch(ch){

            case 1: insertion();
                    maxheap(1,size);
                        break;

            case 2: deletion();
                    maxheap(1,size);
                    display(1,1);
                        break;
            
            case 3: heapsort(1, size);
                    printf("\nThe heap after heap sort is:");
                    display(1,1);
                    printf("\nSorted heap: ");
                    for(int i = 1; i < size; i++)
                        printf("%d  ", heap[i]);
                    maxheap(1, size);
                    maxheap(1,size);
                        break;
            
            case 4: display(1, 1);
                        break;

            case 5: exit(0);
                        break;
            
            default:    printf("\n!!WRONG OPTION!!");
        }
    }

    return 0;
}