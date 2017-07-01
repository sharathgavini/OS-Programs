#include<stdio.h>
void main()
{
	int  n,f[20],b[20],sb[20],i,j,c[20][20],t[20];
	printf("enter the number of files:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter the file name %d",i+1);
		scanf("%d",&f[i]);
		printf("\nEnter the number of blocks:");
		scanf("%d",&b[i]);
		printf("\nenter the starting block:");
		scanf("%d",&sb[i]);
		printf("\nEnter the blocks of file%d:",i+1);
		for(j=0;j<b[i];j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	printf("\n\nFilename\tsize\tstartingblock\nblocks occupied\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t",f[i],b[i],sb[i]);
		for(j=0;j<b[i];j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
