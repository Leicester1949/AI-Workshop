#include<stdio.h>
int main(void)
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d*%d=%2d",j,i,j*i);
            if(j!=i)
            {
                printf(" ");
            }
        }
    printf("\n");
    }
    return 0;
}