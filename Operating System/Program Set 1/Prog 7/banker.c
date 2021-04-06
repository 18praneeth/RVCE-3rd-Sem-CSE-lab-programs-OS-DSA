#include<stdio.h>
#include<stdlib.h>

int main(){
    int process,resources,i,j,k,flag = 0;

    printf("Enter number of processes : ");
    scanf("%d",&process);
    printf("Enter number of resources : ");
    scanf("%d",&resources);

    int max[process][resources],need[process][resources], allocated[process][resources];
    int available[resources], total[resources],count1 = 0,count2 = 0,completed[process];

    printf("Enter total resource instances \n");

    for(i=0;i<resources;i++){
        scanf("%d",&total[i]);
    }

    printf("Enter max resources required : \n");

    for(i=0;i<process;i++){
        for(j=0;j<resources;j++){
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter allocated resources : \n");
    for(i=0;i<process;i++){
        for(j=0;j<resources;j++){
            scanf("%d",&allocated[i][j]);
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    for(i=0;i<resources;i++){
        available[i] = 0;
        for(j=0;j<process;j++){
            available[i] += allocated[j][i];
        }
        available[i] = total[i] - available[i];
    }


    while(count1!=process)
    {
        count2 = count1;
        for(i=0;i<process;i++){
            k=0;
            for(j=0;j<resources;j++){
                if(need[i][j]<= available[j]){
                    k++;
                }
            }
            if(k == resources && completed[i] != 1){
                completed[i] = 1;
                count1++;
                for(j=0;j<resources;j++){
                    available[j] += allocated[i][j];
                    need[i][j] = 0;
                }
                printf("Process %d has completed\n",i);
            }
        }
        if(count1 == count2){
            printf("Unsafe: Deadlock\n");
            exit(0);
        }
    }
    printf("Safe State\n");
    return 0;

}
