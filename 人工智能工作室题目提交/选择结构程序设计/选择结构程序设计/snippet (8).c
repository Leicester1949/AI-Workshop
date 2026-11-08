#include<stdio.h>
int main(void)
{
    int a,b;
    int cnt[10]={0};
    int i;
    scanf("%d %d",&a,&b);
    while(a>0)
    {
        cnt[a%10]++;
        a=a/10;
    }
while(b>0)
{
    cnt[b%10]--;
    b=b/10;
}
    int flag =1;
    for(i=0;i<10;i++)
    {
        if(cnt[i]!=0)
        {
            flag=0;
            break;
        }
    }
    if(flag)
        printf("Tacit!");
    else
        printf("No Tacit!");
        return 0;
}