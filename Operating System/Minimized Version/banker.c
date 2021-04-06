#include <stdio.h>

int main(){
	int processes, resources;
	int i, j;
	printf("\nEnter the number of processes: ");
	scanf("%d", &processes);
	printf("\nEnter the number of resources: ");
	scanf("%d", &resources);

	int max[processes][resources];
	int allocated[processes][resources];
	int need[processes][resources];
	
	int total[resources];
	int available[resources];
	int completed[processes];
	
	printf("\nEnter total resource instances: \n");
	for(j=0; j<resources; j++){
		scanf("%d", &total[j]);
		available[j] = total[j];
	}
	
	printf("\nEnter max resource instances required for every process: \n");
	for(i=0; i<processes; i++){
		printf("For P[%d]: ", i+1);
		for(j=0; j<resources; j++){
			scanf("%d", &max[i][j]);
			completed[i] = 0;
		}
	}
	
	printf("Enter allocated resource instaces for every process:\n");
	for(i=0; i<processes; i++){
		printf("For P[%d] ", i+1);
		for(j=0; j<resources; j++){
			scanf("%d", &allocated[i][j]);
			need[i][j] = max[i][j] - allocated[i][j];
			available[j] = available[j] - allocated[i][j];
		}
	}
	
	printf("Execution sequence: \n");
	int finished = 0;
	int last_fin = 0;
	i = 0;
	
	
	do{
		if(completed[i]){
			i = (i + 1)% processes;
			continue;
		}
		
		int satisfied = 0;
		
		for(j=0; j<resources; j++){
			if(need[i][j] <= available[j])
				satisfied ++;
		}
		
		if(satisfied == resources){
			completed[i] = 1;
			for(j=0; j<resources; j++)
				available[j] += allocated[i][j];
			printf("P[%d] ", i+1);
			finished++;
			last_fin = i;
		}
		
		if(finished == processes){
			break;
		}
		
		i = (i + 1) % processes;
				
	}while(i!= last_fin);
	
	if(finished == processes)
		printf("\nSafe state : No deadlock\n");
	else
		printf("\nNot safe state : Deadlock\n");
	
	return 0;
}
