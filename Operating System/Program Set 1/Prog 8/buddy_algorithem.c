#include<stdio.h>
#include<stdlib.h>

int tree[2050],i,j,k;
void
segmentalloc(int,int),makedivided(int),makefree(int),printing(int,int);
int place(int),power(int,int);
int main()
{
    int totsize,ch,req;
    printf("Enter the Size of the memory  :  ");
    scanf("%d",&totsize);
    while(1)
    {
        printf("\n\t\tMENU\n");
        printf("1)Allocate the process into the Memory\n");
        printf("2)Deallocate the process from Memory\n");
        printf("3)Tree structure for Memory allocation Map\n");
        printf("4)Exit\n");
        printf("Enter your choice  :  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the Process size for allocation : ");
                scanf("%d",&req);
                segmentalloc(totsize,req);
                break;
            case 2:
                printf("\nEnter the process size to be deallocated :  ");
                scanf("%d",&req);
                makefree(req);
                break;
            case 3:
                printf("\nAllocation Map of Memory\n");
                printing(totsize,0);
                break;
            default:
                return 0;
        }
    }
    return 0;
}

void segmentalloc(int totsize,int request)
{
    int flevel=0,size;
    size=totsize;
    if(request>totsize)
    {
        printf("The system don't have enough free memory, use VIRTUAL MEMORY\n");
        return;
    }
    while(1)
    {
        if(request<=size && request>(size/2))
            break;
        else
        {
            size/=2;
            flevel++;
        }
    }
    for(i=power(2,flevel)-1;i<=(power(2,flevel+1)-2);i++)
        if(tree[i]==0 && place(i))
        {
            tree[i]=request;
            makedivided(i);
            printf("Successful Allocation\n");
            break;
        }
    if(i==power(2,flevel+1)-1)
    {
        printf("The system don't have enough free memory, use VIRTUAL MEMORY\n");
    }
}

void makedivided(int node)
{
    while(node!=0)
    {
        node=node%2==0?(node-1)/2:node/2;
        tree[node]=1;
    }
}

int place(int node)
{
    while(node!=0)
    {
        node=node%2==0?(node-1)/2:node/2;
        if(tree[node]>1)
            return 0;
    }
    return 1;
}

void makefree(int request)
{
    int node=0;
    while(1)
    {
        if(tree[node]==request)
            break;
        else
            node++;
    }
    tree[node]=0;
    while(node!=0)
    {
        if(tree[node%2==0?node-1:node+1]==0 && tree[node]==0)
        {
            tree[node%2==0?(node-1)/2:node/2]=0;
            node=node%2==0?(node-1)/2:node/2;
        }
        else
        {break;}
    }
}

int power(int x,int y)
{
    int z,ans;
    if(y==0) return 1;
    ans=x;
    for(z=1;z<y;z++)
        ans*=x;
    return ans;
}

void printing(int totsize,int node)
{
    int permission=0,llimit,ulimit,tab;
    if(node==0)
        permission=1;
    else if(node%2==0)
        permission=tree[(node-1)/2]==1?1:0;
    else
        permission=tree[node/2]==1?1:0;
    if(permission)
    {
        llimit=ulimit=tab=0;
        while(1)
        {
            if(node>=llimit && node<=ulimit)
                break;
            else
            {
                tab++;
                //printf("\n");
                llimit=ulimit+1;
                ulimit=2*ulimit+2;
            }
        }
        printf(" %d ",totsize/power(2,tab));
        if(tree[node]>1)
            printf("- Allocated %d\n",tree[node]);
        else if(tree[node]==1)
            printf("- Divided\n");
        else printf("- Free\n");
        printing(totsize,2*node+1);
        printing(totsize,2*node+2);
    }
}
