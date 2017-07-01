#include<stdio.h>
void main()
{
	int ms,os,size,p[50],ps[50],inter=0,n,i;
	printf("Enter the size of memory:");
	scanf("%d",&ms);
	printf("\nEnter the os memory:");
	scanf("%d",&os);
	printf("\nEnter the number of partitions:");
	scanf("%d",&n);
	size=ms/n;
	ms=ms-os;

	for(i=0;i<n;i++)
	{
		printf("enter the process number and process size:");
		scanf("%d %d",&p[i],&ps[i]);
		if(ps[i]<=size)
		{
			inter=inter+size-ps[i];
			printf("\nprocess is allocated:");

		}
		else
		{
			printf("processs is blocked");
		}
			printf("\ninternal fragmentation is %d",inter);

	}

}
