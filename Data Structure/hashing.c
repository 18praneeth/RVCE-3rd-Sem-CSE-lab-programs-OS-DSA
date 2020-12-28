#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int hashtable[SIZE];

void insert()
{
    int key, hkey, index, i;
    printf("Enter the key to be inserted:\n");
    scanf("%d", &key);
    hkey = key%SIZE;
    for(i=0;i<SIZE;i++)
    {
        index = (hkey+i)%SIZE;
        if(hashtable[index]==-1)
        {
            hashtable[index]=key;
            printf("Inserted\n");
            return;
        }
    }
    printf("No space for new insertion\n");
}

void del()
{
    int key, hkey, index, i;
    printf("Enter the key to be deleted:\n");
    scanf("%d", &key);
    hkey = key%SIZE;
    for(i=0;i<SIZE;i++)
    {
        index = (hkey+i)%SIZE;
        if(hashtable[index]==key)
        {
            hashtable[index]=-1;
            printf("Deleted");
            return;
        }
    }
    printf("Key not found\n");
}

void search()
{
    int key, hkey, index, i;
    printf("Enter the key to be searched:\n");
    scanf("%d", &key);
    hkey = key%SIZE;
    for(i=0;i<SIZE;i++)
    {
        index = (hkey+i)%SIZE;
        if(hashtable[index]==key)
        {
            printf("Key found at index %d\n", index);
            return;
        }
    }
    printf("Key not found\n");
}

void display()
{
    int i;
    printf("Hashtable contents are:\n");
    for(i=0;i<SIZE;i++)
        printf("[%d] : %d\n", i, hashtable[i]);
}

int main()
{

    int ch, i;
    for(i=0;i<SIZE;i++)
        hashtable[i] = -1;
    while(1)
    {
        printf("\nEnter the choice-1.Insert, 2.Delete, 3.Search, 4-Display\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            default:
                return 0;
        }
    }
    return 0;
}
