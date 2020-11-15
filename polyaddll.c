#include<stdio.h>
#include<stdlib.h>

struct poly{

    int coeff;
    int exp;
    struct poly *next;
};
 
struct poly *start1, *start2, *startr = NULL, *tempr;

void display(struct poly *st){

    struct poly *temp;

    temp = st;

    while(temp -> next != NULL){

        printf("%d(x)^%d + ", temp -> coeff, temp -> exp);
        temp = temp -> next;

        if(temp -> next == NULL){

            printf("%d(x)^%d", temp -> coeff, temp -> exp);
        }
    }

    //free(temp);
}

struct poly *read(){

    struct poly *start = NULL;

    printf("\n\nEnter the no. of terms in the polynomial:");
    int n, c, e;
    scanf("%d", &n);
    struct poly *temp;

    for(int i = 0; i < n; i++){

        printf("\n");
        struct poly *p;
        p = (struct poly*)malloc(sizeof(struct poly));

        printf("Enter the coefficient :");
        scanf("%d", &c);
        printf("Enter the exponent :");
        scanf("%d", &e);
        p -> coeff = c;
        p -> exp = e;
        p -> next = NULL;
    
        if(start == NULL){

            start = p;
            temp = p;
        }
        else{

            temp -> next = p;
            temp = temp -> next;
        }
    }

    return start;
}

void *result(int coeff, int expo){

    struct poly *p = (struct poly*)malloc(sizeof(struct poly));

    p -> coeff = coeff;
    p -> exp = expo;
    p -> next = NULL;

    if(startr == NULL){

        startr = p;
        tempr = p;
    }
    else{

        tempr -> next = p;
        tempr = tempr -> next;
    }
}

void add(struct poly *s1, struct poly *s2){

    //struct poly *p, *q;
    int s;

    //p = s1; q = s2;
    while(s1 != NULL && s2 != NULL){

        if(s1 -> exp == s2 -> exp){

            s = s1 -> coeff + s2 -> coeff;

            result(s, s1 -> exp);

            s1 = s1 -> next;
            s2 = s2 -> next;
        }
        else if(s1 -> exp > s2 -> exp){

            result(s1 -> coeff, s1 -> exp);
            s1 = s1 -> next;
        }
        else{

            result(s2 -> coeff, s2 -> exp);
            s2 = s2 -> next;
        }
    }

        while(s2 != NULL){

            result(s2 -> coeff, s2 -> exp);
            s2 = s2 -> next;
        }
        while(s1 != NULL){

            result(s1 -> coeff, s1 -> exp);
            s1 = s1 -> next;
        }
}

void main(){

    start1 = read();
    printf("\nThe first polynomial is:\n");
    display(start1);
    start2 = read();
    printf("\nThe second polynomial is:\n");
    display(start2);
    printf("\n\nThe resultant polynomial is:\n");
    add(start1, start2);
    display(startr);
}