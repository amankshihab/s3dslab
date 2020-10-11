#include<stdio.h>
#include<stdlib.h>

int s[50][50], m, n, t[50][50];

void t2s(){

    int nz, rows, col;
    
    //printf("Enter the no. of rows and columns in the triplet representation:");
    //scanf("%d%d", &m, &n);
    //printf("Enter the no. of non-zero elements:");
    //scanf("%d", &nz);

    printf("\nEnter the triplet matrix:\n");
    scanf("%d%d%d", &rows, &col, &nz);
    for(int i = 0; i < 3; i++){

        for(int j = 0; j <nz; j++){

            scanf("%d", &t[i][j]);
        }
    }

    /*t[0][0] = rows;
    t[0][1] = col;
    t[0][2] = nz;*/

    int k = 1, i, j;

    printf("\nThe sparse matrix is:");
    for( i = 0; i < rows; i++){

        printf("\n");
        
        for(j = 0; j < col; j++){

            if(i == t[k][0] && j == t[k][1]){

                s[i][j] = t[k][2];
            }
            else{
                
                s[i][j] = 0;
            }
            
        }
        ++k;
        printf("%d  ", s[i][j]);
    }
}

void main(){

    int c;
    
    do{
        printf("\nEnter your choice:\n\n1.Triplet representation to sparse matrix\n2.Sparse matrix to triplet representation\n3.Exit\n\nEnter your choice:");
        scanf("%d", &c);

        switch(c){

            case 1: t2s();
                    break;
            //case 2: s2t();
              //      break;
            case 3: exit(0);
                    break;
            default: printf("\n!!Wrong option!!\n");
        }
    }while(c != 3);
}