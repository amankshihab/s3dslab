#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a[100], p, v, delp, sz, temp, ch;
    char ans = 'y';
    printf("Enter size of array:");
    scanf("%d", &sz);
    printf("Enter the array:");
    for(int i = 0; i < sz; i++)
    {
        scanf("%d", &a[i]);
    }
    while(ans != 'n')
    {
        printf("\nChoose an option:\n1.Insertion\n2.Deletion\n3.Display array\n4.Exit\nEnter your option:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : ++sz;
                     printf("\nEnter the place and value to insert:");
                     scanf("%d%d", &p, &v);
                     for(int i = sz; i >= p; i--)
                     {
                         a[i] = a[i - 1];
                     }
                     a[p] = v;
                     printf("\nArray after insertion:\n");
                     for(int i = 0; i < sz; i++)
                     {
                         printf("%d ", a[i]);
                     }
                     break;
            case 2 : printf("\nEnter the position of the element to be deleted:");
                     scanf("%d", &delp);
                     for(int i = delp; i < sz; i++)
                     {
                         a[i] = a[i+1];
                     }
                     --sz;
                     printf("\nArray after deletion:\n");
                     for(int i = 0; i < sz; i++)
                     {
                         printf("%d ", a[i]);
                     }
                     break;
	    case 3 : for(int i = 0; i < sz; i++)
                     {
                         printf("%d ", a[i]);
                     }
                     break;
            case 4 : exit(0);
                     break;
            default: printf("WRONG OPTION!");
        }
        printf("\n\nDo you want to do more operations?(y/n):");
        scanf("%s", &ans);
    }
}
