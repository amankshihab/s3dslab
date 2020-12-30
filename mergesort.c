#include<stdio.h>

//int b[];

/*void printarray(int b[] ,int beg,int size){

    printf("\n");
    for(int i = beg; i <= size; i++)
        printf("%d  ",b[i]);
}*/

void merge(int b[], int first, int mid, int last){

    int temp[50];
    int i = last;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= first){

        if(b[i] <= b[j])
            temp[k+=1] = b[i+=1];
        else
            temp[k+=1] = b[j+=1];
    }

    while(i <= mid)
        temp[k+=1] = b[i+=1];
    while(j <= last)
        temp[k+=1] = b[j+=1];
    k -= 1;

    while(k >= 0){

        b[k+last] = temp[k];
        k -= 1;
    }
}

void mergesort(int b[], int first, int last){

    if(first < last){

        int mid = (first + last) / 2;
        
        mergesort(b, first, mid);
        mergesort(b, mid + 1, last);

        merge(b,first,mid,last);
    }
}

void main(){

    int b[50] = {10,20,41,56,78,42,11,9};

    mergesort(b, 0, 8);

    for(int i = 0; i < 8; i++)
        printf("%d ", b[i]);
}