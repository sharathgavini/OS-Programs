#include<stdio.h>
#define MAX 50
int tat[MAX],bt[MAX],wt[MAX],n,ttat,twt;
float awt,atat;
void display_gantt()
{
    int i,j;
   printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for(i=0;i<n;i++)
    {
        for(j=0;j<bt[i]-1;j++)
            printf(" ");
        printf("P%d",i+1);
        for(j=0;j<bt[i]-1;j++)
            printf(" ");
            printf("|");
    }
        printf("\n");
         printf(" ");
     for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");
     printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("  ");
        if(tat[i] > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", tat[i]);

    }
    printf("\n");
}
void display()
{
    int i;
    printf("+------------+----------------+------------------+----------------------+\n");
    printf("| Process ID |   Burst Time   |   Waiting Time   |   Turn Around Time   |\n");
    printf("+------------+----------------+------------------+----------------------+\n");
    for(i=0;i<n;i++)
    {
    printf("|     %2d     |        %2d      |         %2d       |           %2d         |\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("+------------+----------------+------------------+----------------------+\n");
    display_gantt();
}
void compute()
{
    int i;
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i]+tat[i-1];
        tat[i]=bt[i]+wt[i];
        ttat=ttat+tat[i];
        twt=twt+wt[i];
    }
    display();

}
void main()
{   int i;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter burst time for process %d:",i+1);
        scanf("%d",&bt[i]);
    }
    compute();
}
