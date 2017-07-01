#include<stdio.h>
#define MAX 100
typedef struct
{
    int bt,wt,tat,pid;
}process;
int n,ttat,twt;
void display_gantt(process p[])
{
    int i,j;
   printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for(i=0;i<n;i++)
    {
        for(j=0;j<p[i].bt-1;j++)
            printf(" ");
        printf("P%d",i+1);
        for(j=0;j<p[i].bt-1;j++)
            printf(" ");
            printf("|");
    }
        printf("\n");
         printf(" ");
     for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n");
     printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt; j++) printf("  ");
        if(p[i].tat > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", p[i].tat);

    }
    printf("\n");
}
void display(process p[])
{
    int i;
    printf("+------------+----------------+------------------+----------------------+\n");
    printf("| Process ID |   Burst Time   |   Waiting Time   |   Turn Around Time   |\n");
    printf("+------------+----------------+------------------+----------------------+\n");
    for(i=0;i<n;i++)
    {
    printf("|     %2d     |        %2d      |         %2d       |           %2d         |\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
    }
    printf("+------------+----------------+------------------+----------------------+\n");
    display_gantt(p);
}
void swap(int *m,int *n)
{
    int *temp;
    temp=*m;
    *m=*n;
    *n=temp;
}
void compute(process p[])
{
    int i;
    p[0].wt=0;
    p[0].tat=p[0].bt;
    for(i=1;i<n;i++)
    {
        p[i].wt=p[i-1].tat;
        p[i].tat=p[i].bt+p[i].wt;
        ttat=ttat+p[i].tat;
        twt=twt+p[i].wt;
    }
    display(p);

}

void main()
{
    process p[MAX];
    int i,j;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time for process %d:",i+1);
        scanf("%d",&p[i].bt);
        p[i].pid=i+1;
    }
    //sorting the processes and process ids according to the increasing order of their burst times
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(p[j].bt>p[i].bt)
            {
                swap(&p[j],&p[i]);
                swap(&p[j].pid,&p[i].pid);
            }
        }

    }
    compute(p);

}
