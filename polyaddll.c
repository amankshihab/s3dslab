#include<stdio.h>
#include<stdlib.h>

struct poly{

    int coeff;
    int exp;
    struct poly *next;
};
 
struct poly *start1, *start2;

void display(struct poly *st){

    struct poly *temp;

    temp = st;

    while(temp -> next != NULL){

        printf("%d(x)^%d + ", temp -> coeff, temp -> exp);

        if(temp -> next == NULL){

            printf("%d(x)^%d", temp -> coeff, temp -> exp);
        }
    }
}

struct poly *read(){

    struct poly *start = NULL;

    printf("Enter the no. of terms in the polynomial:");
    int n, c, e;
    scanf("%d", &n);
    struct poly *temp;

    for(int i = 0; i < n; i++){

        printf("\n");
        struct poly *p;
        p = (struct poly*)malloc(sizeof(struct poly));

        printf("Enter the coefficient :");
        scanf("%d", c);
        printf("Enter the exponent :");
        scanf("%d", e);
        p -> coeff = c;
        p -> exp = e;
        p -> next = NULL;
    
        if(start == NULL){

            start = p;
            temp = p;
            printf("11a");
        }
        else{

            temp -> next = p;
            temp = temp -> next;
            printf("111");
        }
    }

    return start;
}

void main(){

    start1 = read();
    display(start1);
    start2 = read();
    display(start2);
    //addAB();
}