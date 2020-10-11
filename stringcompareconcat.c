#include<stdio.h>
#include<stdlib.h>
void main()
{
    char s1[200], s2[200], s3[200], s4[200];
    int c, alen = 0, blen = 0, k, flag = 0, ch = 1;
    while(ch != 0)
    {
        printf("\nChoose your option:\n1.String comparison\n2.String concatenation\n3.Exit\nEnter your choice:");
        scanf("%d", &c);
        switch(c)
        {
            case 1 : flag = 0;
            	     printf("\nEnter the first string:");
                     scanf("%s", s1);
                     printf("Enter the second string:");
                     scanf("%s", s2);
                     for(int i = 0; s2[i] != '\0'; i++)
                     {
                         if(s1[i] != s2[i])
                         {
                             flag = 1;
                             break;
                         }
                         if(flag == 1)
                         break;
                     }
                     if(flag == 1)
                     printf("Strings are not equal.");
                     else
                     printf("Strings are equal.");
                     break;
            case 2 : printf("\nEnter the first string:");
                     scanf("%s", s3);
                     printf("Enter the second string:");
                     scanf("%s", s4);
                     for(int i = 0; s3[i] != '\0'; i++)
                            ++alen;
                     for(int i = 0; s4[i] != '\0'; i++)
                            ++blen;
                     k = alen;
                     for(int j = 0; s4[j] != '\0'; j++, k++)
                     {
                         s3[k] = s4[j];
                     }
                     s3[k] = '\0';
                     printf("The concatenated string is %s.", s3);
                     break;
            case 3 : exit(0);
                     break;
            default : printf("WRONG OPTION!");
        }
        printf("\nWant to choose options further?(1/0):");
        scanf("%d", &ch);
    }
}
