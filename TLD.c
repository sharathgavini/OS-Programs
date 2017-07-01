#include<stdio.h>
struct st
{
	int ds,sds[50];
	char d[50],sd[50][50],f[50][50][50];

}dir[10];
void main()
{ int i,j,k,n;
	printf("Enter the number of directories:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the name of  directory %d:",i+1);
		scanf("%s",dir[i].d);
		printf("enter the size of directory %d:",i+1);
		scanf("%d",&dir[i].ds);
		for(j=0;j<dir[i].ds;j++)
		{
			printf("\nEnter the name of subdirectory %d:",j+1);
			scanf("%s",dir[i].sd[j]);
			printf("\nEnter the size of subdirectory%d:",j+1);
			scanf("%d",&dir[i].sds[j]);
			for(k=0;k<dir[i].sds[j];k++)
			{
				printf("enter the file names:");
				scanf("%s",dir[i].f[j][k]);
			}
		}
	}
	printf("directory\t size\t subdir\t size\t files\t\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t %d\t",dir[i].d,dir[i].ds);
		for(j=0;j<dir[i].ds;j++)
		{
			printf("%s\t %d\t",dir[i].sd[j],dir[i].sds[j]);
			for(k=0;k<dir[i].sds[j];k++)
			{
				printf("%s\n\t\t\t\t",dir[i].f[j][k]);
			}
		}
		printf("\n");
	}

}
