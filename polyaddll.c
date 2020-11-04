#include<stdio.h>
#include<stdlib.h>

int k = 1;

struct node{

    int coeff;
    int expo;
    struct node *link;
};

struct node *temp, *a, *b, *c, *start = NULL, *p1, *p2, *res, *f;

void display(struct node *z){

    //struct node *t = start;
    z = start;
    
    if(z -> link == NULL)
    printf("%dx^(%d)", z -> coeff, z -> expo);
    
    while(z -> link != NULL){

        printf("%dx^(%d) + ", z -> coeff, z -> expo);
        z = z -> link;

        if(z -> link == NULL)
        printf("%dx^(%d)", z -> coeff, z -> expo);
    }

    start = NULL;
}

struct node *readpoly(struct node *y){

    //struct node *p = (struct node*)malloc(sizeof(struct node));
    //struct node *p;
    
    printf("\n\nEnter the no. of elements in the polynomial:");
    int n, i = 0, coeff, expo;
    scanf("%d", &n);

    printf("\n");

    while(i < n){

        y = (struct node*)malloc(sizeof(struct node));
        
        printf("\nEnter the coefficient of x^%d:", (n - i - 1));
        scanf("%d", &coeff);
        
        y -> coeff = coeff; y -> expo = (n - i - 1);

        if(start == NULL){

            start = y;
            y -> link = NULL;
            temp = start;
        }
        else{

            temp -> link = y;
            y -> link = NULL;
            temp = temp -> link;
        }
        
        i += 1;
    }

    printf("\nPolynomial %d is :\n", k);
    k += 1;
    //display(p);
    return y;
}

struct node *addpoly(struct node *h, struct node *l){

    h = start; l = start; res = start; f = start;

    while(1){

        f = (struct node *)malloc(sizeof(struct node));

        
        if(h -> expo == l -> expo){

            f -> coeff = h -> coeff + l -> coeff;
            f -> expo = h -> expo;

            res -> link = f;
            res = res -> link;
            //res = res -> link; 
            h = h-> link; l = l -> link; res -> link = NULL;
        }
        if(h -> expo > l -> expo){

            f -> expo = h -> expo;
            f -> coeff = h -> coeff;
            res -> link = f;
            res = res -> link;
            //res = res -> link; 
            h = h -> link;
            res -> link = NULL;
        }
        if(h -> link == NULL || l -> link == NULL)
        break;
        else{

            f -> expo = l -> expo;
            f -> coeff = l -> coeff;
            res -> link = f;
            res = res -> link;
            //res -> link = NULL;
            //res = res -> link; 
            l = l -> link; 
            res -> link = NULL;
        }
    }

    while(1){

        if(h -> link == NULL)
        break;
        else{

            f = (struct node *)malloc(sizeof(struct node));
            
            f -> coeff = h -> coeff;
            f -> expo = h -> expo;
            res -> link = f;
            res = res -> link;
            //res = res -> link; 
            l = l -> link;
            res -> link = NULL;
        }
    }
    while(1){

        if(l -> link == NULL)
        break;
        else{

            f = (struct node *)malloc(sizeof(struct node));
            
            f -> coeff = l -> coeff;
            f -> expo = l -> expo;
            res -> link = f;
            res = res -> link; 
            l = l -> link;
            res -> link = NULL;
        }
    }

    //res -> link = NULL;

    return res;
}

void main(){

    a = readpoly(p1);
    display(a);
    b = readpoly(p2);
    display(b);
    
    c = addpoly(a, b);
    display(c); 
}