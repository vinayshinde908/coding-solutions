#include<stdio.h>
long long int arr[500005];
int isPresent[10000000]={0};
int main()
{
    long long int i,temp;
    arr[0]=0;
    isPresent[0]=1;
    for(i=1;i<500005;i++)
     {
         temp=arr[i-1]-i;
         if(temp>0&&isPresent[temp]==0)
            {
                arr[i]=temp;
                isPresent[temp]=1;
            }
        else
        {
            arr[i]=arr[i-1]+i;
            isPresent[arr[i-1]+i]=1;
        }
    }
    int t;
    scanf("%d",&t);
    while(t!=-1)
    {
        printf("%lld\n",arr[t]);
        scanf("%d",&t);
    }
    return 0;
}