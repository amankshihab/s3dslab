#include<stdio.h>
#include<stdlib.h>

int n, a[100];

void input(){   //taking in input
    
    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    printf("\nEnter the array:");
    for(int i = 0; i < n; i++){

        scanf("%d", &a[i]);
    }
}

void lin_srch(){    //function for linear search

    int e, pos = 0, flag = 0;
    
    printf("\nEnter the element to search:");
    scanf("%d", &e);

    printf("\n");
    
    for(int i = 0; i < n; i++){

        if(e == a[i]){

            //pos = i;
            flag = 1;
            printf("\n%d found at position %d.\n", e, i);
        }
    }

    if(flag == 0){

        printf("\n%d not found in array.\n", e);
    }
}

int is_sorted(){    //function to check it the array is sorted

    int flag = 1;
    
    for(int i = 0; i < n-1; i++){

        if(a[i] > a[i + 1]){

            flag = 0;
        }
    }

    return flag;
}

void sort(){    //function to sort if unsorted

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

void bin_srch(){    //funtion to perform binary search
    
    int low, high, mid, i = 0, p = 0, flag = 0, x, pos;

    if(is_sorted() == 0)
    sort();

    printf("\nEnter the element to be searched for:");
    scanf("%d", &x);
    
    low = 0; high = n-1;
    mid = ((high + low) / 2);
    
    while(flag == 0 && low <= high){

        mid = ((low + high) / 2);

        if(x == a[mid]){

            pos = mid;
            flag = 1;
        }
        else if(x > a[mid]){

            low = mid + 1;
        }
        else if(x < a[mid]){
            high = mid - 1;
        }
    } 
    
    if(flag == 1)
    printf("\n%d has been at position %d.\n", x, pos);
    else
    printf("\n%d not found in array.\n", x);
}

void main(){    //main function

    int ans = 1;

    input();
    
    do{
        printf("\nSearching techniques:\n1.Linear Search\n2.Binary Search\n3.Re-enter array\n4.Exit\nEnter your choice:");
        scanf("%d", &ans);

        switch(ans){

            case 1 : lin_srch();
                    break;
            case 2 : bin_srch();
                    break;
            case 3 : input();
                    break;
            case 4 : exit(0);
            default:printf("Wrong Option!");
        }
    }while(ans != 4);
}