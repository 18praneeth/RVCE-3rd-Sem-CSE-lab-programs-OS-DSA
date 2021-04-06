#include <stdio.h>
#define p 5
#define r 5
void main()
{
	/*
	int p,r;
	printf("Enter the number of Processes : ");
	scanf("%d",&p);
	printf("Enter the number of Rescources : ");
	scanf("%d",&r);
	*/
	int i,j,k,temp=0,count=0,flag=0;
	int allocated[p][r],max[p][r],need[p][r],available[r],completed[p]={0};
	printf("Enter the Allocated Matrix : \n" );
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
	scanf("%d",&allocated[i][j]);
	printf("Enter the Max Matrix : \n" );
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
	scanf("%d",&max[i][j]);
	printf("Enter the Available Memomry : \n" );
	for(j=0;j<r;j++)
	scanf("%d",&available[j]);
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
	need[i][j]=max[i][j]-allocated[i][j];
	while(count<=p)
	{
		flag=1;
		for(i=0;i<p;i++)
		{
			temp=1;
			if(completed[i]!=0)
			continue;
			for(j=0;j<r;j++)
			{
				if(need[i][j]>available[j])
				{
					temp=0;
					break;
				}	
			}
			if(temp)
			{
				completed[i]=count+1;
				for(j=0;j<r;j++)
				available[j]+=need[i][j];
				count++;
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("A Deadlock\n");
			break;
		}
	}
	if(flag!=1)
	{
		printf("Safe Route");
	}	
}
