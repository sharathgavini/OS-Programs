#include<stdio.h>
void main()
{
	int  n,b[20],sb[20],i,j,c[20][20];
	char f[20][20];
	printf("enter the number of files:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter the file name %d",i+1);
		scanf("%s",&f[i]);
		printf("\nEnter the number of blocks:");
		scanf("%d",&b[i]);
		printf("\nenter the starting block:");
		scanf("%d",&sb[i]);

		for(j=0;j<b[i];j++)
		{
			c[i][j]=sb[i]+j;
		}
	}
	printf("\nfilename\tsize\tstartingblock\tblocks occupied\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t\t%d\t\t%d\t\t",f[i],b[i],sb[i]);
		for(j=0;j<b[i];j++)
			printf("%d ",c[i][j]);
	printf("\n");
	}

}
