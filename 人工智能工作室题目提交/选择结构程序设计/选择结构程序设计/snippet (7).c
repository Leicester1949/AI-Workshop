#include<stdio.h>
int main(void)
{
    int n;
    int count=0;
    scanf("%d",&n);
    while(count<4)
    {
        if(n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=(3*n+1)/2;
        }    
        count=count+1;    
        }
    printf("%d\n",count);
    return 0;
}