#include<stdio.h>

int a[100], n, pos;

int is_sorted(){

    int flag = 1;
    
    for(int i = 0; i < n-1; i++){

        if(a[i] > a[i + 1]){

            flag = 0;
        }
    }

    return flag;
}

void sort(){

    int temp;

    for(int i = 0; i < (n-1); i++){

        for(int j = 0; j < (n - i - 1); j++){

            if(a[j] > a[j+1]){

                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("\nThe entered array has been sorted to perform binary search.\nThe sorted array is :\n");
    for(int i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }
    printf("\n");
}

void bin_srch(int x){
    
    int low, high, mid, i = 0, p = 0;
    
    low = 0; high = n-1;
    mid = ((high + low) / 2);
    
    while(x != a[mid] && low <= high){

        mid = ((low + high) / 2);

        if(x == a[mid]){

            pos = mid;
            p = 1;
        }
        else if(x > a[mid]){

            low = mid + 1;
        }
        else if(x < a[mid]){
            high = mid - 1;
        }
    } 
    
    if(p == 1)
    printf("\n%d has been at position %d.\n", x, pos);
    else
    printf("\n%d not found in array.\n", x);
}

void main(){

    int c, e, p;
    
    printf("\nEnter the size of the array:");
    scanf("%d", &n);

    printf("\nEnter the array:");
    for(int i = 0; i < n; i++){

        scanf("%d", &a[i]);
    }

    if(is_sorted() == 0)
    sort();

    printf("\nEnter the element to search:");
    scanf("%d", &e);

    bin_srch(e);
}