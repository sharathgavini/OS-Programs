#include<stdio.h>
#define MAX 50
int q[MAX],pg[MAX],page_fault=0,frame,pages;
static int r=0;
void initialize()
{
    int i;
    for(i=0;i<frame;i++)
    {
        q[i]=-1;
    }
    return;
}
void display()
{
    int i;
   for(i=0;i<frame;i++)
   {
       if(q[i] < 0) printf("\b");
    printf("%d ",q[i]);
   }
  printf("\t:");

}
int brute_force(int entry)
{
    int i;
   for(i=0;i<frame;i++)
   {
       if(entry==q[i])
        return 1;
   }
   return 0;

}
void main()
{

    int i,found_ele;
    printf("Enter the number of frames:");
    scanf("%d",&frame);
    printf("\nEnter the number of pages:");
    scanf("%d",&pages);
    printf("\nEnter memory reference string:\n");
    for(i=0;i<pages;i++)
    {
        scanf("%d",&pg[i]);
    }
    initialize();
    for(i=0;i<pages;i++)
    {
        if(found_ele=brute_force(pg[i]))
                    continue;
        else
        {

           // q[r%frame++]=pg[i];
            if(r<frame)
            {
                //printf("r:%d\n",r);
                q[r++]=pg[i];
                display();

            }

            else
            {
                r=0;
                //printf("r:%d\n",r);
                q[r++]=pg[i];
                display();
            }
            page_fault++;
            printf("Page fault:%d\n",page_fault);
        }
    }
    //printf("Page fault is %d",page_fault);

}
