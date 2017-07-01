
/*C program for LRU */
#include<stdio.h>
#define MAX 50
int q[MAX],pg[MAX],c[MAX]={0},page_fault=0,frame,pages,time;
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
    printf(" %d ",q[i]);
   }
  printf("\n");

}
int brute_force(int entry)
{
    int i;
   for(i=0;i<frame;i++)
   {
       if(entry==q[i])
       {

       c[i]=time++;
        return 1;
       }

   }
   return 0;

}
int choose_vic(int m[])
{
  int small,i;
  small=0;
    for(i=0;i<frame;i++)
    {

        if(m[i]<m[small])
        {
            small=i;
        }

        }


    //printf("Small %d\n:",small);
    return small;
}
void main()
{

    int i,found_ele,victim;
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
    for(i=0,time=1;i<pages;i++)
    {
      if(found_ele=brute_force(pg[i]))
         {

                    continue;
         }
      if(page_fault<frame)
      {
      c[r]=time++;
      q[r++]=pg[i];
      page_fault++;
      display();

    }
    else
    {
        victim=choose_vic(c);
        r=victim;
        q[r]=pg[i];
        c[r]=time++;
        r++;
        page_fault++;
        //if(r>frame)
         //   r=0;
            display();
    }
}
printf("Total page faults: %d\n",page_fault);
}
