#include<stdio.h>
#include<stdlib.h>
int simu()
{
    return rand()%10 < 7;
}
void main()
{
    int n,w;
    printf("Enter the number of processes:");
    scanf("%d",&n);

    printf("Enter window size:");
    scanf("%d",&w);

    int done=1,k=1;
    while(done<n)
    {
        printf("\n\nSENDING WINDOW\n");
        for(int i=0;i<w && done<=n;i++)
        {
            printf("\nSending frame %d",k);
            k++;
        }
        printf("\n\nACKNOWLEDGEMENTS");
        for(int i=0;i<w && done<=n;i++)
        {
            
            int x=simu();
            if(x)
               {
                printf("\nAcknowledgement %d received",done);
                done++;
                k=done;
               } 
            else
            {
                printf("\nAcknowledgement %d lost",k);
                printf("\nRetransmitting from %d",k);
                break;
            }
        }
       
    }
}
