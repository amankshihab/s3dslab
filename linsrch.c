#include<stdio.h>

int n, a[100];

void lin_srch(){

    int e, pos = 0, flag = 0;
    
    printf("\nEnter the element to search:");
    scanf("%d", &e);

    printf("\n");
    
    for(int i = 0; i < n; i++){

        if(e == a[i]){

            //pos = i;
            flag = 1;
            printf("%d found at position %d.\n", e, i);
        }
    }

    if(flag == 0){

        printf("\n%d not found in array.\n", e);
    }
}

void main(){

    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    
    printf("\nEnter the array:");
    for(int i = 0; i < n; i++){

        scanf("%d", &a[i]);
    }

    lin_srch();

}