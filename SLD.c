#include<stdio.h>
void main()
{
	int n,s[20],i,j;
	char d[100][100],f[50][50][50];
	printf("Enter the number of directories:");
	scanf("%d",&n);
	printf("\nenter the names of directories:");
	for(i=0;i<n;i++)
	{
		scanf("%s",d[i]);
	}

	for(i=0;i<n;i++)
{printf("\n Enter the size of  directory %d:",i+1);
	scanf("%d",&s[i]);
}
for(i=0;i<n;i++)
{
printf("\nenter the names of files in directory %d:",i+1);
for(j=0;j<s[i];j++)
{
	scanf("%s",f[i][j]);
}
}
printf("\n\nDirectory name\t Size \t Filenames\n");
for(i=0;i<n;i++)
{
	printf("%s\t %d\t",d[i],s[i]);
	for(j=0;j<s[i];j++)
	{
		printf("%s\n \t\t",f[i][j]);
	}
	printf("\n");
}
}
