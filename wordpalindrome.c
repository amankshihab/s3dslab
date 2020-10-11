#include<stdio.h>
void main()
{
    char a[100], b[100],flag = 0;
    int len, alen = 0;
    printf("Enter a word:");
    scanf("%s", a);
    for(int i = 0; a[i] != '\0'; i++)
            ++alen;
    len = alen;
    for(int i = len - 1; i >= 0; i--)
    {
        b[len - i - 1] = a[i];
    }
    for(int i = 0; i < len; i++)
    {
        if(b[i] != a[i])
        flag = 1;
    }
    if(flag == 1)
    {
        printf("\n'%s' is not a palindrome.\n", a);
    }
    else
    printf("\n'%s' is a palindrome.\n", a);
}
