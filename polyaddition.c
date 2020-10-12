#include<stdio.h>

struct polynomial
{
    int coeff;
    int expo;
};

struct polynomial p1[10], p2[10], p3[10];

void read1(int t)
{
    
    for(int i = 0;i < t; i++)
    {
        printf("\nEnter the coefficinet of term %d :", i + 1);
        scanf("%d", &p1[i].coeff);

        printf("Enter the exponent:");
        scanf("%d", &p1[i].expo);
    }
}
void read2(int t)
{
    
    for(int i = 0;i < t; i++)
    {
        printf("\nEnter the coefficinet of term %d :", i + 1);
        scanf("%d", &p2[i].coeff);

        printf("Enter the exponent:");
        scanf("%d", &p2[i].expo);
    }
}
int add(struct polynomial p1[10],struct polynomial p2[10],int t1,int t2)
{
    int i = 0,j = 0,k = 0;
    while(i < t1 && j < t2)
    {
        if(p2[j].expo == p1[i].expo)
        {
           p3[k].coeff = p1[i].coeff+p2[j].coeff;
            p3[k].expo = p1[i].expo;
            ++i; ++j; ++k;
        }
        else if(p1[i].expo > p2[j].expo)
        {
           p3[k].coeff = p1[i].coeff;
           p3[k].expo = p1[i].expo;
           ++i; ++k;
        }
        else 
        {
           p3[k].coeff = p2[j].coeff;
           p3[k].expo = p2[j].expo;
           ++j; ++k;
            
        }
    }
    while(j < t2)
    {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        ++j; ++k;
    }
    while(i < t1)
    {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        ++i; ++k;
    }
    return k;
}
void display(struct polynomial p[10], int t3)
{
 
    
    for(int i = 0;i < t3; i++)
    {
        printf("%d(x^%d) ",p[i].coeff, p[i].expo);
        if(i != t3-1)
        printf("+ ");
    }
}
void main()
{
    int t1, t2, t3;
    printf("\nEnter polynomial in descending order of powers\n");
    
    printf("\nEnter the number of terms in polynomial 1 :");
    scanf("%d", &t1);
    read1(t1);
    printf("\nPolynomial 1:\n");
    display(p1, t1);
    
    printf("\n\nEnter the number of terms in polynomial 2 :");
    scanf("%d", &t2);
    read2(t2);
    printf("Polynomial 2:\n");
    display(p2, t2);
    
    t3=add(p1, p2, t1, t2);
    
    printf("\n\nSum of the Polynomial:\n");
    display(p3, t3);
}