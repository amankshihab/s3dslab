#include<stdio.h>
#include<string.h>

char ch[20][50];
int n;


void quicksort(int first, int last){

    int i = first, j = last;
    char pivot[50];
    strcpy(pivot,ch[first]);

    if(first < last){

        while(i < j){

            while((strcmp(ch[i],pivot) >= 0) && i < last){

                i += 1;
            }
            while((strcmp(ch[j],pivot) <= 0) && j > first){

                j -= 1;
            }

            if(i < j){

                char temp[50];

                strcpy(temp,ch[i]);
                strcpy(ch[i],ch[j]);
                strcpy(ch[j],temp);
            }
        }

        char temp[50];

        strcpy(temp,ch[j]);
        strcpy(ch[j],ch[first]);
        strcpy(ch[first],temp);
    }

    for(int k = 0; k < n; k++){

        printf("%s  ", ch[k]);
    }

    quicksort(first,j-1);
    quicksort(j+1,last);
}

int main(){

    printf("Enter the no. of names you wish to enter:");
    scanf("%d",&n); 

    printf("\nEnter the names:");

    for(int i = 0; i < n; i++){

        scanf("%s", ch[i]);
    }

    quicksort(0,n);

    

    return 0;
}