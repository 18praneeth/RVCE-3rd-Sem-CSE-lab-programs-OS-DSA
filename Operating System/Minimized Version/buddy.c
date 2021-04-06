#include <stdio.h>
#include <stdlib.h>

int tree[32] = {};

int max;

int can_alloc(int node){
	while(node != 1){
		node /= 2;
		if(tree[node] == 0)
			continue;
		if(tree[node] == -1)
			return 1;
		return 0;
	}
	return 1;
}

void mem_alloc(int req){
	if(req > max){
		printf("\nThe Required size exceeds the memory\n");
		return;
	}
	
	int level = 0;
	int s = max;
	while(1){
		if(req <= s && req > s/2)
			break;
		s /= 2;
		level ++;
	}
	
	for(int i = ( 1 << level); i < ( 1 << (level + 1)); i++){
		if(tree[i] == 0 && can_alloc(i)){
			tree[i] = req;
			for(i = i/2; tree[i] == 0; i /= 2)
				tree[i] = -1;
			printf("\nSuccessful allocation\n");
			
			if(level > tree[0])
				tree[0] = level;
			return;
		}
	}
	
	printf("The system don't have enough free memory\n");	
}


int mem_print(int node, int level){
	for(int i=0; i<level; i++)
		printf("|	");
	
	int size = max / (1 << level);
	if(tree[node] == 0)
		printf("%d	--> FREE\n", size);
	
	else if(tree[node] == -1){
		printf("%d	--> DIVIDED\n", size);
		mem_print(node*2, level + 1);
		mem_print(node*2 + 1, level +1);
	}
	else
		printf("%d: ALLOCATED - %d\n", size, tree[node]);
}


void mem_dealloc(int size){
	int node = 1;
	int last = 1 << (tree[0] + 1);
	
	for(; node < last; node ++){
		if(tree[node] == size)
			break;
	}
	
	if(node == last){
		printf("Process with size %d is not present in the memory\n", size);
		return;
	}
	
	tree[node] = 0;
	printf("Sucessfull deallocation\n");
	
	while(node != 1){
		int sib = node%2 == 0 ? node + 1: node -1;
		if(tree[sib] == 0){
			node /= 2;
			tree[node] = 0;
		}
		else
			return;
	}
	
}

int main(){
	int choice, req;
	printf("\nBUDDY MEMORY ALLOCATION\n");
	
	printf("\nEnter the total size of memory: ");
	scanf("%d", &max);
	
	while(1){
		printf("\n1. Locate the Process into memory\n");
		printf("\n2. Remove the Process from memory\n");
		printf("\n3. Tree structure of the Memory\n");
		printf("\n4. Exit\n");
		
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: 
					printf("\nMEMORY ALLOCATION\n");
					printf("Enter the process size: ");
					scanf("%d", &req);
					mem_alloc(req);
					break;
			case 2: 
					printf("\nMEMORY DEALLOCATION\n");
					printf("Enter the process size: ");
					scanf("%d", &req);
					mem_dealloc(req);
					break;
			case 3: 
					printf("\nMEMORY ALLOCATION MAP\n");
					mem_print(1, 0);
					break;
			default: 
					return 0;
		}
	}
	
	return 0;
}


