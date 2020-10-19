#include<stdio.h>
#include<stdlib.h>

int s[50][50], m, n, t[50][50];

/*void t2s(){

    int nz, rows, col;
    
    //printf("Enter the no. of rows and columns in the triplet representation:");
    //scanf("%d%d", &m, &n);
    printf("Enter the no. of non-zero elements:");
    scanf("%d", &nz);

    printf("\nEnter the triplet matrix:\n");
    //scanf("%d%d%d", &t[0][0], &t[0][1], &t[0][2]);
    for(int i = 0; i <= nz; i++){

        for(int j = 0; j < 3; j++){

            scanf("%d", &t[i][j]);
        }
    }

    t[0][0] = rows;
    t[0][1] = col;

    int k = 1;

    printf("\nThe sparse matrix is:");
    for(int i = 0; i < rows; i++){

        printf("\n");
        printf("%d", 1);
        
        for(int j = 0; j < col; j++){

            if(i == t[k][0] && j == t[k][1]){

                s[i][j] = t[k][2];
            }
            else{
                
                s[i][j] = 0;
            }
            
        //printf("%d  ", s[i][j]);
        }
        ++k;
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", s[i][j]);
        }
    }
}*/

void s2t(){

    int m, n, k = 0, i, j, ci, cj;
    
    printf("Enter the rows and columns in the matrix:");
    scanf("%d%d", &m, &n);

    t[k][0] = m; t[k][1] = n;

    printf("Enter the matrix:\n");
    for(i = 0; i < m; i++){
        
        ++ci;
        for(j = 0; j < n; j++){

            scanf("%d", &s[i][j]);
            ++cj;
        }
    }

    int count = 0; 

    for(i = 0; i < m; i++){

        for(j = 0; j < n; j++){

            if(s[i][j] != 0){

                ++count; ++k;
                t[k][0] = i;
                t[k][1] = j;
                t[k][2] = s[i][j];
            }
        }
    }
    t[0][2] = count;

    printf("\nTriplet Representation:\n");
    for(i = 0; i <= count; i++){

        printf("\n");
        
        for(j = 0; j < 3; j++){

            printf("%d  ", t[i][j]);
        }
    }
}

void main(){

    int c;
    
    do{
        printf("\n\nEnter your choice:\n1.Triplet representation to sparse matrix\n2.Sparse matrix to triplet representation\n3.Exit\n\nEnter your choice:");
        scanf("%d", &c);

        switch(c){

            case 1: printf("%d", 1);
                    //t2s();
                    break;
            case 2: s2t();
                    break;
            case 3: exit(0);
                    break;
            default: printf("\n!!Wrong option!!\n");
        }
    }while(c != 3);
}