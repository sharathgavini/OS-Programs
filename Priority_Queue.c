#include<stdio.h>
void main()
{
     int p[10],b[10],wt[10],tat[10],i,n,twt=0,ttat=0,b1=0,p1,p2,p3,pr[10];
    float atat,awt;
    printf("enter the number of processes");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {

        printf("\n Enter the value of burst time and priority for %d:",i+1);
        scanf("%d %d",&b[i],&pr[i]);
        p[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        if(i!=n-1)
        {
        if(pr[i]>pr[i+1])
        {
            p3=pr[i];
            pr[i]=pr[i+1];
            pr[i+1]=p3;
            p2=b[i];
            b[i]=b[i+1];
            b[i+1]=p2;
            p1=p[i];
            p[i]=p[i+1];
            p[i+1]=p1;

        }
        }
    }


    printf("\n\nFIRST COME FIRST SERVE SCHEDULING ALGORITHM\n");
    printf("--------------------------------------------------\n");
    printf("Process id  |Priority  |Burst time  |Waiting time  |TurnaroundTime  |\n");
    printf("---------------------------------------------------\n");
    printf("%d       |%d      |%d     |0      |%d       |\n",p[0],pr[0],b[0],b[0]);
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+b[i-1];
        tat[i]=wt[i]+b[i];
        ttat=ttat+tat[i];
        twt=twt+wt[i];
        printf("\n%d\t  |%d\t  |%d\t  |%d\t  |%d  |\n",p[i],pr[i],b[i],wt[i],tat[i]);

    }
    printf("---------------------------------------------------\n");
    printf("\nGhant chart\n----------------------------------------------\n");
    printf("0");
    for(i=0;i<n;i++)
    {
    printf("   |%d\t",p[i]);
    }
    printf("\n-------------------------------------------------\n");
     printf("0");
    for(i=0;i<n;i++)
    {
        b1=b1+b[i];
    printf("   |%d\t",b1);
    }
    printf("\n-------------------------------------------------");
    awt=(float)twt/n;
atat=(float)ttat/n;
printf("\nAverage waiting time is %4.2f",awt);
printf("\nAverage turnaroundtime is %4.2f",atat);
}

