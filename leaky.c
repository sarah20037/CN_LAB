#include<stdio.h>
void main()
{
    int b,n,r,a[100];
    printf("Enter bucket size, number of packets and outgoing rate:");
    scanf("%d %d %d",&b,&n,&r);
    printf("Enter incoming sizes-");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int s=0;
    for(int i=0;i<n;i++)
    {
        int k=a[i];
        printf("\nIncoming packet size is %d",k);
        if(k<=(b-s))
        {
            s+=k;
            printf ("\nBucket size=%d/%d",s,b);
        }
        else
        {
            printf("\nOVERFLOW");
            printf("\nDropped %d packets",k+(s-b));
            printf ("\nBucket size=%d/%d",s,b);
            s=b;
        }
        s-=r;
        if(s<0)
            s=0;
        printf ("\nAfter outgoing,bucket size=%d/%d",s,b);    
    }
}
