#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int simu()
{
    return rand()%10 <7;
}
void main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);

    int k=1;
    while(k<=n)
    {
        printf("\nSending packet %d",k);
        if(simu())
        {
            printf("\nAcknowledgement for packet %d received",k);
            k++;
        }
        else
        {
            printf("\nAchnowledgement for packet %d lost",k);
        } 
    }
}
