#include<stdio.h>
#include<stdlib.h>

int a[50], b[50], size;;

void display(){

    printf("\nThe array now is:\n");
    
    for(int i = 0; i < size; i++)
        printf("%d ", b[i]);    
}

void copy(){

    for(int i = 0; i < size; i++){

        b[i] = a[i];
    }
}

void enter(){

    printf("Enter the size of the array:");
    scanf("%d", &size);
    
    printf("\nEnter the array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &a[i]);

    copy(a, b);
}

void bubblesort(){

    int temp;
    
    for(int i = 0; i < (size - 1); i++){
        
        for(int j = 0; j < (size - i - 1); j++){

            if(b[j] > b[j + 1]){

                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

void sel_sort(){

    for(int i = 0; i < (size - 1); i++){

        int loc = i;
        int min = b[i];

        for(int k = i+1; k < size; k++){

            if(b[k] < min){

                min = b[k];
                loc = k;
            }
        }

        if(loc != i){

            int temp = b[loc];
            b[loc] = b[i];
            b[i] = temp;
        }
    }
}

void ins_sort(){

    int j;
    
    for(int i = 1; i < size; i++){

        int m = b[i];

        for(j = i - 1; j >= 0; j--){

            if(m < b[j])
                b[j+1] = b[j];
            else
                break;
        }
        b[j+1] = m;
    }
}

void main(){

    int ch;

    enter();

    display();

    while(1){
        
        printf("\n\nSorting Algorithms:\n\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Revert array\n5.Re-enter array\n6.Display array\n7.Exit\n\nEnter your choice:");
        scanf("%d", &ch);

        switch(ch){

            case 1 :    bubblesort();
                        printf("\nThe array after bubble sort is:\n");
                        display();
                        break;
            case 2 :    sel_sort();
                        printf("\nThe array after selection sort is:\n");
                        display();
                        break;
            case 3 :    ins_sort(b);
                        printf("\nThe array after insertion sort is:\n");
                        display(b);
                        break;
            case 4 :    copy(a, b);
                        printf("\nThe array has been reverted!");
                        display();
                        break;
            case 5 :    enter();
                        printf("\nOriginal array has been changed!\n");
                        display();
                        break;
            case 6 :    display(b);
                        break;
            case 7 :    exit(1);
                        break;
            default:    printf("\n!!WRONG CHOICE!!");
        }
    }    
}